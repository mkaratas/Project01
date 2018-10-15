#ifndef __display_H
#define __display_H
/**				-----------------------------------------------------------------				*/
/*										Scan Order : Digit1 to Digit 6															*/
/*											First Scanned : Digit1                                    */
/*											Last  Scanned : Digit2                                    */
/*																																								*/
/*				 --------   --------   --------   --------   --------   --------				*/
/*				|        | |        | |        | |        | |        | |        |				*/
/*	  		|        | |        | |        | |        | |        | |        |				*/
/*				| DIGIT6 | | DIGIT5 | | DIGIT4 | | DIGIT3 | | DIGIT2 | | DIGIT1 |				*/
/*				|        | |        | |        | |        | |        | |        |				*/
/*				|        | |        | |        | |        | |        | |        |				*/
/*				 --------   --------   --------   --------   --------   --------				*/
/*				-----------------------------------------------------------------			 **/
#define DIGIT_1_ENABLE			HAL_GPIO_WritePin ( DS6_GPIO_Port   , DS6_Pin 	 , GPIO_PIN_RESET )
#define DIGIT_1_DISABLE   	HAL_GPIO_WritePin ( DS6_GPIO_Port   , DS6_Pin 	 , GPIO_PIN_SET   )
#define DIGIT_2_ENABLE			HAL_GPIO_WritePin ( DS5_GPIO_Port   , DS5_Pin 	 , GPIO_PIN_RESET )
#define DIGIT_2_DISABLE   	HAL_GPIO_WritePin ( DS5_GPIO_Port   , DS5_Pin 	 , GPIO_PIN_SET   )
#define DIGIT_3_ENABLE			HAL_GPIO_WritePin ( DS4_GPIO_Port   , DS4_Pin		 , GPIO_PIN_RESET )
#define DIGIT_3_DISABLE   	HAL_GPIO_WritePin ( DS4_GPIO_Port   , DS4_Pin 	 , GPIO_PIN_SET   )  
#define DIGIT_4_ENABLE			HAL_GPIO_WritePin ( DS3_GPIO_Port   , DS3_Pin 	 , GPIO_PIN_RESET ) 		
#define DIGIT_4_DISABLE   	HAL_GPIO_WritePin ( DS3_GPIO_Port   , DS3_Pin		 , GPIO_PIN_SET   ) 
#define DIGIT_5_ENABLE			HAL_GPIO_WritePin ( DS2_GPIO_Port 	, DS2_Pin 	 , GPIO_PIN_RESET )
#define DIGIT_5_DISABLE   	HAL_GPIO_WritePin ( DS2_GPIO_Port 	, DS2_Pin 	 , GPIO_PIN_SET	  ) 
#define DIGIT_6_ENABLE			HAL_GPIO_WritePin ( DS1_GPIO_Port 	, DS1_Pin 	 , GPIO_PIN_RESET )
#define DIGIT_6_DISABLE   	HAL_GPIO_WritePin ( DS1_GPIO_Port	  , DS1_Pin 	 , GPIO_PIN_SET 	)
 
#define SEGMENT_A_ENABLE		HAL_GPIO_WritePin ( SegA_GPIO_Port  , SegA_Pin   , GPIO_PIN_RESET )
#define SEGMENT_A_DISABLE   HAL_GPIO_WritePin ( SegA_GPIO_Port  , SegA_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_B_ENABLE  	HAL_GPIO_WritePin ( SegB_GPIO_Port  , SegB_Pin   , GPIO_PIN_RESET )
#define SEGMENT_B_DISABLE   HAL_GPIO_WritePin ( SegB_GPIO_Port  , SegB_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_C_ENABLE  	HAL_GPIO_WritePin ( SegC_GPIO_Port  , SegC_Pin   , GPIO_PIN_RESET )
#define SEGMENT_C_DISABLE   HAL_GPIO_WritePin ( SegC_GPIO_Port  , SegC_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_D_ENABLE  	HAL_GPIO_WritePin ( SegD_GPIO_Port  , SegD_Pin   , GPIO_PIN_RESET )
#define SEGMENT_D_DISABLE   HAL_GPIO_WritePin ( SegD_GPIO_Port  , SegD_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_E_ENABLE 		HAL_GPIO_WritePin ( SegE_GPIO_Port  , SegE_Pin   , GPIO_PIN_RESET )
#define SEGMENT_E_DISABLE   HAL_GPIO_WritePin ( SegE_GPIO_Port  , SegE_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_F_ENABLE  	HAL_GPIO_WritePin ( SegF_GPIO_Port  , SegF_Pin   , GPIO_PIN_RESET )
#define SEGMENT_F_DISABLE   HAL_GPIO_WritePin ( SegF_GPIO_Port  , SegF_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_G_ENABLE  	HAL_GPIO_WritePin ( SegG_GPIO_Port  , SegG_Pin   , GPIO_PIN_RESET )
#define SEGMENT_G_DISABLE   HAL_GPIO_WritePin ( SegG_GPIO_Port  , SegG_Pin   , GPIO_PIN_SET	  )
#define SEGMENT_DP_ENABLE 	HAL_GPIO_WritePin ( SegDp_GPIO_Port , SegDp_Pin  , GPIO_PIN_RESET )
#define SEGMENT_DP_DISABLE	HAL_GPIO_WritePin ( SegDp_GPIO_Port , SegDp_Pin  , GPIO_PIN_SET	  )

#define NULL_CHARACTER								10						//		character_table[] array number
#define EQUAL_CHARACTER 							26 						//		character_table[] array number
#define DASH_CHARACTER								27						//		character_table[] array number

#define ASCII_NULL_VALUE							0							// 
#define ASCII_SPACE_VALUE 						32						//

#define ASCII_DASH_VALUE							45						// -
#define ASCII_EQUAL_VALUE 						61						// =
#define ASCI_NUMBER_HEAD 							48						// 0
#define ASCI_NUMBER_END  							57						// 9
#define ASCII_UPPERCASE_HEAD					65						// A
#define ASCII_UPPERCASE_END						90						// Z
#define ASCII_LOWERCASE_HEAD					97						// a
#define ASCII_LOWERCASE_END 					122						// z
#define CHARACTER_TABLE_NUMBER_HEAD 	28
#define DISPLAY_MAX_DIGIT_VALUE				999999

typedef enum {
  OFF = 0,		//	Kapali
  ON					//	Acik
}DisplayState;

extern uint8_t DigitData[6];
extern uint8_t Digit_Dp[6];
extern const char character_table[];

void SevenSegmentDisplay_DigitSelect		( uint8_t	SelectDigit );
void SevenSegmentDisplay_DigitDataWrite ( char value , uint8_t dp );
void SevenSegmentDisplay_SixDigitWrite	( char DigitString[6] , uint8_t Points );
void SevenSegmentDisplay_AllSegment 	  ( DisplayState state );
void SevenSegmentDisplay_Scan						( void );
void Display_2x16LCD_DataUpdate					( char data[9] );
#endif /*__display_H */
