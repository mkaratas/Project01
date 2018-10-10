#ifndef __menu_H
#define __menu_H

#define MENU_ANA_EKRAN										0x00

#define MENU_KAPAK_AC_KAPA								0x11
#define MENU_KESME_NOKTASI         				0x12
#define MENU_UST_LIMIT                   	0x13
#define MENU_START_ALT_LIMITI            	0x14
#define MENU_DENGELEME_SURESI            	0x15
#define MENU_GECIS_SURESI    							0x16
#define MENU_HATA_LIMITI                 	0x17
#define MENU_BOSALMA_SURESI              	0x18
#define MENU_TORBA_BIRAKMA_SURESI        	0x19
#define MENU_SABITLEME_SURESI            	0x1A
#define MENU_HATA_DUZELTME_ORANI         	0x1B
#define MENU_TUR_SAYISI                  	0x1C
#define MENU_BOSALTMA_GECIKMESI          	0x1D

#define MENU_SILO_DEGERI                 0x21

#define MENU_HATA_FARKLARI               0x31


void Menu_Init 	 ( void );
void Menu_Update ( void );

#endif /* __MENU_H */
