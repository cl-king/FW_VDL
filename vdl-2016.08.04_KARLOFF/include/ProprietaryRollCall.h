
#ifndef __PROPRETARYROLLCALL_H__
#define __PROPRETARYROLLCALL_H__

#ifdef _VDL_WABCO_ENABLE

#include "AvgDefines.h"
#include "CoreTypes.h"
#if defined(__cplusplus)
extern "C" {
#endif


/* to initialize all rollcalls*/
void ProprietaryRollCall_Init(void);

/* this function should be called periodically to update the state of rollcall procedure of underlying ECU */
void ProprietaryRollCall_Process_Response(uint8_t u8Mid, uint8_t* u8Data, uint8_t u8Length);

/*
 *function:ProprietaryRollCall_IsNeeded
 *   to check proprietary roll call is needed
 * return value:
 *    0: not needed
 *    1: needed
 */
int ProprietaryRollCall_IsNeeded(uint8_t u8Mid, uint8_t* component_id, int id_leng, int* update);

/* ProprietaryRollCall_Clear is called while vehicle bus is disconnected.
 */
void ProprietaryRollCall_Clear(void);

/* ProprietaryRollCall_Update is called to update internal state machine of roll call procedure
 */
void ProprietaryRollCall_Update(void);

#if defined(__cplusplus)
}
#endif

#endif // _VDL_WABCO_ENABLE

#endif

