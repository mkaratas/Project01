#include "stm32f0xx_hal.h"
#include "sevensegment.h"

/**********************************************
	BUTTON  *		BUTTON  *		BUTTON  *		BUTTON  *
	 EXIT		*	   LEFT		*	    UP		*    ENTER  *
***********************************************/
uint8_t ButtonState[4];				//	ButtonState[0]	--->	S1		--->		Left  Most Button
															//	ButtonState[3]	--->	S3		--->		Right Most Button
uint8_t ButtonStateWait[4];
uint8_t DigitData[6];
uint8_t	Digit_Dp[6];

//	ekrana_yaz( "1.2345" );
//	ekrana_yaz( char *value );
//	ekrana_yaz( char value[6] );
//	ekrana_yaz( char value[6], char decimal_point );


const char character_table[] = {
/*---------------------------------------------------------------------*/
/* 		Array		|		Array		  |			 Array			  	|		 Array Old			 */
/*		Value		|		Number		|		Description		 		|		Description		 	 */
/*---------------------------------------------------------------------*/	
			0x77,  //			0				|		"A"  	Character		|			A	 //97 number
			0x7C,  //			1				|		"b"  	Character		|			b
			0x39,  //			2				|		"C"  	Character		|			c
			0x5E,  //			3				|		"d"  	Character		|			d
			0x79,  //			4				|		"E"  	Character		|			e
			0x71,  //			5				|		  	Character			|			f
			0x3D,  //			6				|		"G"  	Character		|			g
			0x76,  //			7				|		"H"  	Character		|			h
			0x30,  //			8				|		"I"  	Character		|			i
			0x0E,  //			9				|		"J"  	Character		|			j
			0x00,  //			10			|	"NULL"	Character		|			k
			0x38,  //			11			|		"L"  	Character		|			l
			0x00,  //			12			|	"NULL"	Character		|			m
			0x54,  //			13			|		"n"  	Character		|			n
			0x3F,  //			14			|		"O"  	Character		|			o
			0x73,  //			15			|		"P"  	Character		|			p
			0x4F,  //			16			|			  Character			|			q
			0x50,  //			17			|		"r"  	Character		|			r
			0x6D,  //			18			|		"S"  	Character		|			s
			0x78,  //			19			|			  Character			|			t
			0x1C,  //			20			|		"C"  	Character		|			u
			0x00,  //			21			|	"NULL"	Character		|			v	
			0x00,  //			22			|	"NULL"	Character		|			w
			0x00,  //			23			|	"NULL"	Character		|			x
			0x6E,  //			24			|		"Y"  	Character		|			y
			0x5B,  //			25			|		"Z"  	Character		|			z
			
			0x48,  //			26			|		"="  	Character		|			=
			0x40,  //			27			|		"-"  	Character		|			-
			
			0x3F , //			28			|		"0"  	Character		|			0
			0x06 , //			29			|		"1"		Character		|			1	
			0x5B , //			30			|		"2"		Character		|			2
			0x4F , //			31			|		"3"		Character		|			3
			0x66 , //			32			|		"4"		Character		|			4
			0x6D , //			33			|		"5"		Character		|			5
			0x7D , //			34			|		"6"		Character		|			6
			0x07 , //			35			|		"7"		Character		|			7
			0x7F , //			36			|		"8"		Character		|			8
			0x6F , //			37			|		"9"		Character		|			9
};

/*					-----------------------------------------------------------------------------------------------------------						*/
/*					***			***			***			***			***			***			***			***			***			***			***			***			***			***						*/
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_DigitSelect		( uint8_t	SelectDigit) {
	/***************************************************************************************************		
	*
	*	SelectDigit=0x01 ---> [_][_][_][_][_][X] Right Most Display Digit Enabled
	* SelectDigit=0x02 ---> [_][_][_][_][X][_]
	* SelectDigit=0x04 ---> [_][_][_][X][_][_]
	* SelectDigit=0x08 ---> [_][_][X][_][_][_]
	* SelectDigit=0x10 ---> [_][X][_][_][_][_]
	* SelectDigit=0x20 ---> [X][_][_][_][_][_] Left Most Display Digit Enabled
	*
	***************************************************************************************************/
	
	(SelectDigit&0x20) ? HAL_GPIO_WritePin(  SCAN6_GPIO_Port , SCAN6_Pin , GPIO_PIN_RESET ) : HAL_GPIO_WritePin(  SCAN6_GPIO_Port , SCAN6_Pin , GPIO_PIN_SET 	 );		
	(SelectDigit&0x10) ? HAL_GPIO_WritePin(  SCAN5_GPIO_Port , SCAN5_Pin , GPIO_PIN_RESET ) :	HAL_GPIO_WritePin(  SCAN5_GPIO_Port , SCAN5_Pin , GPIO_PIN_SET	 );
	(SelectDigit&0x08) ? HAL_GPIO_WritePin(  SCAN4_GPIO_Port , SCAN4_Pin , GPIO_PIN_RESET ) : HAL_GPIO_WritePin(  SCAN4_GPIO_Port , SCAN4_Pin , GPIO_PIN_SET   );	
	(SelectDigit&0x04) ? HAL_GPIO_WritePin(  SCAN3_GPIO_Port , SCAN3_Pin , GPIO_PIN_RESET )	:	HAL_GPIO_WritePin(  SCAN3_GPIO_Port , SCAN3_Pin , GPIO_PIN_SET   );		
	(SelectDigit&0x02) ? HAL_GPIO_WritePin(  SCAN2_GPIO_Port , SCAN2_Pin , GPIO_PIN_RESET ) :	HAL_GPIO_WritePin(  SCAN2_GPIO_Port , SCAN2_Pin , GPIO_PIN_SET   );	
	(SelectDigit&0x01) ? HAL_GPIO_WritePin(  SCAN1_GPIO_Port , SCAN1_Pin , GPIO_PIN_RESET ) : HAL_GPIO_WritePin(  SCAN1_GPIO_Port , SCAN1_Pin , GPIO_PIN_SET   );	
}
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_DigitDataWrite ( char value , uint8_t dp ) {
	((value&0x01) == 0x01) ? HAL_GPIO_WritePin( SEGA_GPIO_Port  , SEGA_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGA_GPIO_Port  , SEGA_Pin  , GPIO_PIN_SET	);
	((value&0x02) == 0x02) ? HAL_GPIO_WritePin( SEGB_GPIO_Port  , SEGB_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGB_GPIO_Port  , SEGB_Pin  , GPIO_PIN_SET	);
	((value&0x04) == 0x04) ? HAL_GPIO_WritePin( SEGC_GPIO_Port  , SEGC_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGC_GPIO_Port  , SEGC_Pin  , GPIO_PIN_SET	);
	((value&0x08) == 0x08) ? HAL_GPIO_WritePin( SEGD_GPIO_Port  , SEGD_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGD_GPIO_Port  , SEGD_Pin  , GPIO_PIN_SET	);
	((value&0x10) == 0x10) ? HAL_GPIO_WritePin( SEGE_GPIO_Port  , SEGE_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGE_GPIO_Port  , SEGE_Pin  , GPIO_PIN_SET	);
	((value&0x20) == 0x20) ? HAL_GPIO_WritePin( SEGF_GPIO_Port  , SEGF_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGF_GPIO_Port  , SEGF_Pin  , GPIO_PIN_SET	);
	((value&0x40) == 0x40) ? HAL_GPIO_WritePin( SEGG_GPIO_Port  , SEGG_Pin  , GPIO_PIN_RESET) : HAL_GPIO_WritePin( SEGG_GPIO_Port  , SEGG_Pin  , GPIO_PIN_SET	);
	
	( dp == 1 )	?	HAL_GPIO_WritePin( SEGDP_GPIO_Port , SEGDP_Pin , GPIO_PIN_RESET)	:	HAL_GPIO_WritePin( SEGDP_GPIO_Port , SEGDP_Pin , GPIO_PIN_SET);
}
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_SixDigitWrite	( char DigitString[6] , uint8_t Points ) {
//	TxData[0] = DigitString[0]; 
//	TxData[1] = DigitString[1];
//	TxData[2] = DigitString[2];
//	TxData[3] = DigitString[3];
//	TxData[4] = DigitString[4];
//	TxData[5] = DigitString[5];
//	TxData[6] = Points;
 	for( uint8_t i=0 ; i<=5 ; i++ )	{
		uint8_t volatile_value;
		volatile_value  = ( (uint8_t)DigitString[i] );
		if( (volatile_value==ASCII_NULL_VALUE) | (volatile_value==ASCII_SPACE_VALUE)  ) 
			volatile_value = 10;
		if( volatile_value == ASCII_DASH_VALUE  ) 
			volatile_value = DASH_CHARACTER;
		if( volatile_value == ASCII_EQUAL_VALUE )
			volatile_value = EQUAL_CHARACTER;
		if( (volatile_value>=ASCI_NUMBER_HEAD) & (ASCI_NUMBER_END>=volatile_value) )
			volatile_value = volatile_value - ASCI_NUMBER_HEAD + CHARACTER_TABLE_NUMBER_HEAD;
		if( (volatile_value>=ASCII_UPPERCASE_HEAD) & (ASCII_UPPERCASE_END>=volatile_value) )
			volatile_value = volatile_value - ASCII_UPPERCASE_HEAD;
		if( (volatile_value>=ASCII_LOWERCASE_HEAD) & (ASCII_LOWERCASE_END>=volatile_value) )
			volatile_value = volatile_value - ASCII_LOWERCASE_HEAD;
    DigitData[i] = character_table[volatile_value];
		Digit_Dp[5-i]  = (  (Points&(0x01<<i))>>i  );
	}
}
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_Scan						( void ) {
	static uint8_t ScanStep = 0;
	static uint8_t Selected = 0;
	static uint8_t Sampling1[6] = { 0 , 0 , 0 , 0 , 0 , 0 };
	static uint8_t Sampling2[6] = { 1 , 1 , 1 , 1 , 1 , 1 };	
	static uint8_t Sampling3[6] = { 1 , 1 , 1 , 1 , 1 , 1 };
	ScanStep++;
	switch( ScanStep )
	{
		case  1:
			SevenSegmentDisplay_DigitDataWrite( DigitData[Selected] , Digit_Dp[Selected] );
			SevenSegmentDisplay_DigitSelect( 0x01<<Selected );
			break;
		case	10:
			Sampling1[Selected] = Sampling2[Selected];		// 	Old data is saving
			Sampling2[Selected] = HAL_GPIO_ReadPin ( KRL_GPIO_Port , KRL_Pin );
			break;
		case 20:
			Sampling3[Selected] = HAL_GPIO_ReadPin ( KRL_GPIO_Port , KRL_Pin );
			break;
		case 25:
			SevenSegmentDisplay_DigitSelect( 0x00 );
			ScanStep = 0;
			Selected++;
			if( Selected > 5 ) 
				Selected = 0;
			break;
		default:
			break;
	}
//	#define BUTTON_STATE_CALCULATE(x) ( (Sampling1[x]) & (!Sampling2[x]) & (!Sampling3[x]) )
	if( (Sampling1[4]) & (!Sampling2[4]) & (!Sampling3[4]) & BTN_EXIT_WAIT ) {		//	Button_1 Most Left 	Button
		 BUTTON_EXIT = BUTTON_STATE_PRESS;
		 BTN_EXIT_WAIT = BUTTON_100MS_WAIT;
	} 
	if( (Sampling1[2]) & (!Sampling2[2]) & (!Sampling3[2]) & BTN_LEFT_WAIT ) {		//  Button_2
		 BUTTON_LEFT = BUTTON_STATE_PRESS;
		 BTN_LEFT_WAIT = BUTTON_100MS_WAIT; 		 
	}
	if( (Sampling1[5]) & (!Sampling2[5]) & (!Sampling3[5]) & BTN_UP_WAIT ) {			//  Button_3
		 BUTTON_UP = BUTTON_STATE_PRESS;	
		 BTN_UP_WAIT = BUTTON_100MS_WAIT;
	}
	if( (Sampling1[3]) & (!Sampling2[3]) & (!Sampling3[3]) & BTN_ENTR_WAIT ) {		//  Button_4  Most Right Button
		 BUTTON_ENTER =	BUTTON_STATE_PRESS;
		 BTN_ENTR_WAIT = BUTTON_100MS_WAIT;		 
	}
}
/*					----------------------------------------------------------------------------------------------------------						*/
