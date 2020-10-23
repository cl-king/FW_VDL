
#ifndef EVENTTRIGGER_EXTERNAL_H__
#define EVENTTRIGGER_EXTERNAL_H__

#ifdef __INCLUDE_EVENTDATARECORD

typedef enum
{
    VDL_EVENT_Trigger_Type_Acce_Speed = 0,
    VDL_EVENT_Trigger_Type_Acce_Lateral = 1,
    VDL_EVENT_Trigger_Type_StopEvent = 2,
    VDL_EVENT_Trigger_Type_SRS = 3,
    VDL_EVENT_Trigger_Type_DriverDemand = 4,
    VDL_EVENT_Trigger_Type_Radial = 5,
    VDL_EVENT_Trigger_Type_Deceleration = 6,
    VDL_EVENT_Trigger_Type_Acceleration = 7,
    VDL_EVENT_Trigger_Type_TotalNumber = 8,
}VDL_EVENT_Trigger_Type;

typedef enum
{
    VDL_EVENT_Trigger_Transition_NoEvent = 0,
    VDL_EVENT_Trigger_Transition_EventOccur = 1,
    VDL_EVENT_Trigger_Transition_EventEnd = 2,
}VDL_EVENT_Trigger_Transition;

typedef struct
{
    VDL_EVENT_Trigger_Type type;
    uint32_t timestamp;
    VDL_EVENT_Trigger_Transition transition; 
}VDL_EVENT_Trigger_CB_struct;

#if defined(__cplusplus)
extern "C" {
#endif

typedef void (*VDL_EVENT_Trigger_Func)(VDL_EVENT_Trigger_CB_struct* param);


/* EVENT_Trigger_Register_CB is used to register callback function
 * when an event happens. 
 * parameters:
 *    EVENT_Trigger_Func cb: function pointer of callback
 *    void* param:         parameter of call back function
 */
extern void VDL_EVENT_Trigger_Register_CB(VDL_EVENT_Trigger_Func cb, VDL_EVENT_Trigger_CB_struct* param );


/* EVENT_Trigger_Set_Criteria is used to set the criteria for a event trigger type.
 *  EVENT_Trigger_Type type:   trigger type
 *  uint32_t value         :   the threhold that trigger the event
 *  uint32_t duration      :  how long should the trigger stay above threhold to trigger the event
 * For example: The speed trigger is 8 Km/h/s for 500 seconds.The parameter should be:
 *        EVENT_Trigger_Set_Criteria(EVENT_Trigger_Type_Acce_Speed, 8, 500); 
 */
 
extern void VDL_EVENT_Trigger_Set_Criteria(VDL_EVENT_Trigger_Type type, uint32_t value, uint32_t duration);


#if defined(__cplusplus)
}
#endif

#endif // __INCLUDE_EVENTDATARECORD

#endif
