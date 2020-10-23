#ifndef _CORE_PARAM_ENCODING_H_
#define _CORE_PARAM_ENCODING_H_

#include <stdint.h>

// Describes the encoding of a prameter in a broadcast or request message
typedef struct
{
    uint16_t methodId;              // Encoding method ID
    uint8_t reqRequired;            // Do we need to request the data
    uint8_t reqMode;                // Type of request (i.e. service $21, $22, $23 and etc
    uint32_t reqId;                 // CAN ID to use for the request
    uint32_t reqPid;                // The PID, address of offset for the parameter, tied to the J2190 mode
    uint32_t respId;                // CAN ID for the frame containing the data
    uint16_t respDlc;               // Allowed DLC of received CAN frame
    uint8_t respIndex;              // The parameter starts at this index in the frame
    uint8_t respLength;             // The parameter occupies this number of bytes 
    uint8_t respShift;              // The parameter should be shifted right by this many bytes
    uint8_t respMatchVal;           // For methods like reverse the data should match this value after applying mask
    uint32_t respMask;              // The parameter should be masked by this value
    uint32_t respMultiplier;        // Multiplier for scaling
    uint32_t respDivisor;           // Divisor for scaling
    int32_t respOffset;             // Signed offset to be added to a parameter (i.e. temp might need a -40 offset)
}sParamEncoding;

#endif
