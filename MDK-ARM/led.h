#ifndef __LED_H__
#define __LED_H__
#include "gpio.h"
extern int LedFlag;
void LED_SET(void);
void LED_RESET(void);
void LED_Transmit(void);//������Ϣ��Ч
void LED_Receive(void);//������Ϣ��Ч
void Led_Normal(void);//����״̬��Ч
void Led_Toggle(void);//����״̬��Ч;
void Led_Smoke_Error(void);
void Led_Fire_Error(void);
void Led_Light_Error(void);
#endif
