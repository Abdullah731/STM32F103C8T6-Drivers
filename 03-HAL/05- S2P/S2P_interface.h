/************************************************************************************************************
 * Title		:	S2P_interface																			*
 * File name	: 	S2P_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	18 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * MCU Target	:	STM32F103 Microcontroller																*
 * IC Target	:	IC74595 Serial To Parallel Chip															*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	S2P_INTERFACE_H
#define	S2P_INTERFACE_H

/*A function to send data and polling until it finishes*/
void		HS2P_voidSendSynchronous		(u8 Copy_u8DataToSend);


#endif
