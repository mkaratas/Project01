#include "stm32f0xx_hal.h"
#include "lcd2x16.h"

#define LCD_4_BITS

/*													S1	,  1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 11, 12, 13, 14, 15, 16  	*/ 
char lcd2x16_Buff[34] = { 0x80  , ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
													0xC0  , ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
/*													S2	, 18 , 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33 	*/
	
/**
  * @brief  2x16 LCD'nin Bufferine data yazmaya yarar.
  * @param  Channel TIM Channel to be disabled
  *          This parameter can be one of the following values:
  *            @arg LCD_LINE_1: TIM Channel 1 selected
  *            @arg LCD_LINE_2: TIM Channel 2 selected
  * @retval HAL status
*/
void Lcd2x16_BufferSet( LCD_LINE line , char data[16] ) {
		if      ( line == LCD_LINE_1 )
			for ( uint8_t i = 0 ; i<16 ; i++ )
				lcd2x16_Buff[ i+1  ] = data[i];
		else // ( line == LCD_LINE_2 ) 
			for ( uint8_t i = 0 ; i<16 ; i++ )
				lcd2x16_Buff[ i+18 ] = data[ i ];
} 
/****		*****		*****		*****		*****		****/
void Lcd2x16_Scan 		( void ) {
#if 	defined (LCD_4_BITS)
	static uint8_t  lcd_indx = 0; 	
	LCD2X16_PIN_RS_STATE_HIGH;
	if ( lcd_indx==0 | lcd_indx==17 )                                                               
		LCD2X16_PIN_RS_STATE_LOW;
	LCD2X16_PIN_D7_STATE ( (lcd2x16_Buff[lcd_indx]>>7)&0x01 );
	LCD2X16_PIN_D6_STATE ( (lcd2x16_Buff[lcd_indx]>>6)&0x01 );
	LCD2X16_PIN_D5_STATE ( (lcd2x16_Buff[lcd_indx]>>5)&0x01 );
	LCD2X16_PIN_D4_STATE ( (lcd2x16_Buff[lcd_indx]>>4)&0x01 );
	LCD2X16_PIN_E_STATE  ( 1 );	
	LCD2X16_PIN_E_STATE	 ( 0 );
	LCD2X16_PIN_D7_STATE ((lcd2x16_Buff[lcd_indx]>>3)&0x01 );
	LCD2X16_PIN_D6_STATE ((lcd2x16_Buff[lcd_indx]>>2)&0x01 );
	LCD2X16_PIN_D5_STATE ((lcd2x16_Buff[lcd_indx]>>1)&0x01 );
	LCD2X16_PIN_D4_STATE ((lcd2x16_Buff[lcd_indx]>>0)&0x01 );	
	LCD2X16_PIN_E_STATE  ( 1 );	
	LCD2X16_PIN_E_STATE	 ( 0 );	
	lcd_indx++;
	if(  lcd_indx == 34 )
		lcd_indx=0;
	
#elif defined (LCD_8_BITS)
	static uint8_t  lcd_indx = 0;
	LCD2X16_PIN_RS_STATE_HIGH;
	if ( lcd_indx==0 | lcd_indx==17 )                                                               
		LCD2X16_PIN_RS_STATE_LOW;									
	LCD2X16_PIN_D7_STATE ( (lcd2x16_Buff[lcd_indx]>>7)&0x01 );
	LCD2X16_PIN_D6_STATE ( (lcd2x16_Buff[lcd_indx]>>6)&0x01 );
	LCD2X16_PIN_D5_STATE ( (lcd2x16_Buff[lcd_indx]>>5)&0x01 );
	LCD2X16_PIN_D4_STATE ( (lcd2x16_Buff[lcd_indx]>>4)&0x01 );
	LCD2X16_PIN_D3_STATE ( (lcd2x16_Buff[lcd_indx]>>3)&0x01 );
	LCD2X16_PIN_D2_STATE ( (lcd2x16_Buff[lcd_indx]>>2)&0x01 );
	LCD2X16_PIN_D1_STATE ( (lcd2x16_Buff[lcd_indx]>>1)&0x01 );
	LCD2X16_PIN_D0_STATE ( (lcd2x16_Buff[lcd_indx]>>0)&0x01 );
	LCD2X16_PIN_E_STATE  ( 1 );										//	LCD_E_PIN = 1;
	LCD2X16_PIN_E_STATE	 ( 0 );										//	LCD_E_PIN = 0;
	lcd_indx++;
	if(  lcd_indx == 34 )
		lcd_indx=0;
#else
//    #error -- [lcd_2x16_write] LCD Data width not defined
#endif
} 
/****		*****		*****		*****		*****		****/
void lcd2x16_Write 		( uint8_t data  , uint8_t rs  ) {
#if 	defined (LCD_4_BITS)
		LCD2X16_PIN_RS_STATE ( rs );									//	LCD_RS_PIN = rs;			
    // Send MSB First
		LCD2X16_PIN_D7_STATE ( (data>>7)&0x01 );			//	LCD_D7_PIN = (data >> 7) & 0x01;
    LCD2X16_PIN_D6_STATE ( (data>>6)&0x01 );			//	LCD_D6_PIN = (data >> 6) & 0x01;
    LCD2X16_PIN_D5_STATE ( (data>>5)&0x01 );			//	LCD_D5_PIN = (data >> 5) & 0x01;
    LCD2X16_PIN_D4_STATE ( (data>>4)&0x01 );			//	LCD_D4_PIN = (data >> 4) & 0x01;
		// LCD_Pulse
		LCD2X16_PIN_E_STATE  ( 1 );										//	LCD_E_PIN = 1;
    LCD2X16_PIN_E_STATE	 ( 0 );										//	LCD_E_PIN = 0;
    // Send LSB Last
    LCD2X16_PIN_D7_STATE ( (data>>3)&0x01 );			//	LCD_D7_PIN = (data >> 3) & 0x01;
    LCD2X16_PIN_D6_STATE ( (data>>2)&0x01 ); 			//	LCD_D6_PIN = (data >> 2) & 0x01;
    LCD2X16_PIN_D5_STATE ( (data>>1)&0x01 );			//	LCD_D5_PIN = (data >> 1) & 0x01;
    LCD2X16_PIN_D4_STATE ( (data>>0)&0x01 );			//	LCD_D4_PIN = (data >> 0) & 0x01;
    //	LCD_Pulse;
		LCD2X16_PIN_E_STATE  ( 1 );										//	LCD_E_PIN = 1;
    LCD2X16_PIN_E_STATE	 ( 0 );										//	LCD_E_PIN = 0;
    HAL_Delay( 1 );																//	delay_us (50);	 Delay entre 2 envois 		

#elif defined (LCD_8_BITS)
    LCD2X16_PIN_RS_STATE ( rs );									//	LCD_RS_PIN = rs;
		LCD2X16_PIN_D7_STATE ( (data>>7)&0x01 );			//	LCD_D7_PIN = (data >> 7) & 0x01;
    LCD2X16_PIN_D6_STATE ( (data>>6)&0x01 );			//	LCD_D6_PIN = (data >> 6) & 0x01;
    LCD2X16_PIN_D5_STATE ( (data>>5)&0x01 );			//	LCD_D5_PIN = (data >> 5) & 0x01;
    LCD2X16_PIN_D4_STATE ( (data>>4)&0x01 );			//	LCD_D4_PIN = (data >> 4) & 0x01;
    LCD2X16_PIN_D3_STATE ( (data>>3)&0x01 );			//	LCD_D3_PIN = (data >> 3) & 0x01;
    LCD2X16_PIN_D2_STATE ( (data>>2)&0x01 );			//	LCD_D2_PIN = (data >> 2) & 0x01;
    LCD2X16_PIN_D1_STATE ( (data>>1)&0x01 );			//	LCD_D1_PIN = (data >> 1) & 0x01;
    LCD2X16_PIN_D0_STATE ( (data>>0)&0x01 );			//	LCD_D0_PIN = (data >> 0) & 0x01;
    LCD2X16_PIN_E_STATE  ( 1 );										//	LCD_E_PIN = 1;
    LCD2X16_PIN_E_STATE	 ( 0 );										//	LCD_E_PIN = 0;
    HAL_Delay( 1 );																//	delay_us (50);	 Delay entre 2 envois
#else
//    #error -- [lcd_2x16_write] LCD Data width not defined
#endif
}
/****		*****		*****		*****		*****		****/
void lcd2x16_Init 		( void ) {
#if    defined(LCD_4_BITS) 
		LCD2X16_PIN_RS_STATE_LOW;
		LCD2X16_PIN_E_STATE_LOW;
		LCD2X16_PIN_D4_STATE_LOW;
		LCD2X16_PIN_D5_STATE_LOW;
		LCD2X16_PIN_D6_STATE_LOW;
		LCD2X16_PIN_D7_STATE_LOW;
    HAL_Delay (60);                    // > 15 ms @ 5V, > 40 ms @ 3.3V
    lcd2x16_Write (0x30, LCD_COMMAND);     // Valeur d'initialisation
    HAL_Delay (20);                    // > 4.1 ms
    lcd2x16_Write (0x30, LCD_COMMAND);     // a repeter 3 fois
    HAL_Delay(1);                      // > 100 µs
    lcd2x16_Write (0x30, LCD_COMMAND);     // 3e fois
    
		lcd2x16_Write (0x20, LCD_COMMAND);     // Données en 4 Bits
    lcd2x16_Write (0x28, LCD_COMMAND);     // Données en 4 Bits sur 2 lignes en 5x8
		
    lcd2x16_Write (0x14, LCD_COMMAND);     // $14, Deplacement vers la droite
    lcd2x16_Write (0x0C, LCD_COMMAND);  	 // $0C, Display ON, Cursor OFF, Blink OFF
    lcd2x16_Write (0x06, LCD_COMMAND);     // $06, Increment, no display shift
    HAL_Delay (1);
    lcd2x16_Write (0x01, LCD_COMMAND);     // Effacer l'afficheur
    lcd2x16_Write (0x80, LCD_COMMAND);     // Se positionner sur la 1ere Ligne
    HAL_Delay (1);
#elif  defined(LCD_8_BITS)
		LCD2X16_PIN_RS_STATE_LOW;
		LCD2X16_PIN_E_STATE_LOW;
		LCD2X16_PIN_D0_STATE_LOW;
		LCD2X16_PIN_D1_STATE_LOW;
		LCD2X16_PIN_D2_STATE_LOW;
		LCD2X16_PIN_D3_STATE_LOW;
		LCD2X16_PIN_D4_STATE_LOW;
		LCD2X16_PIN_D5_STATE_LOW;
		LCD2X16_PIN_D6_STATE_LOW;
		LCD2X16_PIN_D7_STATE_LOW;
		HAL_Delay( 60 );									 // > 15 ms @ 5V, > 40 ms @ 3.3V
    lcd2x16_Write (0x30, LCD_COMMAND);     // Valeur d'initialisation
    HAL_Delay( 20 );                      // > 4.1 ms
    lcd2x16_Write (0x30, LCD_COMMAND);     // a repeter 3 fois
    HAL_Delay( 1 );                        // > 100 µs
    lcd2x16_Write (0x30, LCD_COMMAND);     // 3e fois
    
		lcd2x16_Write (0x38, LCD_COMMAND);     // Données en 8 Bits sur 2 lignes en 5x8
    lcd2x16_Write (0x14, LCD_COMMAND);     // $14, Deplacement vers la droite
    lcd2x16_Write (0x0C, LCD_COMMAND);     // $0C, Display ON, Cursor OFF, Blink OFF
    lcd2x16_Write (0x06, LCD_COMMAND);     // $06, Increment, no display shift
    HAL_Delay( 1 );
    lcd2x16_Write (0x01, LCD_COMMAND);     // Effacer l'afficheur
    lcd2x16_Write (0x80, LCD_COMMAND);     // Se positionner sur la 1ere Ligne
    HAL_Delay( 1 );
#endif
}
/****		*****		*****		*****		*****		****/
void lcd2x16_Position ( LCD_LINE line , uint8_t pos ) {
	switch ( line ) {
		case LCD_LINE_1 : { 
					lcd2x16_Write(0x80+pos-1, LCD_COMMAND); 
					break; 
					}
		case LCD_LINE_2 : { 
					lcd2x16_Write(0xC0+pos-1, LCD_COMMAND); 
					break; 
					}
		case LCD_LINE_3 : { 
					lcd2x16_Write(0x94+pos-1, LCD_COMMAND); 
					break; 
					}
		case LCD_LINE_4 : { 
					lcd2x16_Write(0xD4+pos-1, LCD_COMMAND); 
					break; 
					}
	}
}
/****		*****		*****		*****		*****		****/
void lcd2x16_Write_String ( char *string ) {
	while ( *string ) {
		lcd2x16_Write( *string++ , LCD_DATA );
	}
}

/****		*****		*****		*****		*****		****/
