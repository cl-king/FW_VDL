#ifndef __TVG850_H
#define __TVG850_H

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define portBASE_TYPE 	int
#define portCHAR 		char
#define portSHORT		short
#define portLONG		long

#define xTaskHandle	int

#define CAN_PORTS	1
#define portTICK_RATE_MS	1
#define portMAX_DELAY		0xFFFFFFFF

#define pdTRUE				1
#define pdFALSE				0

#define pdPASS				1
#define pdFAIL				0
#define errQUEUE_EMPTY		0
#define errQUEUE_FULL		0

#define errCOULD_NOT_ALLOCATe_REQUIRED_MEMORY		-1
#define errNO_TASK_TO_RUN							-2
#define errQUEUE_BLOCKED							-4
#define errQUEUE_YIELD								-5

typedef enum
{
    CrankInit,
    CrankIgnOff,
    CrankIgnOn,
    CrankDetected,
    CrankRunning,
} gmCrankEnum;

typedef unsigned long portTickType;

#define CRITICAL_TRACE(...)		MODULE_TRACE("CRITICAL",__VA_ARGS__)
#define VERBOSE_TRACE(...)  MODULE_TRACE("VERBOSE", __VA_ARGS__)

#include "queue.h"
#include "FilterRamMemMap.h"
#include "CanBuster.h"

#define CAN1_NORMAL_MODE() 	CanBuster_SetTransceiver(1);
#define CAN1_STANDBY_MODE()	CanBuster_SetTransceiver(0);

//#define USE_OLD_FILTERS

typedef pthread_mutex_t * xSemaphoreHandle;

unsigned char RAM_DATA[RAM_DATA_SIZE];

extern uint32_t xTaskGetTickCount(void);


signed portBASE_TYPE Create_Task (void *pvTaskCode,
                                  const signed char* lpszName,
                                  unsigned portSHORT usStackDepth,
                                  void *pvParameters,
                                  unsigned portBASE_TYPE uxPriority,
                                  xTaskHandle *pxCreatedTask);

signed portBASE_TYPE xTaskCreate (void *pvTaskCode,
                                  const signed char* lpszName,
                                  unsigned portSHORT usStackDepth,
                                  void *pvParameters,
                                  unsigned portBASE_TYPE uxPriority,
                                  xTaskHandle *pxCreatedTask);

void portENTER_CRITICAL(void);
void portEXIT_CRITICAL(void);

void Delay_MS(uint32_t delay);

void module_trace(char *format, ...);
void debug_trace(char *format, ...);
void set_logging(uint32_t enable, char *path, uint32_t maxSize);

void GM_Gps_UpdateLocation(long ttag, int lock, uint32_t lat, uint32_t lon, double filteredSpeed, double unfilteredSpeed);
double GM_Gps_GetSpeed(void);
double GM_Gps_GetLatitude(void);
double GM_Gps_GetLongitude(void);
double GM_Gps_GetSpeedUnfiltered(void);
int1_t GM_Gps_GetRMCLock(void);
uint32_t GM_GetSystemTime(void);
uint32_t GM_Gps_GetTime(void);
gmCrankEnum GM_IO_GetCrankState(void);
int1_t GM_Config_GetDefaultCalibration(uint32_t* calibration);
int TVG850_Init(void);

void J1708_SetDebugLevel(int level);
void J1939_SetDebugLevel(int level);
void J1979_SetDebugLevel(int level);

portBASE_TYPE TvgSemaphoreTakeRecursive(xQueueHandle xMutex, portTickType xBlockTime);
portBASE_TYPE TvgSemaphoreGiveRecursive(xQueueHandle xMutex);
xSemaphoreHandle TvgSemaphoreCreateRecursiveMutex(void);
uint16_t GM_HelperCalcCRC(uint8_t *data, uint32_t u32Length);
int ReadEcuMap(uint8_t *data, uint32_t u32Length);
int WriteEcuMap(uint8_t *data, uint32_t u32Length);
unsigned short crc16(unsigned char *p, int len);

#endif


