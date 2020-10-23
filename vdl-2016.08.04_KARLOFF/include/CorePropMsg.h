#ifndef _CORE_PROP_MSG_H_
#define _CORE_PROP_MSG_H_

//------------------------------------------------------------------------------
// INCLUDES                                                         
//------------------------------------------------------------------------------

#include "AvgDefines.h"
#include "CAN.h"
#include "CoreParamEncoding.h"
#include "CoreTypes.h"
#include "FiatMsgs.h"
#include "FordMsgs.h"
#include "GMMsgs.h"
#include "MazdaMsgs.h"
#include "PeugeotMsgs.h"
#include "ToyotaMsgs.h"

//------------------------------------------------------------------------------
// DEFINES                                                          
//------------------------------------------------------------------------------

#define debugDataSlots                          4
#define canDataSize                             8

#define INVALID_REVERSE_METHOD                  (0xFFFF)

#define REVERSE_INDICATOR_CFG_VERSION           1               // Version number for the configuration packet
#define REVERSE_INDICATOR_PACKET_LEN            16              // Size of the config packet in words

#define MAX_BROADCAST_MSG_SIZE                  40              // Message size in bytes

//------------------------------------------------------------------------------
// TYPEDEFS                                                         
//------------------------------------------------------------------------------

// Describes a vehicle bus reverse message method
// !!! NOTE if this configuration structure changes REVERSE_INDICATOR_CFG_VERSION will need to change !!!
typedef struct 
{
    uint16_t methodId;          // Symbolic ID to identify the method
    uint8_t reqRequired;        // 0 - for broadcast messages, 1 for methods requiring a request
    uint8_t reqMode;            // J2190 Mode byte (i.e. Ford uses 0x22 - request by 16 bit PID)
    uint32_t reqId;             // CAN ID used for the request (Typically 0x7E0, PCM physical request address)
    uint32_t reqPid;            // The PID, address or offset for the parameter, tied to J2190 mode 
    uint32_t respId;            // CAN ID of the response (typically 0x7E8, PCM response address
    uint8_t respExpDlc;         // The expected data length count for the response
    uint8_t respOffset;         // The offset of the parameter data in the message
    uint8_t respMask;           // A mask to apply to the byte at the respOffset
    uint8_t respMatchVal;       // The value expected for reverse after applying the mask
}sPropMsgConfiguration;

typedef struct
{
    uint32_t MID;
    uint8_t index;
    uint8_t value[debugDataSlots][canDataSize];
} __attribute__ ((__packed__)) rawBroadcastData;

// CAN broadcast message structure
typedef struct
{
    uint32_t id;                            // CAN ID
    uint8_t dlc;                            // Data length count in bytes
    uint8_t data[MAX_BROADCAST_MSG_SIZE];   // The message data bytes
}sBcastMsg;

//------------------------------------------------------------------------------
// PROTOTYPES                                                       
//------------------------------------------------------------------------------

uint8_t CORE_PropMsgGetRawBroadcastData(uint8_t **buff, uint16_t maxlen);
void CORE_PropMsgBcastProcess(const tsCanMsgV2 *CANMsgRx);
uint32_t CORE_PropMsgGetReverseMsgId(void);
int1_t CORE_PropMsgGetReverseMethod(sPropMsgConfiguration *reverseMethod);
void CORE_PropMsgInit(void);
void CORE_PropMsgSaveConfirmedReverseMethod(sPropMsgConfiguration *method);
void CORE_PropMsgInitBcastFilters(void);
bool CORE_PropGetBcastOdoMethod(DistCalcStatus *odoMethod);
FuelTypes CORE_PropMsgGetFuelType(void);
int1_t CORE_PropMsgGetEngineSize(uint32_t *size);
bool CORE_PropMsgIsPidSupported(uint8_t param);
char * CORE_PropMsgGetConfigFileVersion(void);
void CORE_PropMsgUpdateOdoFilter(void);

#endif
