/********************************************************************
* File:     $Id: Watchdog.h,v 1.5 2009/02/19 10:58:56 simon Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.5 $
* Date:     $Date: 2009/02/19 10:58:56 $
* Author:   $Author: simon $
*
********************************************************************
*
* Description:
* ============
*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2008 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: Watchdog.h,v $
*   Revision 1.5  2009/02/19 10:58:56  simon
*   Removed obsolete #define
*
*   Revision 1.4  2009/01/21 12:35:45  simon
*   Added watchdog support, fixed NMEA0183 formatting bug, added EEPROM read/write functions.
*
*   Revision 1.3  2009/01/16 12:24:34  accutest\colin
*   Changed to allow use in and out of the RTOS
*
*   Revision 1.2  2009/01/14 12:17:39  accutest\colin
*   Watchdog now has its own task.
*
*   Revision 1.1  2008/12/19 14:54:20  accutest\colin
*   Functions to control the ARM watchdog
*
*
*********************************************************************
*/

#ifndef _WATCHDOG_H_ 
#define _WATCHDOG_H_

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

#include "types.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t WATCHDOG_Init(uint32_t u32Milliseconds_);
void WATCHDOG_Set(uint32_t u32Milliseconds_);

void WATCHDOG_Start(void);
void WATCHDOG_Timeout(void);

void WATCHDOG_Feed(void);

int1_t WATCHDOG_LastResetByWatchdog(void);

#ifdef __TARGET_RTOS
uint8_t WATCHDOG_InitModuleRTOS(void);
uint8_t WATCHDOG_RegisterMonitor(uint32_t timeoutMilliseconds, uint8_t resetCode);
void    WATCHDOG_UnRegisterMonitor(uint8_t index);
void    WATCHDOG_FeedMonitor(uint8_t index);
void    WATCHDOG_SetNotification(void* pCallback);
#endif // __TARGET_RTOS

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif /* _WATCHDOG_H_ */
