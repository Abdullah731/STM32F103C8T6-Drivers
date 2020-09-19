/************************************************************************************************************
 * Title		:	MSTK_interface																			*
 * File name	: 	MSTK_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	30 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
 /***********************************************************************************************************
 *	API Description
 *			MSTK_voidInit
 *					<function>			used to initialize the clock source for the systick	between
 *										AHB clock and AHB divided by 8
 *										return				void
 *										parameters			void
 *										local variables		NONE
 *								
 *			MSTK_voidSetBusyWait
 *					<function>			used to start count and stuck in a loop until the timer reaches the 0 
 *										and rise up the count flag.
 *										return				void
 *										parameters			Copy_u32Ticks
 *										local variables		NONE
 *	
 *			MSTK_voidSetIntervalSingle		
 *					<function>			used to count only single time and return immediatly, after timer 
 *										reaches the 0 and rise up the count flag, Timer will fire an interrupt
 *										to be served.
 *										return				void
 *										parameters			Copy_u32Ticks		*Copy_ptr
 *										local variables		NONE
 *			
 *			MSTK_voidSetIntervalPeriodic
 *					<function>			used to count periodicaly and return immediatly, after timer 
 *										reaches the 0 and rise up the count flag, Timer will fire an interrupt
 *										to be served.
 *										return				void
 *										parameters			Copy_u32Ticks		*Copy_ptr
 *										local variables		NONE					
 *										
 *			MSTK_voidStopTimer
 *					<function>			used to force stop the timer.
 *										return				void
 *										parameters			void
 *										local variables		NONE
 *										
 *			MSTK_u32GetElapsedTime		
 *					<function>			used to return the elapsed time that timer counts from the given 
 *										Ticks.
 *										return				u32
 *										parameters			void
 *										local variables		Local_u32ElapsedTime
 *			
 *			MSTK_u32GetRemainingTime	
 *					<function>			used to return back the remain time that timer will counts to reach
 *										0.
 *										return 				u32
 *										parameters			void
 *										local variables		NONE
 ***********************************************************************************************************/
 
#ifndef MSTK_INTERFACE_H
#define MSTK_INTERFACE_H

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks,void (*Copy_ptr)(void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void));
void MSTK_voidStopTimer(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainingTime(void);

#endif
