/************************************************************************************************************
 * Title		:	S2P_config																				*
 * File name	: 	S2P_config.h																			*
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

#ifndef	S2P_CONFIG_H
#define	S2P_CONFIG_H

/*Please write port in pair port,pin*/

#define	HS2P_SERIAL_DATA_PIN		MGPIO_GPIOA,MGPIO_PIN0
#define	HS2P_SHIFT_CLOCK_PIN		MGPIO_GPIOA,MGPIO_PIN2
#define	HS2P_STORE_CLOCK_PIN		MGPIO_GPIOA,MGPIO_PIN1


#endif
