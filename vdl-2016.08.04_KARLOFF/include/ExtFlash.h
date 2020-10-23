/********************************************************************
* File:     $Id: ExtFlash.h,v 1.16 2010/01/18 17:23:38 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.16 $
* Date:     $Date: 2010/01/18 17:23:38 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <KLINE.c>
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2007 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: ExtFlash.h,v $
*   Revision 1.16  2010/01/18 17:23:38  richard
*   *** empty log message ***
*
*   Revision 1.15  2009/11/19 16:00:14  richard
*   Changes made for GM V1.3.0.x.2
*
*   Revision 1.14  2009/11/12 16:54:38  simon
*   Fixed support for M45PE80 and added FLASH_GetSectorCount(), FLASH_GetSectorSize() and FLASH_GetPageSize()
*    functions.
*
*   Revision 1.13  2009/10/19 16:16:02  richard
*   Changes for reltest2 and 8Mbit flash
*
*   Revision 1.12  2009/08/11 17:25:55  richard
*   Build 16
*
*   Revision 1.11  2009/08/07 09:04:29  richard
*   B12
*
*   Revision 1.10  2009/07/16 12:25:57  richard
*   *** empty log message ***
*
*   Revision 1.9  2009/05/26 12:52:53  richard
*   Added extra funtionality required for GeoManager
*
*   Revision 1.8  2009/01/15 16:24:16  simon
*   Added support for storing GPS position.
*
*   Revision 1.7  2008/11/21 11:49:15  simon
*   Added memory map diagram and allocated telematics info block
*
*   Revision 1.6  2008/10/23 14:21:40  richard
*   Changes made for external RS232 on enfora
*
*   Revision 1.5  2008/07/08 08:35:17  ACCUTEST\simon
*   Implemented a Vehicle Info module to store general
*    non-volatile information about the vehicle
*
*   Revision 1.4  2008/07/07 10:37:34  ACCUTEST\richard
*   Added new functions to read and write 256byte (page) blocks
*
*   Revision 1.3  2008/05/08 09:43:19  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.2  2008/02/28 15:23:54  ACCUTEST\simon
*   Added memory map
*
*   Revision 1.1  2007/10/04 11:41:28  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.3  2007/07/05 08:11:33  ACCUTEST\simon
*   Added J1850 (PWM) protocol support. (Uses AVG500L-J1850 expansion board).
*
*   Revision 1.2  2007/06/27 11:48:16  ACCUTEST\peterp
*   Initial Firmware Upgrade version (Ext. Flash stage only) for test.
*
*   Revision 1.1  2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
* Change Log:
*
*********************************************************************
*/

#ifndef EXT_FLASH_H
#define EXT_FLASH_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

#ifdef KARLOFF
#include "AvgDefines.h"
#else
#include "spi.h"
#endif

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#ifndef KARLOFF
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
#endif

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
#define FLASH_VI_END_ADDRESS            (FLASH_APP_START_ADDRESS + 0x1FF)   // 512 Bytes  

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

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t FLASH_Init(void);
void    FLASH_Reset(void);
uint32_t FLASH_GetDeviceID(void);                           // Read JEDEC device signature
void    FLASH_Write(uint8_t u8Byte, uint32_t u32Address);   // Write a byte to FLASH at address nAddress
uint8_t FLASH_Read(uint32_t u32Address);                    // Read byte from address u32Address
uint32_t FLASH_Read32(uint32_t u32Address);                 // Read DWORD from address u32Address
double  FLASH_ReadDouble(uint32_t u32Address);              // Read Couble from address u32Address
void    FLASH_Update(uint8_t u8Byte, uint32_t u32Address);  // Update byte at address u32Address
void    FLASH_Update32(uint32_t u32Data, uint32_t u32Address); // Update DWORD at address u32Address
void    FLASH_UpdateDouble(double fData, uint32_t u32Address); // Update Double at address u32Address
void    FLASH_FastWrite(uint8_t u8Byte, uint32_t u32Address);   // Write a byte to FLASH at address nAddress using program
uint8_t FLASH_FastRead(uint32_t u32Address);                // Fast Read byte from address nAddress
void    FLASH_EraseSector(uint8_t u8Sector);                // Erase sector N (0..3)
void    FLASH_EraseAll(void);                               // Wrapper function calls ...EraseSector with 0,1,2,3 as sector
uint8_t	FLASH_Busy(void);                                   // Function to wait whilst FLASH is busy
void    FLASH_DeepPowerDown(void);                          // Enter Deep Power down mode
void    FLASH_ExitDeepPowerDown(void);                      // Leave Deep Power down mode
void	FLASH_WritePage(uint8_t *u8data, uint32_t u32Address);	// Write 256 bytes of data
void    FLASH_WriteMultiplePages(uint8_t *u8data, uint32_t u32Address, uint32_t u32Size); // Write multiple bytes of data
void	FLASH_ReadPage(uint8_t *u8data, uint32_t u32Address);	// Read 256 bytes of data
int     FLASH_ReadPageEx(uint8_t *u8data, uint32_t u32Address, uint32_t u32Count); //Read upto 256 bytes of data
void    FLASH_ErasePage(uint32_t u32Address);
uint8_t	FLASH_GetSectorCount(void);                         // 4 = 2Mbit, 16 = 8Mbit.

void FLASH_ReadAnyByte(uint8_t *u8data, uint32_t u32Address, uint32_t u32Count);
void FLASH_Write_Wrap_UP(uint8_t *u8DataByte, uint32_t u32Address, uint32_t u32DataSize);
void FLASH_Memset( uint32_t u32Address, uint8_t u8DataByte, uint32_t u32DataSize);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif  // EXT_FLASH_H

