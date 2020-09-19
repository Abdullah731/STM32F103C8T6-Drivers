/************************************************************************************************************
 * Title		:	EXTI_config																				*
 * File name	: 	EXTI_config.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020 - 30 AUG, 2020																*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef EXTI0_CONFIG_H
#define EXTI0_CONFIG_H

/* Define the line number for EXTI */
/*
 * Options:
 * 			from LINE0 : LINE15
 * 			LINE0 	for	EXTI0
 * 			LINE15	for	EXTI15
 */
#define EXTI_LINE		(LINE0)

/* Define the mode of the EXTI */
/* Options:
 * 			RISING_EDGE
 * 			FALLING_EDGE
 * 			ON_CHANGE
 * */
#define EXTI_MODE		(FALLING_EDGE)

#endif
