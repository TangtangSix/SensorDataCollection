#ifndef __LED_H__
#define __LED_H__
#include "gpio.h"
extern int LedFlag;
void LED_SET(void);
void LED_RESET(void);
void LED_Transmit(void);//发送信息灯效
void LED_Receive(void);//接收信息灯效
void Led_Normal(void);//正常状态灯效
void Led_Toggle(void);//错误状态灯效;
void Led_Smoke_Error(void);
void Led_Fire_Error(void);
void Led_Light_Error(void);
#endif
