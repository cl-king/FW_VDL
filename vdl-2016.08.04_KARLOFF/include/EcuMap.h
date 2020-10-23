/********************************************************************
*
* Description:
* ============
*/
/** \file
*	This file contains code to handle multiple ECUs under FMS / J1708
*/ 
/*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2010 Accutest Ltd. All rights reserved.
*********************************************************************
*/

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define ECU_MAP_INVALID_DURATION	0xFFFF

typedef enum {
	EcuMapReset = 0,
    EcuMapJ1587 = 1587,
    EcuMapJ1939 = 1939
}eEcuMapProtocol;

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

int1_t		EcuMap_Reset(eEcuMapProtocol protocol);
int1_t      EcuMap_AddEntry_Ext(eEcuMapProtocol protocol,uint16_t RequestId, uint16_t UpdateRate);
int1_t      EcuMap_UpdateEntry_Ext(eEcuMapProtocol protocol,uint16_t RequestId, uint8_t u8Ecu);
int1_t      EcuMap_NeedUpdate_Ext(eEcuMapProtocol protocol,uint16_t *RequestId, uint8_t *u8Ecu);
int1_t      EcuMap_GetRequestString_Ext(eEcuMapProtocol protocol,uint8_t RequestIndex, char* szString);
uint32_t		EcuMap_GetLastReceiveTime(uint16_t RequestID);
int1_t		EcuMap_WriteMapToFlash(void);
int1_t		EcuMap_ReadMapFromFlash(void);
int1_t		EcuMap_ModifyRequestRate(eEcuMapProtocol protocol, uint16_t RequestId, uint16_t UpdateRate);

int1_t EcuMap_GetRequestString(uint8_t RequestIndex, char* szString);
int1_t EcuMap_StopUpdate(eEcuMapProtocol protocol,uint16_t RequestId);
int1_t EcuMap_GetRequestIdExists(eEcuMapProtocol protocol, uint16_t RequestId);
uint16_t EcuMap_GetRequestRate(eEcuMapProtocol protocol, uint16_t RequestId);
int1_t EcuMap_DoesEcuExist(eEcuMapProtocol protocol, uint8_t u8Ecu);
