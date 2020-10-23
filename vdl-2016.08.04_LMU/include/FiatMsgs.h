#ifndef _FIAT_MSG_H_
#define _FIAT_MSG_H_

//------------------------------------------------------------------------------
// INCLUDES                                                         
//------------------------------------------------------------------------------

#include "CAN.h"

//------------------------------------------------------------------------------
// DEFINES                                                          
//------------------------------------------------------------------------------

// Fiat Message IDs
#define FIAT_BCAST_STATUS_C_ECM_A18A001         0xA18A001
#define FIAT_BCAST_STATUS_C_ECM2_A1CA001        0xA1CA001

// Fiat message A18A001 definitions
#define FIAT_A18A001_REV_PID                    0
#define FIAT_A18A001_REV_REQ_ID                 0
#define FIAT_A18A001_REV_REQ_REQUIRED           0
#define FIAT_A18A001_REV_REQ_MODE               0
#define FIAT_A18A001_REV_RESP_ID                FIAT_BCAST_STATUS_C_ECM_A18A001
#define FIAT_A18A001_REV_RESP_DLC               8
#define FIAT_A18A001_REV_RESP_INDEX             7
#define FIAT_A18A001_REV_RESP_LENGTH            1
#define FIAT_A18A001_REV_RESP_SHIFT             0
#define FIAT_A18A001_REV_RESP_MASK              0x04
#define FIAT_A18A001_REV_RESP_REVERSE_MATCH     0x04
#define FIAT_A18A001_REV_RESP_MULTIPLIER        1
#define FIAT_A18A001_REV_RESP_DIVISOR           1
#define FIAT_A18A001_REV_RESP_OFFSET            0
#define FIAT_STATUS_C_ECM_DLC                   FIAT_A18A001_REV_RESP_DLC
#define FIAT_STATUS_C_ECM_DPF_STS_INDEX         7
#define FIAT_STATUS_C_ECM_DPF_STS_MASK          0x80
#define FIAT_STATUS_C_ECM_DPF_STS_SHIFT         7

// Fiat STATUS_C_ECM2 message A1CA001 definitions
#define FIAT_STATUS_C_ECM2_DLC                  8
#define FIAT_STATUS_C_ECM2_RGN_ON_DEMAND_INDEX  7
#define FIAT_STATUS_C_ECM2_RGN_ON_DEMAND_MASK   0x20
#define FIAT_STATUS_C_ECM2_RGN_ON_DEMAND_SHIFT  5

//------------------------------------------------------------------------------
// TYPEDEFS                                                         
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PROTOTYPES                                                       
//------------------------------------------------------------------------------

void Fiat_BcastStatusCEcm(const tsCanMsgV2 *CANMsgRx);
void Fiat_BcastStatusCEcm2(const tsCanMsgV2 *CANMsgRx);

#endif
