#![no_main]
#![no_std]

#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(non_camel_case_types)]

use panic_halt as _;


use embedded_hal::spi::{Mode, Phase, Polarity};
use cortex_m_semihosting::hprintln;
use cortex_m_rt::entry;
use core::{cell::{Cell, RefCell},
        fmt::Write,
    };
use cortex_m::{
    asm::delay,
    interrupt::Mutex,
    };
use stm32f4xx_hal::{
    pac::*,
    gpio::*,
    prelude::*,
    spi::*,
    serial::*,
    };


const ARRAY_SIZE: usize = 2;

const TX_ARRAY: usize = 2;

const READ: u8 = 0 << 7 | 1 << 6;
const WRITE: u8 = 0 << 7 | 0 << 6;

const COMMAND: u8 = 1 << 7 | 1 << 6;

//FIFO
const FIFO_LOAD: u8 = 0x80;
const FIFO_READ: u8 = 0xBF;

//table 22 and 23 -- sets as initiator, ISO1443A and collision avoidance
const MODE_ADD: u8 = 0x03;
const MODE: u8 = 0b00001001;


//sets to tx/rx ~106kb/s -- this is the slowest
const BIT_RATE_ADD: u8 = 0x04;
const BIT_RATE: u8 = 0b00000000; 

const ANA_PRESET_CMD: u8 = 0xCC;

const OPERATION_CONTROL_ADD: u8 = 0x02;
const OPERATION_CONTROL: u8 = 0b11001100;

const MAIN_IRQ_ADD: u8 = 0x17;

//need to set pA0 as an interupt

type IRQ_MCU = PA0<Input>; 

type SPIHandle = Spi1<(PA5<AF5>,PA6<AF5>,PA7<AF5>)>;    



//sets up a global variable wrapped in a safe abstraction

//  A mutual exclusion primitive useful for protecting shared data
//  This mutex will block threads waiting for the lock to become available.
//  The mutex can be created via a new constructor. Each mutex has a type parameter which 
//  represents the data that it is protecting. The data can only be accessed through the RAII 
//  guards returned from lock and try_lock,
//  which guarantees that the data is only ever accessed when the mutex is locked.

//static G_IRQ: Mutex<RefCell<Option<IRQ_MCU>>> = Mutex::new(RefCell::new(None));
//static G_SPI: Mutex<RefCell<Option<SPIHandle>>> = Mutex::new(RefCell::new(None));

#[entry]
fn main() -> ! {
    if let Some(mut dp) = Peripherals::take() {
        // Set up the system clock.
       
        let rcc = dp.RCC.constrain();
        let clocks = rcc.cfgr.freeze();

        let gpioa = dp.GPIOA.split();
        let gpiob = dp.GPIOB.split();
        let mut cs = gpiob.pb6.into_push_pull_output();
        cs.set_high();
        
        let mut led = gpioa.pa8.into_push_pull_output();
        led.set_high();

        //clk, miso, mosi, respectively
        let pa5 = gpioa.pa5.into_alternate().internal_pull_up(true);
        let pa6 = gpioa.pa6.into_alternate();
        let pa7 = gpioa.pa7.into_alternate();
        let mode = Mode {

            polarity: Polarity::IdleLow,
            phase: Phase::CaptureOnSecondTransition,
        
        };
    
        let mut spi = Spi::new(
                                dp.SPI1,
                                (pa5, pa6, pa7),
                                mode,
                                1.MHz(),
                                &clocks
                            );

        /*sets up pa0 as input for mcu_irq */
        let mut irq = gpioa.pa0;
        
        /*  Saving for when I want to do interuppts again
        let mut syscfg = dp.SYSCFG.constrain();
        irq.make_interrupt_source(&mut syscfg);
        irq.trigger_on_edge(&mut dp.EXTI, Edge::Rising);
        irq.enable_interrupt(&mut dp.EXTI);
        */
        let uart_tx = gpioa.pa2.into_alternate();
        
        //configuring UART 
        let mut tx = dp.USART2.tx(
            uart_tx,
            Config::default()
                .baudrate(115200.bps())
                .wordlength_8()
                .parity_none(),
            &clocks,
        )
        .unwrap();

        /*// Enable the external interrupt in the NVIC by passing the NFC IRQ interrupt number
        unsafe {
            cortex_m::peripheral::NVIC::unmask(irq.interrupt());
        }
*/

        // Now that NFC IRQ is configured, move button into global context
       /*
            cortex_m::interrupt::free(|cs| {
            G_IRQ.borrow(cs).replace(Some(irq));
           // G_SPI.borrow(cs).replace(Some(spi));
        });

        */
        let tx_buffer = cortex_m::singleton!(: [u8; ARRAY_SIZE] = [1; ARRAY_SIZE]).unwrap();
        
        /*
        Attempting to read ID register. 0x3F--read mode 'mosi --0b01xxxxxx'
        Should report 0x0D
         */
        tx_buffer[0] = 0x40 | 0x3F;
        tx_buffer[1] = 0x00;

        //hprintln!("{:#x?}", buffer[0]);
 
        cs.set_low();
        delay(3);
        let result = spi.transfer(tx_buffer).unwrap();
        delay(3);
        cs.set_high();

        //hprintln!("printing NFC ID");
        //hprintln!("{:#x?}", result);
        writeln!(tx, "Device ID {:#x?}\r", result).unwrap();
        
        tx_buffer[0] = 0x00 | 0x02;
        tx_buffer[1] = 0xD3;

        //tries to write 0x02 to enable regulators and osc
        cs.set_low();
        delay(3);
        let result = spi.transfer(tx_buffer).unwrap();
        delay(3);
        cs.set_high();

        //try to confirm the write
        tx_buffer[0] = 0x40 | 0x02;
        tx_buffer[1] = 0x00;
        cs.set_low();
        delay(3);
        let result = spi.transfer(tx_buffer).unwrap();
        delay(3);
        cs.set_high();
        writeln!(tx, "0x02 reg {:#x?}\r", result).unwrap();
        /*
        cortex_m::interrupt::free(|cs| {
            G_SPI.borrow(cs).replace(Some(spi));
           
        });*/

    }
        loop {
            //rprintln!("hello, world!");
        }
    }

/*#[interrupt]
fn EXTI0() {
    cortex_m::interrupt::free(|cs| {
        let refcell = G_IRQ.borrow(cs).borrow();
        let exti = match refcell.as_ref() { None => return, Some(v) => v };
        exti.pr1.modify(|_, w| w.pr0().set_bit());
    });
    let irq_buffer = cortex_m::singleton!(: [u8; 1] = [1; 1]).unwrap();
    irq_buffer[0] =READ | MAIN_IRQ_ADD;
    //let result = spi.transfer(irq_buffer);
}
*/
