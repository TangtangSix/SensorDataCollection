#include "smoke.h"

double Smoke_Sensor_Value=0;
int SmokeFlog=1;

void Detect_Smoke(void){
	//启动ADC装换
	HAL_ADC_Start(&hadc1);  
	//等待转换完成，第二个参数是超时时间，单位是ms.
	HAL_ADC_PollForConversion(&hadc1, 50);  
	//判断转换完成标志位是否设置
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))  
	{
		/*开始获取转换值*/
		uint16_t value = HAL_ADC_GetValue(&hadc1);		
		Smoke_Sensor_Value=value/33.0;
		printf("烟雾浓度为: %.2f\r\n",Smoke_Sensor_Value);
		//当烟雾指数高于20则触发异常
		if(Smoke_Sensor_Value>20){
			SmokeFlog=0;
		}
		else{
			SmokeFlog=1;
		}
	}
}

