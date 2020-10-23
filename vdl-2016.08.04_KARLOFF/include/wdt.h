/********************************************************************
* File:     $Id: wdt.h,v 1.7 2008/03/06 13:43:20 ACCUTEST\simon Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.7 $
* Date:     $Date: 2008/03/06 13:43:20 $
* Author:   $Author: ACCUTEST\simon $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides Watchdog header file.
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
*   $Log: wdt.h,v $
*   Revision 1.7  2008/03/06 13:43:20  ACCUTEST\simon
*   Added standard comment blocks
*
*   Revision 1.6  2008/01/23 14:37:49  ACCUTEST\richard
*   Fixed to make 500L release build
*
*   Revision 1.5  2008/01/03 17:31:25  ACCUTEST\peterp
*   *** empty log message ***
*
*   Revision 1.4  2007/12/13 09:36:42  ACCUTEST\peterp
*   Accessing non-Watchdog APB registers in the
*   middle of the feed sequence causes a reset.
*   See LPC2468 Errata Sheet Version 1.1, 7 June 2007.
*   Changed the define in wdt.h such that interrupts are
*   disabled immediately before the WDT feed and re-enabled
*   immediately afterward.
*
*   Revision 1.3  2007/12/12 13:53:24  ACCUTEST\simon
*   Added WATCHDOG_FEED macro and watchdog is now enabled by adding a __TARGET_WATCHDOG
*    define to the build configuration.
*
*   Revision 1.2  2007/11/16 14:39:54  ACCUTEST\peterp
*   Test harnesses compile in in DEBUG mode only.
*
*   Revision 1.1  2007/11/14 16:22:21  ACCUTEST\peterp
*   (1) Added USB driver & test harness.
*   (2) Added WDT (watchdog timer) and test harness.
*
*
*********************************************************************
*/

#ifndef __WDT_H 
#define __WDT_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

#include "AvgDefines.h"

#ifdef __TARGET_WATCHDOG

#include "irq.h"
#include "target.h"
#include "timer.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define WDEN            (0x00000001)
#define WDRESET         (0x00000002)
#define WDTOF           (0x00000004)
#define WDINT           (0x00000008)
#define WDT_FEED_VALUE  (0x003FFFFF)
#define WDT_KICK_LIMIT  (10000000)

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

extern void     WDTHandler(void);
extern uint32_t WDTInit(uint32_t timeout);
extern void     WDTFeed(void);
extern void     WDTReset(void);

#define WATCHDOG_FEED { portDISABLE_INTERRUPTS(); WDTFeed(); portENABLE_INTERRUPTS(); }
#else
#define WATCHDOG_FEED
#define WDT_KICK_LIMIT  (10000000)
#endif

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif /* end __WDT_H */

/*****************************************************************************
**                            End Of File: wdt.h
******************************************************************************/
