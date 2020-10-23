#ifndef __DEVICE_UTIL_H
#define __DEVICE_UTIL_H

int DeviceOpen(const char *name);
int DeviceWrite(int handle, uint8_t *buf, int len, struct timeval *timeout);
int DeviceRead(int handle, uint8_t *buf, int len, struct timeval *timeout);
int DeviceClose(int handle);

#endif
