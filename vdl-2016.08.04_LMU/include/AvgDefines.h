/********************************************************************
* File:     $Id: AvgDefines.h,v 1.54 2010/03/23 15:20:43 Mswain Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.54 $
* Date:     $Date: 2010/03/23 15:20:43 $
* Author:   $Author: Mswain $
*
*********************************************************************
*
* Description:
* ============
*
* Provides general defines for the AVG project such as
* software module id's and RTOS task specific defines.
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2003-2007 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: AvgDefines.h,v $
*   Revision 1.54  2010/03/23 15:20:43  Mswain
*   GeomanagerInterface code.
*
*   Revision 1.53  2010/03/10 09:54:50  Rharvie
*   Bug fixes carried forward from V1.2.3.x.9
*
*   Revision 1.52  2010/02/02 10:19:29  Mswain
*   J1708 STP Support
*
*   Revision 1.51  2009/11/30 16:57:19  richard
*   Combined all vehicle protocols.
*   Added FIFO test
*
*   Revision 1.50  2009/11/12 10:43:29  richard
*   Changes made for GM V1.3.0.x.1
*
*   Revision 1.49  2009/10/27 11:06:03  colin
*   Changed stack size to try to prevent stack corruption especially of the watchdog
*
*   Revision 1.48  2009/09/28 15:19:15  MSwain
*   Bootloader
*
*   Revision 1.47  2009/08/21 13:17:58  richard
*   Build 26 changes
*
*   Revision 1.46  2009/08/17 08:32:20  richard
*   GeoManager build 21
*
*   Revision 1.45  2009/08/10 10:39:24  richard
*   *** empty log message ***
*
*   Revision 1.44  2009/08/07 11:41:02  richard
*   B13 patches
*
*   Revision 1.43  2009/08/03 16:27:35  richard
*   Changes for GeoManager build 10
*
*   Revision 1.42  2009/07/24 09:02:21  richard
*   Added code to tell bootloader not to OTAP
*
*   Revision 1.41  2009/07/23 16:27:41  simon
*   Added UART2 and UART3 VIC slots
*
*   Revision 1.40  2009/07/17 09:42:08  simon
*   Added USB, MCI and SD_MMC support for AVG660
*
*   Revision 1.39  2009/07/16 12:25:57  richard
*   *** empty log message ***
*
*   Revision 1.38  2009/07/02 08:39:27  simon
*   Fixed build conditions
*
*   Revision 1.37  2009/07/01 13:36:50  richard
*   Extras for AVG660
*
*   Revision 1.36  2009/05/26 12:51:48  richard
*   Added extra funtionality required for GeoManager
*
*   Revision 1.35  2009/03/17 17:11:03  richard
*   Added bootloader check (set __INCLUDE_BOOTLOADER_UPGRADE to use it)
*
*   Revision 1.34  2009/03/10 14:29:39  simon
*   Added RESET_AT_COMMAND_DELAYED_RS and renumnbered RESET_AT_COMMAND_RS to identify
*    older units in the field !!!
*
*   Revision 1.33  2009/03/03 10:27:01  simon
*   Version 2.5.0.1 : Minor fixes and addition of AT$DATE= and AT$TIME= commands
*
*   Revision 1.32  2009/02/19 12:51:02  simon
*   Moved xQueueReceive2() into the RTOS core
*
*   Revision 1.31  2009/02/11 17:05:46  simon
*   Version 2.4.10.0 : Added hardware ignition for AVG600 targets, fixed a few casts and
*    reduced watchdog task stack requirements.
*
*   Revision 1.30  2009/02/06 13:39:59  richard
*   Latest changes for 2.4.9.5
*
*   Revision 1.29  2009/01/27 16:20:15  richard
*   *** empty log message ***
*
*   Revision 1.28  2009/01/23 12:28:43  simon
*   Removed AVG200/400 defines !!!
*
*   Revision 1.27  2009/01/21 12:35:45  simon
*   Added watchdog support, fixed NMEA0183 formatting bug, added EEPROM read/write functions.
*
*   Revision 1.26  2009/01/14 11:52:06  simon
*   Added stack watermark code, locking on SPI and SPI FLASH modules and changed stack
*    sizes and RTOS config.
*
*   Revision 1.25  2008/12/24 11:54:40  richard
*   Changs made to get instant GPS on AVG650
*
*   Revision 1.24  2008/10/27 09:16:15  accutest\colin
*   Added macro for J1587 RTOS configuration
*
*   Revision 1.23  2008/10/23 14:21:40  richard
*   Changes made for external RS232 on enfora
*
*   Revision 1.22  2008/09/15 15:22:32  simon
*   Added support for AVG600 builds (based on AVG500 hardware core + GPRS/GPS module)
*
*   Revision 1.21  2008/08/06 13:25:01  accutest\colin
*   Changed AVG600 -> AVG700 and added parameters for the TrafficMaster build
*
*   Revision 1.20  2008/08/05 11:11:57  ACCUTEST\richard
*   *** empty log message ***
*
*   Revision 1.19  2008/07/18 08:07:02  ACCUTEST\richard
*   New defines for new modules
*
*   Revision 1.18  2008/07/02 16:31:05  ACCUTEST\simon
*   Progressed AT Command set and renamed AVG500M to AVG600
*
*   Revision 1.17  2008/06/24 12:34:14  ACCUTEST\richard
*   Increased STKSIZE_RX_STP stack size for @Road build.
*
*   Revision 1.16  2008/05/12 10:14:38  ACCUTEST\simon
*   CMS J1979 V2.3.3.0, plus various bug fixes and fuel rate calculation tweeks.
*
*   Revision 1.15  2008/05/08 09:43:06  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.14  2008/03/19 15:12:00  ACCUTEST\simon
*   Added __EXCLUDE_RTOS to prevent warnings in production test builds
*
*   Revision 1.13  2008/03/06 14:18:38  ACCUTEST\richard
*   Trimmed some of the stack sizes
*
*   Revision 1.12  2008/03/06 13:42:48  ACCUTEST\simon
*   Added OBDII_LDVS resources
*
*   Revision 1.11  2008/02/28 16:38:50  ACCUTEST\simon
*   Added Sleep(x) macro for RTOS support
*
*   Revision 1.10  2008/02/18 10:07:29  ACCUTEST\richard
*   Added telematics #defines
*
*   Revision 1.9  2007/12/13 13:56:41  ACCUTEST\peterp
*   (1) Added GPS task, priority and queue.
*   (2) Updated VIC Channel and slot definitions.
*
*   Revision 1.8  2007/12/12 13:53:24  ACCUTEST\simon
*   Added WATCHDOG_FEED macro and watchdog is now enabled by adding a __TARGET_WATCHDOG
*    define to the build configuration.
*
*   Revision 1.7  2007/12/10 16:50:07  ACCUTEST\simon
*   Added RTOS not included warning
*
*   Revision 1.6  2007/11/29 17:43:54  ACCUTEST\simon
*   Added defines for EINT0
*
*   Revision 1.5  2007/11/15 09:44:24  ACCUTEST\simon
*   J1979 response -> request timing improved, code for CAN channels 3 and 4 removed,
*    CMS stp channel progressed.
*
*   Revision 1.4  2007/10/26 14:00:32  ACCUTEST\simon
*   *** empty log message ***
*
*   Revision 1.3  2007/10/22 11:40:22  ACCUTEST\peterp
*   Added LCD_TRACE facility for AVG600 build.
*
*   Revision 1.2  2007/10/22 08:46:15  ACCUTEST\peterp
*   AVG500L (NXP LPC2129) and AVG600 (NXP LPC2468) port.
*
*
*********************************************************************
*/
#ifndef AvgDefines_included
#define AvgDefines_included

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// standard I/O support
#include <stdio.h>

#ifndef __TARGET_AVG500L
#ifndef __TARGET_AVG600
#ifndef __TARGET_AVG660
#ifndef __TARGET_TM3000
#ifndef KARLOFF
#error ("TARGET AVG is not defined !!!")
#endif
#endif
#endif
#endif
#endif

#ifdef __TARGET_AVG500L
#ifdef __TARGET_AVG600
#error ("TARGET AVG is defined for multiple targets ... Doh !!!")
#endif
#endif

#ifdef __TARGET_AVG500L
#ifdef __TARGET_AVG660
#error ("TARGET AVG is defined for multiple targets ... Doh !!!")
#endif
#endif

#ifdef __TARGET_AVG600
#ifdef __TARGET_AVG660
#error ("TARGET AVG is defined for multiple targets ... Doh !!!")
#endif
#endif

// Firmware support

#ifdef __TARGET_AVG500L 
#include "AVG500L.h"        // AVG 500 Series
#endif
#ifdef __TARGET_AVG600
#include "AVG600.h"         // AVG 650
#endif
#ifdef __TARGET_AVG660
#include "AVG660.h"         // AVG 660
#endif
#ifdef __TARGET_TM3000
#include "TM3000.h"
#endif
#ifdef KARLOFF
#include "TVG850.h"
#define __EXCLUDE_RTOS
#endif

#include "wdt.h"            // Watchdog support

#ifdef __TARGET_RTOS
#include "RTOS.h"           // RTOS Support

#ifdef __TARGET_AVG500L 
// Sleep(x) implementation
#define Sleep(x)                                        \
{                                                       \
    portTickType xLastWakeTime;                         \
    xLastWakeTime = xTaskGetTickCount();                \
    vTaskDelayUntil(&xLastWakeTime, MS_TO_TICKS((x)));  \
}
#else

#define Sleep(x)    vTaskDelay(x);

#endif

#else
#ifndef __TARGET_RTOS      // has the RTOS been explicitly included ???
#ifndef __EXCLUDE_RTOS
#warning "__TARGET_RTOS or __EXCLUDE_RTOS has not been defined so the RTOS will be excluded from the build."
#endif // __EXCLUDE_RTOS
#endif
#ifdef KARLOFF
#define Sleep(x) usleep(x*1000);
#else
#define Sleep(x)
#endif
#endif

// module options

// general data types
#include "Gendefs.h"
#include "types.h"

#ifdef USE_LCD_3x16_EXPANSION_BOARD
#include "lcd_3x16.h"
#endif

// PC interface definitions
#include "serialtransportids.h"     

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*! Function used to configure the VIC for interrupts */
extern uint8_t VIC_Configure(uint8_t u8SlotNo, uint32_t u32Channel, uint32_t* pISR);

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

/*------------------- Module RTOS Requirements ---------------------*/

/********************************************************************
Defines for RTOS task priority allocations 
*********************************************************************/
// Older defines - mostly not used
#define TSK_PRIO_CAN_TX			4u
#define TSK_PRIO_STP_CAN_TX		4u
#define TSK_PRIO_STP			5u
#define TSK_PRIO_STP_MODEC      4u
#define TSK_PRIO_STP_CMS        5u
#define TSK_PRIO_CORE_J1939		4u
#define TSK_PRIO_CORE_J1979		4u
#define TSK_PRIO_CORE_FORD		4u
#define TSK_PRIO_CORE_GPS		4u
#define TSK_PRIO_GPS			4u

#define TSK_PRIO_STP_TELEMATICS	4u
#define TSK_PRIO_APPLICATION    4u
#define TSK_PRIO_NMEA			4u
#define TSK_PRIO_J1587          4u
#define TSK_PRIO_STP_J1708_TX	4u

// Following used in GeoManager app - be careful on priorities - 0 = idle, 5 = top

#define TSK_PRIO_J1979          5u
#define TSK_PRIO_CORE_GENERIC	4u
#define TSK_PRIO_GM_MODEM       3u
#define TSK_PRIO_GM_GPS         3u
#define TSK_PRIO_GM_VEHICLE     2u
#define TSK_PRIO_GM_DRV         2u
#define TSK_PRIO_GM_SAFETY      2u
#define TSK_PRIO_GM_EXT         1u
#define TSK_PRIO_GM_ACCEL       1u
#define TSK_PRIO_FLASH          3u


#ifdef BUILD_TRAFFICMASTER
#define TSK_PRIO_J1587_OBDII    3u
#endif /* BUILD_TRAFFICMASTER */

#define TSK_PRIO_WATCHDOG       4u

/********************************************************************
Defines for watchdog task monitor timeouts
*********************************************************************/
#define TSK_WDG_TIMEOUT_CAN_TX          (120000)
#define TSK_WDG_TIMEOUT_STP_CAN_TX		(120000)
#define TSK_WDG_TIMEOUT_STP             (120000)
#define TSK_WDG_TIMEOUT_J1979           (120000)
#define TSK_WDG_TIMEOUT_STP_MODEC       (120000)
#define TSK_WDG_TIMEOUT_STP_CMS         (120000)
#define TSK_WDG_TIMEOUT_CORE_J1939		(120000)
#define TSK_WDG_TIMEOUT_CORE_J1979		(120000)
#define TSK_WDG_TIMEOUT_CORE_GENERIC	(120000)
#define TSK_WDG_TIMEOUT_CORE_FORD		(120000)
#define TSK_WDG_TIMEOUT_GPS             (120000)
#define TSK_WDG_TIMEOUT_STP_TELEMATICS	(120000)
#define TSK_WDG_TIMEOUT_APPLICATION     (120000)
#define TSK_WDG_TIMEOUT_NMEA			(120000)
#define TSK_WDG_TIMEOUT_J1587           (120000)

#ifdef BUILD_TRAFFICMASTER
#define TSK_WDG_TIMEOUT_J1587_OBDII     (120000)
#endif /* BUILD_TRAFFICMASTER */

#define TSK_WDG_TIMEOUT_GM_VEHICLE      (120000)
#define TSK_WDG_TIMEOUT_GM_MODEM        (120000)
#define TSK_WDG_TIMEOUT_GM_GPS          (120000)
#define TSK_WDG_TIMEOUT_GM_EXT          (120000)
#define TSK_WDG_TIMEOUT_GMI             (120000)
#define TSK_WDG_TIMEOUT_IDT		        (120000)
#define TSK_WDG_TIMEOUT_GM_OTAP         (120000)
#define TSK_WDG_TIMEOUT_FLASH           (120000)

#define TSK_WDG_TIMEOUT_WATCHDOG        (120000)


/********************************************************************
Defines for Watchdog Monitor reset codes
*********************************************************************/

#define TSK_RESET_CODE_CAN_TX           (1)
#define TSK_RESET_CODE_STP_CAN_TX		(2)
#define TSK_RESET_CODE_STP              (3)
#define TSK_RESET_CODE_J1979            (4)
#define TSK_RESET_CODE_STP_MODEC        (5)
#define TSK_RESET_CODE_STP_CMS          (6)
#define TSK_RESET_CODE_CORE_J1939		(7)
#define TSK_RESET_CODE_CORE_J1979		(8)
#define TSK_RESET_CODE_CORE_FORD		(9)
#define TSK_RESET_CODE_GPS              (10)
#define TSK_RESET_CODE_STP_TELEMATICS	(11)
#define TSK_RESET_CODE_APPLICATION      (12)
#define TSK_RESET_CODE_NMEA             (13)
#define TSK_RESET_CODE_J1587            (14)

#ifdef BUILD_TRAFFICMASTER
#define TSK_RESET_CODE_J1587_OBDII      (15)
#endif /* BUILD_TRAFFICMASTER */

#define TSK_RESET_CODE_CORE_GPS			(16)

#define TSK_RESET_CODE_GM_VEHICLE       (17)
#define TSK_RESET_CODE_GM_MODEM         (18)
#define TSK_RESET_CODE_GM_GPS           (19)
#define TSK_RESET_CODE_GM_EXT           (20)
#define TSK_RESET_CODE_CORE_GENERIC		(21)
#define TSK_RESET_CODE_GMI              (22)
#define TSK_IDT_CODE                    (23)
#define TSK_RESET_CODE_TFTP_OTAP        (24)
#define TSK_RESET_CODE_FLASH            (25)

// scheduled update reset codes
#define RESET_CODE_UPDATE_SCHEDULE_BASE (100)
#define RESET_CODE_UPDATE_SCHEDULE_TOP  (129)

// application update codes
#define RESET_CODE_APPLICATION_BASE     (130)
#define RESET_CODE_APPLICATION_TOP      (199)

// startup reset codes
#define RESET_CODE_OUT_OF_MEMORY        (200)
#define RESET_CODE_MODULE_FAILED        (201)
#define RESET_CODE_BOOTLOADER           (202)

// AT Command reset codes
#define RESET_AT_COMMAND_RS             (251)
#define RESET_AT_COMMAND_DELAYED_RS     (252)
#define RESET_BOOTLOADER_UPGRADE        (253)
#define RESET_RUN_MAIN_APP              (254)

// watchdog reset code
#define TSK_RESET_CODE_WATCHDOG         (255)

/********************************************************************
Defines for RTOS task stack sizes - note all in DWORDS!!!
Minimum is configMINIMAL_STACK_SIZE (16)
*********************************************************************/

#define STKSIZE_CAN_TX			128u
#define STKSIZE_STP_CAN_TX		128u
#define STKSIZE_RX_STP			256u //128u
#define	STKSIZE_J1979			1024u
#define	STKSIZE_STP_MODEC_TX    300u //256
#define	STKSIZE_STP_MODEC_RX    300u
#define	STKSIZE_STP_CMS         300u //512
#define	STKSIZE_CORE_J1939      300u
#define	STKSIZE_CORE_GPS		300u
#define	STKSIZE_CORE_J1979      300u
#define STKSIZE_CORE_FORD       300u
#define STKSIZE_CORE_GENERIC	512u
#define STKSIZE_RX_GPS			512u
#define STKSIZE_STP_TELEMATICS	128u
#define STKSIZE_APPLICATION     128u
#define STKSIZE_NMEA			144u //128u
#define STKSIZE_J1587           128u
#define STKSIZE_GEOMANAGERBIG   1024u   // Made large so that GeoManager structs (up to 512 bytes) can be placed on stack
#define STKSIZE_GEOMANAGERSML   256u
#define STKSIZE_IDT		        512u
#define STKSIZE_STP_J1708_TX	128u
#define STKSIZE_STP_J1979	128u

#ifdef BUILD_TRAFFICMASTER
#define STKSIZE_J1587_OBDII     128u
#undef STKSIZE_J1979
#define	STKSIZE_J1979           512u
#endif /* BUILD_TRAFFICMASTER */

#define STKSIZE_WATCHDOG        128u //64u

/********************************************************************
Defines for RTOS queue sizes
*********************************************************************/

#define QSIZE_CANRX				400u
#define	QSIZE_CANTX				50u
#define QSIZE_STPRX				256u
#define QSIZE_ENFORARX			128u
#define QSIZE_USBTX             128u
#define QSIZE_J1979_MESSAGE     40u
#define QSIZE_J1939_MESSAGE     10u
#define QSIZE_KLINERX           20u
#define QSIZE_EXTUART_TX        128u
#define QSIZE_EXTUART_RX        128u
#define QSIZE_GPSRX             128u    // GPS Rx queue size.

#ifdef BUILD_TRAFFICMASTER
#undef QSIZE_CANRX
#define	QSIZE_CANRX             25u
#undef QSIZE_CANTX 
#define	QSIZE_CANTX             10u
#endif /* BUILD_TRAFFICMASTER */


/*------------------- Module Interrupt Vectors ---------------------*/

/********************************************************************
Defines for the VIC 
*********************************************************************/

// Predefined VIC Channel allocations

#ifdef __TARGET_PROCESSOR_STR710

#define VIC_CHANNEL_MAX         31u
#define VIC_MAX_CHANNELS        32u

#define	VIC_CHANNEL_RTOS			0u              // DO NOT CHANGE
#define VIC_CHANNEL_TIMER0          (VIC_CHANNEL_RTOS) // TIMER0 alias for non-RTOS builds !!!
#define VIC_CHANNEL_FLASH           1u
#define VIC_CHANNEL_PRCUU           2u
#define VIC_CHANNEL_RTC             3u
#define VIC_CHANNEL_WATCHDOG        4u
#define VIC_CHANNEL_EINT0			5u
#define VIC_CHANNEL_USB_HI			6u
#define VIC_CHANNEL_I2C0ERR         7u
#define VIC_CHANNEL_I2C1ERR         8u
#define VIC_CHANNEL_UART0			9u
#define VIC_CHANNEL_UART1			10u
#define VIC_CHANNEL_UART2			11u
#define VIC_CHANNEL_UART3			12u
#define VIC_CHANNEL_SPI0            13u
#define VIC_CHANNEL_SPI1            14u
#define VIC_CHANNEL_I2C0            15u
#define VIC_CHANNEL_I2C1            16u
#define VIC_CHANNEL_CAN             17u
#define VIC_CHANNEL_ADC             18u
#define VIC_CHANNEL_TIMER1			19u
#define VIC_CHANNEL_TIMER2			20u
#define VIC_CHANNEL_TIMER3			21u
#define VIC_CHANNEL_HDLC            25u
#define VIC_CHANNEL_USB_LOW         26u
#define VIC_CHANNEL_TIMER0_OVER     29u
#define VIC_CHANNEL_TIMER0_COMPA    30u
#define VIC_CHANNEL_TIMER0_COMPB    31u
#else

#define VIC_CHANNEL_MAX         27u
#define VIC_MAX_CHANNELS        32u


#define VIC_CHANNEL_TIMER0		4u
#define VIC_CHANNEL_TIMER1		5u
#define VIC_CHANNEL_UART0		6u
#define VIC_CHANNEL_UART1		7u
#define VIC_CHANNEL_PWM         8u
#define VIC_CHANNEL_I2C         9u
#define VIC_CHANNEL_SPI0        10u
#define VIC_CHANNEL_SPI1        11u
#define VIC_CHANNEL_PLL         12u
#define VIC_CHANNEL_RTC         13u
#define VIC_CHANNEL_EINT0		14u
#define VIC_CHANNEL_EINT1		15u
#define VIC_CHANNEL_EINT2		16u
#define VIC_CHANNEL_EINT3		17u
#define VIC_CHANNEL_ADC         18u

#ifdef __TARGET_PROCESSOR_LPC2388
#define VIC_CHANNEL_WATCHDOG	0u
#define VIC_CHANNEL_I2C1        19u 
#define VIC_CHANNEL_BOD         20u  
#define VIC_CHANNEL_ETHERNET    21u
#define VIC_CHANNEL_USB         22u  
#define VIC_CHANNEL_CAN         23u
#define VIC_CHANNEL_SD_MMC      24u
#define VIC_CHANNEL_DMA         25u
#define VIC_CHANNEL_TIMER2      26u
#define VIC_CHANNEL_TIMER3      27u
#define VIC_CHANNEL_UART2       28u
#define VIC_CHANNEL_UART3       29u
#define VIC_CHANNEL_I2C2        30u
#define VIC_CHANNEL_I2S         31u
#undef VIC_CHANNEL_MAX
#define VIC_CHANNEL_MAX         31u
#else
#define VIC_CHANNEL_WATCHDOG	1u
#define VIC_CHANNEL_CANERR      19u 
#define VIC_CHANNEL_CAN1TX		20u  
#define VIC_CHANNEL_CAN2TX      21u
#define VIC_CHANNEL_CAN1RX		26u  
#define VIC_CHANNEL_CAN2RX      27u
#endif
#ifdef __TARGET_AVG700
#define VIC_CHANNEL_UART2		28u
#define VIC_CHANNEL_UART3		29u
#undef VIC_CHANNEL_MAX
#define VIC_CHANNEL_MAX         29u
#endif  // __TARGET_AVG700
#endif

#if defined( __TARGET_PROCESSOR_LPC2388) || defined(__TARGET_PROCESSOR_STR710)
// VIC PRIOTIRY allocations (different from LPC21xx)
#define	VIC_SLOT_RTOS			0u              // DO NOT CHANGE
#define VIC_SLOT_TIMER0         (VIC_SLOT_RTOS) // TIMER0 alias for non-RTOS builds !!!
#define VIC_SLOT_UART0			VIC_SLOT_RTOS
#define VIC_SLOT_CAN			VIC_SLOT_RTOS
#define VIC_SLOT_BOD            3u
#define VIC_SLOT_DMA			4u
#define VIC_SLOT_UART1			VIC_SLOT_RTOS
#define VIC_SLOT_USB			6u
#define VIC_SLOT_SD_MMC			7u
#define VIC_SLOT_EINT1			8u
#define VIC_SLOT_TIMER1			9u
#define VIC_SLOT_EINT0			10u
#define VIC_SLOT_WATCHDOG       11u
#define VIC_SLOT_RTC            11u
#define VIC_SLOT_UART2			VIC_SLOT_RTOS
#define VIC_SLOT_UART3			VIC_SLOT_RTOS
#define VIC_SLOT_SSP1			14u
#define VIC_SLOT_TIMER2			14u
#define VIC_SLOT_TIMER3			15u
#else
// VIC slot allocations
#define	VIC_SLOT_RTOS			0u		// DO NOT CHANGE
#define VIC_SLOT_UART0			1u
#define VIC_SLOT_CAN1RX			2u
#define VIC_SLOT_CAN2RX			3u
#define VIC_SLOT_CANERR			4u
#define VIC_SLOT_CAN1TX			5u
#define VIC_SLOT_CAN2TX			6u
#define VIC_SLOT_UART1			7u
#define VIC_SLOT_EINT1			8u
#define VIC_SLOT_TIMER1			9u
#define VIC_SLOT_EINT0			10u
#define VIC_SLOT_WATCHDOG       11u
#define VIC_SLOT_UART2			12u
#define VIC_SLOT_UART3			13u
#endif

#ifdef __TARGET_AVG700
#define VIC_SLOT_UART2			12u
#define VIC_SLOT_UART3			13u
#endif // __TARGET_AVG700

#define VIC_SLOT_MAX			15u

#ifdef __TARGET_PROCESSOR_STR710
#define __ramfunc __attribute__ ((section (".fast")))
#define __ramint __attribute__ ((interrupt, section (".fast")))
#else
#define __ramfunc
#define __ramint
#endif
/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* CLASSES                                                          */
/*------------------------------------------------------------------*/

#endif /* AvgDefines_included */

