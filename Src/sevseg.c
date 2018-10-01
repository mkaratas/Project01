#include "stm32f0xx_hal.h"
#include "sevseg.h"


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
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_DigitDataWrite ( char value , uint8_t dp ) {
	((value&0x01) == 0x01) ? SEGMENT_A_ENABLE  : SEGMENT_A_DISABLE;
	((value&0x02) == 0x02) ? SEGMENT_B_ENABLE  : SEGMENT_B_DISABLE;
	((value&0x04) == 0x04) ? SEGMENT_C_ENABLE  : SEGMENT_C_DISABLE;
	((value&0x08) == 0x08) ? SEGMENT_D_ENABLE  : SEGMENT_D_DISABLE;
	((value&0x10) == 0x10) ? SEGMENT_E_ENABLE  : SEGMENT_E_DISABLE;
	((value&0x20) == 0x20) ? SEGMENT_F_ENABLE  : SEGMENT_F_DISABLE;
	((value&0x40) == 0x40) ? SEGMENT_G_ENABLE  : SEGMENT_G_DISABLE;	
	
	( dp == 1 )						 ? SEGMENT_DP_ENABLE : SEGMENT_DP_DISABLE;
}
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_SixDigitWrite	( char DigitString[6] , uint8_t Points ) {
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
    DigitData[5-i] = character_table[volatile_value];
		Digit_Dp [ i ]  = (  (Points&(0x01<<i))>>i  );
	}
}
/*					----------------------------------------------------------------------------------------------------------						*/
void SevenSegmentDisplay_Scan						( void ) {
	static uint8_t ScanStep = 0;
	static uint8_t Selected = 0;
	ScanStep++;
	switch ( ScanStep ) {
		case  1 :		// Taramanin 25 de biri kadar bütün displayleri pasf yapma
			SevenSegmentDisplay_DigitSelect   ( 0x01<<Selected );
			SevenSegmentDisplay_DigitDataWrite( DigitData[Selected] , Digit_Dp[Selected] );
			break;
		case 24 :
			SevenSegmentDisplay_DigitSelect		( 0x00 );
			SevenSegmentDisplay_DigitDataWrite( 0xFF , 0x01 );		
			break;
		case 25 :	// Tarama sirasi gelen display datlarini kesme
	    
			ScanStep = 0;
			Selected++;
			if( Selected > 5 ) 
				Selected = 0;
			break;
		
		default :
			break;
	}
}
/*					----------------------------------------------------------------------------------------------------------						*/
