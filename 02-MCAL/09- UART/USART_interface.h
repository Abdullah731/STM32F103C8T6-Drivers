/************************************************************************************************************
 * Title		:	USART_interface																			*
 * File name	: 	USART_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	23 SEP, 2020																			*
 * Version		: 	v1.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 ***********************************************************************************************************/

 /***************************************** SOURCE REVISION LOG *********************************************
 *
 *    Date			Version			Author			  Description 
 *  23 SEP, 2020	  1.0		Abdullah Mustafa	Initial Release.
 *
 **********************************************************************************************************/
 
#ifndef	USART_INTERFACE_H
#define	USART_INTERFACE_H

void 	MUSART1_voidInit(void);
void 	MUSART1_voidTransmit(u8 * Copy_u8PDataArr);
void 	MUSART1_u8Receive(u8 * Copy_u8PDataReceived);

#endif
