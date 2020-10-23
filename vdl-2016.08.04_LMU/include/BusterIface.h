#ifndef __BUSTER_IFACE_H
#define __BUSTER_IFACE_H

#include <stdint.h>
#include <sys/time.h>

#define NO_VH_BUS       0     // for no bus
#define J1708_BUS       1     // for J1708 bus
#define J1939_BUS       2     // for J1938 bus
#define OBDII_BUS       3     // for OBDII bus

#define BUSTER_ACK			0x06
#define BUSTER_NAK			0x15
#define BUSTER_CONFLICT		0x18

#define BUSTER_PKT_ID		0
#define BUSTER_PKT_LEN		1
#define BUSTER_PKT_DATA		2
#define BUSTER_PKT_OVERHEAD	3
#define BUSTER_PKT_MAX		256

typedef struct{
	int physical;
	int len;
	uint32_t  mTimeStamp;				/*!< Message Timestamp */
	uint8_t data[BUSTER_PKT_MAX + BUSTER_PKT_OVERHEAD + 1];
}s_bus_msg;

typedef struct{
	uint8_t msgID;
	int length;
	uint32_t  mTimeStamp;				/*!< Message Timestamp */

	uint8_t data[BUSTER_PKT_MAX - BUSTER_PKT_OVERHEAD];
}s_buster_msg;

int BusterIfaceInit(void);
int BusterIfaceOpen(int busType);
//void BusterIfaceJ1979AutoDetect(void);
//obd_protocol BusterIfaceRequestProtocol(void);
//int BusterIfaceSendFunctional(uint8_t *data, uint8_t len);
int BusterIfaceGetResponse(int busType, s_buster_msg *msg, struct timeval *timeout);
//int BusterIfaceWrite(int busType, uint8_t *buf, int size, struct timeval *timeout);
//int BusterIfaceRead(int busType, uint8_t *buf, int size, struct timeval *timeout);
int BusterIfaceSendMsg(int busType, s_buster_msg *msg, struct timeval *timeout);
void BusterIfaceResetStats(void);

#endif
