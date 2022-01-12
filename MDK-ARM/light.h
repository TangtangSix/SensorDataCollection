#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "gpio.h"
#include <stdio.h>
#include "adc.h"
#include "led.h"

extern double Light_Sensor_Value;
extern int LightFlag;


void Detect_Light(void);//¼à¿Ø¹âÃôµç×è

#endif
