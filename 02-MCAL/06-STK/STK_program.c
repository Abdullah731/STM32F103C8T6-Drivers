/************************************************************************************************************
 * Title		:	STK_program																				*
 * File name	: 	STM_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	30 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static void (* MSTK_CallBack)(void);

static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	#if MSTK_CLOCK_SOURCE == MSTK_AHB_DIV_8
		MSTK->CTRL = 0x00000000;
	#elif MSTK_CLOCK_SOURCE == MSTK_AHB
		SET_BIT(MSTK -> CTRL, 2);
	#else
		#error ("Wrong MSTK_CLOCK_SOURCE..!")
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	MSTK -> LOAD = Copy_u32Ticks;
	/* Enable the Timer and start to count*/
	SET_BIT(MSTK->CTRL, 0);
	/*Polling until the count flag (bit 16) becomes 1*/
	while(!(GET_BIT(MSTK->CTRL, 16)));
	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VALUE  = 0;
}
 
 void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void (* Copy_ptr)(void))
{
	/* Disable Timer */
	CLR_BIT( MSTK->CTRL ,0);
	MSTK -> VALUE = 0;
	MSTK -> LOAD = Copy_u32Ticks;
	/* Enable the Timer and start to count*/
	SET_BIT(MSTK -> CTRL, 0);
	/*Save the Callback*/
	MSTK_CallBack = Copy_ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK -> CTRL, 1);
}
 
 void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	MSTK -> LOAD = Copy_u32Ticks;
	/* Enable the Timer and start to count*/
	SET_BIT(MSTK -> CTRL, 0);
	/*Save the Callback*/
	MSTK_CallBack = Copy_ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK -> CTRL, 1);
}
 
void MSTK_voidStopTimer(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, 1);
	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD 	= 0;
	MSTK -> VALUE 	= 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = 0;
	Local_u32ElapsedTime = (MSTK -> LOAD - MSTK -> VALUE);
	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	Local_u32RemainTime = MSTK -> VALUE ;
	return Local_u32RemainTime;
}
 
void SysTick_Handler(void)
{
	u8 Local_u8Temporary = 0;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK -> CTRL, 1);
		/* Stop Timer */
		SET_BIT(MSTK -> CTRL, 0);
		MSTK -> LOAD 	= 0;
		MSTK -> VALUE	= 0;
	}

	/* Callback notification */
	MSTK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(MSTK -> CTRL,16);
}
