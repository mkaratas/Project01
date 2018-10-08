#include "gpio.h"

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/

/****		*****		*****		*****		*****		****/
void MX_GPIO_Init ( void ) {

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	
	/*Configure Seven Segment Display Segment GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA , 					SegE_Pin|SegG_Pin  										, GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOB , SegA_Pin|SegB_Pin|SegC_Pin|SegD_Pin|SegDp_Pin  , GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOF , 							SegF_Pin  												, GPIO_PIN_SET );

	/*Configure Seven Segment Display Scan GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOB , 		DS1_Pin|DS2_Pin 		 , GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOC , DS3_Pin|DS4_Pin|DS6_Pin , GPIO_PIN_SET );
	HAL_GPIO_WritePin( GPIOF , 				DS5_Pin          , GPIO_PIN_SET );
	
	/*Configure 2x16 LCD GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA , DB0_Pin|DB1_Pin|DB2_Pin|DB3_Pin|
														 DB4_Pin|DB5_Pin|DB6_Pin|DB7_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB , 		DBE_Pin|DBRW_Pin|DBRS_Pin 	 , GPIO_PIN_RESET );
	
	/*Configure Panel Panel GPIO pin Output Level */
	HAL_GPIO_WritePin( GPIOA , 						Panel7_Pin						, GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB , Panel6_Pin|Panel5_Pin|Panel4_Pin , GPIO_PIN_RESET );
	HAL_GPIO_WritePin( GPIOB , 						Panel1_Pin 						, GPIO_PIN_SET 	 );
	
	/****		*****		*****		*****		*****		*****		****/
	/****		*****		*****		*****		*****		*****		****/
	/****		*****		*****		*****		*****		*****		****/
	
	/*Configure GPIO pins : Seven Segment Display Segment GPIO pin */
	GPIO_InitStruct.Pin   = SegE_Pin|SegG_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOA , &GPIO_InitStruct );
	
	GPIO_InitStruct.Pin   = SegA_Pin|SegB_Pin|SegC_Pin|SegD_Pin|SegDp_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOB , &GPIO_InitStruct );
	
	GPIO_InitStruct.Pin   = SegF_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOF , &GPIO_InitStruct );
	
	/*Configure GPIO pins : Seven Segment Display Scan	  GPIO pin */
	GPIO_InitStruct.Pin   = DS1_Pin|DS2_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOB , &GPIO_InitStruct );
	
	GPIO_InitStruct.Pin   = DS3_Pin|DS4_Pin|DS6_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOC , &GPIO_InitStruct );
	
	GPIO_InitStruct.Pin   = DS5_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOF , &GPIO_InitStruct );
	
	/*Configure GPIO pins : 2x16  LCD GPIO pin */
	GPIO_InitStruct.Pin   = DB0_Pin | DB1_Pin | DB2_Pin | DB3_Pin |
													DB4_Pin | DB5_Pin | DB6_Pin | DB7_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOA , &GPIO_InitStruct );
	
	GPIO_InitStruct.Pin   = DBE_Pin | DBRW_Pin | DBRS_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOB , &GPIO_InitStruct );
	
	/*Configure GPIO pins : Panel GPIO pin */
	
	GPIO_InitStruct.Pin   = Panel7_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOA , &GPIO_InitStruct );
	
	GPIO_InitStruct.Pin   = Panel6_Pin | Panel5_Pin | Panel4_Pin | Panel1_Pin;
  GPIO_InitStruct.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(	GPIOB , &GPIO_InitStruct );	
	
	GPIO_InitStruct.Pin  = Panel2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init ( GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin  = Panel3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init ( GPIOB, &GPIO_InitStruct);


}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
