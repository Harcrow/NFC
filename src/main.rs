#![no_main]
#![no_std]

use cortex_m::asm::delay;
//use cortex_m::delay;
// Halt on panic
use panic_halt as _;
use cortex_m_rt::entry;
use embedded_hal::spi::{Mode, Phase, Polarity};
use core::cell::{Cell, RefCell};
use cortex_m::interrupt::Mutex;

use cortex_m_semihosting::hprintln;

use stm32f4xx_hal::{
                    pac::{self, interrupt},
                    gpio::*,
                    prelude::*,
                    spi::*,
                };

const ARRAY_SIZE: usize = 5;
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
//stm32f4xx_hal::gpio::gpioa::PA0
type IrqMcu = PA0<Input>; 

//PICK UP FROM HERE ********************
type SPIHandle = Spi1<(PA5<AF5>,PA6<AF5>,PA7<AF5>)>;

/*pub type I2c1Handle = I2CMasterDma<
    I2C1,                                       // Instance of I2C
    (PB8<AF4<OpenDrain>>, PB9<AF4<OpenDrain>>), // Pins
    Stream1<DMA1>,                              // Stream used for Tx
    0,                                          // Channel for Tx
    Stream0<DMA1>,                              // Stream used for Rx (Not used in example)
    1,                                          // Channel for Rx (Not used in example)
>; */

//sets up a global variable wrapped in a safe abstraction

//  A mutual exclusion primitive useful for protecting shared data
//  This mutex will block threads waiting for the lock to become available.
//  The mutex can be created via a new constructor. Each mutex has a type parameter which 
//  represents the data that it is protecting. The data can only be accessed through the RAII 
//  guards returned from lock and try_lock,
//  which guarantees that the data is only ever accessed when the mutex is locked.
static G_IRQ: Mutex<RefCell<Option<IrqMcu>>> = Mutex::new(RefCell::new(None));
static G_SPI: Mutex<RefCell<Option<SPIHandle>>> = Mutex::new(RefCell::new(None));

#[entry]
fn main() -> ! {
    if let Some(dp) = pac::Peripherals::take() {
        
        // Set up the system clock.
        let rcc = dp.RCC.constrain();
        let clocks = rcc.cfgr.freeze();

        let gpioa = dp.GPIOA.split();
        let gpiob = dp.GPIOB.split();
        let mut cs = gpiob.pb6.into_push_pull_output();
        cs.set_high();


        //clk, miso, mosi, respectively
        let pa5 = gpioa.pa5.into_alternate().internal_pull_up(true);
        let pa6 = gpioa.pa6.into_alternate();
        let pa7 = gpioa.pa7.into_alternate();
        let mode = Mode {

            polarity: Polarity::IdleLow,
            phase: Phase::CaptureOnSecondTransition,
        
        };
    

    let mut spi = Spi::new(dp.SPI1,
        (pa5, pa6, pa7),
         mode,
         1.MHz(),
         &clocks);


        /*sets up pa0 as interuppt for mcu_irq */
        let mut irq = gpioa.pa0;
        let mut syscfg = dp.SYSCFG.constrain();
        irq.make_interrupt_source(&mut syscfg);
        irq.trigger_on_edge(&mut dp.EXTI, Edge::Rising);
        irq.enable_interrupt(&mut dp.EXTI);


        // Enable the external interrupt in the NVIC by passing the NFC IRQ interrupt number
        unsafe {
            cortex_m::peripheral::NVIC::unmask(irq.interrupt());
        }

        // Now that NFC IRQ is configured, move button into global context
        cortex_m::interrupt::free(|cs| {
            G_IRQ.borrow(cs).replace(Some(irq));
        });

    
   
        let tx_buffer = cortex_m::singleton!(: [u8; ARRAY_SIZE] = [1; ARRAY_SIZE]).unwrap();
        
        /*
        Attempting to read ID register. 0x3F--read mode 'mosi --0b01xxxxxx'
         */
        tx_buffer[0] = 0x40 | 0x3F;
        tx_buffer[1] = 0x00;
        //hprintln!("{:#x?}", buffer[0]);
        cs.set_low();
        delay(1000);

        let result = spi.transfer(tx_buffer);
          
        delay(1000);
        cs.set_high();
        hprintln!("{:#x?}", result);
    }
        loop {
            cortex_m::asm::nop();
        }
    }

#[interrupt]
fn EXTI0() {
    cortex_m::interrupt::free(|cs| {
        let refcell = G_IRQ.borrow(cs).borrow();
        let exti = match refcell.as_ref() { None => return, Some(v) => v };
        exti.pr1.modify(|_, w| w.pr0().set_bit());
    });
    let irq_buffer = cortex_m::singleton!(: [u8; 1] = [1; 1]).unwrap();
    irq_buffer[0] =READ | MAIN_IRQ_ADD;
    let result = spi.transfer(irq_buffer);




}