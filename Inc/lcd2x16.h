#ifndef __lcd2x16_H
#define __lcd2x16_H 


#define LCD2X16_PIN_RS_STATE_HIGH 	HAL_GPIO_WritePin( DB_RS_GPIO_Port  , DB_RS_Pin , GPIO_PIN_SET )
#define LCD2X16_PIN_RW_STATE_HIGH 	HAL_GPIO_WritePin( DB_RW_GPIO_Port  , DB_RW_Pin , GPIO_PIN_SET )
#define LCD2X16_PIN_E_STATE_HIGH 		HAL_GPIO_WritePin( DB_E_GPIO_Port 	, DB_E_Pin	, GPIO_PIN_SET )
#define LCD2X16_PIN_D7_STATE_HIGH 	HAL_GPIO_WritePin( DB7_GPIO_Port 		, DB7_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D6_STATE_HIGH 	HAL_GPIO_WritePin( DB6_GPIO_Port 		, DB6_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D5_STATE_HIGH 	HAL_GPIO_WritePin( DB5_GPIO_Port 		, DB5_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D4_STATE_HIGH 	HAL_GPIO_WritePin( DB4_GPIO_Port 		, DB4_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D3_STATE_HIGH 	HAL_GPIO_WritePin( DB3_GPIO_Port 		, DB3_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D2_STATE_HIGH 	HAL_GPIO_WritePin( DB2_GPIO_Port 		, DB2_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D1_STATE_HIGH 	HAL_GPIO_WritePin( DB1_GPIO_Port 		, DB1_Pin 	, GPIO_PIN_SET )
#define LCD2X16_PIN_D0_STATE_HIGH 	HAL_GPIO_WritePin( DB0_GPIO_Port 		, DB0_Pin 	, GPIO_PIN_SET )

#define LCD2X16_PIN_RS_STATE_LOW		HAL_GPIO_WritePin( DB_RS_GPIO_Port  , DB_RS_Pin , GPIO_PIN_RESET )
#define LCD2X16_PIN_RW_STATE_LOW		HAL_GPIO_WritePin( DB_RW_GPIO_Port  , DB_RW_Pin , GPIO_PIN_RESET )
#define LCD2X16_PIN_E_STATE_LOW			HAL_GPIO_WritePin( DB_E_GPIO_Port   , DB_E_Pin  , GPIO_PIN_RESET )
#define LCD2X16_PIN_D7_STATE_LOW		HAL_GPIO_WritePin( DB7_GPIO_Port 	  , DB7_Pin   , GPIO_PIN_RESET )
#define LCD2X16_PIN_D6_STATE_LOW		HAL_GPIO_WritePin( DB6_GPIO_Port 	  , DB6_Pin   , GPIO_PIN_RESET )
#define LCD2X16_PIN_D5_STATE_LOW		HAL_GPIO_WritePin( DB5_GPIO_Port    , DB5_Pin   , GPIO_PIN_RESET )
#define LCD2X16_PIN_D4_STATE_LOW		HAL_GPIO_WritePin( DB4_GPIO_Port    , DB4_Pin   , GPIO_PIN_RESET )
#define LCD2X16_PIN_D3_STATE_LOW		HAL_GPIO_WritePin( DB3_GPIO_Port    , DB3_Pin 	, GPIO_PIN_RESET )
#define LCD2X16_PIN_D2_STATE_LOW		HAL_GPIO_WritePin( DB2_GPIO_Port    , DB2_Pin   , GPIO_PIN_RESET )
#define LCD2X16_PIN_D1_STATE_LOW		HAL_GPIO_WritePin( DB1_GPIO_Port    , DB1_Pin 	, GPIO_PIN_RESET )
#define LCD2X16_PIN_D0_STATE_LOW		HAL_GPIO_WritePin( DB0_GPIO_Port    , DB0_Pin 	, GPIO_PIN_RESET )

#define LCD2X16_PIN_RS_STATE( x ) 	( x ) ? ( LCD2X16_PIN_RS_STATE_HIGH ) : ( LCD2X16_PIN_RS_STATE_LOW );
#define LCD2X16_PIN_RW_STATE( x ) 	( x ) ? ( LCD2X16_PIN_RW_STATE_HIGH ) : ( LCD2X16_PIN_RW_STATE_LOW );
#define LCD2X16_PIN_E_STATE( x ) 	  ( x ) ? ( LCD2X16_PIN_E_STATE_HIGH  ) : ( LCD2X16_PIN_E_STATE_LOW  );
#define LCD2X16_PIN_D7_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D7_STATE_HIGH ) : ( LCD2X16_PIN_D7_STATE_LOW );
#define LCD2X16_PIN_D6_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D6_STATE_HIGH ) : ( LCD2X16_PIN_D6_STATE_LOW );
#define LCD2X16_PIN_D5_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D5_STATE_HIGH ) : ( LCD2X16_PIN_D5_STATE_LOW );
#define LCD2X16_PIN_D4_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D4_STATE_HIGH ) : ( LCD2X16_PIN_D4_STATE_LOW );
#define LCD2X16_PIN_D3_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D3_STATE_HIGH ) : ( LCD2X16_PIN_D3_STATE_LOW );
#define LCD2X16_PIN_D2_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D2_STATE_HIGH ) : ( LCD2X16_PIN_D2_STATE_LOW );
#define LCD2X16_PIN_D1_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D1_STATE_HIGH ) : ( LCD2X16_PIN_D1_STATE_LOW );
#define LCD2X16_PIN_D0_STATE( x ) 	( x ) ? ( LCD2X16_PIN_D0_STATE_HIGH ) : ( LCD2X16_PIN_D0_STATE_LOW );

/****		*****				Clear Display					*****		****/
#define LCD_CMD_ClearDisplay						0x01
/****		*****			 		Cursor Home					*****		****/
#define LCD_CMD_CursorHome          		0x02
/****		*****				Entry Mode Set				*****		****/
#define LCD_CMD_EntryMode_ShiftedRight  0x04
#define LCD_CMD_EntryMode_ShiftedLeft	  0x05 
#define LCD_CMD_EntryMode_Decrement     0x04
#define LCD_CMD_EntryMode_Increment     0x06
/****		*****				Display On/Off				*****		****/
#define LCD_CMD_CursorBlinkOff          0x08
#define LCD_CMD_CursorOff               0x08
#define LCD_CMD_DisplayOff							0x08
#define LCD_CMD_CursorBlinkOn						0x09
#define LCD_CMD_CursorOn                0x0A
#define LCD_CMD_DisplayOn               0x0C
/****		*****		Cursor and Display Shift	*****		****/
#define LCD_CMD_CursorPositionLeft      0x10
#define LCD_CMD_CursorPositionRight     0x14
#define LCD_CMD_ShiftDisplayLeft        0x18
#define LCD_CMD_ShiftDisplayRight       0x1E
/****		*****					Clear Display				*****		****/
#define LCD_CMD_4BitDataLength          0x20
#define LCD_CMD_8BitDataLength          0x30
#define LCD_CMD_1Line5x7Dots            0x20
#define LCD_CMD_1Line5x10Dots           0x24
#define LCD_CMD_2Line5x7Dots            0x28


#define LCD_COMMAND   0
#define LCD_DATA			1

#define __LCD2X16_CLEAR		lcd2x16_Write( 0x01 , LCD_COMMAND )	

typedef enum {
   LCD_LINE_1 = 1,
   LCD_LINE_2 = 2,
   LCD_LINE_3 = 3,
   LCD_LINE_4 = 4
}LCD_LINE;

void lcd2x16_Write 				( uint8_t data , uint8_t rs );
void lcd2x16_Init 				( void );
void lcd2x16_Position 		( LCD_LINE line, uint8_t pos ); 
void lcd2x16_Write_String ( char *string );


#endif /*__lcd2x16_H */
