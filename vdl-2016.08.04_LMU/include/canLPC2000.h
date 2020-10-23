/********************************************************************
* File:     $Id: canLPC2000.h,v 1.15 2009/07/16 12:25:57 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.15 $
* Date:     $Date: 2009/07/16 12:25:57 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <CANLPC2000.c>
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2006 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: canLPC2000.h,v $
*   Revision 1.15  2009/07/16 12:25:57  richard
*   *** empty log message ***
*
*   Revision 1.14  2009/07/06 13:53:30  simon
*   Added CAN BTR values for AVG660
*
*   Revision 1.13  2009/07/01 11:06:47  simon
*   Fixed compiler warnings
*
*   Revision 1.12  2009/02/27 11:49:28  richard
*   Fix for Modec code
*
*   Revision 1.11  2009/01/27 16:20:43  richard
*   Added code to allow Config Tool to control passive mode when detecting J1939
*
*   Revision 1.10  2008/10/03 08:44:34  simon
*   Added MLG0208 module, Added LED module, Added AT response handlers.
*    changed LED calls.
*
*   Revision 1.9  2008/09/15 15:22:32  simon
*   Added support for AVG600 builds (based on AVG500 hardware core + GPRS/GPS module)
*
*   Revision 1.8  2008/07/18 08:06:45  ACCUTEST\richard
*   Added ability to use software filtering on CAN messages, ideal for J1939
*
*   Revision 1.7  2008/06/23 08:49:03  ACCUTEST\richard
*   Added function definition
*
*   Revision 1.6  2008/05/08 09:43:06  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.5  2008/03/06 14:19:30  ACCUTEST\richard
*   Changed code to use spare filter RAM for temp storage
*   Added Auto Baud function
*
*   Revision 1.4  2008/03/06 13:55:09  ACCUTEST\simon
*   Added TestMessage in DEBUG mode
*
*   Revision 1.3  2007/11/15 09:44:24  ACCUTEST\simon
*   J1979 response -> request timing improved, code for CAN channels 3 and 4 removed,
*    CMS stp channel progressed.
*
*   Revision 1.2  2007/10/26 14:00:32  ACCUTEST\simon
*   *** empty log message ***
*
*   Revision 1.1  2007/10/04 11:41:30  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.12  2007/09/28 08:16:21  ACCUTEST\simon
*   Various fixes and enhancements
*
*   Revision 1.11  2007/08/14 08:37:27  ACCUTEST\simon
*   Added MODEC module, added physical initialization option for J1979, fixed a few minor
*    bugs.
*
*   Revision 1.10  2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   Revision 1.9  2007/05/16 10:59:43  ACCUTEST\simon
*   Initial J1979 working code.
*
*   Revision 1.8  2007/04/20 14:14:27  ACCUTEST\simon
*   J1979 in progress
*
*   Revision 1.7  2007/01/23 11:15:37  ACCUTEST\paull
*   changes made for AVG500L
*
*   Revision 1.6  2007/01/12 12:00:55  ACCUTEST\paull
*   Corrected CRC issue in STP Module.
*
*   Revision 1.5  2006/12/21 11:38:43  ACCUTEST\paull
*   style changes
*
*   Revision 1.4  2006/12/14 13:54:40  ACCUTEST\paull
*   style changes
*
*   Revision 1.3  2006/12/07 17:05:16  ACCUTEST\paull
*   General updates
*
*   Revision 1.2  2006/12/01 13:44:21  ACCUTEST\paull
*   general updates
*
*   Revision 1.1  2006/11/27 15:51:56  ACCUTEST\paull
*   Initial checkin of the ARM_AVG module.
*
*
*********************************************************************
*/

#ifndef CANLPC2000_H
#define CANLPC2000_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Shared AVG and PC CAN definitions
#define CAN_MAX_MSG_LEN     8		// Maximum length of a CAN packet

// Following not fully working - 1st filter works, others dont
// It will save 500 bytes of ram though
//#define USE_FILTER_RAM				// Use top half of filter ram
#include "CAN.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

// this should be defined in the target platform header file (i.e. AVGxxx.h)
#ifndef CAN_PORTS
#error ("Need to define CAN_PORTS in target platform header file (i.e. AVGxxx.h)")
#endif
/*
// Macro to calculate the BTR register value for the CAN controller
#define	CAN_BTR (TSEG1, TSEG2, BRP, SJW, SAM)\
	{\
		(uint32_t)(BRP   & CAN1BTR_BRP_MASK)						|\
		(uint32_t)(TSEG1 & CAN1BTR_TSEG1_MASK) << CAN1BTR_TSEG1_BIT	|\
		(uint32_t)(TSEG2 & CAN1BTR_TSEG2_MASK) << CAN1BTR_TSEG2_BIT	|\
        (uint32_t)(SAM   & CAN1BTR_SAM_MASK)   << CAN1BTR_SAM_BIT	|\
        (uint32_t)(SJW   & CAN1BTR_SJW_MASK)   << CAN1BTR_SJW_BIT	|\
	}
*/
// Bit rate settings


#ifdef __TARGET_AVG660                      /* AVG660 */
// 12Mhz xtal (72Mhz clock)
#if OSCILLATOR_CLOCK_FREQUENCY==12000000    /* 48 MHz CAN clock */
#define CAN_BTR_1000K       (0x001a0004)    /* CAN BTR settings bus 1000K baud */
#define CAN_BTR_500K        (0x001c0008)    /* CAN BTR settings bus 500K baud */
#define CAN_BTR_250K        (0x001c0011)    /* CAN BTR settings bus 250K baud */
#define CAN_BTR_125K        (0x001c0023)    /* CAN BTR settings bus 125K baud */
#define CAN_BTR_100K        (0x001c002c)    /* CAN BTR settings bus 100K baud */
#endif // OSCILLATOR_CLOCK_FREQUENCY==12000000
#else // __TARGET_AVG660                    /* AVG540/AVG550/AVG650 */
// 10Mhz xtal (60Mhz clock)
#if OSCILLATOR_CLOCK_FREQUENCY==10000000    /* 10 MHz clock */
#define CAN_BTR_125K        (0x001C001D)	// CAN BTR settings bus 125K baud
#define CAN_BTR_250K        (0x001C000e)	// CAN BTR settings bus 250K baud
#define CAN_BTR_500K        (0x001b0007)	// CAN BTR settings bus 500K baud
#define CAN_BTR_1000K		(0x001b0003)	// CAN BTR settings bus 1000K baud
#endif // OSCILLATOR_CLOCK_FREQUENCY==10000000
#endif // __TARGET_AVG660

#ifdef __TARGET_TM3000      // Taken from ISO15765
#define CAN_BTR_125K        (0x2B8B)	// CAN BTR settings bus 125K baud
#define CAN_BTR_250K        (0x2B84)	// CAN BTR settings bus 250K baud
#define CAN_BTR_500K        (0x2B82)	// CAN BTR settings bus 500K baud
//#define CAN_BTR_1000K		(0x1b03)	// CAN BTR settings bus 1000K baud
#endif

#ifdef KARLOFF
#define CAN_BTR_125K        125000		// CAN BTR settings bus 125K baud
#define CAN_BTR_250K        250000		// CAN BTR settings bus 250K baud
#define CAN_BTR_500K        500000		// CAN BTR settings bus 500K baud
#endif

// Default baudrates
#define CAN_SPEED_AUTO		(0L)	
#define CAN_SPEED_125K		(125000L)	
#define CAN_SPEED_250K		(250000L)	
#define CAN_SPEED_500K		(500000L)	
#define CAN_SPEED_1000K		(1000000L)	

// CAN message type definitions
#define	CAN_ID_STD          (0x00)	// Select 11 bit indentifiers
#define	CAN_ID_XTD          (0x04)	// Select 29 bit indentifiers
#define	CAN_RTR_FRAME       (0x01)	// Sets a remote transmit request frame
#define CAN_BUS_ERR         (0x08)	// Bus off message

// CAN_SendMessage return codes
#define CAN_SM_OK                       0   // OK, Success
#define CAN_SM_ERR_TIMEOUT              1   // timeout error has occurred
#define CAN_SM_ERR_INVALID_PORT         2   // Invalid Port Number
#define CAN_SM_ERR_BUSOFF               3   // CAN is BUS OFF
#define CAN_SM_ERR_BUS_ERROR            4   // SendMessage caused a BUS ERROR
#define CAN_SM_ERR_BITRATE_ERROR        5   // Incorrect bit rate detected
#define CAN_SM_ERR_NO_ACK               6   // SendMessage not ACKed
#define CAN_SM_ERR_ARBITRATION_LOST     7   // SendMessage not ACKed
#define CAN_SM_ERR_NO_TX_BUFFER         8   // TX buffer not available
#define CAN_SM_ERR_PORT_OFF             9   // CAN Port is not ON !!!
#define CAN_SM_ERR_BUSY                 10  // CAN Port is currently busy
#define CAN_SM_ERR                      11  // Unknown error has occurred

#define CAN_ID_29BIT          0x80000000
#define CAN_ID_29BIT_MASK	  0x1FFFFFFF
#define CAN_ID_11BIT_MASK	  0x000007FF

// CAN Port status
#define CAN_STATUS_OK               (0)
#define CAN_STATUS_BUSY             (1)
#define CAN_STATUS_BUS_ERROR        (2)
#define CAN_STATUS_ERROR_PASSIVE    (3)
#define CAN_STATUS_ARBITRATION_LOST (4)

#define CAN_MAX_TX_RETRY            (100)
/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

// Enumeration for the available can ports
typedef enum {
  CAN_PORT_1 = 1,
  CAN_PORT_2
} teCanPorts;

// Enumeration for the bus status
typedef enum {
  CanBusStatus_Offline = 0,
  CanBusStatus_Error,
  CanBusStatus_BusOn,
  CanBusStatus_ErrorActive,
  CanBusStatus_ErrorPassive,
  CanBusStatus_BusOff,
} teCanBusStatus;

// Set up filter function as uint8_t FilterFunction(teCanPorts nPort, tsCanMsgV2* CanMsg);
typedef uint8_t (CAN_MSG_FILTER_CALLBACK)(teCanPorts, tsCanMsgV2*);	

uint8_t  CAN_InitModule(void);
uint8_t  CAN_InitController(teCanPorts eCanPort);
uint8_t  CAN_SetBaudrate(teCanPorts eCanPort, uint32_t u32BTR);
uint8_t  CAN_SetBaudrateEx(teCanPorts eCanPort, uint32_t u32BTR, int1_t bPassive);
uint32_t CAN_GetBaudrate(teCanPorts eCanPort);
uint32_t CAN_AutoDetectBaudrate(teCanPorts eCanPort, int1_t* u1IsExtended);
uint8_t  CAN_Start(teCanPorts eCanPort);
uint8_t  CAN_Stop(teCanPorts eCanPort);
uint8_t  CAN_SendMessage(tsCanMsgV2 *pCanMsg, int1_t bEnsurePortIsOn);
void     CAN_DeleteAllFilters(void);
uint8_t  CAN_AddFilter(teCanPorts eCanPort, uint32_t u32FilterId);
uint8_t  CAN_AddFilterXtd(teCanPorts eCanPort, uint32_t u32FilterId);
uint8_t  CAN_AddFilterGroup(teCanPorts eCanPort, uint32_t u32FilterIdLow, uint32_t u32FilterIdHigh);
uint8_t  CAN_AddFilterGroupXtd(teCanPorts eCanPort, uint32_t u32FilterIdLow, uint32_t u32FilterIdHigh);
uint8_t  CAN_ReceiveAll(void);
uint8_t  CAN_ReceiveNone(void);
uint8_t  CAN_GetFilterStatus(void);
uint8_t  CAN_SetFilterOptions(uint8_t FilterStatus);
uint8_t  CAN_BusOFF(teCanPorts eCanPort);
int1_t   CAN_IsBusOFF(teCanPorts eCanPort);
uint8_t  CAN_BusON(teCanPorts eCanPort);
uint8_t  CAN_GetOperatingMode(teCanPorts eCanPort);
uint8_t  CAN_SetOperatingMode(teCanPorts eCanPort, uint8_t u8Mode);
void     CAN_EnableAutoFlowControl(teCanPorts eCanPort, int1_t bEnable);
teCanBusStatus CAN_GetBusStatus(teCanPorts eCanPort);
void	 CAN_SetSWFilter(teCanPorts eCanPort, CAN_MSG_FILTER_CALLBACK pCallback);

// STP Module ownership
uint8_t  CAN_SetOwner(teCanPorts eCanPort, uint8_t u8Owner);
uint8_t  CAN_GetOwner(teCanPorts eCanPort);

// Debug
#ifdef DEBUG
void    CAN_DebugDump(void);
void    CAN_TestMessage(teCanPorts eCanPort);
#define CAN_REGISTERS   CAN_DebugDump()
#define CAN_TEST(x)     CAN_TestMessage(x)
#else
#define CAN_REGISTERS
#define CAN_TEST(x)
#endif

/*
uint32_t GetBaudrate(uint8_t u8InterfaceNo); 
uint8_t* GetTimeQuanta(uint8_t u8InterfaceNo);
uint8_t*  GetBitTime(uint8_t u8InterfaceNo);
uint8_t*  GetSamplePoint(uint8_t u8InterfaceNo);
uint8_t*  GetTxclk();
uint8_t	  GetSJW(uint8_t u8InterfaceNo);
uint8_t	  GetTseg1(uint8_t u8InterfaceNo);
uint8_t	  GetTseg2(uint8_t u8InterfaceNo);
uint8_t	  GetBTR0(uint8_t u8InterfaceNo);
uint8_t	  GetBTR1(uint8_t u8InterfaceNo);
void SetBaudrate(uint8_t u8InterfaceNo, uint32_t u32NewVal);
*/

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

#ifdef USE_FILTER_RAM
// Structure that defines a filter entry
typedef struct {
	uint32_t ID;        // The message id
	uint32_t	 CanPort;	// The CAN port
}tsFilterEntry;

// Structure that defines a filter entry
typedef struct {
	uint32_t FromID;    // The message id
	uint32_t ToID;      // The message id
	uint32_t CanPort;	// The CAN port
}tsGroupFilterEntry;

#else
// Structure that defines a filter entry
typedef struct {
	uint32_t ID;        // The message id
	uint8_t	 CanPort;	// The CAN port
}tsFilterEntry;

// Structure that defines a filter entry
typedef struct {
	uint32_t FromID;    // The message id
	uint32_t ToID;      // The message id
	uint8_t	 CanPort;	// The CAN port
}tsGroupFilterEntry;

#endif
/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

// Enumeration for the filter status
typedef enum {
  ReceiveNone = 1,
  ReceiveAll,
  FiltersApplied,  
} teFilterStatus;

// Operation modes of the can port
#define	CAN_OP_MODE_NORMAL  0x00	// Normal operating mode
#define	CAN_OP_MODE_RM		0x01	// Reset mode
#define	CAN_OP_MODE_LOM		0x02	// Listen only mode, can only be changed in reset mode
#define	CAN_OP_MODE_STM		0x04	// Self test mode, can only be changed in reset mode
#define	CAN_OP_MODE_TPM		0x08	// Transmit Priority mode, can only be changed in reset mode
#define	CAN_OP_MODE_SM		0x10	// Sleep mode, CAN port sleeps if not busy
#define	CAN_OP_MODE_RPM		0x20	// Dominant bit mode
#define	CAN_OP_MODE_TM		0x80	// Self test mode

// The Tx CAN message queue
xQueueHandle xCanTxMsgQueue;

//The Rx CAN message queue
xQueueHandle xCan1RxMsgQueue;
xQueueHandle xCan2RxMsgQueue;

#endif // CANLPC2000_H







