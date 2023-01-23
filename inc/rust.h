usbd_custom_hid_if.h:#define __USBD_CUSTOM_HID_IF_H_
usbd_conf.h:#define __USBD_CONF__H__
usbd_conf.h:#define USBD_MAX_NUM_INTERFACES     1
usbd_conf.h:#define USBD_MAX_NUM_CONFIGURATION     1
usbd_conf.h:#define USBD_MAX_STR_DESC_SIZ     512
usbd_conf.h:#define USBD_SUPPORT_USER_STRING     0
usbd_conf.h:#define USBD_DEBUG_LEVEL     0
usbd_conf.h:#define USBD_LPM_ENABLED     0
usbd_conf.h:#define USBD_SELF_POWERED     1
usbd_conf.h:#define USBD_CUSTOMHID_OUTREPORT_BUF_SIZE     64
usbd_conf.h:#define USBD_CUSTOM_HID_REPORT_DESC_SIZE     29
usbd_conf.h:/* #define for FS and HS identification */
usbd_conf.h:#define DEVICE_FS 		0
usbd_conf.h:#define USBD_malloc               (uint32_t *)USBD_static_malloc
usbd_conf.h:#define USBD_free                 USBD_static_free
usbd_conf.h:#define USBD_memset               /* Not used */
usbd_conf.h:#define USBD_memcpy               /* Not used */
usbd_conf.h:#define USBD_Delay   HAL_Delay
usbd_conf.h:#define  USBD_UsrLog(...)   printf(__VA_ARGS__);\
usbd_conf.h:#define USBD_UsrLog(...)   
usbd_conf.h:#define  USBD_ErrLog(...)   printf("ERROR: ") ;\
usbd_conf.h:#define USBD_ErrLog(...)   
usbd_conf.h:#define  USBD_DbgLog(...)   printf("DEBUG : ") ;\
usbd_conf.h:#define USBD_DbgLog(...)                         
mifare_ul.h:#define MIFARE_UL_H
nfc.h:#define NFC_H
dispatcher.h:#define DISPATCHER_H
topaz.h:#define TOPAZ_H
topaz.h:#define TOPAZ_UID_LENGTH 4
topaz.h:#define TOPAZ_HR_LENGTH 2
usb_hid_stream_driver.h:#define _USB_HID_STREAM_DRIVER_H
kovio.h:#define KOVIO_H
kovio.h:#define KOVIO_UID_LENGTH 32
usbd_desc.h:#define __USBD_DESC__H__
iso14443_common.h:#define ISO_14443_COMMON_H
felica.h:#define FELICA_H
felica.h:#define FELICA_MAX_ID_LENGTH 8
usb_device.h:#define __usb_device_H
iso14443a.h:#define ISO_14443_A_H
iso14443a.h:#define ISO14443A_MAX_UID_LENGTH 10
iso14443a.h:#define ISO14443A_MAX_CASCADE_LEVELS 3
iso14443a.h:#define ISO14443A_CASCADE_LENGTH 7
iso14443a.h:#define ISO14443A_RESPONSE_CT  0x88
platform.h:#define PLATFORM_H
platform.h:#define ST25R391X_SS_PIN            SPI1_CS_Pin         /*!< GPIO pin used for ST25R3911 SPI SS                */ 
platform.h:#define ST25R391X_SS_PORT           SPI1_CS_GPIO_Port   /*!< GPIO port used for ST25R3911 SPI SS port          */ 
platform.h:#define ST25R391X_INT_PIN           IRQ_3911_Pin        /*!< GPIO pin used for ST25R3911 External Interrupt    */
platform.h:#define ST25R391X_INT_PORT          IRQ_3911_GPIO_Port  /*!< GPIO port used for ST25R3911 External Interrupt   */
platform.h:#define PLATFORM_LED_FIELD_PIN      LED_FIELD_Pin       /*!< GPIO pin used as field LED                        */
platform.h:#define PLATFORM_LED_FIELD_PORT     LED_FIELD_GPIO_Port /*!< GPIO port used as field LED                       */
platform.h:#define platformProtectST25R391xComm()                do{ globalCommProtectCnt++; __DSB();NVIC_DisableIRQ(EXTI0_IRQn);__DSB();__ISB();}while(0) /*!< Protect unique access to ST25R391x communication channel - IRQ disable on single thread environment (MCU) ; Mutex lock on a multi thread environment      */
platform.h:#define platformUnprotectST25R391xComm()              do{ if (--globalCommProtectCnt==0) {NVIC_EnableIRQ(EXTI0_IRQn);} }while(0)                /*!< Unprotect unique access to ST25R391x communication channel - IRQ enable on a single thread environment (MCU) ; Mutex unlock on a multi thread environment */
platform.h:#define platformProtectST25R391xIrqStatus()           platformProtectST25R391xComm()                /*!< Protect unique access to IRQ status var - IRQ disable on single thread environment (MCU) ; Mutex lock on a multi thread environment */
platform.h:#define platformUnprotectST25R391xIrqStatus()         platformUnprotectST25R391xComm()              /*!< Unprotect the IRQ status var - IRQ enable on a single thread environment (MCU) ; Mutex unlock on a multi thread environment         */
platform.h:#define platformProtectWorker()                                                                     /* Protect RFAL Worker/Task/Process from concurrent execution on multi thread platforms   */
platform.h:#define platformUnprotectWorker()                                                                   /* Unprotect RFAL Worker/Task/Process from concurrent execution on multi thread platforms */
platform.h:#define platformIrqST25R3911SetCallback( cb )          
platform.h:#define platformIrqST25R3911PinInitialize()                
platform.h:#define platformLedsInitialize()                                                                    /*!< Initializes the pins used as LEDs to outputs*/
platform.h:#define platformLedOff( port, pin )                   do{platformGpioClear(port, pin);if(pin==LED_FIELD_Pin)platformGpioClear(port, LED_FIELD_Pin_MB1325B);}while(0)    /*!< Turns the given LED Off                     */ /* Support for old board version MB1325-A */
platform.h:#define platformLedOn( port, pin )                    do{platformGpioSet(port, pin);if(pin==LED_FIELD_Pin)platformGpioSet(port, LED_FIELD_Pin_MB1325B);}while(0)        /*!< Turns the given LED On                      */ /* Support for old board version MB1325-A */
platform.h:#define platformLedToogle( port, pin )                do{platformGpioToogle(port, pin);if(pin==LED_FIELD_Pin)platformGpioToogle(port, LED_FIELD_Pin_MB1325B);}while(0)  /*!< Toogle the given LED                        */ /* Support for old board version MB1325-A */
platform.h:#define platformGpioSet( port, pin )                  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)    /*!< Turns the given GPIO High                   */
platform.h:#define platformGpioClear( port, pin )                HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)  /*!< Turns the given GPIO Low                    */
platform.h:#define platformGpioToogle( port, pin )               HAL_GPIO_TogglePin(port, pin)                 /*!< Toogles the given GPIO                      */
platform.h:#define platformGpioIsHigh( port, pin )               (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) /*!< Checks if the given LED is High             */
platform.h:#define platformGpioIsLow( port, pin )                (!platformGpioIsHigh(port, pin))              /*!< Checks if the given LED is Low              */
platform.h:#define platformTimerCreate( t )                      timerCalculateTimer(t)                        /*!< Create a timer with the given time (ms)     */
platform.h:#define platformTimerIsExpired( timer )               timerIsExpired(timer)                         /*!< Checks if the given timer is expired        */
platform.h:#define platformDelay( t )                            HAL_Delay( t )                                /*!< Performs a delay for the given time (ms)    */
platform.h:#define platformGetSysTick()                          HAL_GetTick()                                 /*!< Get System Tick ( 1 tick = 1 ms)            */
platform.h:#define ST25R3911_COM_SINGLETXRX
platform.h:#define platformSpiTxRx( txBuf, rxBuf, len )          spiTxRx(txBuf, rxBuf, len)                    /*!< SPI transceive                              */
platform.h:#define platformSpiSelect()                           spiSelect(ST25R391X_SS_PORT, ST25R391X_SS_PIN)
platform.h:#define platformSpiDeselect()                         spiDeselect(ST25R391X_SS_PORT, ST25R391X_SS_PIN)
platform.h:#define platformI2CTx( txBuf, len )                                                                 /*!< I2C Transmit                                */
platform.h:#define platformI2CRx( txBuf, len )                                                                 /*!< I2C Receive                                 */
platform.h:#define platformI2CStart()                                                                          /*!< I2C Start condition                         */
platform.h:#define platformI2CStop()                                                                           /*!< I2C Stop condition                          */
platform.h:#define platformI2CRepeatStart()                                                                    /*!< I2C Repeat Start                            */
platform.h:#define platformI2CSlaveAddrWR(add)                                                                 /*!< I2C Slave address for Write operation       */
platform.h:#define platformI2CSlaveAddrRD(add)                                                                 /*!< I2C Slave address for Read operation        */
platform.h:// #define platformLog(...)                                                                            /*!< Log method                                  */
platform.h:#define platformLog(...) logITM(__VA_ARGS__)       
platform.h:#define RFAL_FEATURE_LISTEN_MODE               true                   /*!< Enable/Disable RFAL support for Listen Mode                               */
platform.h:#define RFAL_FEATURE_WAKEUP_MODE               true                   /*!< Enable/Disable RFAL support for the Wake-Up mode                          */
platform.h:#define RFAL_FEATURE_NFCA                      true                   /*!< Enable/Disable RFAL support for NFC-A (ISO14443A)                         */
platform.h:#define RFAL_FEATURE_NFCB                      true                   /*!< Enable/Disable RFAL support for NFC-B (ISO14443B)                         */
platform.h:#define RFAL_FEATURE_NFCF                      true                   /*!< Enable/Disable RFAL support for NFC-F (FeliCa)                            */
platform.h:#define RFAL_FEATURE_NFCV                      true                   /*!< Enable/Disable RFAL support for NFC-V (ISO15693)                          */
platform.h:#define RFAL_FEATURE_T1T                       true                   /*!< Enable/Disable RFAL support for T1T (Topaz)                               */
platform.h:#define RFAL_FEATURE_ST25TB                    true                   /*!< Enable/Disable RFAL support for ST25TB                                    */
platform.h:#define RFAL_FEATURE_DYNAMIC_ANALOG_CONFIG     true                   /*!< Enable/Disable Analog Configs to be dynamically updated (RAM)             */
platform.h:#define RFAL_FEATURE_DYNAMIC_POWER             false                  /*!< Enable/Disable RFAL dynamic power support                                 */
platform.h:#define RFAL_FEATURE_ISO_DEP                   true                   /*!< Enable/Disable RFAL support for ISO-DEP (ISO14443-4)                      */
platform.h:#define RFAL_FEATURE_ISO_DEP_POLL              true                   /*!< Enable/Disable RFAL support for Poller mode (PCD) ISO-DEP (ISO14443-4)    */
platform.h:#define RFAL_FEATURE_ISO_DEP_LISTEN            false                  /*!< Enable/Disable RFAL support for Listen mode (PICC) ISO-DEP (ISO14443-4)   */
platform.h:#define RFAL_FEATURE_NFC_DEP                   true                   /*!< Enable/Disable RFAL support for NFC-DEP (NFCIP1/P2P)                      */
platform.h:#define RFAL_FEATURE_ISO_DEP_IBLOCK_MAX_LEN    256                    /*!< ISO-DEP I-Block max length. Please use values as defined by rfalIsoDepFSx */
platform.h:#define RFAL_FEATURE_ISO_DEP_APDU_MAX_LEN      1024                   /*!< ISO-DEP APDU max length. Please use multiples of I-Block max length       */
iso14443b_st25tb.h:#define ISO_14443_B_ST25TB_H
iso14443b_st25tb.h:#define ISO14443B_ST25TB_UIDSIZE 8
config.h:#define _CONFIG_H_
config.h:#define ST25R3911_USE_INDICATION_LEDS 1
config.h:#define ST25R3911_USE_INDICATION_LEDS 1
iso14443b.h:#define ISO_14443_B_H
iso14443b.h:#define ISO14443B_PUPI_LENGTH 4
iso14443b.h:#define ISO14443B_APPDATA_LENGTH 4
iso14443b.h:#define ISO14443B_PROTINFO_LENGTH 3
stm32l4xx_hal_conf.h:#define __STM32L4xx_HAL_CONF_H
stm32l4xx_hal_conf.h:#define HAL_MODULE_ENABLED  
stm32l4xx_hal_conf.h:/*#define HAL_ADC_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_CRYP_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_CAN_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_COMP_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_CRC_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_CRYP_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_DAC_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_DCMI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_DMA2D_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_DFSDM_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_DSI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_FIREWALL_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_GFXMMU_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_HCD_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_HASH_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_I2S_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_IRDA_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_IWDG_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_LTDC_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_LCD_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_LPTIM_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_NAND_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_NOR_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_OPAMP_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_OSPI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_OSPI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:#define HAL_PCD_MODULE_ENABLED
stm32l4xx_hal_conf.h:/*#define HAL_QSPI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_QSPI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_RNG_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_RTC_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_SAI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_SD_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_SMBUS_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_SMARTCARD_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:#define HAL_SPI_MODULE_ENABLED
stm32l4xx_hal_conf.h:/*#define HAL_SRAM_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_SWPMI_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_TIM_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_TSC_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:#define HAL_UART_MODULE_ENABLED
stm32l4xx_hal_conf.h:/*#define HAL_USART_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:/*#define HAL_WWDG_MODULE_ENABLED   */
stm32l4xx_hal_conf.h:#define HAL_GPIO_MODULE_ENABLED
stm32l4xx_hal_conf.h:#define HAL_I2C_MODULE_ENABLED
stm32l4xx_hal_conf.h:#define HAL_DMA_MODULE_ENABLED
stm32l4xx_hal_conf.h:#define HAL_RCC_MODULE_ENABLED
stm32l4xx_hal_conf.h:#define HAL_FLASH_MODULE_ENABLED
stm32l4xx_hal_conf.h:#define HAL_PWR_MODULE_ENABLED
stm32l4xx_hal_conf.h:#define HAL_CORTEX_MODULE_ENABLED
stm32l4xx_hal_conf.h:  #define HSE_VALUE    ((uint32_t)8000000U) /*!< Value of the External oscillator in Hz */
stm32l4xx_hal_conf.h:  #define HSE_STARTUP_TIMEOUT    ((uint32_t)100U)   /*!< Time out for HSE start up, in ms */
stm32l4xx_hal_conf.h:  #define MSI_VALUE    ((uint32_t)48000000U) /*!< Value of the Internal oscillator in Hz*/
stm32l4xx_hal_conf.h:  #define HSI_VALUE    ((uint32_t)16000000U) /*!< Value of the Internal oscillator in Hz*/
stm32l4xx_hal_conf.h: #define HSI48_VALUE   ((uint32_t)48000000U) /*!< Value of the Internal High Speed oscillator for USB FS/SDMMC/RNG in Hz.
stm32l4xx_hal_conf.h: #define LSI_VALUE  ((uint32_t)32000U)       /*!< LSI Typical Value in Hz*/
stm32l4xx_hal_conf.h:  #define LSE_VALUE    ((uint32_t)32768U) /*!< Value of the External oscillator in Hz*/
stm32l4xx_hal_conf.h:  #define LSE_STARTUP_TIMEOUT    ((uint32_t)5000U)   /*!< Time out for LSE start up, in ms */
stm32l4xx_hal_conf.h:  #define EXTERNAL_SAI1_CLOCK_VALUE    ((uint32_t)2097000U) /*!< Value of the SAI1 External clock source in Hz*/
stm32l4xx_hal_conf.h:  #define EXTERNAL_SAI2_CLOCK_VALUE    ((uint32_t)2097000U) /*!< Value of the SAI2 External clock source in Hz*/
stm32l4xx_hal_conf.h:#define  VDD_VALUE					  ((uint32_t)3300U) /*!< Value of VDD in mv */           
stm32l4xx_hal_conf.h:#define  TICK_INT_PRIORITY            ((uint32_t)0U)    /*!< tick interrupt priority */            
stm32l4xx_hal_conf.h:#define  USE_RTOS                     0U     
stm32l4xx_hal_conf.h:#define  PREFETCH_ENABLE              0U
stm32l4xx_hal_conf.h:#define  INSTRUCTION_CACHE_ENABLE     1U
stm32l4xx_hal_conf.h:#define  DATA_CACHE_ENABLE            1U
stm32l4xx_hal_conf.h:/* #define USE_FULL_ASSERT    1U */
stm32l4xx_hal_conf.h:#define USE_SPI_CRC                   0U
stm32l4xx_hal_conf.h:  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
stm32l4xx_hal_conf.h:  #define assert_param(expr) ((void)0U)
iso15693_3.h:#define ISO_15693_3_H
iso15693_3.h:#define ISO15693_UID_LENGTH 8
iso15693_3.h:#define ISO15693_MAX_MEMORY_BLOCK_SIZE 32
iso15693_3.h:#define ISO15693_CMD_INVENTORY 1
iso15693_3.h:#define ISO15693_CMD_STAY_QUIET 2
iso15693_3.h:#define ISO15693_CMD_READ_SINGLE_BLOCK 0x20
iso15693_3.h:#define ISO15693_CMD_WRITE_SINGLE_BLOCK 0x21
iso15693_3.h:#define ISO15693_CMD_READ_MULTIPLE_BLOCKS 0x23
iso15693_3.h:#define ISO15693_CMD_SELECT 0x25
iso15693_3.h:#define ISO15693_CMD_GET_SYSTEM_INFORMATION 0x2B
iso15693_3.h:#define ISO15693_M24LR_IC_MFG_CODE          0x02   /* M24LR */
iso15693_3.h:#define ISO15693_CMD_FAST_READ_SINGLE_BLOCK 0xC0   /* M24LR */
iso15693_3.h:#define ISO15693_CMD_FAST_READ_MULTI_BLOCK  0xC3   /* M24LR */
iso15693_3.h:#define ISO15693_REQ_FLAG_INVENTORY       0x04
iso15693_3.h:#define ISO15693_REQ_FLAG_PROT_EXTENSION  0x08
iso15693_3.h:#define ISO15693_REQ_FLAG_SELECT          0x10
iso15693_3.h:#define ISO15693_REQ_FLAG_ADDRESS         0x20
iso15693_3.h:#define ISO15693_REQ_FLAG_AFI             0x10
iso15693_3.h:#define ISO15693_REQ_FLAG_1_SLOT          0x20
iso15693_3.h:#define ISO15693_REQ_FLAG_OPTION          0x40
iso15693_3.h:#define ISO15693_RESP_FLAG_ERROR          0x01
iso15693_3.h:#define ISO15693_RESP_FLAG_PROT_EXTENSION 0x08
stm32l4xx_it.h:#define __STM32L4xx_IT_H
stream_driver.h:#define STREAM_DRIVER_H
stream_driver.h:#define StreamInitialize       uartStreamInitialize
stream_driver.h:#define StreamConnect          uartStreamConnect
stream_driver.h:#define StreamDisconnect       uartStreamDisconnect
stream_driver.h:#define StreamReady            uartStreamReady
stream_driver.h:#define StreamHasAnotherPacket uartStreamHasAnotherPacket
stream_driver.h:#define StreamPacketProcessed  uartStreamPacketProcessed
stream_driver.h:#define StreamReceive          uartStreamReceive
stream_driver.h:#define StreamTransmit         uartStreamTransmit
stream_driver.h:#define StreamInitialize       usbStreamInitialize
stream_driver.h:#define StreamConnect          usbStreamConnect
stream_driver.h:#define StreamDisconnect       usbStreamDisconnect
stream_driver.h:#define StreamReady            usbStreamReady
stream_driver.h:#define StreamHasAnotherPacket usbStreamHasAnotherPacket
stream_driver.h:#define StreamPacketProcessed  usbStreamPacketProcessed
stream_driver.h:#define StreamReceive          usbStreamReceive
stream_driver.h:#define StreamTransmit         usbStreamTransmit
main.h:#define __MAIN_H
main.h:#define IRQ_3911_Pin GPIO_PIN_0
main.h:#define IRQ_3911_GPIO_Port GPIOA
main.h:#define IRQ_3911_EXTI_IRQn EXTI0_IRQn
main.h:#define LED_F_Pin GPIO_PIN_1
main.h:#define LED_F_GPIO_Port GPIOA
main.h:#define LED_B_Pin GPIO_PIN_4
main.h:#define LED_B_GPIO_Port GPIOA
main.h:#define LED_A_Pin GPIO_PIN_0
main.h:#define LED_A_GPIO_Port GPIOB
main.h:#define LED_FIELD_Pin GPIO_PIN_8
main.h:#define LED_FIELD_GPIO_Port GPIOA
main.h:#define LED_V_Pin GPIO_PIN_4
main.h:#define LED_V_GPIO_Port GPIOB
main.h:#define LED_AP2P_Pin GPIO_PIN_5
main.h:#define LED_AP2P_GPIO_Port GPIOB
main.h:#define SPI1_CS_Pin GPIO_PIN_6
main.h:#define SPI1_CS_GPIO_Port GPIOB
main.h:/* #define USE_FULL_ASSERT    1U */
main.h:#define LED_FIELD_Pin_MB1325B GPIO_PIN_3  /* Support for old board version MB1325-A */
main.h:#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
