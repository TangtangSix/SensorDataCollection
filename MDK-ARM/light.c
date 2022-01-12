#include "light.h"

double Light_Sensor_Value=0;
int LightFlag=1;
void Detect_Light(void){

	//启动ADC装换
	HAL_ADC_Start(&hadc3);  
	//等待转换完成，第二个参数是超时时间，单位是ms.
    HAL_ADC_PollForConversion(&hadc3, 50);  
	 //判断转换完成标志位是否设置
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc3), HAL_ADC_STATE_REG_EOC)) 
    {
      /*开始获取转换值*/
		uint16_t value = HAL_ADC_GetValue(&hadc3); 
		//光照越强,电压越小,光照百分比越大		
		Light_Sensor_Value=100*1.0-value*1.0/33;
		printf("读取的光亮度为: %.2f\r\n",Light_Sensor_Value);
			//当光照百分比高于90或者低于30则触发异常
			if(Light_Sensor_Value>90 || Light_Sensor_Value<30){
				LightFlag=0;
			}
			else{
				LightFlag=1;

			}
    }
}
