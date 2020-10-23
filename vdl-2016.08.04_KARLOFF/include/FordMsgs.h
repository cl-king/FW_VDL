#ifndef _FORD_MSGS_H_
#define _FORD_MSGS_H_

//------------------------------------------------------------------------------
// INCLUDES                                                         
//------------------------------------------------------------------------------

#include "CoreParamEncoding.h"
#include "CoreTypes.h"
#include "J2190.h"

//------------------------------------------------------------------------------
// DEFINES                                                          
//------------------------------------------------------------------------------

// Ford proprietary request addresses           
#define FORD_IPC_REQ_ADDR_720                       0x720       // Instrument Control Panel Module
#define FORD_GEM_REQ_ADDR_726                       0x726       // Generic Electronic Module
#define FORD_PCM_REQ_ADDR_7E0                       0x7E0       // Powertrain Control Module

// Ford proprietary response addresses
#define FORD_IPC_RESP_ADDR_728                      0x728       // Instrument Control Panel Module
#define FORD_GEM_RESP_ADDR_72E                      0x72E       // Generic Electronic Module
#define FORD_PCM_RESP_ADDR_7E8                      0x7E8       // Powertrain Control Module

// Ford broadcast message IDs
#define FORD_BCAST_201                              0x201       // RPM on some late model Ford vehicles
#define FORD_BCAST_204                              0x204       // RPM on some vehicles
#define FORD_BCAST_351                              0x351       // Speed on E-series vehicles
#define FORD_BCAST_407                              0x407       // MAP on 6.7L diesel
#define FORD_BCAST_VIN_40A                          0x40A       // VIN on some late model US vehicles
#define FORD_BCAST_415                              0x415       // Speed on some late model Ford vehicles
#define FORD_BCAST_422                              0x422       // Contains calculated load on some vehicle
#define FORD_BCAST_430                              0x430       // Odometer on some late model vehicles
#define FORD_BCAST_REVERSE_433                      0x433       // European Ford manual transmission reverse indicator broadcast
#define FORD_BCAST_43E                              0x43E       // Raw MAP on some vehicles
#define FORD_BCAST_VIN_4FF                          0x4FF       // VIN on some late model US vehicles

// Ford proprietary PIDs
#define FORD_11B6_TRANS_RANGE_PID                   0x11B6      // Transmission range selection PID
#define FORD_404C_TOTAL_DISTANCE                    0x404C      // Totatl distance, km * 10
#define FORD_6103_ENG_RUNTIME                       0x6103      // Engine runtime, sec
#define FORD_6180_ODOMETER                          0x6180      // European Ford odometer, from IPC 1/10 km, from PCM 1/10 mile
#define FORD_6182_ODOMETER                          0x6182      // Ford odometer message, miles * 500
#define FORD_B105_TRANS_GEAR_PID                    0xB105      // Transmission gear/reverse switch PID
#define FORD_DD01_TOTAL_VEHICLE_DISTANCE            0xDD01      // Total distance in km
#define FORD_F47F_ENG_RUNTIME                       0xF47F      // Engine runtime, sec

// Scale value for the Ford hi-res 6182 odometer
#define FORD_ODO_SCALING							500.0

// Defines for transmission range PID 11B6
#define FORD_11B6_TRANS_RANGE_REQ_REQUIRED          1
#define FORD_11B6_TRANS_RANGE_REQ_MODE              J2190_MODE_22_REQ
#define FORD_11B6_TRANS_RANGE_REQ_ID                FORD_PCM_REQ_ADDR_7E0
#define FORD_11B6_TRANS_RANGE_RESP_ID               FORD_PCM_RESP_ADDR_7E8
#define FORD_11B6_TRANS_RANGE_RESP_DLC              5
#define FORD_11B6_TRANS_RANGE_RESP_INDEX            0       // Note offset is relative to data portion of resp
#define FORD_11B6_TRANS_RANGE_RESP_LENGTH           1
#define FORD_11B6_TRANS_RANGE_RESP_SHIFT            0
#define FORD_11B6_TRANS_RANGE_RESP_REVERSE_MATCH    0x78
#define FORD_11B6_TRANS_RANGE_RESP_MASK             0xFF
#define FORD_11B6_TRANS_RANGE_RESP_MULTIPLIER       1
#define FORD_11B6_TRANS_RANGE_RESP_DIVISOR          1
#define FORD_11B6_TRANS_RANGE_RESP_OFFSET           0


// Defines for transmission gear/reverse PID B105
#define FORD_B105_TRANS_GEAR_REQ_REQUIRED           1
#define FORD_B105_TRANS_GEAR_REQ_MODE               J2190_MODE_22_REQ
#define FORD_B105_TRANS_GEAR_REQ_ID                 FORD_GEM_REQ_ADDR_726
#define FORD_B105_TRANS_GEAR_RESP_ID                FORD_GEM_RESP_ADDR_72E
#define FORD_B105_TRANS_GEAR_RESP_DLC               8
#define FORD_B105_TRANS_GEAR_RESP_INDEX             0       // Note offset is relative to data portion of resp
#define FORD_B105_TRANS_GEAR_RESP_LENGTH            1
#define FORD_B105_TRANS_GEAR_RESP_SHIFT             0
#define FORD_B105_TRANS_GEAR_RESP_MASK              0x08
#define FORD_B105_TRANS_GEAR_RESP_REVERSE_MATCH     0x08
#define FORD_B105_TRANS_GEAR_RESP_MULTIPLIER        1
#define FORD_B105_TRANS_GEAR_RESP_DIVISOR           1
#define FORD_B105_TRANS_GEAR_RESP_OFFSET            0

// Ford message 201 definitions
#define FORD_201_REQ_REQUIRED                       0
#define FORD_201_REQ_MODE                           0
#define FORD_201_REQ_ID                             0
#define FORD_201_REQ_PID                            0
#define FORD_201_RESP_ID                            FORD_BCAST_201
#define FORD_201_RESP_DLC                           8
#define FORD_201_RPM_SCALING                        0.25
#define FORD_201_RPM_INDEX                          0
#define FORD_201_RPM_LENGTH                         2
#define FORD_201_RPM_SHIFT                          0
#define FORD_201_RPM_MATCH_VAL                      0
#define FORD_201_RPM_MASK                           0xFFFF
#define FORD_201_RPM_MULTIPLIER                     1
#define FORD_201_RPM_DIVISOR                        4
#define FORD_201_RPM_OFFSET                         0
#define FORD_201_SPEED_NOT_AVAIL                    0x2710
#define FORD_201_SPEED_SCALING                      0.01
#define FORD_201_SPEED_OFFSET                       4
#define FORD_201_SPEED_LENGTH                       2

// Ford message 204 definitions
#define FORD_204_REQ_REQUIRED                       0
#define FORD_204_REQ_MODE                           0
#define FORD_204_REQ_ID                             0
#define FORD_204_REQ_PID                            0
#define FORD_204_RESP_ID                            FORD_BCAST_204
#define FORD_204_RESP_DLC                           8
#define FORD_204_RPM_SCALING                        2
#define FORD_204_RPM_INDEX                          3
#define FORD_204_RPM_LENGTH                         2
#define FORD_204_RPM_SHIFT                          0
#define FORD_204_RPM_MATCH_VAL                      0
#define FORD_204_RPM_MASK                           0xFFFF
#define FORD_204_RPM_MULTIPLIER                     2
#define FORD_204_RPM_DIVISOR                        1
#define FORD_204_RPM_OFFSET                         0

// Ford 0x351 message
#define FORD_351_REQ_REQUIRED                       0
#define FORD_351_REQ_MODE                           0
#define FORD_351_REQ_ID                             0
#define FORD_351_REQ_PID                            0
#define FORD_351_RESP_ID                            FORD_BCAST_351
#define FORD_351_RESP_DLC                           8
#define FORD_351_SPEED_SCALING                      1.0
#define FORD_351_SPEED_INDEX                        1
#define FORD_351_SPEED_LENGTH                       1
#define FORD_351_SPEED_SHIFT                        0
#define FORD_351_SPEED_MATCH_VAL                    0
#define FORD_351_SPEED_MASK                         0xFF
#define FORD_351_SPEED_MULTIPLIER                   1
#define FORD_351_SPEED_DIVISOR                      1
#define FORD_351_SPEED_OFFSET                       0
#define FORD_351_MAF_INDEX                          5
#define FORD_351_MAF_LENGTH                         1
#define FORD_351_MAF_SHIFT                          0
#define FORD_351_MAF_MATCH_VAL                      0
#define FORD_351_MAF_MASK                           0xFF
#define FORD_351_MAF_MULTIPLIER                     325
#define FORD_351_MAF_DIVISOR                        100
#define FORD_351_MAF_OFFSET                         0

// Ford 0x407 message
#define FORD_407_REQ_REQUIRED                       0
#define FORD_407_REQ_MODE                           0
#define FORD_407_REQ_ID                             0
#define FORD_407_REQ_PID                            0
#define FORD_407_RESP_ID                            FORD_BCAST_407
#define FORD_407_RESP_DLC                           8
#define FORD_407_MAP_INDEX                          1
#define FORD_407_MAP_LENGTH                         1
#define FORD_407_MAP_SHIFT                          0
#define FORD_407_MAP_MATCH_VAL                      0
#define FORD_407_MAP_MASK                           0xFF
#define FORD_407_MAP_MULTIPLIER                     10
#define FORD_407_MAP_DIVISOR                        15
#define FORD_407_MAP_OFFSET                         70

// Ford 0x415 message
#define FORD_415_REQ_REQUIRED                       0
#define FORD_415_REQ_MODE                           0
#define FORD_415_REQ_ID                             0
#define FORD_415_REQ_PID                            0
#define FORD_415_RESP_ID                            FORD_BCAST_415
#define FORD_415_RESP_DLC                           8
#define FORD_415_SPEED_SCALING                      0.01
#define FORD_415_SPEED_INDEX                        0
#define FORD_415_SPEED_LENGTH                       2
#define FORD_415_SPEED_SHIFT                        0
#define FORD_415_SPEED_MATCH_VAL                    0
#define FORD_415_SPEED_MASK                         0xFFFF
#define FORD_415_SPEED_MULTIPLIER                   1
#define FORD_415_SPEED_DIVISOR                      100
#define FORD_415_SPEED_OFFSET                       0

// Ford 0x422 load method constants
#define FORD_422_REQ_REQUIRED                       0
#define FORD_422_REQ_MODE                           0
#define FORD_422_REQ_ID                             0
#define FORD_422_REQ_PID                            0
#define FORD_422_RESP_ID                            FORD_BCAST_422
#define FORD_422_RESP_DLC                           8
#define FORD_422_LOAD_INDEX                         5
#define FORD_422_LOAD_LENGTH                        1
#define FORD_422_LOAD_SHIFT                         0
#define FORD_422_LOAD_MATCH_VAL                     0
#define FORD_422_LOAD_MASK                          0xFF
#define FORD_422_LOAD_MULTIPLIER                    100
#define FORD_422_LOAD_DIVISOR                       255
#define FORD_422_LOAD_OFFSET                        0
        
// Ford 0x430 odometer method constants
#define FORD_430_REQ_REQUIRED                       0
#define FORD_430_REQ_MODE                           0
#define FORD_430_REQ_ID                             0
#define FORD_430_REQ_PID                            0
#define FORD_430_RESP_ID                            FORD_BCAST_430
#define FORD_430_RESP_DLC                           8       // Length of a valid Ford 430 odometer message
#define FORD_430_ODOMETER_SCALING                   1       // scale factor for a Ford 430 odometer message, 1/64 of km
#define FORD_430_1_ODOMETER_INDEX                   1       // Some odometers start at byte 1, F-150 5.0L
#define FORD_430_2_ODOMETER_INDEX                   3       // Some odometers start at byte 3, F-250 6.7L
#define FORD_430_ODOMETER_LENGTH                    3
#define FORD_430_ODOMETER_SHIFT                     0
#define FORD_430_ODOMETER_MATCH_VAL                 0
#define FORD_430_ODOMETER_MASK                      0xFFFFFF
#define FORD_430_ODOMETER_MULTIPLIER                1
#define FORD_430_ODOMETER_DIVISOR                   1
#define FORD_430_ODOMETER_OFFSET                    0

// Ford reverse message 433 definitions, European Ford Connect T200
#define FORD_433_REV_PID                            0
#define FORD_433_REV_REQ_ID                         0
#define FORD_433_REV_REQ_REQUIRED                   0
#define FORD_433_REV_REQ_MODE                       0
#define FORD_433_REV_RESP_ID                        FORD_BCAST_REVERSE_433
#define FORD_433_REV_RESP_DLC                       8
#define FORD_433_REV_RESP_INDEX                     4
#define FORD_433_REV_RESP_LENGTH                    1
#define FORD_433_REV_RESP_SHIFT                     0
#define FORD_433_REV_RESP_MASK                      0x01
#define FORD_433_REV_RESP_REVERSE_MATCH             0x01
#define FORD_433_REV_RESP_MULTIPLIER                1
#define FORD_433_REV_RESP_DIVISOR                   1
#define FORD_433_REV_RESP_OFFSET                    0

// Ford 0x43E message
#define FORD_43E_REQ_REQUIRED                       0
#define FORD_43E_REQ_MODE                           0
#define FORD_43E_REQ_ID                             0
#define FORD_43E_REQ_PID                            0
#define FORD_43E_RESP_ID                            FORD_BCAST_43E
#define FORD_43E_RESP_DLC                           8
#define FORD_43E_MAP_INDEX                          5
#define FORD_43E_MAP_LENGTH                         1
#define FORD_43E_MAP_SHIFT                          0
#define FORD_43E_MAP_MATCH_VAL                      0
#define FORD_43E_MAP_MASK                           0xFF
#define FORD_43E_MAP_MULTIPLIER                     325
#define FORD_43E_MAP_DIVISOR                        100
#define FORD_43E_MAP_OFFSET                         -110

// Ford VIN 40A definitions
#define FORD_40A_VIN_DLC                            8
#define FORD_40A_VIN_CODE_INDEX                     0
#define FORD_40A_VIN_CODE_VALUE                     0xC1    // The first byte contains this value
#define FORD_40A_MSG_TYPE_INDEX                     1       // The message type is found in the second byte
#define FORD_40A_MSG_TYPE_VIN_SEG1                  0       // Contains characters 1-6 of the VIN
#define FORD_40A_MSG_TYPE_VIN_SEG2                  1       // Contains characters 7-12 of the VIN
#define FORD_40A_MSG_TYPE_VIN_SEG3                  2       // Contains characters 13-17 of the VIN
#define FORD_40A_VIN_SEG_INDEX                      2       // All VIN segments start at index 2 of the message
#define FORD_40A_VIN_SEG1_LENGTH                    6       // Segment 1 is 6 bytes in length
#define FORD_40A_VIN_SEG1_CHAR_START_INDEX          0       // Segment 1 is the beginning of the VIN
#define FORD_40A_VIN_SEG2_LENGTH                    6       // Segment 2 is 6 bytes in length
#define FORD_40A_VIN_SEG2_CHAR_START_INDEX          6       // Segment 2 is the mid section of the VIN
#define FORD_40A_VIN_SEG3_LENGTH                    5       // Segment 3 is 5 bytes in length
#define FORD_40A_VIN_SEG3_CHAR_START_INDEX          12      // Segment 3 is the end of the VIN

// Ford VIN 4FF definitions
#define FORD_4FF_VIN_DLC                            8
#define FORD_4FF_MSG_TYPE_INDEX                     0       // The message type is found in the first byte
#define FORD_4FF_MSG_TYPE_VIN_SEG1                  0x30    // Contains characters 1-5 of the VIN
#define FORD_4FF_MSG_TYPE_VIN_SEG2                  0x31    // Contains characters 6-11 of the VIN
#define FORD_4FF_MSG_TYPE_VIN_SEG3                  0x32    // Contains characters 12-17 of the VIN
#define FORD_4FF_VIN_SEG_INDEX                      1       // All VIN segments start at index 1 of the message
#define FORD_4FF_VIN_SEG1_LENGTH                    5       // Segment 1 is 5 bytes in length
#define FORD_4FF_VIN_SEG1_CHAR_START_INDEX          0       // Segment 1 is the beginning of the VIN
#define FORD_4FF_VIN_SEG2_LENGTH                    6       // Segment 2 is 6 bytes in length
#define FORD_4FF_VIN_SEG2_CHAR_START_INDEX          5       // Segment 2 is the mid section of the VIN
#define FORD_4FF_VIN_SEG3_LENGTH                    6       // Segment 3 is 6 bytes in length
#define FORD_4FF_VIN_SEG3_CHAR_START_INDEX          11      // Segment 3 is the end of the VIN

//------------------------------------------------------------------------------
// TYPEDEFS                                                         
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// PROTOTYPES                                                       
//------------------------------------------------------------------------------

void Ford_BcastOdoMsg430(const tsCanMsgV2 *CANMsgRx, const sParamEncoding *encoding, DistCalcStatus method);
void Ford_BcastVinMsg40A(const tsCanMsgV2 *CANMsgRx, char *broadcastVin);
void Ford_BcastVinMsg4FF(const tsCanMsgV2 *CANMsgRx, char *broadcastVin);

#endif
