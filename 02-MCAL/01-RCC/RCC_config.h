/************************************************************************************************************
 * Title		:	RCC_config																				*
 * File name	: 	RCC_config.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	8 AUG, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H


/* Select the Input clock for processor */
/* Options:		MRCC_HSE_CRYSTAL
 * 				MRCC_HSE_RC
 * 				MRCC_HSI
 * 				MRCC_PLL
 */
#define MRCC_CLOCK_TYPE		(MRCC_HSE_CRYSTAL)

/* NOTE: Select config only if you have PLL as input clock source */
/* Options:
 * 			MRCC_PLL_IN_HSI_DIV_2
 * 			MRCC_PLL_IN_HSE_DIV_2
 * 			MRCC_PLL_IN_HSE
 */
#if	MRCC_CLOCK_TYPE == MRCC_PLL
/* Select the input for the PLL */
/* Options:
 * 			MRCC_PLL_IN_HSI_DIV_2
 *			MRCC_PLL_IN_HSE_DIV_2
 *			MRCC_PLL_IN_HSE
 */
	#define MRCC_PLL_INPUT		(MRCC_PLL_IN_HSI_DIV_2)

/* Select the Multiplication factor of the PLL */
/* Options:
	 * Multiplication factor is from 2 to 16
	 */
	#define MRCC_PLL_MUL_VALUE		(4)
#endif
#endif
