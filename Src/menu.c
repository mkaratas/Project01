#include "stm32f0xx_hal.h"
#include "menu.h"
#include "lcd2x16.h" 

static uint8_t menu;

/****		*****		*****		*****		*****		****/
void Menu_Init 	 ( void ) {
	menu = MENU_ANA_EKRAN;  
}
/****		*****		*****		*****		*****		****/
void Menu_Update ( void ) {
	switch( menu ) {
		case MENU_ANA_EKRAN							: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "    ANA MENU     ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "    ANA MENU     ");
			break;
		}
		case MENU_KAPAK_AC_KAPA 				: {
			Lcd2x16_BufferSet( LCD_LINE_1 , " KAPAK: AC/KAPA ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     SURESI     ");			
			break;
		}
		case MENU_KESME_NOKTASI 				: {
		  Lcd2x16_BufferSet( LCD_LINE_1 , "   YAVAS KESME  ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     NOKTASI    ");
			break;
		}
		case MENU_UST_LIMIT							: {
		  Lcd2x16_BufferSet( LCD_LINE_1 , "       UST      ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "      LIMIT     ");			
			break;
		}
		case MENU_START_ALT_LIMITI			: {
		  Lcd2x16_BufferSet( LCD_LINE_1 , "      START     ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "   ALT LIMITI   ");			
			break;
		}
		case MENU_DENGELEME_SURESI			: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "    DENGELEME   ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     SURESI     ");	
			break;
		}
		case MENU_GECIS_SURESI					: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "   HIZLI/YAVAS   ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "  GECIS  SURESI  ");	
			break;
		}
		case MENU_HATA_LIMITI						: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "      HATA      ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     LIMITI     ");			
			break;
		}
		case MENU_BOSALMA_SURESI				: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "    BOSALTMA    ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     SURESI     ");			
			break;
		}
		case MENU_TORBA_BIRAKMA_SURESI	: {
			Lcd2x16_BufferSet( LCD_LINE_1 , " TORBA  BIRAKMA ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     SURESI     ");			
			break;
		}
		case MENU_SABITLEME_SURESI			: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "    SABITLEME   ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     SURESI     ");			
			break;
		}
		case MENU_HATA_DUZELTME_ORANI		: {
			Lcd2x16_BufferSet( LCD_LINE_1 , " HATA  DUZELTME ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     ORANI      ");			
			break;
		}
		case MENU_TUR_SAYISI						: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "       TUR      ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "     SAYISI     ");			
			break;
		}
		case MENU_BOSALTMA_GECIKMESI		: {
			Lcd2x16_BufferSet( LCD_LINE_1 , "    BOSALTMA    ");
			Lcd2x16_BufferSet( LCD_LINE_2 , "    GECIKMESI   ");				
			break;
		}
		case MENU_SILO_DEGERI						: {
			
			break;
		}
		case MENU_HATA_FARKLARI					: {
			
			break;
		}
		default:{
			break;
		}
	}
}
/****		*****		*****		*****		*****		****/
