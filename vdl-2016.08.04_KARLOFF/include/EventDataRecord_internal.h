#ifndef EVENTDATARECORD_INTERNAL_H__
#define EVENTDATARECORD_INTERNAL_H__

#ifdef __INCLUDE_EVENTDATARECORD

typedef struct
{
    uint32_t total;            /* total number of allocated EVENTDATA_Record_Item entries in @items */
    
    uint32_t newest;           /* the entry in @items to store a new EVENTDATA_Record_Item. *
                                * Initially it is 0, then accumulated everytime a new *
                                * EVENTDATA_Record_Item is added. when it reachs @total, it should start with 0 again.*/
    uint32_t circled;         /* the message have already reached the end of @items at least once */    
    VDL_EVENTDATA_Record_Item* items;   /* array of EVENTDATA_Record_Item, initialized in EVENTDATA_Buf_Init */
    
}EVENTDATA_Record_buffer;

extern EVENTDATA_Record_buffer s_event_record;

extern uint32_t EventDataRecord_init_done;

#if defined(__cplusplus)
extern "C" {
#endif

/* maximum event buffer length is 3 minutes*/
#define MAXIMUM_RECORD_DURATION (3*60)

/* minimum event buffer length is 15 seconds*/
#define MINIMUM_RECORD_DURATION 15

/* the default event data sampling frequency is every 100 ms*/
#define EVENTDATA_RECORD_SAMPLING_PERIOD 100
/* number of EVENTDATA_Record_Item per second, should be 1000/EVENTDATA_SAMPLING_FREQUENCY */
#define EVENTDATA_RECORD_SAMPLE_NUMBER_PER_SECOND 10

int EVENTDATA_Record_mutex_init(void);
int EVENTDATA_Record_mutex_lock(void);
int EVENTDATA_Record_mutex_unlock(void);

int32_t EVENTDATA_Record_Get_StartEntry(uint32_t start_time, EVENTDATA_Record_buffer* record_buf);
int32_t EVENTDATA_Record_Get_EndEntry(uint32_t end_time, EVENTDATA_Record_buffer* record_buf);
uint32_t EVENTDATA_Record_Get_TottalEntries(int32_t start_entry, int32_t end_entry, EVENTDATA_Record_buffer* record_buf);

void EVENTDATA_Record_init_item(VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_WSI(uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_EBC1(uint8_t src,uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_CCVS(uint8_t src,uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_ERC1(uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_EEC1(uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_EEC2(uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939_ETC2(uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_fill_item_J1939(uint8_t src,uint16_t pidORpgn, uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);

uint32_t EVENTDATA_Record_is_data_element_exist_byte(uint8_t data, uint8_t mask);
uint32_t EVENTDATA_Record_is_data_element_exist_short(uint16_t data, uint16_t mask);
void EVENTDATA_Record_set_J1587_data_byte(uint8_t* data, uint8_t mask, uint8_t value);
void EVENTDATA_Record_fill_item_J1587(uint8_t src,uint16_t pidORpgn, uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
void EVENTDATA_Record_set_J1587_data_short(uint16_t* data, uint16_t mask, uint16_t value);
void EVENTDATA_Record_fill_item(CoreStatus protocol, uint8_t src, uint16_t pidORpgn, uint8_t* buf, uint32_t len, VDL_EVENTDATA_Record_Item* item);
uint32_t EVENTDATA_Record_Buf_Malloc_Record(uint32_t duration, VDL_EVENTDATA_Record* record);

void EVENTDATA_Buf_Release_Record(VDL_EVENTDATA_Record* record);

#if defined(__cplusplus)
}
#endif

#endif // __INCLUDE_EVENTDATARECORD

#endif
