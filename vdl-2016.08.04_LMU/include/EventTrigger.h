
#include "AvgDefines.h"
#include "CoreTypes.h"
#include "EventTrigger_external.h"

#ifndef EVENTTRIGGER_H__
#define EVENTTRIGGER_H__

#ifdef __INCLUDE_EVENTDATARECORD

#include "EventTrigger_external.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*
 *
 */
void EVENT_Trigger_Init(void);


/* EVENT_Trigger_Check is used to check if an event trigger criteria is met
 *
 * paramters:
 *     EVENT_Trigger_Type type:   trigger type
 *     uint32_t value:            value for this trigger type
 * return:
 *     none
 */
uint32_t EVENT_Trigger_Check(VDL_EVENT_Trigger_Type type, int32_t triggerValue, uint32_t timestamp);

void EVENT_Trigger_Check_LongAcce_WithSpeed(ParamSource source, uint8_t ecu, float speed,uint32_t timestamp);

void EVENT_Trigger_AcceSensor_Supported(void);

void EVENT_Trigger_end(void);

#if defined(__cplusplus)
}
#endif

#endif // __INCLUDE_EVENTDATARECORD

#endif
