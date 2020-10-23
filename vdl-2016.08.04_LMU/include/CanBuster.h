#ifndef __CAN_BUSTER_H
#define __CAN_BUSTER_H

#include <stdint.h>
#include "TVG850.h"
#include "CAN.h"

int CanBuster_SetTransceiver(int on);
int CanBuster_SetBaudrate(uint32_t u32BTR);
uint32_t CanBuster_GetBaudrate(void);
int CanBuster_ReceiveAll(void);
int CanBuster_SetMode(uint8_t mode);
uint8_t CanBuster_GetMode(void);
int CanBuster_Start(void);
int CanBuster_Stop(void);
int CanBuster_IsTxBusy(void);
int CanBuster_IsBusOff(void);
int CanBuster_BusOn(void);
int CanBuster_SendMessage(tsCanMsgV2 *pCanMsg);
int CanBuster_SetHWFilter(uint16_t *filters, int filterCount);
int CanBuster_Init(void);
void CanBuster_SetRxQueue(xQueueHandle msgQueue);

#endif
