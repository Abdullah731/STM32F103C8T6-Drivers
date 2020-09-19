/************************************************************************************************************
 * Title		:	STK_private																				*
 * File name	: 	STK_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	30 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/***************************************** Register Definition *********************************************/
typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VALUE   ;
}MSTK_t;

#define     MSTK    ((volatile MSTK_t*)0xE000E010)


/***************************************** Clock source Definition *********************************************/

#define	MSTK_AHB_DIV_8		(1)
#define	MSTK_AHB			(2)

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

#endif
