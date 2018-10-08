#ifndef __MAIN_H
#define __MAIN_H
 
#define SegA_Pin 					GPIO_PIN_6
#define SegA_GPIO_Port 		GPIOB

#define SegB_Pin 					GPIO_PIN_7
#define SegB_GPIO_Port 		GPIOB

#define SegC_Pin 					GPIO_PIN_5
#define SegC_GPIO_Port 		GPIOB

#define SegD_Pin 					GPIO_PIN_4
#define SegD_GPIO_Port 		GPIOB

#define SegE_Pin 					GPIO_PIN_15
#define SegE_GPIO_Port 		GPIOA

#define SegF_Pin 					GPIO_PIN_7
#define SegF_GPIO_Port 		GPIOF

#define SegG_Pin 					GPIO_PIN_12
#define SegG_GPIO_Port 		GPIOA

#define SegDp_Pin 				GPIO_PIN_9
#define SegDp_GPIO_Port 	GPIOB

#define DS1_Pin 					GPIO_PIN_8
#define DS1_GPIO_Port 		GPIOB

#define DS2_Pin	 					GPIO_PIN_3
#define DS2_GPIO_Port 		GPIOB

#define DS3_Pin 					GPIO_PIN_15
#define DS3_GPIO_Port 		GPIOC

#define DS4_Pin 					GPIO_PIN_14
#define DS4_GPIO_Port 		GPIOC

#define DS5_Pin 					GPIO_PIN_6
#define DS5_GPIO_Port 		GPIOF

#define DS6_Pin 					GPIO_PIN_13
#define DS6_GPIO_Port 		GPIOC

#define DB0_Pin 					GPIO_PIN_7
#define DB0_GPIO_Port 		GPIOA

#define DB1_Pin 					GPIO_PIN_6
#define DB1_GPIO_Port 		GPIOA

#define DB2_Pin 					GPIO_PIN_5
#define DB2_GPIO_Port 		GPIOA

#define DB3_Pin 					GPIO_PIN_4
#define DB3_GPIO_Port 		GPIOA

#define DB4_Pin 					GPIO_PIN_3
#define DB4_GPIO_Port 		GPIOA

#define DB5_Pin 					GPIO_PIN_2
#define DB5_GPIO_Port 		GPIOA

#define DB6_Pin 					GPIO_PIN_1
#define DB6_GPIO_Port 		GPIOA

#define DB7_Pin 					GPIO_PIN_0
#define DB7_GPIO_Port 		GPIOA

#define DBE_Pin 					GPIO_PIN_0 
#define DBE_GPIO_Port			GPIOB

#define DBRW_Pin 					GPIO_PIN_1
#define DBRW_GPIO_Port 		GPIOB

#define DBRS_Pin 					GPIO_PIN_10
#define DBRS_GPIO_Port 		GPIOB 

#define Panel1_Pin 				GPIO_PIN_11
#define Panel1_GPIO_Port	GPIOB

#define Panel2_Pin 				GPIO_PIN_11
#define Panel2_GPIO_Port	GPIOA

#define Panel3_Pin 				GPIO_PIN_12
#define Panel3_GPIO_Port 	GPIOB
 
#define Panel4_Pin 				GPIO_PIN_13
#define Panel4_GPIO_Port	GPIOB

#define Panel5_Pin 				GPIO_PIN_14
#define Panel5_GPIO_Port 	GPIOB

#define Panel6_Pin 				GPIO_PIN_15
#define Panel6_GPIO_Port 	GPIOB

#define Panel7_Pin 				GPIO_PIN_8
#define Panel7_GPIO_Port 	GPIOA


typedef enum {
  CHECKED = 0,		//	 kontrol edildi
  CHECKIT					//	 kontrol et
}control_state;

extern control_state Control_SevSegScan,
										 Control_PanelScan;

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
