#include "led.h"
#include "smoke.h"
#include "light.h"
#include "rtthread.h"

int LedFlag=1;


void LED_SET(void){
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
}

void LED_RESET(void){
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);
}
//发送数据时led灯变化
void LED_Transmit(void){
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	 rt_thread_mdelay(150);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	 rt_thread_mdelay(150);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	 rt_thread_mdelay(150);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
	 rt_thread_mdelay(150);
}

//接收数据时led变化
void LED_Receive(void){
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
	 rt_thread_mdelay(100);
	
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	 rt_thread_mdelay(100);
	
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	 rt_thread_mdelay(100);

	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	 rt_thread_mdelay(100);
	 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
	 rt_thread_mdelay(100);
}


void Led_Normal(void){

	if(Light_Sensor_Value<20){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);

	}
	else if(Light_Sensor_Value<40 && Light_Sensor_Value>=20)
	{
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	}
	else if(Light_Sensor_Value<60 && Light_Sensor_Value>=40){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	}
	else if(Light_Sensor_Value<80 && Light_Sensor_Value>=60){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	}
	else if(Light_Sensor_Value<95 && Light_Sensor_Value>=80){
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	}
}

void Led_Smoke_Error(void){
	
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
	rt_thread_mdelay(500);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
	rt_thread_mdelay(500);
}
void Led_Fire_Error(void){
	
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
	rt_thread_mdelay(500);
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
	rt_thread_mdelay(500);

}
void Led_Light_Error(void){
	
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
	rt_thread_mdelay(500);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
	rt_thread_mdelay(500);

}

void Led_Toggle(void){
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
}
