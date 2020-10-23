/********************************************************************
* File:     $Id: Debug.h,v 1.52 2010/05/14 10:10:12 Amiao Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.52 $
* Date:     $Date: 2010/05/14 10:10:12 $
* Author:   $Author: Amiao $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides debug definitions for the AVG 500 project
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2006-2007 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: Debug.h,v $
*   Revision 1.52  2010/05/14 10:10:12  Amiao
*   Changes from 1.4
*
*   Revision 1.51  2010/04/12 15:28:49  Rharvie
*   *** empty log message ***
*
*   Revision 1.50  2010/01/18 17:23:38  richard
*   *** empty log message ***
*
*   Revision 1.49  2010/01/18 11:55:51  simon
*   disabled DISKIO debug output
*
*   Revision 1.48  2010/01/15 10:07:09  simon
*   *** empty log message ***
*
*   Revision 1.47  2010/01/08 14:53:58  simon
*   Added DMA and DISKIO module flags
*
*   Revision 1.46  2009/12/17 14:54:45  richard
*   Release 1.3.0.x.7
*
*   Fixed incorrect GeoFencing calculations
*   Fixed error in processing radius on packet 0x61
*   Fixed bug in ALT-248 debug
*   Fixed problem that stopped GPS only working when DataPort2 != 24
*
*   Revision 1.45  2009/11/30 16:57:19  richard
*   Combined all vehicle protocols.
*   Added FIFO test
*
*   Revision 1.44  2009/11/20 12:06:56  richard
*   *** empty log message ***
*
*   Revision 1.43  2009/11/19 16:00:14  richard
*   Changes made for GM V1.3.0.x.2
*
*   Revision 1.42  2009/10/19 16:16:02  richard
*   Changes for reltest2 and 8Mbit flash
*
*   Revision 1.41  2009/10/06 09:43:56  richard
*   *** empty log message ***
*
*   Revision 1.40  2009/08/25 12:01:28  simon
*   Added SD/MMC, FAT and USB OTG Debug support
*
*   Revision 1.39  2009/07/24 11:33:15  simon
*   Added power module and supoort in the production test for it.
*
*   Revision 1.38  2009/07/16 12:25:57  richard
*   *** empty log message ***
*
*   Revision 1.37  2009/07/02 15:12:52  richard
*   *** empty log message ***
*
*   Revision 1.36  2009/03/25 15:01:26  accutest\colin
*   Added iButton debug macro
*
*   Revision 1.35  2009/03/03 10:27:01  simon
*   Version 2.5.0.1 : Minor fixes and addition of AT$DATE= and AT$TIME= commands
*
*   Revision 1.34  2009/02/06 13:40:00  richard
*   Latest changes for 2.4.9.5
*
*   Revision 1.33  2009/01/27 16:24:01  richard
*   *** empty log message ***
*
*   Revision 1.32  2008/12/24 11:54:40  richard
*   Changs made to get instant GPS on AVG650
*
*   Revision 1.31  2008/11/13 15:18:07  richard
*   Changes made for Enfora Pass through and general reliability improvements
*
*   Revision 1.30  2008/10/13 13:32:55  richard
*   Made Modec style USB -> RS232 work again.
*   Improvements on rx data speed (no longer polled)
*   Tweaked Delay_US function as it sometimes locked up in Modec build
*
*   Revision 1.29  2008/10/10 13:12:58  simon
*   Added AVG650 debug option
*
*   Revision 1.28  2008/10/03 08:45:30  simon
*   *** empty log message ***
*
*   Revision 1.27  2008/09/12 09:22:58  richard
*   *** empty log message ***
*
*   Revision 1.26  2008/08/14 11:29:37  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.25  2008/08/06 13:28:05  accutest\colin
*   Added J1708 and TrafficMaster debug output
*
*   Revision 1.24  2008/08/05 11:12:07  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.23  2008/07/29 16:02:47  ACCUTEST\richard
*   Changes to make Enfora / Webtech / LCD builds use CoreParams
*
*   Revision 1.22  2008/07/18 08:07:14  ACCUTEST\richard
*   New defines for new modules
*
*   Revision 1.21  2008/07/03 15:31:54  ACCUTEST\richard
*   Latest changes including WebTech module
*
*   Revision 1.20  2008/07/03 09:50:46  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.19  2008/07/02 16:31:05  ACCUTEST\simon
*   Progressed AT Command set and renamed AVG500M to AVG600
*
*   Revision 1.18  2008/06/20 08:48:06  ACCUTEST\simon
*   Added AT Command interpreter
*
*   Revision 1.17  2008/06/18 10:55:10  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.16  2008/06/13 14:03:10  ACCUTEST\simon
*   Fixed various compiler warnings
*
*   Revision 1.15  2008/05/12 10:14:38  ACCUTEST\simon
*   CMS J1979 V2.3.3.0, plus various bug fixes and fuel rate calculation tweeks.
*
*   Revision 1.14  2008/05/08 09:43:19  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.13  2008/03/19 15:13:25  ACCUTEST\simon
*   Added SD debug
*
*   Revision 1.12  2008/03/17 13:20:18  ACCUTEST\simon
*   *** empty log message ***
*
*   Revision 1.11  2008/03/06 14:22:10  ACCUTEST\richard
*   Added RTOS debug fution
*
*   Revision 1.10  2008/02/22 12:39:06  ACCUTEST\simon
*   Added LDVS debug
*
*   Revision 1.9  2008/02/20 16:34:10  ACCUTEST\simon
*   Added J1939
*
*   Revision 1.8  2008/02/18 09:52:33  ACCUTEST\richard
*   Added debug define for telematics build
*
*   Revision 1.7  2008/01/29 12:12:43  ACCUTEST\simon
*   Added aditional switches
*
*   Revision 1.6  2008/01/21 12:40:48  ACCUTEST\simon
*   Added KWP2000_TRACE functionality
*
*   Revision 1.5  2008/01/21 12:24:54  ACCUTEST\simon
*   Intermediate dev build
*
*   Revision 1.4  2007/12/21 12:24:06  ACCUTEST\peterp
*   Added AVG600_DEBUG and MAIN_DEBUG terms.
*
*   Revision 1.3  2007/12/13 13:57:16  ACCUTEST\peterp
*   Added GPS_DEBUG term.
*
*   Revision 1.2  2007/12/05 16:09:41  ACCUTEST\peterp
*   Added ATMEL_DEBUG
*
*   Revision 1.1  2007/11/29 17:35:18  ACCUTEST\simon
*   New file. Allows the turning ON/OFF of debug traces on a modular level
*
*
*********************************************************************
*/

#ifndef __DEBUG_H__
#define __DEBUG_H__
#ifndef KARLOFF
#ifdef DEBUG

/*******************************************************************/

//
// Module level DEBUG output only
//
// Show = (1)
// Hide = (0)

// CRITICAL ERRORS
#define CRITICAL_DEBUG      (1)   // CRITICAL debug output (use on )

// GENERAL
#define MAIN_DEBUG          (0)   // MAIN debug output
#define AVG600_DEBUG        (0)   // AVG600 debug output.
#define RTOS_DEBUG		    (0)	  // RTOS debug output
#define UPDATER_DEBUG       (0)   // Update Scheduler debug output

// HARDWARE MODULES
#define VIC_DEBUG           (0)   // VIC debug output
#define SPI_DEBUG           (0)   // SPI debug output
#define CAN_DEBUG           (0)   // CAN debug output
#define ATMEL_DEBUG         (1)   // ATMEL debug output
#define GPS_DEBUG           (0)   // GPS debug output
#define GPRS_DEBUG          (0)   // GPRS debug output
#define USB_DEBUG           (0)   // USB debug output
#define UPGRADE_DEBUG       (0)   // UPGRADER debug output
#define SD_DEBUG            (0)   // SD CARD debug output
#define MCI_DEBUG           (0)   // MCI (SD/MMC HAL) debug output
#define DISKIO_DEBUG        (0)   // DISKIO (SD/MMC) debug output
#define DMA_DEBUG           (0)   // GP DMA debug output
#define LCD_DEBUG			(0)   // LCD Display debug output
#define MLG0208_DEBUG       (0)   // MLG0208 debug output
#define MODEM_DEBUG         (0)   // Modem configuration
#define IBUTTON_DEBUG       (0)   // iButton module
#define POWER_DEBUG         (0)   // Power Management module

// PROTOCOL MODULES
#define KLINE_DEBUG         (1)   // KLINE debug output (ISO 9141-2)
#define ISO15765_DEBUG      (0)   // ISO15765 debug output
#define J1939_DEBUG         (0)   // J1939 debug output
#define J1979_DEBUG         (0)   // J1979 debug output
#define J1850_DEBUG         (0)   // J1850 debug output
#define J1708_DEBUG         (0)   // J1708 debug output
#define KWP2000_DEBUG       (0)   // KWP2000 debug output
#define VAUXHALL_DEBUG      (0)   // KWP2000 VAUXHALL debug output
#define NMEA0183_DEBUG      (0)   // NMEA-0183 debug output
#define FAT_DEBUG           (1)   // FAT (SD/MMC) debug output
#define DOT_DEBUG           (0)   // DOT MODULE for iDT

// CUSTOMER MODULES
#define CMS_DEBUG           (0)   // CMS debug output
#define ATROAD_DEBUG        (0)   // @ROAD debug output
#define MODEC_DEBUG         (0)   // MODEC debug output
#define TELEMATIC_DEBUG     (0)   // ACCUTEST TELEMATICS debug output
#define NMEACMD_DEBUG		(0)	  // NMEA Command generator debug output
#define WEBTECH_DEBUG		(0)	  // WEBTECH tracker debug output
#define FMSOUT_DEBUG        (0)   // FMS data debug output
#define J1587_GATEWAY_DEBUG (0)   // TrafficMaster OBDII to J1587 gateway
#define FORD_DEBUG          (0)   // Microlise ford module
#define AVG650_DEBUG        (1)   // AVG650 debug output
#define GEOMANAGER_DEBUG    (1)   // Trimble GeoManager module

// STP
#define STP_DEBUG           (0)   // STP debug output
#define J1979_STP_DEBUG     (0)   // J1979 STP debug output
#define CAN_STP_DEBUG       (0)   // CAN STP debug output
#define LDVS_DEBUG          (0)   // LDVS OBDII Protocol STP
#define ENFORA_DEBUG        (0)   // ENFORA debug output
#define AT_DEBUG            (0)   // AT debug output
#define CORE_DEBUG			(0)	  // CORE params output


/*******************************************************************/

#else

//
// Module level RELEASE output only
//
// Show = (1)
// Hide = (0)

/*******************************************************************/

#endif // DEBUG

/*******************************************************************/

//
// Module level DEBUG and RELEASE output
//
// Show = (1)
// Hide = (0)

// OUTPUT STREAMS
#define LCD_3x16_OUTPUT     (1)   // Output to LCD 3x16

/*******************************************************************/

#ifndef LCD_TRACE0
#define LCD_TRACE0(...)
#endif // LCD_TRACE0
#ifndef LCD_TRACE1
#define LCD_TRACE1(...) 
#endif // LCD_TRACE1
#ifndef LCD_TRACE2
#define LCD_TRACE2(...) 
#endif // LCD_TRACE2
#ifndef LCD_CLEAR
#define LCD_CLEAR()
#endif // LCD_CLEAR

#if (CRITICAL_DEBUG == 1)
#define CRITICAL_TRACE(...)  MODULE_TRACE("CRITICAL", __VA_ARGS__)
#else
#define CRITICAL_TRACE(...) 
#endif

/*******************************************************************/
#endif // #ifndef KARLOFF
#endif // __DEBUG_H__

