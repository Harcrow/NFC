
#define MIFARE_UL_H
#define NFC_H
#define DISPATCHER_H
#define TOPAZ_H
#define TOPAZ_UID_LENGTH 4
#define TOPAZ_HR_LENGTH 2

#define ISO_14443_COMMON_H


#define ISO_14443_A_H
#define ISO14443A_MAX_UID_LENGTH 10
#define ISO14443A_MAX_CASCADE_LEVELS 3
#define ISO14443A_CASCADE_LENGTH 7
#define ISO14443A_RESPONSE_CT  0x88
#define PLATFORM_H
#define ST25R391X_SS_PIN            SPI1_CS_Pin         /*!< GPIO pin used for ST25R3911 SPI SS                */ 
#define ST25R391X_SS_PORT           SPI1_CS_GPIO_Port   /*!< GPIO port used for ST25R3911 SPI SS port          */ 
#define ST25R391X_INT_PIN           IRQ_3911_Pin        /*!< GPIO pin used for ST25R3911 External Interrupt    */
#define ST25R391X_INT_PORT          IRQ_3911_GPIO_Port  /*!< GPIO port used for ST25R3911 External Interrupt   */
#define PLATFORM_LED_FIELD_PIN      LED_FIELD_Pin       /*!< GPIO pin used as field LED                        */
#define PLATFORM_LED_FIELD_PORT     LED_FIELD_GPIO_Port /*!< GPIO port used as field LED                       */
#define platformProtectST25R391xComm()  
              do{ globalCommProtectCnt++; __DSB();NVIC_DisableIRQ(EXTI0_IRQn);__DSB();__ISB();}while(0) /*!< Protect unique access to ST25R391x communication channel - IRQ disable on single thread environment (MCU) ; Mutex lock on a multi thread environment      */
#define platformUnprotectST25R391xComm()
              do{ if (--globalCommProtectCnt==0) {NVIC_EnableIRQ(EXTI0_IRQn);} }while(0)                /*!< Unprotect unique access to ST25R391x communication channel - IRQ enable on a single thread environment (MCU) ; Mutex unlock on a multi thread environment */
#define platformProtectST25R391xIrqStatus()
           platformProtectST25R391xComm()
                           /*!< Protect unique access to IRQ status var - IRQ disable on single thread environment (MCU) ; Mutex lock on a multi thread environment */
#define platformUnprotectST25R391xIrqStatus() 
        platformUnprotectST25R391xComm()
                      /*!< Unprotect the IRQ status var - IRQ enable on a single thread environment (MCU) ; Mutex unlock on a multi thread environment         */
#define platformProtectWorker() 
                                                                    /* Protect RFAL Worker/Task/Process from concurrent execution on multi thread platforms   */
#define platformUnprotectWorker()
                                                                   /* Unprotect RFAL Worker/Task/Process from concurrent execution on multi thread platforms */
#define platformIrqST25R3911SetCallback( cb )          
#define platformIrqST25R3911PinInitialize()                
#define platformLedsInitialize()                                                                    /*!< Initializes the pins used as LEDs to outputs*/
#define platformLedOff( port, pin )
                   do{platformGpioClear(port, pin);if(pin==LED_FIELD_Pin)platformGpioClear(port, LED_FIELD_Pin_MB1325B);}while(0)    /*!< Turns the given LED Off                     */ /* Support for old board version MB1325-A */
#define platformLedOn( port, pin )
                    do{platformGpioSet(port, pin);if(pin==LED_FIELD_Pin)platformGpioSet(port, LED_FIELD_Pin_MB1325B);}while(0)        /*!< Turns the given LED On                      */ /* Support for old board version MB1325-A */
#define platformLedToogle( port, pin )
                do{platformGpioToogle(port, pin);if(pin==LED_FIELD_Pin)platformGpioToogle(port, LED_FIELD_Pin_MB1325B);}while(0)  /*!< Toogle the given LED                        */ /* Support for old board version MB1325-A */
#define platformGpioSet( port, pin )
                  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET)    /*!< Turns the given GPIO High                   */
#define platformGpioClear( port, pin )
                HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET)  /*!< Turns the given GPIO Low                    */
#define platformGpioToogle( port, pin )
               HAL_GPIO_TogglePin(port, pin)                 /*!< Toogles the given GPIO                      */
#define platformGpioIsHigh( port, pin ) 
              (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) /*!< Checks if the given LED is High             */
#define platformGpioIsLow( port, pin ) 
               (!platformGpioIsHigh(port, pin))              /*!< Checks if the given LED is Low              */
#define platformTimerCreate( t )
                      timerCalculateTimer(t)                        /*!< Create a timer with the given time (ms)     */
#define platformTimerIsExpired( timer )
               timerIsExpired(timer)                         /*!< Checks if the given timer is expired        */
#define platformDelay( t )
                            HAL_Delay( t )                                /*!< Performs a delay for the given time (ms)    */
#define platformGetSysTick()
                          HAL_GetTick()                                 /*!< Get System Tick ( 1 tick = 1 ms)            */
#define ST25R3911_COM_SINGLETXRX
#define platformSpiTxRx( txBuf, rxBuf, len )
          spiTxRx(txBuf, rxBuf, len)                    /*!< SPI transceive                              */
#define platformSpiSelect()      
                     spiSelect(ST25R391X_SS_PORT, ST25R391X_SS_PIN)
#define platformSpiDeselect()
                         spiDeselect(ST25R391X_SS_PORT, ST25R391X_SS_PIN)

#define platformLog(...) logITM(__VA_ARGS__)       
#define RFAL_FEATURE_LISTEN_MODE               true                   /*!< Enable/Disable RFAL support for Listen Mode                               */
#define RFAL_FEATURE_WAKEUP_MODE               true                   /*!< Enable/Disable RFAL support for the Wake-Up mode                          */
#define RFAL_FEATURE_NFCA                      true                   /*!< Enable/Disable RFAL support for NFC-A (ISO14443A)                         */
#define RFAL_FEATURE_NFCB                      true                   /*!< Enable/Disable RFAL support for NFC-B (ISO14443B)                         */
#define RFAL_FEATURE_NFCF                      true                   /*!< Enable/Disable RFAL support for NFC-F (FeliCa)                            */
#define RFAL_FEATURE_NFCV                      true                   /*!< Enable/Disable RFAL support for NFC-V (ISO15693)                          */
#define RFAL_FEATURE_T1T                       true                   /*!< Enable/Disable RFAL support for T1T (Topaz)                               */
#define RFAL_FEATURE_ST25TB                    true                   /*!< Enable/Disable RFAL support for ST25TB                                    */
#define RFAL_FEATURE_DYNAMIC_ANALOG_CONFIG     true                   /*!< Enable/Disable Analog Configs to be dynamically updated (RAM)             */
#define RFAL_FEATURE_DYNAMIC_POWER             false                  /*!< Enable/Disable RFAL dynamic power support                                 */
#define RFAL_FEATURE_ISO_DEP                   true                   /*!< Enable/Disable RFAL support for ISO-DEP (ISO14443-4)                      */
#define RFAL_FEATURE_ISO_DEP_POLL              true                   /*!< Enable/Disable RFAL support for Poller mode (PCD) ISO-DEP (ISO14443-4)    */
#define RFAL_FEATURE_ISO_DEP_LISTEN            false                  /*!< Enable/Disable RFAL support for Listen mode (PICC) ISO-DEP (ISO14443-4)   */
#define RFAL_FEATURE_NFC_DEP                   true                   /*!< Enable/Disable RFAL support for NFC-DEP (NFCIP1/P2P)                      */
#define RFAL_FEATURE_ISO_DEP_IBLOCK_MAX_LEN    256                    /*!< ISO-DEP I-Block max length. Please use values as defined by rfalIsoDepFSx */
#define RFAL_FEATURE_ISO_DEP_APDU_MAX_LEN      1024                   /*!< ISO-DEP APDU max length. Please use multiples of I-Block max length       */
#define ISO_14443_B_ST25TB_H
#define ISO14443B_ST25TB_UIDSIZE 8
#define _CONFIG_H_
#define ST25R3911_USE_INDICATION_LEDS 1
#define ST25R3911_USE_INDICATION_LEDS 1
#define ISO_14443_B_H
#define ISO14443B_PUPI_LENGTH 4
#define ISO14443B_APPDATA_LENGTH 4
#define ISO14443B_PROTINFO_LENGTH 3


#define ISO_15693_3_H
#define ISO15693_UID_LENGTH 8
#define ISO15693_MAX_MEMORY_BLOCK_SIZE 32
#define ISO15693_CMD_INVENTORY 1
#define ISO15693_CMD_STAY_QUIET 2
#define ISO15693_CMD_READ_SINGLE_BLOCK 0x20
#define ISO15693_CMD_WRITE_SINGLE_BLOCK 0x21
#define ISO15693_CMD_READ_MULTIPLE_BLOCKS 0x23
#define ISO15693_CMD_SELECT 0x25
#define ISO15693_CMD_GET_SYSTEM_INFORMATION 0x2B
#define ISO15693_M24LR_IC_MFG_CODE          0x02   /* M24LR */
#define ISO15693_CMD_FAST_READ_SINGLE_BLOCK 0xC0   /* M24LR */
#define ISO15693_CMD_FAST_READ_MULTI_BLOCK  0xC3   /* M24LR */
#define ISO15693_REQ_FLAG_INVENTORY       0x04
#define ISO15693_REQ_FLAG_PROT_EXTENSION  0x08
#define ISO15693_REQ_FLAG_SELECT          0x10
#define ISO15693_REQ_FLAG_ADDRESS         0x20
#define ISO15693_REQ_FLAG_AFI             0x10
#define ISO15693_REQ_FLAG_1_SLOT          0x20
#define ISO15693_REQ_FLAG_OPTION          0x40
#define ISO15693_RESP_FLAG_ERROR          0x01
#define ISO15693_RESP_FLAG_PROT_EXTENSION 0x08


#define IRQ_3911_Pin GPIO_PIN_0
#define IRQ_3911_GPIO_Port GPIOA
#define IRQ_3911_EXTI_IRQn EXTI0_IRQn
#define LED_F_Pin GPIO_PIN_1
#define LED_F_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_4
#define LED_B_GPIO_Port GPIOA
#define LED_A_Pin GPIO_PIN_0
#define LED_A_GPIO_Port GPIOB
#define LED_FIELD_Pin GPIO_PIN_8
#define LED_FIELD_GPIO_Port GPIOA
#define LED_V_Pin GPIO_PIN_4
#define LED_V_GPIO_Port GPIOB
#define LED_AP2P_Pin GPIO_PIN_5
#define LED_AP2P_GPIO_Port GPIOB
#define SPI1_CS_Pin GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOB
/* #define USE_FULL_ASSERT    1U */
#define LED_FIELD_Pin_MB1325B GPIO_PIN_3  /* Support for old board version MB1325-A */

