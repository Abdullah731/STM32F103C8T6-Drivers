/************************************************************************************************************
 * Title		:	RCC_private																				*
 * File name	: 	RCC_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	8 AUG, 2020 - 4 SEP, 2020 																				*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


typedef struct
{
	volatile u32	CR;
	volatile u32	CFGR;
	volatile u32	CIR;
	volatile u32	APB2RSTR;
	volatile u32	APB1RSTR;
	volatile u32	AHBENR;
	volatile u32	APB2ENR;
	volatile u32	APB1ENR;
	volatile u32	BDCR;
	volatile u32	CSR;

}MRCC_t;

#define MRCC 	((volatile MRCC_t *)0x40021000)
/***************************************** Clock Types **********************************/
#define MRCC_HSE_CRYSTAL      0
#define MRCC_HSE_RC           1
#define MRCC_HSI              2
#define MRCC_PLL              3

/************************************ PLL Input Options **********************************/
#define MRCC_PLL_IN_HSI_DIV_2  0
#define MRCC_PLL_IN_HSE_DIV_2  1
#define MRCC_PLL_IN_HSE        2





#endif