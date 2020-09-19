/************************************************************************************************************
 * Title		:	MAFIO_program																			*
 * File name	: 	MAFIO_program.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"



void MAFIO_voidSetEXTIConfig(u8 Copy_u8LineNum, u8 Copy_u8PortName)
{
	u8 Local_u8RegIndex = 0;
	u8 Local_u8Port = 0;
	if(Copy_u8LineNum <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(Copy_u8LineNum <= 7)
	{
		Local_u8RegIndex = 1;
		Copy_u8LineNum -=4;	
	}
	else if(Copy_u8LineNum <= 11)
	{
		Local_u8RegIndex = 2;
		Copy_u8LineNum -= 8;	
	}
	else if(Copy_u8LineNum <= 15)
	{
		Local_u8RegIndex = 3;
		Copy_u8LineNum -= 12;
	}
	else
	{
		/*An error to be displayed*/
	}
	
	switch(Copy_u8PortName)
	{
		case GPIOA:
			Local_u8Port = 0b0000;
			break;
		case GPIOB:
			Local_u8Port = 0b0001;
			break;
		case GPIOC:
			Local_u8Port = 0b0010;
			break;
		default:
			/*An error to be displayed*/
			break;
	}
	
	/* Reset the register before any logical operations */
	MAFIO -> EXTICR[Local_u8RegIndex] &=~((0b1111) << (Copy_u8LineNum * 4));
	MAFIO -> EXTICR[Local_u8RegIndex] |= ((Local_u8Port) << (Copy_u8LineNum * 4));
	
}
