#ifndef _PEUGEOT_MSG_H_
#define _PEUGEOT_MSG_H_

//------------------------------------------------------------------------------
// INCLUDES                                                         
//------------------------------------------------------------------------------

#include "CAN.h"

//------------------------------------------------------------------------------
// DEFINES                                                          
//------------------------------------------------------------------------------

// Peugeot Message IDs
#define PEUGEOT_BCAST_REVERSE_412           0x412

// Peugeot reverse message 412 definitions
#define PEUGEOT_412_REV_PID                     0
#define PEUGEOT_412_REV_REQ_ID                  0
#define PEUGEOT_412_REV_REQ_REQUIRED            0
#define PEUGEOT_412_REV_REQ_MODE                0
#define PEUGEOT_412_REV_RESP_ID                 PEUGEOT_BCAST_REVERSE_412
#define PEUGEOT_412_REV_RESP_DLC                8
#define PEUGEOT_412_REV_RESP_INDEX              0
#define PEUGEOT_412_REV_RESP_LENGTH             1
#define PEUGEOT_412_REV_RESP_SHIFT              0
#define PEUGEOT_412_REV_RESP_MASK               0x04
#define PEUGEOT_412_REV_RESP_REVERSE_MATCH      0x04
#define PEUGEOT_412_REV_RESP_MULTIPLIER         1
#define PEUGEOT_412_REV_RESP_DIVISOR            1
#define PEUGEOT_412_REV_RESP_OFFSET             0

//------------------------------------------------------------------------------
// TYPEDEFS                                                         
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PROTOTYPES                                                       
//------------------------------------------------------------------------------

#endif
