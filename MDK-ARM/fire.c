#include "fire.h"
#include "rtthread.h"
int FireFlag=1;

void Detect_Fire(void){
	//�͵�ƽ����
	if(HAL_GPIO_ReadPin(GPIOE,FIRE_Pin)==GPIO_PIN_RESET){
		FireFlag=1;
		printf("���洫����: ����\r\n");
	}
	//�ߵ�ƽ�쳣
	 else if (HAL_GPIO_ReadPin(GPIOE,FIRE_Pin)==GPIO_PIN_SET){
		FireFlag=0;
		printf("���洫����: �Ż���\n");
	 }
}

