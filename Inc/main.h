/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define DS6_Pin GPIO_PIN_13
#define DS6_GPIO_Port GPIOC
#define DS4_Pin GPIO_PIN_14
#define DS4_GPIO_Port GPIOC
#define DS3_Pin GPIO_PIN_15
#define DS3_GPIO_Port GPIOC
#define DB7_Pin GPIO_PIN_0
#define DB7_GPIO_Port GPIOA
#define DB6_Pin GPIO_PIN_1
#define DB6_GPIO_Port GPIOA
#define DB5_Pin GPIO_PIN_2
#define DB5_GPIO_Port GPIOA
#define DB4_Pin GPIO_PIN_3
#define DB4_GPIO_Port GPIOA
#define DB3_Pin GPIO_PIN_4
#define DB3_GPIO_Port GPIOA
#define DB2_Pin GPIO_PIN_5
#define DB2_GPIO_Port GPIOA
#define DB1_Pin GPIO_PIN_6
#define DB1_GPIO_Port GPIOA
#define DB0_Pin GPIO_PIN_7
#define DB0_GPIO_Port GPIOA
#define DB_E_Pin GPIO_PIN_0
#define DB_E_GPIO_Port GPIOB
#define DB_RW_Pin GPIO_PIN_1
#define DB_RW_GPIO_Port GPIOB
#define DB_RS_Pin GPIO_PIN_10
#define DB_RS_GPIO_Port GPIOB
#define Relay1_Pin GPIO_PIN_11
#define Relay1_GPIO_Port GPIOB
#define Relay3_Pin GPIO_PIN_12
#define Relay3_GPIO_Port GPIOB
#define Relay4_Pin GPIO_PIN_13
#define Relay4_GPIO_Port GPIOB
#define Relay5_Pin GPIO_PIN_14
#define Relay5_GPIO_Port GPIOB
#define Relay6_Pin GPIO_PIN_15
#define Relay6_GPIO_Port GPIOB
#define Relay7_Pin GPIO_PIN_8
#define Relay7_GPIO_Port GPIOA
#define Relay2_Pin GPIO_PIN_11
#define Relay2_GPIO_Port GPIOA
#define Seg_G_Pin GPIO_PIN_12
#define Seg_G_GPIO_Port GPIOA
#define DS5_Pin GPIO_PIN_6
#define DS5_GPIO_Port GPIOF
#define Seg_F_Pin GPIO_PIN_7
#define Seg_F_GPIO_Port GPIOF
#define Seg_E_Pin GPIO_PIN_15
#define Seg_E_GPIO_Port GPIOA
#define DS2_Pin GPIO_PIN_3
#define DS2_GPIO_Port GPIOB
#define Seg_D_Pin GPIO_PIN_4
#define Seg_D_GPIO_Port GPIOB
#define Seg_C_Pin GPIO_PIN_5
#define Seg_C_GPIO_Port GPIOB
#define Seg_A_Pin GPIO_PIN_6
#define Seg_A_GPIO_Port GPIOB
#define Seg_B_Pin GPIO_PIN_7
#define Seg_B_GPIO_Port GPIOB
#define DS1_Pin GPIO_PIN_8
#define DS1_GPIO_Port GPIOB
#define Seg_DP_Pin GPIO_PIN_9
#define Seg_DP_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

typedef enum {
  CHECKED = 0,		//	 kontrol edildi
  CHECKIT					//	 kontrol et
}control_state;

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
