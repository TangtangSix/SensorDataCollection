#include "wife.h"
#include "rtthread.h"

char buf[100]={0};
char com3[100]={0};
uint16_t length3=0;

void WIFI_Init(void){
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT\r\n", strlen("AT\r\n"),0xFFFF);
	rt_thread_mdelay(100);
	printf("%s",com3);
	memset(com3,0,sizeof(com3));

	//���ó�AP+STAģʽ
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT+CWMODE=3\r\n", strlen("AT+CWMODE=3\r\n"),0xFFFF);
	rt_thread_mdelay(100);
	printf("���ó�AP+STAģʽ %s",com3);	
	memset(com3,0,sizeof(com3));

	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
	
	//������Ч
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT+RST\r\n", strlen("AT+RST\r\n"),0xFFFF);
	rt_thread_mdelay(5000);
	printf("������Ч %s",com3);
	memset(com3,0,sizeof(com3));

	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
	
	//��ѯ�豸IP
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT+CIFSR\r\n", strlen("AT+CIFSR\r\n"),0xFFFF);
	rt_thread_mdelay(1000);
	printf("��ѯ�豸IP %s",com3);
	memset(com3,0,sizeof(com3));

	//���÷�����IP��ַ�˿ں�
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT+CIPSTART=\"TCP\",\"183.230.40.33\",80\r\n", strlen("AT+CIPSTART=\"TCP\",\"183.230.40.33\",80\r\n"),0xFFFF);
	rt_thread_mdelay(2000);
	printf("���÷�����IP��ַ�˿ں� %s",com3);
	memset(com3,0,sizeof(com3));

	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);

	//����͸��ģʽ
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT+CIPMODE=1\r\n", strlen("AT+CIPMODE=1\r\n"),0xFFFF);
	rt_thread_mdelay(1000);
	printf("����͸��ģʽ %s",com3);
	memset(com3,0,sizeof(com3));

	//��ʼ͸��
	HAL_UART_Transmit(&huart3, (uint8_t *)"AT+CIPSEND\r\n", strlen("AT+CIPSEND\r\n"),0xFFFF);
	rt_thread_mdelay(1000);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);
}

void WIFI_SendTempData(char *data){
	HAL_UART_Transmit(&huart3, (uint8_t *)"POST /devices/806166105/datapoints?type=5 HTTP/1.1\n", strlen("POST /devices/806166105/datapoints?type=5 HTTP/1.1\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)"api-key: z9yJbkoNEmz=36sGjmJQUNVZmzM=\n", strlen("api-key: z9yJbkoNEmz=36sGjmJQUNVZmzM=\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)"Host:api.heclouds.com\n", strlen("Host:api.heclouds.com\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)"Content-Length:10\n\n", strlen("Content-Length:10\n\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)",;Temp,", strlen(",;Temp,"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)data, strlen(data),0xFFFF);

}

void WIFI_SendHumData(char *data){
	HAL_UART_Transmit(&huart3, (uint8_t *)"POST /devices/806166105/datapoints?type=5 HTTP/1.1\n", strlen("POST /devices/806166105/datapoints?type=5 HTTP/1.1\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)"api-key: z9yJbkoNEmz=36sGjmJQUNVZmzM=\n", strlen("api-key: z9yJbkoNEmz=36sGjmJQUNVZmzM=\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)"Host:api.heclouds.com\n", strlen("Host:api.heclouds.com\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)"Content-Length:9\n\n", strlen("Content-Length:9\n\n"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)",;Hum,", strlen(",;Hum,"),0xFFFF);
	HAL_UART_Transmit(&huart3, (uint8_t *)data, strlen(data),0xFFFF);
}

