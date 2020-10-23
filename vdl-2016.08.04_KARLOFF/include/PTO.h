
#ifndef __PTO_H
#define __PTO_H

/********************************************************************
*
* Description:
* ============
*
*   Interfaces for PTO(Power Take-Off) processing
*
*--------------------------------------------------------------------
*
*
*********************************************************************
*  (C) Copyright 2010 Trimble MRM Ltd. All rights reserved.
*********************************************************************
*/

/*------------------------------------------------------------------*/
/* INCLUDES 														*/
/*------------------------------------------------------------------*/

#include "types.h"
#ifndef KARLOFF
#include "GeoManager.h"
#endif

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#define PTO_SW3_STATE (gbSW3_State)
#define PTO_SW4_STATE (gbSW4_State)

#define PTO_SW3_ND_STATE (IO_DigitalInput(PTO_SW3)) // non-debounced state
#define PTO_SW4_ND_STATE (IO_DigitalInput(PTO_SW4))

#define Get_PTO_SW3_Mode()  (GM_Config.PTO_SW3_Settings&0x0F)
#define Get_PTO_SW4_Mode()  (GM_Config.PTO_SW4_Settings&0x0F)

#define Get_PTO_SW3_DebounceTime()  ((uint8_t)(GM_Config.PTO_SW3_Settings>>8))
#define Get_PTO_SW4_DebounceTime()  ((uint8_t)(GM_Config.PTO_SW4_Settings>>8))

#define Get_PTO_SW3_FunctionCode()  ((uint8_t)(GM_System.PTO_SW_FunctionCode>>16))
#define Get_PTO_SW4_FunctionCode()  ((uint8_t)(GM_System.PTO_SW_FunctionCode&0xFFFF))

#define Get_PTO_SW3_NegHoldOffTime()  ((uint8_t)(GM_System.PTO_SW_NegativeHoldOff>>16))
#define Get_PTO_SW4_NegHoldOffTime()  ((uint8_t)(GM_System.PTO_SW_NegativeHoldOff&0xFFFF))

#define PTO_SW4 (1) //DIN1 -> Channel #1
#define PTO_SW3 (2) //DIN2 -> Channel #2

#define PTO_SWITCH3 (3)
#define PTO_SWITCH4 (4)
/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/
void   GM_PTO_Init( void );
void   GM_Process_PTO( void );
#ifndef KARLOFF
void   GM_PTO_SetGeoManagerConfigParam( uint8_t u8ConfParam, uint16_t u16ConfVal );
int1_t GM_PTO_Handle_PTOSwitchSettingsPacket( uint8_t u8PacketID, 
                                              uint16_t u16Packetlength, 
                                              gmIP* pstRespAddr );
#endif

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

/* Used to allocate memory */
#ifdef PTO_DEFINE_GLOBAL_VAR
       #define PTO_EXTERN
#else
       #define PTO_EXTERN extern
#endif

PTO_EXTERN  int1_t gbSW3_State;
PTO_EXTERN  int1_t gbSW4_State;




#endif // __PTO_H

