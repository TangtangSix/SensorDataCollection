/* USER CODE BEGIN Header */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "led.h"
#include "fire.h"
#include "smoke.h"
#include "light.h"
#include "wife.h"
#include <string.h>
#include <stdio.h>
#include "rtthread.h"
#include "stm32f4xx_it.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


uint16_t length1=0;
char com1[100]=	{0};
uint16_t length2=0;
char com2[100]=	{0};;
char c;//ָ�� 0:ֹͣ  1:��ʼ
char t[10]={0};
char h[10]={0};
int SendDataFlag=0;



//�����߳�
struct rt_thread smoke_thread;
struct rt_thread fire_thread;
struct rt_thread light_thread;
//����ջ
rt_uint8_t rt_smoke_thread_stack[512];
rt_uint8_t rt_fire_thread_stack[512];
rt_uint8_t rt_light_thread_stack[512];
//������
void smoke_task_entry(void *parameter);
void fire_task_entry(void *parameter);
void light_task_entry(void *parameter);
 
//��ʼ���̺߳���
void MX_RT_Thread_Init(void)
{
	//��ʼ���߳�
	/*
		��̬�̶߳���
		�߳���
		�߳���ں���
		�߳���ڲ���
		�߳�ջ��ַ
		�߳�ջ�ռ��С
		�߳����ȼ�
		�߳�ʱ��Ƭ
		
	*/
	rt_thread_init(&smoke_thread,"smoke",smoke_task_entry,RT_NULL,&rt_smoke_thread_stack[0],sizeof(rt_smoke_thread_stack),2,60);
	rt_thread_init(&fire_thread,"fire",fire_task_entry,RT_NULL,&rt_fire_thread_stack[0],sizeof(rt_fire_thread_stack),3,60);
	rt_thread_init(&light_thread,"light",light_task_entry,RT_NULL,&rt_light_thread_stack[0],sizeof(rt_light_thread_stack),4,60);
	//�����̵߳���
	rt_thread_startup(&smoke_thread);
	rt_thread_startup(&fire_thread);
	rt_thread_startup(&light_thread);
}
 

 
//����������
void smoke_task_entry(void *parameter)
{
	//1000ms��˸һ��
	while(1)
	{
		Detect_Smoke();
		//�쳣
		if(!SmokeFlog){
			//��Ӧָʾ������
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_RESET);
			//����������
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);
			
		}
		else{
			//��Ӧָʾ��Ϩ��
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_9,GPIO_PIN_SET);
			//�����쳣�رշ�����
			if(SmokeFlog && FireFlag && LightFlag){
				HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET);
			}
		}
		//��ʱ1000ms
		rt_thread_mdelay(1000);
	}
}
//����������
void fire_task_entry(void *parameter)
{
	//1000ms��˸һ��
	while(1)
	{
		Detect_Fire();
		//�쳣
		if(!FireFlag){
			//��Ӧָʾ������
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_RESET);
			//����������
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);
			
		}
		else{
			//��Ӧָʾ��Ϩ��
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_10,GPIO_PIN_SET);
			//�����쳣�رշ�����
			if(SmokeFlog && FireFlag && LightFlag){
				HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET);
			}
		}
		//��ʱ1000ms
		rt_thread_mdelay(1000);
	}
}
//���ռ������
void light_task_entry(void *parameter)
{
	//1000ms��˸һ��
	while(1)
	{
		Detect_Light();
		//�쳣
		if(!LightFlag){
			//��Ӧָʾ������
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
			//����������
			HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_SET);
		}
		else{
			//��Ӧָʾ��Ϩ��
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
			//�����쳣�رշ�����
			if(SmokeFlog && FireFlag && LightFlag){
				HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,GPIO_PIN_RESET);
			}
		}
		//��ʱ1000ms
		rt_thread_mdelay(1000);
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  //SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART1_UART_Init();
	MX_ADC2_Init();
	MX_DMA_Init();
	MX_ADC3_Init();
	MX_USART2_UART_Init();
	MX_ADC1_Init();
	MX_USART3_UART_Init();
	
  /* USER CODE BEGIN 2 */
	//�����ж�
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&c, 1);
	HAL_UART_Receive_IT(&huart2, (uint8_t *)&c, 1);
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&c, 1);
	
	//��ʼ��LED
	LED_SET();
	
	//��ʼ��WiFiģ��
	WIFI_Init();
	Led_Toggle();
	rt_thread_mdelay(400);
	Led_Toggle();
	rt_thread_mdelay(400);
	Led_Toggle();
	rt_thread_mdelay(400);
	Led_Toggle();
	rt_thread_mdelay(400);
	Led_Toggle();
	rt_thread_mdelay(400);
	Led_Toggle();
	
	//�������߳�����
	MX_RT_Thread_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	//	int i=0;
	while (1)
	{

		if(SendDataFlag==1){
			//�����¶�
			WIFI_SendTempData(t);
			//����ʪ��
			WIFI_SendHumData(h);
			
			printf("�¶�: %d \t ʪ��: %d",((t[0]-'0')*10+(t[1]-'0')),((h[0]-'0')*10+(h[1]-'0')));
			memset(t,0,sizeof(t));
			memset(h,0,sizeof(h));
			
			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
			rt_thread_mdelay(500);
			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
			rt_thread_mdelay(500);
			SendDataFlag=0;
		}
		rt_thread_mdelay(500);
	}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */


//�����жϴ���ص�
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//����һ
	if(huart==&huart1){
		com1[length1++]=c;
		if(com1[length1-2] == 0x0D && com1[length1-1] == 0x0A){
				HAL_UART_Transmit(&huart3, (uint8_t *)&com1, strlen(com1),0xFFFF);
				length1=0;
				printf("%s",com1);
				memset(com1,0,sizeof(com1));
		}

		//���������ж�
		HAL_UART_Receive_IT(&huart1, (uint8_t *)&c, 1);  
	}
	
	//���ڶ�
	else if(huart==&huart2){
		{
			com2[length2++]=c;
			if(length2>99){
				length2=0;
				memset(com2,0,sizeof(com2));
			}
			else{
				if(com2[length2-2] == 0x0D && com2[length2-1] == 0x0A){
					//��ȡ�¶�
					t[0]=com2[2];
					t[1]=com2[3];
					t[2]='\r';
					t[3]='\n';
					//��ȡʪ��
					h[0]=com2[6];
					h[1]=com2[7];
					h[2]='\r';
					h[3]='\n';
					SendDataFlag=1;
					//��ӡ��ʪ��
					length2=0;
					memset(com2,0,sizeof(com2));

				}
			}
			
		}
					//���������ж�
		HAL_UART_Receive_IT(&huart2, (uint8_t *)&c, 1); 
	}
	
	else if(huart==&huart3){
		buf[length3++]=c;
		if(buf[length3-2] == 0x0D && buf[length3-1] == 0x0A){
				for(int i=0;i<length3;i++){
						com3[i]=buf[i];
				}
				memset(buf,0,sizeof(buf));
				length3=0;
		}
		//���������ж�
		HAL_UART_Receive_IT(&huart3, (uint8_t *)&c, 1); 
	}
}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
