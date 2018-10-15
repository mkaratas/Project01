#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f0xx_hal.h"
#include "main.h"

#define Usart1_Buffer_Size 12

extern uint8_t usart1_rx_data[Usart1_Buffer_Size];

extern UART_HandleTypeDef huart1;




extern void _Error_Handler(char *, int);

void MX_USART1_UART_Init(void);


void UsartReceiveData_SearchCommand ( void );


#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
