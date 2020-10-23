#ifndef __J1979_IFACE_H
#define __J1979_IFACE_H

#include "BusterIface.h"

typedef enum{
	protocol_none 			= 0,
	protocol_j1850_vpw,
	protocol_j1850_pwm,
	protocol_iso9141,
	protocol_chrysler_sci,
	protocol_kwp2000,
	protocol_can_11_500,
	protocol_can_29_500,
	protocol_can_11_250,
	protocol_can_29_250
}obd_protocol;

typedef struct{
	obd_protocol protocol;
	uint8_t kb1;
	uint8_t kb2;
	uint8_t fast;
}obd_connection_state;

int J1979IfaceInit(void);
int J1979IfaceSendFunctional(uint8_t *data, uint8_t len);
int J1979IfaceSendPhysical(uint8_t *data, uint8_t len, uint8_t ecu);
void J1979IfaceAutoDetect(uint8_t protocol);
void J1979IfaceGetConnectionState(obd_connection_state *state);
int J1979IfaceGetResponse(s_bus_msg *msg, uint32_t timeout);
void J1979IfaceDisconnect(void);
bool J1979IfaceConflicted(void);
void J1979IfaceSetAuxFilter(uint32_t canID, uint32_t rate, uint32_t filterIndex);
int J1979IfaceGetBroadcastData(s_bus_msg *msg);

#endif
