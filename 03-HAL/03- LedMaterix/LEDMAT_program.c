/************************************************************************************************************
 * Title		:	LEDMAT_program																			*
 * File name	: 	LEDMAT_program.c																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	1 SEP, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/****************************************************************************************************************
 * APIs Description
 *
 * 		HLEDMAT_voidInit
 * 				<Function>				used to initialized and set pin direction for Rows and Columns pins.
 * 									return:				void
 * 									parameters:			void
 * 									Local Variables		Local_u8LoopCounter
 *
 *
 *
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"

extern u8 Zeko1[];
//extern u8 Zeko2[];
//extern u8 Zeko3[];
//extern u8 Zeko4[];


u8 Global_u8RowsArray[16] = {LEDMAT_ROW0_PIN,
					         LEDMAT_ROW1_PIN,
							 LEDMAT_ROW2_PIN,
							 LEDMAT_ROW3_PIN,
							 LEDMAT_ROW4_PIN,
					         LEDMAT_ROW5_PIN,
					         LEDMAT_ROW6_PIN,
					         LEDMAT_ROW7_PIN,
					        };

u8 Global_u8ColsArray[16] = {LEDMAT_COL0_PIN,
							 LEDMAT_COL1_PIN,
							 LEDMAT_COL2_PIN,
							 LEDMAT_COL3_PIN,
							 LEDMAT_COL4_PIN,
							 LEDMAT_COL5_PIN,
							 LEDMAT_COL6_PIN,
							 LEDMAT_COL7_PIN,
							};

void HLEDMAT_voidInit(void)
{
	/*Declare a Local variable for the loop*/
	u8 Local_u8LoopCounter = 0;
	/*Loop inside the Row and Col arrays*/
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter <=7; Local_u8LoopCounter++)
	{
		/*(2 * Local_u8LoopCounter) to get only the PORT ,(2 * Local_u8LoopCounter) + 1 to get only the pin number*/
		MGPIO_voidSetPinDirection(Global_u8RowsArray[(2 * Local_u8LoopCounter)], Global_u8RowsArray[(2 * Local_u8LoopCounter) + 1], OUTPUT_X2MHZ_PP);
		MGPIO_voidSetPinDirection(Global_u8ColsArray[(2 * Local_u8LoopCounter)],Global_u8ColsArray[(2 * Local_u8LoopCounter) + 1],  OUTPUT_X2MHZ_PP);
	}
}

void HLEDMAT_voidDisplayCharacter(u8 *Copy_u8DataArr)
{
	u8 Local_u8LoopCounter = 0;
		for(Local_u8LoopCounter = 0; Local_u8LoopCounter <= 7; Local_u8LoopCounter++)
		{
			/*Call DisableAllCols function to disable all Columns*/
			HLEDMAT_voidDisableAllCols();
			/*Call SetRowValues function to set Values on Rows*/
			HLEDMAT_voidSetRowValues(Copy_u8DataArr[Local_u8LoopCounter]);
			/*Enable one Column at a time */
			MGPIO_voidSetPinValue(Global_u8ColsArray[(2 * Local_u8LoopCounter)],Global_u8ColsArray[(2 * Local_u8LoopCounter) + 1], LOW);
			/*Delay for 2.5 ms*/
			MSTK_voidSetBusyWait(2500);
		}
}

static void HLEDMAT_voidDisableAllCols(void)
{
	/*Declare a variable for loop*/
	u8 Local_u8Counter = 0;
	/*Loop in Columns array*/
	for(Local_u8Counter = 0; Local_u8Counter<=7; Local_u8Counter++)
	{
		/*Set All Column pins to be HIGH to disable (Active low)*/
		MGPIO_voidSetPinValue(Global_u8ColsArray[(2 * Local_u8Counter)],Global_u8ColsArray[(2 * Local_u8Counter) + 1], HIGH);
	}
}

static void HLEDMAT_voidSetRowValues(u8 Copy_u8Data)
{
	u8 Local_u8Bit = 0;
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter <=7; Local_u8Counter++)
	{
		Local_u8Bit = GET_BIT(Copy_u8Data,Local_u8Counter);
		MGPIO_voidSetPinValue(Global_u8RowsArray[(2 * Local_u8Counter)], Global_u8RowsArray[(2 * Local_u8Counter) + 1], Local_u8Bit);
	}
}

void HLEDMAT_DisplayString(void)
{
	u8 Local_u8NameLoop ;  // 5 loops * 3 arrays = 20 change for one name display

	u8 Local_u8Wait ;     // wait to see each letter

	for ( Local_u8NameLoop = 0 ; Local_u8NameLoop < 5 ; Local_u8NameLoop ++ )
	{
		for ( Local_u8Wait = 0 ; Local_u8Wait<10 ; Local_u8Wait++ )
		{
			HLEDMAT_voidDisplayCharacter( (8 * (Local_u8NameLoop) + Zeko1   ));
		}
	}

}
