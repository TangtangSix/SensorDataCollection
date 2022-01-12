#include "light.h"

double Light_Sensor_Value=0;
int LightFlag=1;
void Detect_Light(void){

	//����ADCװ��
	HAL_ADC_Start(&hadc3);  
	//�ȴ�ת����ɣ��ڶ��������ǳ�ʱʱ�䣬��λ��ms.
    HAL_ADC_PollForConversion(&hadc3, 50);  
	 //�ж�ת����ɱ�־λ�Ƿ�����
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc3), HAL_ADC_STATE_REG_EOC)) 
    {
      /*��ʼ��ȡת��ֵ*/
		uint16_t value = HAL_ADC_GetValue(&hadc3); 
		//����Խǿ,��ѹԽС,���հٷֱ�Խ��		
		Light_Sensor_Value=100*1.0-value*1.0/33;
		printf("��ȡ�Ĺ�����Ϊ: %.2f\r\n",Light_Sensor_Value);
			//�����հٷֱȸ���90���ߵ���30�򴥷��쳣
			if(Light_Sensor_Value>90 || Light_Sensor_Value<30){
				LightFlag=0;
			}
			else{
				LightFlag=1;

			}
    }
}
