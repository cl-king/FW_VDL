/********************************************************************
* File:     $Id: KLine.h,v 1.7 2010/01/22 14:48:19 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.7 $
* Date:     $Date: 2010/01/22 14:48:19 $
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
*  (C) Copyright 2006 Accutest Ltd. All rights reserved.
*********************************************************************
*
* Revision History
*   $Log: KLine.h,v $
*   Revision 1.7  2010/01/22 14:48:19  richard
*   Build 1.3.0.x.13
*
*   Revision 1.6  2008/11/03 09:32:08  simon
*   Added K-Line timer (based on RTOS tick) functionality.
*
*   Revision 1.5  2008/10/03 08:45:07  simon
*   Added MLG0208 module, Added LED module, Added AT response handlers.
*    changed LED calls.
*
*   Revision 1.4  2008/07/07 09:28:15  ACCUTEST\simon
*   Corrected bug when trying to connect to KWP2000-SLOW using an auto protocol detect.
*    Also requests for SID/PID now removes PID when doing
*    a service 3,4 or 7 request.
*
*   Revision 1.3  2008/06/23 08:52:30  ACCUTEST\richard
*   Added function definition
*
*   Revision 1.2  2008/03/07 14:49:47  ACCUTEST\simon
*   Increased interbyte delay from 5ms to 6ms
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.8  2007/07/13 10:49:50  ACCUTEST\simon
*   Added External UART and MODEC STP modules.
*
*   Revision 1.7  2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
*   Revision 1.6  2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   Revision 1.5  2007/05/16 15:43:22  ACCUTEST\simon
*   Corrected error in ISO9141 SendMessage.
*
*   Revision 1.4  2007/05/16 10:59:44  ACCUTEST\simon
*   Initial J1979 working code.
*
*   Revision 1.3  2007/04/20 14:14:27  ACCUTEST\simon
*   J1979 in progress
*
*   Revision 1.2  2007/03/28 13:13:56  ACCUTEST\paull
*   no message
*
*   Revision 1.1  2007/03/28 12:37:23  ACCUTEST\paull
*   *** empty log message ***
*
*   Revision 1.3  2006/12/21 11:38:43  ACCUTEST\paull
*   style changes
*
*   Revision 1.2  2006/12/01 13:43:54  ACCUTEST\paull
*   Added STP queue message post functionality.
*
*   Revision 1.1  2006/11/29 09:46:43  ACCUTEST\paull
*   First check in of the usb module.
*
*   Revision 1.1  2006/11/27 15:51:56  ACCUTEST\paull
*   Initial checkin of the ARM_AVG module.
*
*
*********************************************************************
*/

#ifndef KLINE_H
#define KLINE_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define KLINE_SLOW_INIT		1
#define KLINE_FAST_INIT		2
#define KLINE_CARB_INIT		3

#define KLINE_BAUD_1200		1200
#define KLINE_BAUD_2400		2400
#define KLINE_BAUD_4800		4800
#define KLINE_BAUD_9600		9600
#define KLINE_BAUD_10400	10400

//
//typedef enum {
//    Connected = 0,		/*!< Connected to selected protocol */
//    ProtocolError,      /*!< Incorrect protocol detected */
//	ConnectError        /*!< Not Connected */
//} eConnStatus;

// KeyByte Information
typedef struct {
    uint8_t KeyByte1;
    uint8_t KeyByte2;
    uint8_t ECUAddress;
} tsKeyByteInfo;

// TIMINGS - see ISO9141-2 - Table A.1 and A.2
// variable timings
typedef struct {
    uint16_t W1_MAX;
    uint16_t W2_MAX; 
    uint16_t W3_MAX;
    uint16_t W4_MIN;
    uint16_t W4_MAX; 
    uint16_t P1_MAX;
    uint16_t P2_MIN;
    uint16_t P3_MIN;
    uint16_t P2_MAX;
    uint16_t P3_MAX;
    uint16_t P4_MAX;
    uint16_t P5_MAX;
    uint16_t ECU_RESET;
    uint16_t KEEPALIVE;
} tsTimings;

// fixed timings
#define KLINE_TIMING_W0_MIN     2UL
#define KLINE_TIMING_W1_MIN     60UL
#define KLINE_TIMING_W3_MIN     0UL
#define KLINE_TIMING_W5_MIN     300UL
#define KLINE_TIMING_P4_MIN     5UL         // interbyte delay

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

/* Module */
uint8_t     KLine_InitModule(void);

/* communication */
uint8_t         KLine_StartComms(uint8_t u8InitType, uint32_t u32Baud, void *pCheckKeyBytesCallback, void *pInitCompleteCallback, uint8_t bUseExtendedTimings, uint8_t u8ExtendTimings);
uint8_t         KLine_StopComms(void);
uint8_t         KLine_SendRequest(uint8_t *pData, uint8_t u8Length);
tsKeyByteInfo*  KLine_GetKeyByteInfo(void);
void            KLine_Enable(int1_t bEnable);

// STP Module ownership
void            KLine_SetOwner(uint8_t u8Owner);
uint8_t         KLine_GetOwner(void);

void            KLine_EnableInterrupt(int1_t bEnable);

// RTOS tick
void            KLine_Tick(void);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

#ifdef __TARGET_PROCESSOR_LPC2129 
/*! KLine state machine */
typedef enum 
{
    KLineState_Success = 0,             // 0
    KLineState_Idle,                    // 1
    KLineState_WaitingForSyncByte,      // 2
    KLineState_WaitingForKeyByte1,      // 3
    KLineState_WaitingForKeyByte2,      // 4
    KLineState_WaitingForECUAddress,    // 5
    KLineState_Error,                   // 6
    KLineState_ResponsePending,         // 7
    KLineState_TimedOut                 // 8

} teKlineState;

typedef enum 
{
    KLineConflict_NORMAL = 0,
    KLineConflict_CONFLICT
} teKlineConflict;

#endif

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

tsTimings Timing;

// The Rx KLINE byte queue
xQueueHandle xKLineRxByteQueue;



#endif // KLINE_H







