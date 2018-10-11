#include "main.h"
#include "stm32f0xx_hal.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "sevseg.h"
#include "lcd2x16.h"
#include "menu.h"
#include "panel.h"

control_state Control_msn1;

			
/****		*****		*****		*****		*****		****/
void SystemClock_Config(void);
/****		*****		*****		*****		*****		****/
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef *htim ) {
	if( htim->Instance == TIM6 )					//	1000(Hz) --> 1 msn
		Control_msn1 = CHECKIT;
//	if( htim->Instance == TIM3 )					// 100 000(Hz) --> 10usn
//		Control_msn1 = CHECKIT;
}
/****		*****		*****		*****		*****		****/
int main ( void ) {

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
	
	MX_TIM6_Init();
	
//  MX_DMA_Init();
//  MX_USART1_UART_Init();

  MX_TIM3_Init();

	lcd2x16_Init();
	lcd2x16_Write_String( "    2x16 LCD");
	lcd2x16_Position( LCD_LINE_2 , 1 );
	lcd2x16_Write_String( " #  DENEMESI  #");
	
	HAL_Delay( 2000 );
	__LCD2X16_CLEAR; 

	Menu_Init(); 

	Lcd2x16_BufferSet( LCD_LINE_1 , "123456789ABCDEF");
	Lcd2x16_BufferSet( LCD_LINE_2 , "abcdefghijklmnt");
	SevenSegmentDisplay_SixDigitWrite	( "123456" , 0x00 );
	HAL_TIM_Base_Start_IT( &htim6 );
	
//  HAL_TIM_Base_Start_IT( &htim3 );

	while ( 1 ) {
		if ( Control_msn1 == CHECKIT ) {
			SevenSegmentDisplay_Scan();			//	RunTime = 21 usn 
			Panel_Scan_Led_Button();        //  RunTime = 5 usn 
			Lcd2x16_Scan();									//	RunTime = 8 usn 
			Control_msn1 = CHECKED;			
		}
	}
}
/****		*****		*****		*****		*****		****/
/** System Clock Configuration
*/
void SystemClock_Config ( void ) {

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

   /**Initializes the CPU, AHB and APB busses clocks 
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
