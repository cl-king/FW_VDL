/********************************************************************
* File:     $Id: J1939.h,v 1.9 2009/11/30 16:57:19 richard Exp $
* Project:  AVG - Accutest Vehicle Gateway
* version:  $Revision: 1.9 $
* Date:     $Date: 2009/11/30 16:57:19 $
* Author:   $Author: richard $
*
********************************************************************
*
* Description:
* ============
*/
/** \file
*	Provides header file information for module <J1979.c>
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
*   $Log: J1939.h,v $
*   Revision 1.9  2009/11/30 16:57:19  richard
*   Combined all vehicle protocols.
*   Added FIFO test
*
*   Revision 1.8  2009/03/11 15:04:30  accutest\colin
*   Added Connection Management and Data Transfer Broadcast PGN as macro
*
*   Revision 1.7  2008/10/10 13:14:10  simon
*   Added J1939_PGN_XXXXX macros and created psudo macros for non-standard existing macros.
*
*   Revision 1.6  2008/09/08 11:02:40  richard
*   *** empty log message ***
*
*   Revision 1.5  2008/08/05 11:11:38  ACCUTEST\richard
*   Added send PGN command
*
*   Revision 1.4  2008/07/18 08:08:38  ACCUTEST\richard
*   Added J1939 PGN filters, and Request PGN functions
*
*   Revision 1.3  2008/06/13 14:03:10  ACCUTEST\simon
*   Fixed various compiler warnings
*
*   Revision 1.2  2007/12/10 17:00:23  ACCUTEST\simon
*   Added standard J1939 defines
*
*   Revision 1.1  2007/10/26 14:00:32  ACCUTEST\simon
*   *** empty log message ***
*
*
*********************************************************************
*/

#ifndef J1939_H
#define J1939_H

/*------------------------------------------------------------------*/
/* INCLUDES                                                         */
/*------------------------------------------------------------------*/

// AVG specific definitions
#include "AvgDefines.h"

// Required Modules
#include "canLPC2000.h"     // CAN

/*------------------------------------------------------------------*/
/* DEFINES                                                          */
/*------------------------------------------------------------------*/

#if (J1939_DEBUG == 1)
#define J1939_TRACE(...)  MODULE_TRACE("J1939", __VA_ARGS__)
#else
#define J1939_TRACE(...) 
#endif

#define J1939_MAX_REQUEST_LEN           8
#define J1939_MAX_RESPONSE_LEN          64  // caters for general multiframe data

#define J1939_MSG_LENGTH                5
#define J1939_DATA_LENGTH               8

#define J1939_MAX_MSG_LENGTH			1785 // Max message length as defined by J1939
#define J1939_MAX_MSG_SEGMENTS			255  // Max number of message segments defined by J1939

#define J1939_TESTER_ADDRESS			0xF9

// J1939 Default Priorities
#define J1939_CONTROL_PRIORITY			0x03
#define J1939_INFO_PRIORITY				0x06
#define J1939_PROPRIETARY_PRIORITY		0x06
#define J1939_REQUEST_PRIORITY			0x06
#define J1939_ACK_PRIORITY				0x06
#define J1939_TP_CM_PRIORITY			0x07
#define J1939_TP_DT_PRIORITY			0x07

// J1939 Defined Addresses
#define J1939_ENGINE_1_ADDRESS			0
#define J1939_ENGINE_2_ADDRESS			1
#define J1939_BRAKE_CONTROLLER_ADDRESS	11
#define J1939_CRUISE_CONTROL_ADDRESS	17
#define J1939_BODY_CONTROLLER_ADDRESS	33
#define J1939_OFF_BOARD_DIAG_1_ADDRESS  249
#define J1939_NULL_ADDRESS				254
#define J1939_GLOBAL_ADDRESS			255

// Address used by the Trimble device
#define J1939_DIAG_TOOL_ADDRESS         J1939_OFF_BOARD_DIAG_1_ADDRESS

// Some J1939 PDU Formats, Control Bytes, and PGN's
#define J1939_PF_DM22                       195
#define J1939_PF_REQUEST2					201
#define J1939_PF_TRANSFER					202
#define J1939_PF_ACKNOWLEDGMENT				232
#define J1939_ACK_CONTROL_BYTE				0
#define J1939_NACK_CONTROL_BYTE				1
#define J1939_ACCESS_DENIED_CONTROL_BYTE	2
#define J1939_CANNOT_RESPOND_CONTROL_BYTE	3
#define J1939_PF_REQUEST					234
#define J1939_PF_DT							235		// Data Transfer message
#define J1939_PF_TP_CM						236		// Connection Management message
#define J1939_PF_CM_BAM						236		// Connection Management message (old label)
#define J1939_RTS_CONTROL_BYTE				16		// Request to Send control byte of CM message
#define J1939_CTS_CONTROL_BYTE				17		// Clear to Send control byte of CM message
#define J1939_EOMACK_CONTROL_BYTE			19		// End of Message control byte of CM message
#define J1939_BAM_CONTROL_BYTE				32		// BAM control byte of CM message
#define J1939_CONNABORT_CONTROL_BYTE		255		// Connection Abort control byte of CM message
#define J1939_PGN2_REQ_ADDRESS_CLAIM		0x00
#define J1939_PGN1_REQ_ADDRESS_CLAIM		0xEA
#define J1939_PGN0_REQ_ADDRESS_CLAIM		0x00
#define J1939_PGN2_COMMANDED_ADDRESS		0x00
#define J1939_PGN1_COMMANDED_ADDRESS		0xFE	// (-81 PDU Format)
#define J1939_PGN0_COMMANDED_ADDRESS		0xD8	// (-81 PDU Specific)
#define J1939_PF_ADDRESS_CLAIMED			238		// With global address
#define J1939_PF_CANNOT_CLAIM_ADDRESS		238		// With null address
#define J1939_PF_PROPRIETARY_A				239
#define J1939_PF_PROPRIETARY_B				255

#define J1939_PGN_TP_CONNECTION_MANAGEMENT  0xECFF  /* As above but as broadcast */
#define J1939_PGN_TP_DATA_TRANSFER          0xEBFF  /* As above but as broadcast */

// standard PGN's (using standard ID's as defined in J1939-71, sorted by PGN number)
#define J1939_PGN_TSC1                      0x0000
#define J1939_PGN_TC1                       0x0100
#define J1939_PGN_XBR                       0x0400
#define J1939_PGN_DM22                      0xC3F9 // F9 is the address of TVG850 which uses OBDII
#define J1939_PGN_CM1                       0xE000
#define J1939_PGN_GLOBAL_ACK				0xE8FF
#define J1939_PGN_RM                        0xEAFE
#define J1939_PGN_ADDRESSCLAIM              0xEEFF
#define J1939_PGN_ERC1                      0xF000
#define J1939_PGN_EBC1                      0xF001
#define J1939_PGN_ETC1                      0xF002
#define J1939_PGN_EEC2						0xF003      // Electronic Engine Controller 2
#define J1939_PGN_EEC1						0xF004      // Electronic Engine Controller 1
#define J1939_PGN_ETC2                      0xF005
#define J1939_PGN_VDC2						0xF009  //Vehicle Dynamic Stability Control 2
#define J1939_PGN_ACCS						0xF02D // Acceleration Sensor
#define J1939_PGN_DPFC						0xFD7C  // Diesel Particulate Filter Control 1              
#define J1939_PGN_EEC6						0xFDA3      // Electronic Engine Controller 6
#define J1939_PGN_PTODE						0xFDA4      // PTO Drive Engagement
#define J1939_PGN_ET3						0xFE69
#define J1939_PGN_TCO1						0xFE6C
#define J1939_PGN_ACC1						0xFE6F
#define J1939_PGN_IT6						0xFE87
#define J1939_PGN_EI						0xFE92		// engine information
#define J1939_PGN_LFI                       0xFEB3  // Fuel Information(Liquid)
#define J1939_PGN_WSI                       0xFEBF // Wheel Speed Information
#define J1939_PGN_SERV					    0xFEC0
#define J1939_PGN_VDHR						0xFEC1
#define J1939_PGN_DM1						0xFECA      // DM1
#define J1939_PGN_DM2						0xFECB      // DM2
#define J1939_PGN_DM3						0xFECC      // DM3
#define J1939_PGN_CA                        0xFED8
#define J1939_PGN_DM5						0xFECE      // DM5
#define J1939_PGN_SOFT						0xFEDA
#define J1939_PGN_IO						0xFEDC
#define J1939_PGN_EEC3						0xFEDF      // Electronic Engine Controller 3
#define J1939_PGN_VD						0xFEE0
#define J1939_PGN_HOURS						0xFEE5
#define J1939_PGN_TD						0xFEE6
#define J1939_PGN_VH						0xFEE7
#define J1939_PGN_VDS						0xFEE8
#define J1939_PGN_LFC						0xFEE9      // Fuel Consumption (Liquid)
#define J1939_PGN_VW                        0xFEEA      // Vehicle Weight
#define J1939_PGN_CI                        0xFEEB      // Component Identification
#define J1939_PGN_VI                        0xFEEC      // Vehicle Identification
#define J1939_PGN_CCSS                      0xFEED      // Cruise Control/Vehicle Speed Setup
#define J1939_PGN_ET1						0xFEEE      // Engine Temperature 1
#define J1939_PGN_EFLP						0xFEEF		// ENGINE FLUID LEVEL/PRESSURE
#define J1939_PGN_PTO						0xFEF0      // Power Takeoff Information
#define J1939_PGN_CCVS						0xFEF1      // Cruise Control/Vehicle Speed
#define J1939_PGN_LFE                       0xFEF2      // Fuel Economy (Liquid)
#define J1939_PGN_VP                        0xFEF3      // Vehicle Position
#define J1939_PGN_TIRE                      0xFEF4      // Tire Condition
#define J1939_PGN_AC						0xFEF5		// AMBIENT CONDITIONS
#define J1939_PGN_IC1						0xFEF6      // Inlet/Exhaust Conditions 1
#define J1939_PGN_VEP1						0xFEF7      // Vehicle Electrical Power 1
#define J1939_PGN_TF						0xFEF8		// TRANSMISSION FLUIDS
#define J1939_PGN_AI						0xFEF9      // Axle Information
#define J1939_PGN_B                         0xFEFA      // Brakes
#define J1939_PGN_DD						0xFEFC      // Dash Display
#define J1939_PGN_EGF1                      0xF00A      // Engine Gas Flow Rate

// proprietory PGN's
#define J1939_PGN_PROP_A                    0xEF00

// derrived PGN's (using psudo ID's ... try not to use these !!!!! use the standard ones above.)
#define J1939_PGN_TEMP						(J1939_PGN_ET1)
#define J1939_PGN_SERVICE					(J1939_PGN_SERV)
#define J1939_PGN_HRVD						(J1939_PGN_VDHR)
#define J1939_PGN_FUEL						(J1939_PGN_LFC)
#define J1939_PGN_WEIGHT                    (J1939_PGN_VW)
#define J1939_PGN_VEHICLEID					(J1939_PGN_VI)
#define J1939_PGN_LFE_EMS					(J1939_PGN_LFE)
#define J1939_PGN_DASH                      (J1939_PGN_DD)

#define J1939_PGN_MASK                      0x03FFFF00  // CAN ID bits 8 to 25

#define J1939_MAX_PGN_FILTERS				40

// Definitions for assembling a J1939 PDU1 message ID
#define PDU1_SA(sa)                         ((uint32_t)((sa) & 0xFF))                 // Source address is bits 0-7
#define PDU1_DA(da)                         ((uint32_t)((da) & 0xFF) << 8)            // Destination address is bits 8-15
#define PDU1_PF(pf)                         ((uint32_t)((pf) & 0xFF) << 16)           // PDU format is bits 16-23
#define PDU1_PRI(priority)                  ((uint32_t)((priority) & 0x07) << 26)     // Message priority is bits 26-28, note bits 24 and 25 are 0 for PDU1
#define J1939_PDU1(priority, pf, da, sa)    ((uint32_t)(PDU1_PRI((priority)) | PDU1_PF((pf)) | PDU1_DA((da)) | PDU1_SA((sa))))

/*------------------------------------------------------------
 J1939 PGN EEC1 defintions
*/

// SPN offsets
#define J1939_EEC1_TORQUE_INDEX                 (0)
#define J1939_EEC1_DRIVER_DEMAND_TORQUE_INDEX   (1)
#define J1939_EEC1_ACTUAL_TORQUE_INDEX          (2)
#define J1939_EEC1_ENGINE_SPEED_INDEX           (3)
#define J1939_EEC1_SRC_ADDR_INDEX               (5)
#define J1939_EEC1_STARTER_MODE_INDEX           (6)
#define J1939_EEC1_ENGINE_DEMAND_TORQUE_INDEX   (7)

// Engine speed definitions
#define J1939_EEC1_ENGINE_SPEED_LENGTH          (2)             // Bytes
#define J1939_EEC1_ENGINE_SPEED_MASK            (0xFFFF)        // Bit mask
#define J1939_EEC1_ENGINE_SPEED_SHIFT           (0)             // Bit shift
#define J1939_EEC1_ENGINE_SPEED_RES             (0.125L)        // Resolution
#define J1939_EEC1_ENGINE_SPEED_VALID_LIMIT     (8031.875L)     // Max allowed

//--- End PGN EEC1

/*------------------------------------------------------------
 J1939 PGN DM22 Individual clear of active and previously active DTC
*/

// Message offsets
#define J1939_DM22_DTC_CONTROL_BYTE_INDEX       (0)
#define J1939_DM22_RESERVED_1_INDEX             (1)
#define J1939_DM22_RESERVED_2_INDEX             (2)
#define J1939_DM22_RESERVED_3_INDEX             (3)
#define J1939_DM22_RESERVED_4_INDEX             (4)
#define J1939_DM22_SPN_LSB_INDEX                (5)
#define J1939_DM22_SPN_MID_INDEX                (6)
#define J1939_DM22_SPN_MSB_FMI_INDEX            (7)

#define J1939_DM22_DATA_LENGTH_COUNT            (8)
#define J1939_DM22_RESERVED_FILL_BYTE           (0xFF)

#define J1939_DM22_SPN_LSB(pgn)                 ((uint8_t)((pgn) & 0xFF))
#define J1939_DM22_SPN_MID(pgn)                 ((uint8_t)(((pgn) >> 8) & 0xFF))
#define J1939_DM22_SPN_MSB_FMI(pgn,fmi)         ((uint8_t)(((((pgn) >> 16) & 0x07) << 5) | ((fmi) & 0x1F)))

//----End PGN DM22

/*------------------------------------------------------------------*/
/* PROTOTYPES                                                       */
/*------------------------------------------------------------------*/

uint8_t J1939_InitModule(void);
int1_t  J1939_ProcessMessage(tsCanMsgV2 *pCANMsg);
void    J1939_SendMessage(tsCanMsgV2 *pCANMsg);
int1_t  J1939_ProcessPGN(uint32_t u32PGN, tsCanMsgV2 *pCANMsg);

int1_t	J1939_SetFilter(uint8_t u8Filter, uint16_t u16PGN);
void	J1939_EnableFilters(int1_t bEnable);
void 	J1939_ClearFilters(void);

int1_t	J1939_DecodePgn(tsCanMsgV2 *pCANMsg, uint16_t *u16PGN, uint8_t *u8Src, uint8_t **data);
int1_t	J1939_RequestPGN(uint16_t u16PGN);
int1_t J1939_SendPGN(uint16_t u16PGN, uint8_t dest, uint8_t port);
int1_t  J1939_IsPGNOnRequest(uint16_t u16PGN);

/*------------------------------------------------------------------*/
/* TYPEDEFS                                                         */
/*------------------------------------------------------------------*/

// J1939 message type
typedef enum {
    J1939MsgType_Request            = 0,    // service/pid request from external module
	J1939MsgType_Response           = 1,    // external response
	J1939MsgType_Status             = 2,    // internal status report
    J1939MsgType_Information        = 3,    // internal information
    J1939MsgType_ResponseRaw        = 4,    // raw request from external module
    J1939MsgType_InternalRequest    = 5,    // service/pid request from internal module
    J1939MsgType_InternalResponse   = 6     // internal response
} teJ1939MsgType;

// J1939 message
typedef struct {
    teJ1939MsgType eJ1939MsgType;
    uint8_t u8Data[J1939_MAX_RESPONSE_LEN];
    uint8_t u8Dlc;
    uint8_t u8ChkSum;
} tsJ1939Msg;

struct J1939_MESSAGE_ID {
	unsigned char	SourceAddress;
	unsigned char	PDUSpecific;
	unsigned char	PDUFormat;					// CA should use only PDUFormat.
	unsigned int	DataPage			: 1;
	unsigned int	Reserved            : 1;
	unsigned int	Priority			: 3;
	unsigned int	Unused              : 3;
};

union J1939_ID_UNION {
	struct J1939_MESSAGE_ID	Id;
	uint32_t mId;
};

typedef union J1939_ID_UNION tuJ1939MessageId;

struct J1939_FLAG_STRUCT {
	unsigned int	CannotClaimAddress				: 1;
	unsigned int	WaitingForAddressClaimContention: 1;
	unsigned int	GettingCommandedAddress			: 1;
	unsigned int	GotFirstDataPacket				: 1;
	unsigned int	ReceivedMessagesDropped			: 1; 
};

union J1939_FLAGS_UNION {
	struct J1939_FLAG_STRUCT	Flags;
	unsigned char				FlagVal; };

typedef union J1939_FLAGS_UNION tuJ1939Flags;


struct J1939_TPCM_16 {
    uint8_t unused0;
    uint16_t TotalMessageSize;
    uint8_t TotalNumberOfPackets;
    uint8_t MaximumNumberOfPackets;
    uint8_t unused1;
    uint8_t unused2;
    uint8_t unused3;
};

struct J1939_TPCM_17 {
    uint8_t unused0;
    uint8_t NumberOfPacketsThatCanBeSent;
    uint8_t NextPacketNumberToBeSent;
    uint8_t unused1;
    uint8_t unused2;
    uint8_t unused3;
    uint8_t unused4;
    uint8_t unused5;
};

struct J1939_TPCM_19 {
    uint8_t unused0;
    uint16_t TotalMessageSizeEoMA;
    uint8_t TotalNumberOfPacketsEoMA;
    uint8_t unused1;
    uint8_t unused2;
    uint8_t unused3;
    uint8_t unused4;
};

struct J1939_TPCM_32 {
    uint8_t unused0;
    uint8_t unused1;
    uint8_t unused2;
    uint8_t TotalNumberOfPacketsBAM;
    uint16_t TotalMessgaeSizeBAM;
    uint8_t unused3;
    uint8_t unused4;
};

struct J1939_TPCM_255 {
    uint8_t unused0;
    uint8_t ConnectionAbortReason;
    uint8_t unused2;
    uint8_t unused3;
    uint8_t unused4;
    uint8_t unused5;
    uint8_t unused6;
    uint8_t unused7;
};

union J1939_TPCM_UNION {
	struct J1939_TPCM_16	ControlByte16;
	struct J1939_TPCM_17	ControlByte17;
	struct J1939_TPCM_19	ControlByte19;
	struct J1939_TPCM_32	ControlByte32;
	struct J1939_TPCM_255	ControlByte255;
};

typedef union J1939_TPCM_UNION tuTPCM;

// J1939 DM22 INDIVIDUAL DTC CLEAR/RESET CONTROL BYTE
typedef enum {
	J1939DM22Reserved						 = 0,   
	J1939DM22ClearPreviousActiveFaultRequest = 1,   
	J1939DM22ClearPreviousActiveFaultACK	 = 2,   
	J1939DM22ClearPreviousActiveFaultNACK	 = 3,   
	J1939DM22ClearActiveFaultRequest		 = 17,   
	J1939DM22ClearActiveFaultACK			 = 18,   
	J1939DM22ClearActiveFaultNACK			 = 19 
} tuJ1939DM22ControlByte;

// J1939 DM22 NEGATIVE ACKNOWLEDGE INDICATORS FOR INDIVIDUAL DTC CLEAR
typedef enum {
	J1939DM22GeneralNACK					 = 0,   
	J1939DM22AccessDenied					 = 1,   
	J1939DM22DTCUnknown						 = 2,   
	J1939DM22DTCNoLongerPreviousActive		 = 3,   
	J1939DM22NoLongerActive					 = 4,   
} tuJ1939DM22ControlByteIndicator;

/*------------------------------------------------------------------*/
/* GLOBALS                                                          */
/*------------------------------------------------------------------*/

#endif // J1939_H



