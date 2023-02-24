#![no_main]
#![no_std]
#![deny(unsafe_code)]
#![allow(unused_imports)]

use panic_rtt_target as _panic_handler;

#[rtic::app(device = stm32f4xx_hal::pac, peripherals = true,)]
mod app {
use rtt_target::{rprintln, rtt_init_print};
use systick_monotonic::*;
use embedded_hal::spi::{Mode, Phase, Polarity};
use stm32f4xx_hal::{
    dma::{config, traits::StreamISR, MemoryToPeripheral, Stream2, StreamsTuple, Transfer},
    pac::*,
    prelude::*,
    spi::*,
    gpio::*,
};
}

const ARRAY_SIZE: usize = 10;

//need to set pA0 as an interupt
//stm32f4xx_hal::gpio::gpioa::PA0


//type SPIHandle = Spi1<(PA5<AF5>,PA6<AF5>,PA7<AF5>)>;
#[shared]
struct Shared {
    led1 :gpio::PA5<Output<PushPull>>,
    SPIHandle :spi::SPI1<(PA5<AF5>,PA6<AF5>,PA7<AF5>)>,
    buffer :[u8; ARRAY_SIZE]],

//nfc_irq: PA0<Input>;
#[local]
struct Local {
    nfc_irq :gpio::PA0<Input>
}

#[monotonic(binds = SysTick, default = true)]

#[init]
fn init(ctx: init ::Context) -> (Shared, Local, init::Monotonics){

    let mut dp = ctx.device;
    let rcc = dp.RCC.constrain();
    /* let clocks = rcc
            .cfgr
            .use_hse(8.mhz())
            .sysclk(72.mhz())
            .pclk1(36.mhz())
            .freeze(&mut flash.acr);*/
    let clocks = rcc.cfgr.freeze();

    
    // 1) Promote the GPIOA and GPIOB PAC struct
    let gpioa = dp.GPIOA.split();
    let gpiob = dp.GPIOB.split();

    //clk, miso, mosi, respectively
    let pa5 = gpioa.pa5.into_alternate().internal_pull_up(true);
    let pa6 = gpioa.pa6.into_alternate();
    let pa7 = gpioa.pa7.into_alternate();

    let mut spi = Spi::new(dp.SPI1,
        (pa5, pa6, pa7),
         mode,
         1.MHz(),
         &clocks);

    // 2) Configure Pin and Obtain Handle
    let mut led = gpioa.pa5.into_push_pull_output();
    let mut cs = gpiob.pb6.into_push_pull_output();
    
    let nfc_irq = gpioa.pa0;
    let mut syscfg = dp.SYSCFG.constrain();
    
    nfc_irq.make_interrupt_source(&mut syscfg)
    nfc_irq.trigger_on_edge(&mut dp.EXTI, Edge::Rising)
    nfc_irq.enable_interrupt(&mut dp.EXTI);

    cs.set_high();
    
    let mode = Mode {

        polarity: Polarity::IdleLow,
        phase: Phase::CaptureOnSecondTransition,
    
    };
    rtt_init_print!();
    rprintln!("hello, world!");

    
    // lastly return the shared and local resources, as per RTIC's spec.
    (
        // Initialization of shared resources
        Shared { 
            led1,
            SPIHandle,
            ARRAY_SIZE,
        },
        // Initialization of task local resources
        Local {
            nfc_irq,
        },
        // Move the monotonic timer to the RTIC run-time, this enables
        // scheduling
        init::Monotonics(),
    )
}

fn idle(_: idle::Context) -> ! {
    loop {
        // Go to sleep
        cortex_m::asm::wfi();
    }
}

}  

#[task(binds = EXTI0, local = [nfc_irq]. shared = [led1, SPIHandle, buffer]]
fn tag_scan(mut ctx: tag_scan::Context ) {
   

   let mut led = *ctx.shared.nfc_irq;
   let mut spi = *ctx.shared.SPIHandle;


   ctx.local.nfc_irq.clear_interrupt_pending_bit();

   
    });
    let irq_buffer = cortex_m::singleton!(: [u8; 1] = [1; 1]).unwrap();
    irq_buffer[0] =READ | MAIN_IRQ_ADD;
    let result = spi.transfer(irq_buffer);




}