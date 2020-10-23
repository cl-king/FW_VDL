#include "AvgDefines.h"
#include "CoreTypes.h"
#include "EventDataRecord_external.h"

#ifndef EVENTDATARECORD_H__
#define EVENTDATARECORD_H__

#ifdef __INCLUDE_EVENTDATARECORD        
        
#define EVENTDATARECORD_SUCCESS              0
#define EVENTDATARECORD_ERROR_NOENOUGHMEMORY 1
#define EVENTDATARECORD_ERROR_FAILTOLOCK 2
#define EVENTDATARECORD_ERROR_NOTINITIALIZED 3
#define EVENTDATARECORD_ERROR_NODATAFOUND 4
#define EVENTDATARECORD_ERROR_INVALID_DURATION 5

#if defined(__cplusplus)
extern "C" {
#endif


/* intialize event data buffer module
 *  param: 
 *     BufDur: how many seconds of event data the buffer holds
 *  return value:
 *     0: success
 *     non-zero: failed
 */
uint32_t EVENTDATA_Record_Init(uint32_t BufDur);

/* add a CAN message into event data buffer
 * param:
 *    protocol: which protocol the saved message is
 *    src: MID for J1587 or ECU address for J1939
 *    pidORpgn: PID for J1587 or PGN for J1939
 *    buf:   the CAN message buffer 
 *    len:   the length in byte of @buf
 * return value:
 *    0: succeed in adding CAN message into event buffer
 *    non-zero: failed   
 */
uint32_t EVENTDATA_Record_Add_Msg(CoreStatus protocol, uint8_t src, uint16_t pidORpgn, uint8_t* buf, uint32_t len);


/* clear all memory allocated
 */
void EVENTDATA_Record_clear(void);

#if defined(__cplusplus)
}
#endif

#endif // __INCLUDE_EVENTDATARECORD

#endif
