/********************************************************************
* File:     $Id: ISO9141.h,v 1.4 2010/04/13 15:24:12 Rharvie Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.4 $
* Date:     $Date: 2010/04/13 15:24:12 $
* Author:   $Author: Rharvie $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <ISO9141.c>
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
*   $Log: ISO9141.h,v $
*   Revision 1.4  2010/04/13 15:24:12  Rharvie
*   Fixed strange issue on ISO9141 going randomly into conflict
*
*   Revision 1.3  2010/04/12 15:28:10  Rharvie
*   New code for multiple ECU support
*
*   Revision 1.2  2008/01/29 12:12:21  ACCUTEST\simon
*   Bug fixes
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.4  2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
*   Revision 1.3  2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   Revision 1.2  2007/05/16 10:59:43  ACCUTEST\simon
*   Initial J1979 working code.
*
*   Revision 1.1  2007/04/20 14:14:28  ACCUTEST\simon
*   J1979 in progress
*
*
*********************************************************************
*/

#ifndef ISO9141_MODULE_H
#define ISO9141_MODULE_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required modules
#include "KLine.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define ISO9141_INIT_BAUD_RATE  5u	// 5 bits/s
#define ISO9141_MAX_MSG_LEN     7

// WaitForResponse Return Codes
#define ISO9141_WFR_OK                      0
#define ISO9141_WFR_ERR_TIMEOUT             1
#define ISO9141_WFR_ERR_BUFFER_TOO_SMALL    2
#define ISO9141_WFR_ERR_BAD_CHECKSUM        3
#define ISO9141_WFR_ERR_NO_BUFFER           4
#define ISO9141_WFR_ERR_PHYSCIAL_NOT_AVAIL  5
#define ISO9141_WFR_ERR_INVALID_SEQUENCE    0x21
#define ISO9141_WFR_ERR_NEGATIVE_RESPONSE   0x7F

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

// Module
uint8_t ISO9141_InitModule(void);

// Module Functions
uint8_t ISO9141_Init(uint8_t u8TimingMultiplier);
uint8_t ISO9141_StopComms(void);

uint8_t ISO9141_GetSupportedPIDs(uint32_t *pu32SupportedPIDs, 
                                 uint8_t u8Blocks);

uint8_t ISO9141_AddChecksum(int1_t bEnable);

uint8_t ISO9141_SendRequestRaw(uint8_t *pu8Data, 
                                uint8_t u8DataLength, 
                                uint8_t *pu8ResponseData, 
                                uint8_t *pu8ResponseDataLength,
                                void *pCallback,
                                uint8_t u8RequestID);

uint8_t	ISO9141_SendRequest(uint8_t *pu8Data, 
                            uint8_t u8DataLength, 
                            uint8_t *pu8ResponseData, 
                            uint8_t *pu8ResponseDataLength,
                            uint8_t u8Ecu);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*! ISO9141 message format */
typedef struct {
	uint8_t u8HdrByte1;
    uint8_t u8HdrByte2;
    uint8_t u8SrcAddr;
	uint8_t u8Data[ISO9141_MAX_MSG_LEN];
    uint8_t u8ChkSum;
	uint8_t u8Dlc;
} tsISO9141Msg;

/*! ISO9141 message format */
typedef struct {
	uint8_t u8HdrByte1;
    uint8_t u8HdrByte2;
    uint8_t u8SrcAddr;
	uint8_t u8Data[ISO9141_MAX_MSG_LEN];
    uint8_t u8ChkSum;
	uint8_t u8Dlc;
} tsStpISO9141Msg;
	

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

/*! The Rx ISO9141 message queue */
xQueueHandle xISO9141RxMsgQueue;

#endif /* ISO9141_MODULE_H */







