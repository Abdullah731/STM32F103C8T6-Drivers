/************************************************************************************************************
 * Title		:	LED_program																				*
 * File name	: 	LED_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	31 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/***********************************************************************************************************
	API Description
			LED_voidLedOn
					<Function>			used to Turn On a LED using the Port Name and Pin Number, the output
										mode that can be used is from OUTPUT_X10MHZ_PP	OUTPUT_X2MHZ_PP
																	  OUTPUT_X50MHZ_PP
									return				void
									parameters			Copy_u8PortName		Copy_u8PinNum	Copy_u8OutputMode
									Local Variables		NONE

			LED_voidLedOff
					<Function>			used to Turn Off a LED using the Port Name and Pin Number
									return				void
									parameters			Copy_u8PortName		Copy_u8PinNum
									Local Variables		NONE			
			LED_LED_voidLedToggle		used to toggle a LED with first state of HIGH and delay for a number
										of ticks using the SYSTICK peripheral.
									return				void
									parameters			Copy_u8PortName		Copy_u8PinNum	Copy_u8DelayTime
									Local Variables		NONE

***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "GPIO_interface.h"
#include "STK_interface.h"



void LED_voidLedOn(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutputMode)
{
	if((Copy_u8OutputMode == OUTPUT_X10MHZ_PP) || (Copy_u8OutputMode == OUTPUT_X2MHZ_PP) ||(Copy_u8OutputMode == OUTPUT_X50MHZ_PP))
	{
		MGPIO_voidSetPinDirection(Copy_u8PortName, Copy_u8PinNum, Copy_u8OutputMode);
		MGPIO_voidSetPinValue(Copy_u8PortName, Copy_u8PinNum, HIGH);
	}
	else
	{
		/*An error to be displayed*/
	}
}

void LED_voidLedOff(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{
	MGPIO_voidSetPinValue(Copy_u8PortName, Copy_u8PinNum, LOW);
}

void LED_voidLedToggle(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8DelayTime)
{
	MGPIO_voidSetPinValue(Copy_u8PortName, Copy_u8PinNum, HIGH);
	MSTK_voidSetBusyWait(Copy_u8DelayTime);
	MGPIO_voidSetPinValue(Copy_u8PortName, Copy_u8PinNum, LOW);
	MSTK_voidSetBusyWait(Copy_u8DelayTime);
}
