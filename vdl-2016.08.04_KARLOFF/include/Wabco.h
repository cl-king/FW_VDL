#ifndef _WABCO_H__
#define _WABCO_H__

#ifdef _VDL_WABCO_ENABLE

#include "AvgDefines.h"
#include "CoreTypes.h"

/* initialization */
void Wabco_Rollcall_Init(void);

/* to check if the MID is for Wabco ABS controller*/
int Wabco_ECUIsWabco(uint8_t u8Mid, uint8_t* id, int id_len, int* update);

/* to check if Wabco ABS controller is installed in the truck*/
int Wabco_ABS_installed(void);

/* update the state of roll call procedure*/
void Wabco_Rollcall_Process_Response(uint8_t u8Mid, uint8_t* u8Data, uint8_t u8Length);

/* update Wabco roll call procedure state machine */
void Wabco_Rollcall_Update(void);

/* cleare allocated memory, etc.*/
void Wabco_Rollcall_Clear(void);

#endif // _VDL_WABCO_ENABLE

#endif

