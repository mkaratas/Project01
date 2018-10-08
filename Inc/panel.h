#ifndef __panel_H
#define __panel_H


#define PanelLedsAnode_High		HAL_GPIO_WritePin( Panel1_GPIO_Port , Panel1_Pin , GPIO_PIN_RESET )
#define PanelLedsAnode_Low    HAL_GPIO_WritePin( Panel1_GPIO_Port , Panel1_Pin , GPIO_PIN_SET   )

#define PanelLed_L1_ON        HAL_GPIO_WritePin( Panel6_GPIO_Port , Panel6_Pin , GPIO_PIN_RESET )
#define PanelLed_L1_OFF       HAL_GPIO_WritePin( Panel6_GPIO_Port , Panel6_Pin , GPIO_PIN_SET   )

#define PanelLed_L2_ON        HAL_GPIO_WritePin( Panel5_GPIO_Port , Panel5_Pin , GPIO_PIN_RESET )
#define PanelLed_L2_OFF       HAL_GPIO_WritePin( Panel5_GPIO_Port , Panel5_Pin , GPIO_PIN_SET   )

#define PanelLed_L3_ON        HAL_GPIO_WritePin( Panel4_GPIO_Port , Panel4_Pin , GPIO_PIN_RESET )
#define PanelLed_L3_OFF       HAL_GPIO_WritePin( Panel4_GPIO_Port , Panel4_Pin , GPIO_PIN_SET 	)

#define PanelLed_L4_ON        HAL_GPIO_WritePin( Panel7_GPIO_Port , Panel7_Pin , GPIO_PIN_RESET )
#define PanelLed_L4_OFF       HAL_GPIO_WritePin( Panel7_GPIO_Port , Panel7_Pin , GPIO_PIN_SET 	)

#define BTN_MENU_STATE        HAL_GPIO_ReadPin ( Panel3_GPIO_Port , Panel3_Pin )
#define BTN_START_STATE       HAL_GPIO_ReadPin ( Panel3_GPIO_Port , Panel3_Pin )
#define BTN_ENTER_STATE       HAL_GPIO_ReadPin ( Panel3_GPIO_Port , Panel3_Pin )
#define BTN_UP_STATE          HAL_GPIO_ReadPin ( Panel3_GPIO_Port , Panel3_Pin )
#define BTN_RIGHT_STATE       HAL_GPIO_ReadPin ( Panel2_GPIO_Port , Panel2_Pin )
#define BTN_DOWN_STATE        HAL_GPIO_ReadPin ( Panel2_GPIO_Port , Panel2_Pin )
#define BTN_LEFT_STATE				HAL_GPIO_ReadPin ( Panel2_GPIO_Port , Panel2_Pin )

#define BTN_ARRAY_NUMBER_MENU		0
#define BTN_ARRAY_NUMBER_START  1
#define BTN_ARRAY_NUMBER_UP     2
#define BTN_ARRAY_NUMBER_ENTER  3
#define BTN_ARRAY_NUMBER_DOWN   4
#define BTN_ARRAY_NUMBER_RIGHT  5
#define BTN_ARRAY_NUMBER_LEFT   6

				 
typedef enum {
  LED_OFF = 0,		//	 
  LED_ON					//
}PanelLed;

typedef enum {
  NotPress = 0,		//	 
  Press						//	 
}PanelButtonState;


void Panel_Scan_Led_Button ( void );

#endif /* __PANEL_H */
