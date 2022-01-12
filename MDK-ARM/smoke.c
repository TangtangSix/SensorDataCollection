#include "smoke.h"

double Smoke_Sensor_Value=0;
int SmokeFlog=1;

void Detect_Smoke(void){
	//����ADCװ��
	HAL_ADC_Start(&hadc1);  
	//�ȴ�ת����ɣ��ڶ��������ǳ�ʱʱ�䣬��λ��ms.
	HAL_ADC_PollForConversion(&hadc1, 50);  
	//�ж�ת����ɱ�־λ�Ƿ�����
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))  
	{
		/*��ʼ��ȡת��ֵ*/
		uint16_t value = HAL_ADC_GetValue(&hadc1);		
		Smoke_Sensor_Value=value/33.0;
		printf("����Ũ��Ϊ: %.2f\r\n",Smoke_Sensor_Value);
		//������ָ������20�򴥷��쳣
		if(Smoke_Sensor_Value>20){
			SmokeFlog=0;
		}
		else{
			SmokeFlog=1;
		}
	}
}

