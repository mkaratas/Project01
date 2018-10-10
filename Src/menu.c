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
			static uint16_t sayac;
			sayac++;
			char bsmk[4];
			
			bsmk[0] = '0' + (uint8_t)((sayac/1000)%10);
			bsmk[1] = '0' + (uint8_t)((sayac/100 )%10);
			bsmk[2] = '0' + (uint8_t)((sayac/10  )%10);
			bsmk[3] = '0' + (uint8_t)( sayac%10);
			lcd2x16_Position( LCD_LINE_2 , 13 );
			lcd2x16_Write_String( &bsmk[0] ) ;

			break;
		}
		case MENU_KAPAK_AC_KAPA 				: {
			
			break;
		}
		case MENU_KESME_NOKTASI 				: {
		
			break;
		}
		case MENU_UST_LIMIT							: {
			
			break;
		}
		case MENU_START_ALT_LIMITI			: {
			
			break;
		}
		case MENU_DENGELEME_SURESI			: {
			
			break;
		}
		case MENU_GECIS_SURESI					: {
			
			break;
		}
		case MENU_HATA_LIMITI						: {
			
			break;
		}
		case MENU_BOSALMA_SURESI				: {
			
			break;
		}
		case MENU_TORBA_BIRAKMA_SURESI	: {
			
			break;
		}
		case MENU_SABITLEME_SURESI			: {
			
			break;
		}
		case MENU_HATA_DUZELTME_ORANI		: {
			
			break;
		}
		case MENU_TUR_SAYISI						: {
			
			break;
		}
		case MENU_BOSALTMA_GECIKMESI		: {
			
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
