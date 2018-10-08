#include "stm32f0xx_hal.h"

#include "gpio.h"

#include "panel.h"


PanelLed 					PanelLed_L1_State = LED_ON,
									PanelLed_L2_State = LED_OFF ,
									PanelLed_L3_State = LED_ON, 
									PanelLed_L4_State = LED_OFF;

PanelButtonState  Button_Menu,
								  Button_Start,
								  Button_Up,
								  Button_Right,
								  Button_Down,
								  Button_Left,
							    Button_Enter;
									
uint16_t count_menu = 0,
				 count_start= 0,
				 count_up   = 0,
				 count_right= 0,
				 count_down = 0,
				 count_left = 0,
				 count_enter= 0;


void Panel_Scan_Led_Button ( void ) {
 static uint8_t step_counter;			//	A value of 5 mili seconds increases
 static GPIO_PinState sampling1[7];
 static GPIO_PinState sampling2[7];
 static GPIO_PinState sampling3[7];
 step_counter++;
 switch ( step_counter ) {
		case 1: {
			PanelLedsAnode_High;
			( PanelLed_L1_State == LED_ON ) ? PanelLed_L1_ON : PanelLed_L1_OFF;
			( PanelLed_L2_State == LED_ON ) ? PanelLed_L2_ON : PanelLed_L2_OFF;
			( PanelLed_L3_State == LED_ON ) ? PanelLed_L3_ON : PanelLed_L3_OFF;
			( PanelLed_L4_State == LED_ON ) ? PanelLed_L4_ON : PanelLed_L4_OFF;
			break;
		}
	  case 2: {
			PanelLedsAnode_Low;
			HAL_GPIO_WritePin( Panel7_GPIO_Port , Panel7_Pin , GPIO_PIN_SET 	);
			HAL_GPIO_WritePin( Panel6_GPIO_Port , Panel6_Pin , GPIO_PIN_RESET );
			HAL_GPIO_WritePin( Panel5_GPIO_Port , Panel5_Pin , GPIO_PIN_RESET );
			HAL_GPIO_WritePin( Panel4_GPIO_Port , Panel4_Pin , GPIO_PIN_RESET );					                     
			break;
		}
		case 3: {
			/****	*****	Enter Buton Islemleri *****	****/
			sampling3[ BTN_ARRAY_NUMBER_ENTER ] = BTN_ENTER_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_ENTER] & !sampling2[BTN_ARRAY_NUMBER_ENTER] & sampling3[BTN_ARRAY_NUMBER_ENTER] )
					count_enter++;	//	Button_Enter = Press;
					
			/****	*****	Right Buton Islemleri *****	****/		
			sampling3[ BTN_ARRAY_NUMBER_RIGHT ] = BTN_RIGHT_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_RIGHT] & !sampling2[BTN_ARRAY_NUMBER_RIGHT] & sampling3[BTN_ARRAY_NUMBER_RIGHT] )
					count_right++;	//	Button_Right = Press;
					
			HAL_GPIO_WritePin( Panel7_GPIO_Port , Panel7_Pin , GPIO_PIN_RESET	);
			HAL_GPIO_WritePin( Panel6_GPIO_Port , Panel6_Pin , GPIO_PIN_SET		);
			break;
		}
		case 4: {
			/****	*****	Down Buton Islemleri *****	****/
			sampling3[ BTN_ARRAY_NUMBER_DOWN ] = BTN_DOWN_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_DOWN]  & !sampling2[BTN_ARRAY_NUMBER_DOWN]  & sampling3[BTN_ARRAY_NUMBER_DOWN] 	)
					count_down++;		//	Button_Down = Press;
			
			/****	*****	Up   Buton Islemleri *****	****/
			sampling3[ BTN_ARRAY_NUMBER_UP	 ] = BTN_UP_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_UP] 	 & !sampling2[BTN_ARRAY_NUMBER_UP] 	  & sampling3[BTN_ARRAY_NUMBER_UP] 	  )
					count_up++;			//	Button_Up = Press;
					
			HAL_GPIO_WritePin( Panel6_GPIO_Port , Panel6_Pin , GPIO_PIN_RESET );
			HAL_GPIO_WritePin( Panel5_GPIO_Port , Panel5_Pin , GPIO_PIN_SET   );
			break;
		}
		case 5: {
			/****	*****	Menu Buton Islemleri *****	****/
			sampling3[ BTN_ARRAY_NUMBER_MENU ] = BTN_MENU_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_MENU]  & !sampling2[BTN_ARRAY_NUMBER_MENU]  & sampling3[BTN_ARRAY_NUMBER_MENU]  )
					count_menu++;		//	Button_Menu = Press;
			/****	*****	Left Buton Islemleri *****	****/
			sampling3[ BTN_ARRAY_NUMBER_LEFT ] = BTN_LEFT_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_LEFT]  & !sampling2[BTN_ARRAY_NUMBER_LEFT]  & sampling3[BTN_ARRAY_NUMBER_LEFT] 	)
					count_left++;		//	Button_Left = Press;
					
			HAL_GPIO_WritePin( Panel5_GPIO_Port , Panel5_Pin , GPIO_PIN_RESET );
			HAL_GPIO_WritePin( Panel4_GPIO_Port , Panel4_Pin , GPIO_PIN_SET   );
			break;
		}
		case 6: {
			sampling3[ BTN_ARRAY_NUMBER_START	 ] = BTN_START_STATE;
			if( !sampling1[BTN_ARRAY_NUMBER_START] & !sampling2[BTN_ARRAY_NUMBER_START] & sampling3[BTN_ARRAY_NUMBER_START] )
					count_start++;	//	Button_Start = Press;
			for( uint8_t i = 0 ; i<=6 ; i++ ) {
				sampling1[i] = sampling2[i];
				sampling2[i] = sampling3[i];
			}
			HAL_GPIO_WritePin( Panel4_GPIO_Port , Panel4_Pin , GPIO_PIN_RESET );
		  step_counter = 0;
		
		}
		
			
 }
 
}

