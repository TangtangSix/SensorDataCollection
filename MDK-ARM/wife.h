#ifndef __WIFE_H__
#define __WIFE_H__

#include "gpio.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"

extern char buf[100];
extern char com3[100];
extern uint16_t length3;

void WIFI_Init(void);
void WIFI_SendTempData(char *data);
void WIFI_SendHumData(char *data);
#endif
