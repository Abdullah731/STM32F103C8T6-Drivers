/************************************************************************************************************
 * Title		:	EXTI_private																			*
 * File name	: 	EXTI_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020 - 30 AUG, 2020																*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/


#ifndef EXTI0_PRIVATE_H
#define EXTI0_PRIVATE_H

/* A Structure with Members of the EXTI registers */

typedef struct
{
	volatile u32		IMR;
	volatile u32		EMR;
	volatile u32		RTSR;
	volatile u32		FTSR;
	volatile u32		SWIER;
	volatile u32		PR;

}EXTI_t;

/* Define a Pointer to the upper structure to access all it's members */
#define EXTI	((volatile EXTI_t *) 0x40010400)



#endif
