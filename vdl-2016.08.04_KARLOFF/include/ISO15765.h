/********************************************************************
* File:     $Id: ISO15765.h,v 1.4 2010/04/12 15:28:10 Rharvie Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.4 $
* Date:     $Date: 2010/04/12 15:28:10 $
* Author:   $Author: Rharvie $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <ISO15765.c>
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
*   $Log: ISO15765.h,v $
*   Revision 1.4  2010/04/12 15:28:10  Rharvie
*   New code for multiple ECU support
*
*   Revision 1.3  2008/06/20 08:52:00  ACCUTEST\richard
*   Changed the way CTS messages are sent to match T-SCAN
*
*   Revision 1.2  2008/06/18 12:32:20  ACCUTEST\richard
*   increased timeout value to handle service 9 stuff
*
*   Revision 1.1  2007/10/04 11:41:29  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.5  2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
*   Revision 1.4  2007/06/04 10:50:47  ACCUTEST\simon
*   Added @Road STP module and added more build configurations to solution in
*    order to better manage specific build targets.
*
*   Revision 1.3  2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   Revision 1.2  2007/05/16 10:59:43  ACCUTEST\simon
*   Initial J1979 working code.
*
*   Revision 1.1  2007/04/20 14:14:27  ACCUTEST\simon
*   J1979 in progress
*
*
*********************************************************************
*/

#ifndef ISO15765_MODULE_H
#define ISO15765_MODULE_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required modules
#include "canLPC2000.h"

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define ISO15765_REQUEST_DLC                    8   // bytes in CAN payload
#define ISO15765_RESPONSE_DLC                   8   // bytes in CAN payload

#define TIMING_P2_CAN                           50      // milliseconds - request/response timeout
#define TIMING_P3_CAN                           5000    // milliseconds - request pending

// WaitForResponse Return Codes
#define ISO15765_WFR_OK                         0
#define ISO15765_WFR_ERR_TIMEOUT                1
#define ISO15765_WFR_ERR_BUFFER_TOO_SMALL       2
#define ISO15765_WFR_ERR_INVALID_DLC            3
#define ISO15765_WFR_ERR_NO_BUFFER              4
#define ISO15765_WFR_ERR_PAYLOAD_TOO_BIG        0x10
#define ISO15765_WFR_ERR_INVALID_LENGTH_BYTE    0x20
#define ISO15765_WFR_ERR_INVALID_SEQUENCE       0x21
#define ISO15765_WFR_ERR_NEGATIVE_RESPONSE      0x7F
#define ISO15765_WFR_OK_MULTIFRAME_RESPONSE     0x80    // multi-packet

#define ISO15765_N_PCI_SF                       0x00    // Single Frame
#define ISO15765_N_PCI_FF                       0x10    // First Frame
#define ISO15765_N_PCI_CF                       0x20    // Consecutive Frame
#define ISO15765_N_PCI_FC                       0x30    // Flow Control

// Flow Status (FS)
#define ISO15765_FS_CTS                         0x00
#define ISO15765_FS_WT                          0x01

#define INVALID_MSG_FILTER                      (0xFFFFFFFF)    // Max CAN ID size is 29 bits so this works fine

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

// Module
uint8_t ISO15765_InitModule(void);

// Module Functions
uint8_t ISO15765_Init(teCanPorts eCanPort, int1_t bUseExtendedIDs, uint32_t u32BTR);
uint8_t ISO15765_StopComms(void);

uint8_t ISO15765_SendRequestRaw(uint8_t *pu8Data, 
                                uint8_t u8DataLength, 
                                uint8_t *pu8ResponseData, 
                                uint8_t *pu8ResponseDataLength,
                                void *pCallback,
                                uint8_t u8RequestID);

uint8_t	ISO15765_SendRequest(uint8_t *pu8Data, 
                             uint8_t u8DataLength, 
                             uint8_t *pu8ResponseData, 
                             uint8_t *pu8ResponseDataLength,
                             uint8_t u8Ecu);

void ISO15765_RemoveTrailingBytes(int1_t bRemoveTrailingBytes);
void ISO15765_RemovePCIbyte(int1_t bRemovePCIbyte);
int1_t ISO15765_SetBroadcastFilter(uint32_t canID, uint32_t rate, uint32_t filterIndex);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

// Defines the number and type of broadcast filters for CAN filtering
typedef enum{
    odometerBcastFilter,
    reverseBcastFilter,
    dpfRegenBcastFilter,
    dpfStatusBcastFilter,
    vinBcastFilter1,
    vinBcastFilter2,
    vinBcastFilter3,
    vinBcastFilter4,
    rpmBcastFilter,
    speedBcastFilter,
    mafBcastFilter,
    mapBcastFilter,
    fuelRateBcastFilter,
    loadBcastFilter,
    // ^^^ Insert new types above here ^^^
    maxBcastFilter,
    invalidBcastFilter = 0xFFFF
}eBcastFilterTypes;

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif // ISO15765_MODULE_H







