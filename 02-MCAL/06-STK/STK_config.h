/************************************************************************************************************
 * Title		:	STK_config																				*
 * File name	: 	STK_config.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	30 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/* Choose the clock source for SYSTICK*/
/*Options:
			STK_AHB_DIV_8
			STK_AHB
*/
#define		MSTK_CLOCK_SOURCE		(MSTK_AHB_DIV_8)


#endif
