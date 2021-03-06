#include "stm32f0xx_hal.h"
#include "sevseg.h"

#include "main.h"

uint8_t DigitData[6];
uint8_t	Digit_Dp[6];

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
/****		*****		*****		*****		*****		****/		
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
	(SelectDigit&0x20) ? DIGIT_6_ENABLE : DIGIT_6_DISABLE;	
	(SelectDigit&0x10) ? DIGIT_5_ENABLE :	DIGIT_5_DISABLE;
	(SelectDigit&0x08) ? DIGIT_4_ENABLE : DIGIT_4_DISABLE;	
	(SelectDigit&0x04) ? DIGIT_3_ENABLE	:	DIGIT_3_DISABLE;		
	(SelectDigit&0x02) ? DIGIT_2_ENABLE :	DIGIT_2_DISABLE;	
	(SelectDigit&0x01) ? DIGIT_1_ENABLE : DIGIT_1_DISABLE;	
}
/****		*****		*****		*****		*****		****/
void SevenSegmentDisplay_DigitDataWrite ( char value , uint8_t dp ) {
	((value&0x01) == 0x01) ? SEGMENT_A_ENABLE  : SEGMENT_A_DISABLE;
	((value&0x02) == 0x02) ? SEGMENT_B_ENABLE  : SEGMENT_B_DISABLE;
	((value&0x04) == 0x04) ? SEGMENT_C_ENABLE  : SEGMENT_C_DISABLE;
	((value&0x08) == 0x08) ? SEGMENT_D_ENABLE  : SEGMENT_D_DISABLE;
	((value&0x10) == 0x10) ? SEGMENT_E_ENABLE  : SEGMENT_E_DISABLE;
	((value&0x20) == 0x20) ? SEGMENT_F_ENABLE  : SEGMENT_F_DISABLE;
	((value&0x40) == 0x40) ? SEGMENT_G_ENABLE  : SEGMENT_G_DISABLE;	
	( 		dp			== 0x01) ? SEGMENT_DP_ENABLE : SEGMENT_DP_DISABLE;
}
/****		*****		*****		*****		*****		****/
void SevenSegmentDisplay_SixDigitWrite	( char DigitString[6] , uint8_t Points ) {
 	for( uint8_t i=0 ; i<=5 ; i++ )	{
		uint8_t casual_val;
		casual_val  = ( (uint8_t)DigitString[i] );
		if( (casual_val==ASCII_NULL_VALUE) | (casual_val==ASCII_SPACE_VALUE)  ) 
			casual_val = 10;
		if( casual_val == ASCII_DASH_VALUE  ) 
			casual_val = DASH_CHARACTER;
		if( casual_val == ASCII_EQUAL_VALUE )
			casual_val = EQUAL_CHARACTER;
		if( (casual_val>=ASCI_NUMBER_HEAD) & (ASCI_NUMBER_END>=casual_val) )
			casual_val = casual_val - ASCI_NUMBER_HEAD + CHARACTER_TABLE_NUMBER_HEAD;
		if( (casual_val>=ASCII_UPPERCASE_HEAD) & (ASCII_UPPERCASE_END>=casual_val) )
			casual_val = casual_val - ASCII_UPPERCASE_HEAD;
		if( (casual_val>=ASCII_LOWERCASE_HEAD) & (ASCII_LOWERCASE_END>=casual_val) )
			casual_val = casual_val - ASCII_LOWERCASE_HEAD;
    DigitData[5-i] = character_table[casual_val];
		Digit_Dp [ i ] = (  (Points&(0x01<<i))>>i  );
	}
}
/****		*****		*****		*****		*****		****/
void SevenSegmentDisplay_AllSegment 	  ( DisplayState state ) {
	if ( state == ON ) {
			SEGMENT_A_ENABLE;
			SEGMENT_B_ENABLE;
			SEGMENT_C_ENABLE;
			SEGMENT_D_ENABLE;
			SEGMENT_E_ENABLE;
			SEGMENT_F_ENABLE;
			SEGMENT_G_ENABLE;
			SEGMENT_DP_ENABLE;
	}
	else/*State==OFF*/ {
			SEGMENT_A_DISABLE;
			SEGMENT_B_DISABLE;
			SEGMENT_C_DISABLE;
			SEGMENT_D_DISABLE;
			SEGMENT_E_DISABLE;
			SEGMENT_F_DISABLE;
			SEGMENT_G_DISABLE;
			SEGMENT_DP_DISABLE;
	}

}
/****		*****		*****		*****		*****		****/
void SevenSegmentDisplay_Scan						( void ) {
	SevenSegmentDisplay_DigitSelect		( 0x00 );
	SevenSegmentDisplay_AllSegment		( OFF );
	static uint8_t SelectedDigit = 0;
  SelectedDigit++;
	if ( SelectedDigit >5 )
		SelectedDigit = 0;
	SevenSegmentDisplay_DigitDataWrite( DigitData[SelectedDigit] , Digit_Dp[SelectedDigit] );
	SevenSegmentDisplay_DigitSelect 	( 0x01<<SelectedDigit );
}
/****		*****		*****		*****		*****		****/
