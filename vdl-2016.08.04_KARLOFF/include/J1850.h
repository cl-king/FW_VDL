/********************************************************************
* File:     $Id: J1850.h,v 1.3 2010/04/12 15:28:10 Rharvie Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.3 $
* Date:     $Date: 2010/04/12 15:28:10 $
* Author:   $Author: Rharvie $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <J1850.c>
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
*   $Log: J1850.h,v $
*   Revision 1.3  2010/04/12 15:28:10  Rharvie
*   New code for multiple ECU support
*
*   Revision 1.2  2008/09/23 09:27:50  richard
*   New J1850 functions to help with transit simulation
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.2  2007/07/05 08:11:32  ACCUTEST\simon
*   Added J1850 (PWM) protocol support. (Uses AVG500L-J1850 expansion board).
*
*   Revision 1.1  2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
*
*********************************************************************
*/

#ifndef J1850_MODULE_H
#define J1850_MODULE_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required modules

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define J1850_INIT_BAUD_RATE              5u	// 5 bits/s
#define J1850_MAX_MSG_LEN                 7

// WaitForResponse Return Codes
#define J1850_WFR_OK                      0
#define J1850_WFR_ERR_TIMEOUT             1
#define J1850_WFR_ERR_BUFFER_TOO_SMALL    2
#define J1850_WFR_ERR_BAD_CHECKSUM        3
#define J1850_WFR_ERR_NO_BUFFER           4

#define J1850_WFR_ERR_INVALID_SEQUENCE    0x21
#define J1850_WFR_ERR_NEGATIVE_RESPONSE   0x7F

#define J1850_MODE_PWM                    0
#define J1850_MODE_VPW                    1

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

// Module
uint8_t J1850_InitModule(void);

// Module Functions
uint8_t J1850_Init(uint8_t u8Mode, uint8_t u8ExtendTimings);
uint8_t J1850_StopComms(void);
uint8_t J1850_GetChkSum(uint8_t *pData, uint16_t u16Size);

uint8_t J1850_GetSupportedPIDs(uint32_t *pu32SupportedPIDs, 
                                 uint8_t u8Blocks);

uint8_t J1850_SendRequestRaw(uint8_t *pu8Data, 
                                uint8_t u8DataLength, 
                                uint8_t *pu8ResponseData, 
                                uint8_t *pu8ResponseDataLength,
                                void *pCallback,
                                uint8_t u8RequestID);

uint8_t	J1850_SendRequest(uint8_t *pu8Data, 
                            uint8_t u8DataLength, 
                            uint8_t *pu8ResponseData, 
                            uint8_t *pu8ResponseDataLength,
                            uint8_t u8ExpectedMessageCount,
                            uint8_t u8Ecu);

uint8_t J1850_SendRawData(uint8_t *pu8Data, 		
                               uint8_t u8DataLength);

uint8_t J1850_GetRawData(      uint8_t *pu8ResponseData, 	
                               uint8_t *pu8ResponseDataLength,
                               void *pCallback,		
                               uint8_t u8RequestID,
                               uint32_t u32Timeout);	

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*! J1850 message format */
typedef struct {
	uint8_t u8HdrByte1;
    uint8_t u8HdrByte2;
    uint8_t u8SrcAddr;
	uint8_t u8Data[J1850_MAX_MSG_LEN];
    uint8_t u8ChkSum;
	uint8_t u8Dlc;
} tsJ1850Msg;

/*! J1850 message format */
typedef struct {
	uint8_t u8HdrByte1;
    uint8_t u8HdrByte2;
    uint8_t u8SrcAddr;
	uint8_t u8Data[J1850_MAX_MSG_LEN];
    uint8_t u8ChkSum;
	uint8_t u8Dlc;
} tsStpJ1850Msg;
	

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

/*! The Rx J1850 message queue */
xQueueHandle xJ1850RxMsgQueue;

#endif /* J1850_MODULE_H */







