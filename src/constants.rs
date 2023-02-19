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