#ifdef KARLOFF
#ifndef EXTFLASH_TVG850_H
#define EXTFLASH_TVG850_H

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

// FLASH Commands
#define FLASH_CMD_DEVICE_ID             (0x9F)
#define FLASH_CMD_WRITE_ENABLE          (0x06)
#define FLASH_CMD_PAGE_WRITE            (0x0A)
#define FLASH_CMD_PAGE_PROGRAM          (0x02)
#define FLASH_CMD_READ_DATA             (0x03)
#define FLASH_CMD_FAST_READ             (0x0B)
#define FLASH_CMD_READ_STATUS_REG       (0x05)
#define FLASH_CMD_SECTOR_ERASE          (0xD8)
#define FLASH_CMD_PAGE_ERASE			(0xDB)
#define FLASH_CMD_ENTER_DEEP_POWERDOWN	(0xB9)
#define FLASH_CMD_EXIT_DEEP_POWERDOWN	(0xAB)

// device IDs
#define FLASH_DEVICE_M45PE20            (0x00204012)  // STMicroelectronics
#define FLASH_DEVICE_M45PE80            (0x00204014)  // Numonyx
#define FLASH_DEVICE_M45PE16            (0x00204015)  // Numonyx

/*------------------------------------------------------------------*/
/* MEMORY MAP (NOTE : DO NOT move addresses once allocated !!!)     */
/*------------------------------------------------------------------*/

// External Flash Memory Map
#define FLASH_START_ADDRESS             (0x00000)
#define FLASH_END_ADDRESS               (0x3FFFF)

/*-0xFFFFF---------------------------*/
/*                                   */
/*       OTAP buffer                 */
/*       (448 kBytes)    			 */
/*                                   */
/*-0x90000---------------------------*/
/*-0x8FFFF---------------------------*/
/*                                   */
/*       GeoManager PVT FIFO         */
/*           (320 kBytes)			 */
/*                                   */
/*-0x40000---------------------------*/
/* ######## ME45P80 ONLY ########### */
/*-0x3FFFF---------------------------*/
/*                                   */
/*           (9.5 Kbytes)            */
/*                                   */
/*-0x3D800---------------------------*/
/*-0x3D7FF---------------------------*/
/*                                   */
/*                                   */
/*            TELEMATICS             */
/*           (4480 bytes)            */
/*                                   */
/*                                   */
/*-0x3C680---------------------------*/
/*-0x3C67F---------------------------*/
/*                                   */
/*                                   */
/*        APPLICATION LAYER          */
/*           (1024 bytes)            */
/*                                   */
/*                                   */
/*-0x3C280---------------------------*/
/*-0x3C27F---------------------------*/
/*                                   */
/*        VEHICLE INFORMATION        */
/*           (512 bytes)             */
/*                                   */
/*-0x3C080---------------------------*/
/*-0x3C07F---------------------------*/
/*                                   */
/*-0x3C000---------------------------*/
/*-0x3BFFF---------------------------*/
/*                                   */
/*                                   */
/*                                   */
/*        FIFO message               */
/*        (240 Kbytes)               */
/*                                   */
/*                                   */
/*                                   */
/*-0x00000---------------------------*/

// Upgrader Module
#define FLASH_FW_START_ADDRESS          FLASH_START_ADDRESS
#define FLASH_FW_END_ADDRESS            (FLASH_START_ADDRESS + 0x3BFFF)     // 240 KB
#define FLASH_FW_BASE_ADDRESS           (0x3C000)         
#define FLASH_FW_CFG_RECORD             (FLASH_FW_BASE_ADDRESS)             // 16 Bytes - Location of Config Rec in Ext Flash
#define FLASH_FW_TBC_RECORD             (FLASH_FW_BASE_ADDRESS + 0x10)      // ?? Bytes - Location of Version & TBC in Ext Flash

// Vehicle Information Data Storage
#define FLASH_VI_START_ADDRESS          (0x3C080)   
#define FLASH_VI_END_ADDRESS            (FLASH_VI_START_ADDRESS + 0x1FF)   // 512 Bytes  

// Application Layer Data Storage
#define FLASH_APP_START_ADDRESS         (0x3C280)   
#define FLASH_APP_END_ADDRESS           (FLASH_APP_START_ADDRESS + 0x3FF)   // 1024 Bytes  

#define FLASH_APP_EXT_UART_BAUD_ADDRESS (FLASH_APP_START_ADDRESS)
#define FLASH_APP_EXT_UART_BAUD_SIZE    (4)

// Telematics Data Storage
#define FLASH_TELEMATICS_START_ADDRESS  (0x3C680)   
#define FLASH_TELEMATICS_END_ADDRESS    (FLASH_APP_START_ADDRESS + 0x117F)   // 4480 Bytes  

#define FLASH_GEOMANAGER_START_ADDRESS	(0x3D800)
#define FLASH_GEOMANAGER_END_ADDRESS	(FLASH_END_ADDRESS)

// External FIFO - not to be used with upgrader module
#define FLASH_FIFO_START_ADDRESS		(FLASH_FW_START_ADDRESS)
#define FLASH_FIFO_END_ADDRESS			(FLASH_FW_END_ADDRESS)

// Secondary FIFO - needs 8Mbit flash chip
#define FLASH_FIFO2_START_ADDRESS		(0x40000)
#define FLASH_FIFO2_END_ADDRESS			(0x8FFFF)

//For Messages and Forms in IDT
#define FIFO2_START_MSG_AND_FORMS       (FLASH_FIFO2_START_ADDRESS + (FIFO_BLOCK_SIZE * 2048))

#define FLASH_OTAP_START_ADDRESS        (0x90000)
#define FLASH_OTAP_END_ADDRESS          (0xFFFFF)

#define FLASH_OTAP_START_SECTOR         9
#define FLASH_OTAP_END_SECTOR           15


#define FLASH_PAGE_SIZE                 (256)               // 256 bytes
#define FLASH_SECTOR_SIZE               (65536)             // 64 KBytes
#define FLASH_DEFAULT_MAX_SECTORS       (4)                 // assume the smallest part available

#endif // EXTFLASH_TVG660_H
#endif // __TARGET_AVG660
