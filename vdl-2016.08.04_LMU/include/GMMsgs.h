#ifndef _GM_MSGS_H_
#define _GM_MSGS_H_

//------------------------------------------------------------------------------
// INCLUDES                                                         
//------------------------------------------------------------------------------

#include "AvgDefines.h"
#include "CAN.h"

//------------------------------------------------------------------------------
// DEFINES                                                          
//------------------------------------------------------------------------------

// GM broadcast CAN IDs
#define GM_BCAST_C9                             0xC9        // Broadcast RPM value , typically 10ms
#define GM_BCAST_F9                             0xF9        // Broadcast speed value, typically 12ms
#define GM_BCAST_120                            0x120       // Broadcast odometer value, typically 5 seconds
#define GM_BCAST_1EF                            0x1EF       // Broadcast MAF value, typically 10 seconds
#define GM_BCAST_TRANS_1F5                      0x1F5       // Broadcast transmission info, typically 25 ms
#define GM_BCAST_VIN2_4E1                       0x4E1       // Broadcast of last 8 chars of the VIN, typically 1000 ms
#define GM_BCAST_VIN1_514                       0x514       // Broadcast of first 8 chars of the VIN, leading country char missing

// GM 0xC9 message definitions
#define GM_C9_REQ_REQUIRED                      0
#define GM_C9_REQ_MODE                          0
#define GM_C9_REQ_ID                            0
#define GM_C9_REQ_PID                           0
#define GM_C9_RESP_ID                           GM_BCAST_C9
#define GM_C9_RESP_DLC                          8           // Length of a valid RPM message
#define GM_C9_RPM_SCALING                       0.25        // Resolution is 1/4 RPM
#define GM_C9_RPM_INDEX                         1           // RPM starts at byte offset 1
#define GM_C9_RPM_LENGTH                        2           // RPM is two bytes in length
#define GM_C9_RPM_SHIFT                         0
#define GM_C9_RPM_MATCH_VAL                     0
#define GM_C9_RPM_MASK                          0xFFFF
#define GM_C9_RPM_MULTIPLIER                    1
#define GM_C9_RPM_DIVISOR                       4
#define GM_C9_RPM_OFFSET                        0

// GM 0xF9 message definitions
#define GM_F9_REQ_REQUIRED                      0
#define GM_F9_REQ_MODE                          0
#define GM_F9_REQ_ID                            0
#define GM_F9_REQ_PID                           0
#define GM_F9_RESP_ID                           GM_BCAST_F9
#define GM_F9_RESP_DLC                          8           // Length of a valid speed message
#define GM_F9_SPEED_SCALING                     (3.6/100.0) // Resolution is m/s * 100, convert to k/h
#define GM_F9_SPEED_INDEX                       3           // Speed starts at byte offset3
#define GM_F9_SPEED_LENGTH                      2           // Speed is two bytes in length
#define GM_F9_SPEED_SHIFT                       0
#define GM_F9_SPEED_MATCH_VAL                   0
#define GM_F9_SPEED_MASK                        0xFFFF
#define GM_F9_SPEED_MULTIPLIER                  36
#define GM_F9_SPEED_DIVISOR                     1000
#define GM_F9_SPEED_OFFSET                      0

// GM 0x120 odometer method constants
#define GM_120_REQ_REQUIRED                     0
#define GM_120_REQ_MODE                         0
#define GM_120_REQ_ID                           0
#define GM_120_REQ_PID                          0
#define GM_120_RESP_ID                          GM_BCAST_120
#define GM_120_RESP_DLC                         5           // Length of a valid GM 120 odometer message
#define GM_120_ODOMETER_SCALING                 0.015625    // scale factor for a GM 120 odometer message, 1/64 of km
#define GM_120_ODOMETER_INDEX                   0
#define GM_120_ODOMETER_LENGTH                  4
#define GM_120_ODOMETER_SHIFT                   0
#define GM_120_ODOMETER_MATCH_VAL               0
#define GM_120_ODOMETER_MASK                    0xFFFFFFFF
#define GM_120_ODOMETER_MULTIPLIER              1
#define GM_120_ODOMETER_DIVISOR                 64
#define GM_120_ODOMETER_OFFSET                  0

// GM 0x1EF message defintions
#define GM_1EF_REQ_REQUIRED                     0
#define GM_1EF_REQ_MODE                         0
#define GM_1EF_REQ_ID                           0
#define GM_1EF_REQ_PID                          0
#define GM_1EF_RESP_ID                          GM_BCAST_1EF
#define GM_1EF_RESP_DLC                         4           // Length of a valid GM 1EF MAF message
#define GM_1EF_MAF_SCALING                      0.01        // Scaled by 100
#define GM_1EF_1_MAF_INDEX                      2           // MAF starts at byte offset 2
#define GM_1EF_MAF_LENGTH                       2           // MAF is two bytes in length
#define GM_1EF_MAF_SHIFT                        0
#define GM_1EF_MAF_MATCH_VAL                    0
#define GM_1EF_MAF_MASK                         0xFFFF
#define GM_1EF_MAF_MULTIPLIER                   1
#define GM_1EF_MAF_DIVISOR                      100
#define GM_1EF_MAF_OFFSET                       0

// GM Transmission message 0x1F5 definitions
#define GM_1F5_TRANS_REQ_REQUIRED               0
#define GM_1F5_TRANS_REQ_MODE                   0
#define GM_1F5_TRANS_REQ_ID                     0
#define GM_1F5_TRANS_PID                        0
#define GM_1F5_TRANS_RESP_ID                    GM_BCAST_TRANS_1F5
#define GM_1F5_TRANS_RESP_DLC                   8
#define GM_1F5_TRANS_RESP_INDEX                 0
#define GM_1F5_TRANS_RESP_LENGTH                1
#define GM_1F5_TRANS_RESP_SHIFT                 0
#define GM_1F5_TRANS_RESP_MASK                  0x0F
#define GM_1F5_TRANS_RESP_REVERSE_MATCH         0x0E
#define GM_1F5_TRANS_RESP_MULTIPLIER            1
#define GM_1F5_TRANS_RESP_DIVISOR               1
#define GM_1F5_TRANS_RESP_OFFSET                0

#define GM_1F5_TRANS_MSG_DLC                    8
#define GM_1F5_TRANS_MSG_ACTUAL_GEAR_OFFSET     0
#define GM_1F5_TRANS_MSG_ACTUAL_GEAR_MASK       0x0F
#define GM_1F5_FORWARD1                         1
#define GM_1F5_FORWARD2                         2
#define GM_1F5_FORWARD3                         3
#define GM_1F5_FORWARD4                         4
#define GM_1F5_FORWARD5                         5
#define GM_1F5_FORWARD6                         6
#define GM_1F5_NEUTRAL                          13
#define GM_1F5_REVERSE                          14
#define GM_1F5_PARK                             15

// GM VIN message 0x4E1 defintions
#define GM_4E1_VIN_DLC                          8
#define GM_4E1_VIN_CHAR_START_INDEX             9   // Starting char is the 10th character of the VIN (index is -1)
#define GM_4E1_VIN_SEGMENT_LENGTH               8   // 8 VIN chars in this segment

// GM VIN message 0x514 defintions
#define GM_514_VIN_DLC                          8
#define GM_514_VIN_CHAR_START_INDEX             1   // Starting char is the 2nd character of the VIN (index is -1)
#define GM_514_VIN_SEGMENT_LENGTH               8   // 8 VIN chars in this segment

//------------------------------------------------------------------------------
// TYPEDEFS                                                         
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PROTOTYPES                                                       
//------------------------------------------------------------------------------

void GM_BcastOdoMsg120(const tsCanMsgV2 *CANMsgRx);
void GM_BcastVinMsg4E1(const tsCanMsgV2 *CANMsgRx, char *broadcastVin);
void GM_BcastVinMsg514(const tsCanMsgV2 *CANMsgRx, char *broadcastVin);

#endif
