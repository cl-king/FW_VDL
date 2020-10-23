/********************************************************************
* File:     $Id: KWP2000.h,v 1.12 2010/04/12 15:28:10 Rharvie Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.12 $
* Date:     $Date: 2010/04/12 15:28:10 $
* Author:   $Author: Rharvie $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <KWP2000.c>
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
*   $Log: KWP2000.h,v $
*   Revision 1.12  2010/04/12 15:28:10  Rharvie
*   New code for multiple ECU support
*
*   Revision 1.11  2009/10/06 09:43:56  richard
*   *** empty log message ***
*
*   Revision 1.10  2009/09/29 14:28:16  simon
*   Added readECUIdentification function
*
*   Revision 1.9  2009/08/25 11:54:39  simon
*   Added define for checksum length
*
*   Revision 1.8  2008/06/24 12:35:19  ACCUTEST\richard
*   Added negative response codes
*
*   Revision 1.7  2008/06/23 08:52:30  ACCUTEST\richard
*   Added function definition
*
*   Revision 1.6  2008/06/20 08:48:07  ACCUTEST\simon
*   Added AT Command interpreter
*
*   Revision 1.5  2008/06/13 14:03:10  ACCUTEST\simon
*   Fixed various compiler warnings
*
*   Revision 1.4  2008/06/09 15:26:21  ACCUTEST\richard
*   Integrated KWP2000 and KWP2000_Vauxhall
*
*   Revision 1.3  2008/05/08 09:43:34  ACCUTEST\simon
*   Bug fixes added Enfora build configuration
*
*   Revision 1.2  2008/01/29 12:12:21  ACCUTEST\simon
*   Bug fixes
*
*   Revision 1.1  2007/10/04 11:41:30  ACCUTEST\simon
*   Relocated from LPC2000 directory with flatter, more sharable, file structure.
*
*   Revision 1.5  2007/08/14 08:37:27  ACCUTEST\simon
*   Added MODEC module, added physical initialization option for J1979, fixed a few minor
*    bugs.
*
*   Revision 1.4  2007/06/21 14:50:30  ACCUTEST\simon
*   Interim development build
*
*   Revision 1.3  2007/05/29 08:53:24  ACCUTEST\simon
*   Fixed various issues with all protocols and added multi-message support.
*
*   Revision 1.2  2007/05/16 10:59:44  ACCUTEST\simon
*   Initial J1979 working code.
*
*   Revision 1.1  2007/04/20 14:14:28  ACCUTEST\simon
*   J1979 in progress
*
*
*********************************************************************
*/

#ifndef KWP2000_MODULE_H
#define KWP2000_MODULE_H

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

#define KWP2000_INIT_BAUD_RATE                  (5u)        // 5 bits/s

#define KWP2000_MAX_REQUEST_LEN                 (8)         // bytes
#define KWP2000_MAX_HEADER_LEN                  (4)         // bytes
#define KWP2000_CHECKSUM_LEN                    (1)         // bytes

//
// TODO : find some ram to get this increased to somewhere near 255 !!!!
//
#ifdef __INCLUDE_VAUXHALL_MODULE
#define KWP2000_MAX_RESPONSE_LEN                (64)        // spec says 255, but we don't have enough RAM !!!
#else
#define KWP2000_MAX_RESPONSE_LEN                (32)        // spec says 255, but we don't have enough RAM !!!
#endif

// WaitForResponse Return Codes
#define KWP2000_WFR_OK                          (0)
#define KWP2000_WFR_ERR_TIMEOUT                 (1)
#define KWP2000_WFR_ERR_BUFFER_TOO_SMALL        (2)
#define KWP2000_WFR_ERR_BAD_CHECKSUM            (3)
#define KWP2000_WFR_ERR_NO_BUFFER               (4)

#define KWP2000_WFR_ERR_INVALID_SEQUENCE        (0x21)
#define KWP2000_WFR_ERR_NEGATIVE_RESPONSE       (0x7F)

// Negative response codes
#define KWP2000_SIDNR_GR                        (0x10)
#define KWP2000_SIDNR_SNS                       (0x11)
#define KWP2000_SIDNR_SFNSIF                    (0x12)
#define KWP2000_SIDNR_BRR                       (0x21)
#define KWP2000_SIDNR_CNCORSE                   (0x22)
#define KWP2000_SIDNR_RCRRP                     (0x78)

#define KWP2000_TESTER_ID                       (0xF1)
#define KWP2000_DEFAULT_ECU_ID_CARB             (0x6A)      // CARB mode
#define KWP2000_DEFAULT_ECU_ID                  (0x33)      // normal mode

// Services
#define KWP2000_SERVICE_J1979_00                (0x00)      // J1979 - Service $00
#define KWP2000_SERVICE_J1979_01                (0x01)      // J1979 - Service $01
#define KWP2000_SERVICE_J1979_02                (0x02)      // J1979 - Service $02
#define KWP2000_SERVICE_J1979_03                (0x03)      // J1979 - Service $03
#define KWP2000_SERVICE_J1979_04                (0x04)      // J1979 - Service $04
#define KWP2000_SERVICE_J1979_05                (0x05)      // J1979 - Service $05
#define KWP2000_SERVICE_J1979_06                (0x06)      // J1979 - Service $06
#define KWP2000_SERVICE_J1979_07                (0x07)      // J1979 - Service $07
#define KWP2000_SERVICE_J1979_08                (0x08)      // J1979 - Service $08
#define KWP2000_SERVICE_J1979_09                (0x09)      // J1979 - Service $09
#define KWP2000_SERVICE_J1979_0A                (0x0A)      // J1979 - Service $0A
#define KWP2000_SERVICE_J1979_0B                (0x0B)      // J1979 - Service $0B
#define KWP2000_SERVICE_J1979_0C                (0x0C)      // J1979 - Service $0C
#define KWP2000_SERVICE_J1979_0D                (0x0D)      // J1979 - Service $0D
#define KWP2000_SERVICE_J1979_0E                (0x0E)      // J1979 - Service $0E
#define KWP2000_SERVICE_J1979_0F                (0x0F)      // J1979 - Service $0F
#define KWP2000_SERVICE_ER                      (0x11)      // ecuReset
#define KWP2000_SERVICE_RFFD                    (0x12)      // readFreezeFrameData
#define KWP2000_SERVICE_RDTC                    (0x13)      // readDiagnosticTroubleCodes
#define KWP2000_SERVICE_CDI                     (0x14)      // clearDiagnosticInformation
#define KWP2000_SERVICE_RSODTC                  (0x17)      // readStatusOfDTC
#define KWP2000_SERVICE_RDTCBS                  (0x18)      // readDTCByStatus
#define KWP2000_SERVICE_REI                     (0x1A)      // readECUIdentification
#define KWP2000_SERVICE_RDBLI                   (0x21)      // readDataByLocalIdentifier
#define KWP2000_SERVICE_TP                      (0x3E)      // testerPresent
#define KWP2000_SERVICE_STC                     (0x81)      // startCommunication
#define KWP2000_SERVICE_SPC                     (0x82)      // stopCommunication
#define KWP2000_SERVICE_ATP                     (0x83)      // accessTimingParameter

// Parameters (applies to services: RDBLI, REI)
#define KWP2000_PARAM_ECUIDT                    (0x80)      // ECU identification table
#define KWP2000_PARAM_ECUIST                    (0x81)      // ECU identification scaling table
#define KWP2000_PARAM_VIN                       (0x90)      // Vehicle identification number
#define KWP2000_PARAM_VMECUHN                   (0x91)      // Vehicle manufacturer ECU hardware number
#define KWP2000_PARAM_SSECUHN                   (0x92)      // System supplier ECU hardware number
#define KWP2000_PARAM_SSECUHVN                  (0x93)      // System supplier ECU hardware version number
#define KWP2000_PARAM_PD                        (0x99)      // Programming date

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

// Module
uint8_t KWP2000_InitModule(void);

// Module Functions
uint8_t KWP2000_Init(uint8_t u8InitType, 
                     uint8_t u8ExtendTimings, 
                     uint8_t u8ECUAddress, 
                     int1_t bPhysicalAddressing);

uint8_t KWP2000_FixHeaders(int1_t bEnable);
uint8_t KWP2000_AddChecksum(int1_t bEnable);

uint8_t KWP2000_StopComms(void);

uint8_t KWP2000_SendRequestRaw(uint8_t *pu8Data, 
                               uint8_t u8DataLength, 
                               uint8_t *pu8ResponseData, 
                               uint8_t *pu8ResponseDataLength,
                               void *pCallback,
                               uint8_t u8RequestID);

uint8_t	KWP2000_SendRequest(uint8_t *pu8Data, 
                            uint8_t u8DataLength, 
                            uint8_t *pu8ResponseData, 
                            uint8_t *pu8ResponseDataLength, 
                            uint8_t u8ExpectedMessageCount,
                            uint8_t u8Ecu);

// KWP2000 Services
uint8_t KWP2000_StartCommunication(uint8_t u8ECUAddress, int1_t bPhysicalAddressing);
uint8_t KWP2000_StopCommunication(void);
uint8_t KWP2000_AccessTimingParameter(void);
uint8_t KWP2000_SendData(void);
uint8_t KWP2000_TesterPresent(void);
uint8_t KWP2000_ReadECUIdentification(uint8_t u8IdentificationOption);
uint8_t KWP2000_ReadDataByLocalIdentifier(uint8_t u8Identifier);
void    KWP2000_GetResponseBufferInfo(uint8_t **ppu8Buffer, uint8_t *pu8BufferLength);
void    KWP2000_SetMaximumResponseLength(uint8_t u8Length);
uint8_t KWP2000_ReadStatusOfDTC(uint8_t* pu8NumberOfStoredDTCs);
uint8_t KWP2000_ClearDiagnosticInformation(void);
int1_t	KWP2000_GetAndStoreVIN(void);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

/*! The Rx KWP2000 message queue */
xQueueHandle xKWP2000RxMsgQueue;

#endif // KWP2000_MODULE_H







