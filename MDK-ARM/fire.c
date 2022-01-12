#include "fire.h"
#include "rtthread.h"
int FireFlag=1;

void Detect_Fire(void){
	//低电平正常
	if(HAL_GPIO_ReadPin(GPIOE,FIRE_Pin)==GPIO_PIN_RESET){
		FireFlag=1;
		printf("火焰传感器: 正常\r\n");
	}
	//高电平异常
	 else if (HAL_GPIO_ReadPin(GPIOE,FIRE_Pin)==GPIO_PIN_SET){
		FireFlag=0;
		printf("火焰传感器: 着火了\n");
	 }
}

