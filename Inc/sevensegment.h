#ifndef __display_H
#define __display_H

#define NULL_CHARACTER				10						//		character_table[] array number
#define EQUAL_CHARACTER 			26 						//		character_table[] array number
#define DASH_CHARACTER				27						//		character_table[] array number

#define ASCII_NULL_VALUE			0							// 
#define ASCII_SPACE_VALUE 		32						//

#define ASCII_DASH_VALUE			45						// -
#define ASCII_EQUAL_VALUE 		61						// =
#define ASCI_NUMBER_HEAD 			48						// 0
#define ASCI_NUMBER_END  			57						// 9
#define ASCII_UPPERCASE_HEAD	65						// A
#define ASCII_UPPERCASE_END		90						// Z
#define ASCII_LOWERCASE_HEAD	97						// a
#define ASCII_LOWERCASE_END 	122						// z
#define CHARACTER_TABLE_NUMBER_HEAD 28

#define DISPLAY_MAX_DIGIT_VALUE	999999

#define BUTTON_STATE_PRESS	1
#define BUTTON_STATE_RESET  0

#define BUTTON_100MS_WAIT		0
#define BUTTON_100MS_OK			1

#define DIGIT_1	0
#define	DIGIT_2	1
#define	DIGIT_3 2
#define	DIGIT_4 3
#define	DIGIT_5 4
#define	DIGIT_6 5

#define BUTTON_EXIT 	ButtonState[0]
#define BUTTON_LEFT		ButtonState[1]
#define BUTTON_UP   	ButtonState[2]
#define BUTTON_ENTER  ButtonState[3]    

#define BTN_EXIT_WAIT	ButtonStateWait[0]
#define BTN_LEFT_WAIT ButtonStateWait[1]
#define BTN_UP_WAIT   ButtonStateWait[2]
#define BTN_ENTR_WAIT ButtonStateWait[3]

extern uint8_t ButtonState[4];				//	ButtonState[0]	--->	S1		--->		Left  Most Button
																			//	ButtonState[3]	--->	S3		--->		Right Most Button
extern uint8_t ButtonStateWait[4];

extern uint8_t DigitData[6];
extern uint8_t Digit_Dp[6];


void SevenSegmentDisplay_DigitSelect( uint8_t	SelectDigit);
void SevenSegmentDisplay_DigitDataWrite( char value , uint8_t dp );
void SevenSegmentDisplay_SixDigitWrite( char DigitString[6] , uint8_t Points );
void SevenSegmentDisplay_Scan			(void);

#endif /*__display_H */
