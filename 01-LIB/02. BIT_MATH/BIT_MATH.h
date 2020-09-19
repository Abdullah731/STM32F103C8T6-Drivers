/************************************************************************************************************
 * Title		:	BIT_MATH																				*
 * File name	: 	BIT_MATH.h																				*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	29 JUL, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)		(VAR |=  (1 << (BIT)))
#define CLR_BIT(VAR,BIT)		(VAR &= ~(1 << (BIT)))
#define GET_BIT(VAR,BIT)		((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)		(VAR ^=  (1 << (BIT)))


#endif
