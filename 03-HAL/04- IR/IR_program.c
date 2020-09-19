/************************************************************************************************************
 * Title		:	IR_program																				*
 * File name	: 	IR_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	12 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI0_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data        	= 0;

/*
 * A function that initiate the IR Receiver which set the pin direction to be an input floating
 */
void HIR_voidInit(void)
{
	/*Set the defined pin to be input floating*/
	MGPIO_voidSetPinDirection(HIR_PORT_PIN,INPUT_FLOATING);
	/*Initiate the NVIC peripheral to set the priorities*/
	MNVIC_voidInit();
	/*Enable the defined External interrupt peripheral from the NVIC*/
	switch(HIR_EXTI_LINE)
	{
		case EXTI0:
			/*Enable the defined line from the NVIC*/
			MNVIC_voidEnableInterrupt(MNVIC_EXTI0);
			/*Enable the defined line from the EXTI peripheral itself*/
			MEXTI_voidEnableEXTI(LINE0);
			/*Set the external interrupt Mode to be sensitive to the Falling Edge*/
			MEXTI_voidSetSignalLatch(LINE0,FALLING_EDGE);
			break;

		case EXTI1:
			/*Enable the defined line from the NVIC*/
			MNVIC_voidEnableInterrupt(MNVIC_EXTI1);
			/*Enable the defined line from the EXTI peripheral itself*/
			MEXTI_voidEnableEXTI(LINE1);
			/*Set the external interrupt Mode to be sensitive to the Falling Edge*/
			MEXTI_voidSetSignalLatch(LINE1,FALLING_EDGE);
			break;

		case EXTI2:
			/*Enable the defined line from the NVIC*/
			MNVIC_voidEnableInterrupt(MNVIC_EXTI2);
			/*Enable the defined line from the EXTI peripheral itself*/
			MEXTI_voidEnableEXTI(LINE2);
			/*Set the external interrupt Mode to be sensitive to the Falling Edge*/
			MEXTI_voidSetSignalLatch(LINE2,FALLING_EDGE);
			break;

		case EXTI3:
			/*Enable the defined line from the NVIC*/
			MNVIC_voidEnableInterrupt(MNVIC_EXTI3);
			/*Enable the defined line from the EXTI peripheral itself*/
			MEXTI_voidEnableEXTI(LINE3);
			/*Set the external interrupt Mode to be sensitive to the Falling Edge*/
			MEXTI_voidSetSignalLatch(LINE3,FALLING_EDGE);
			break;

		default:
			/*An error to be displayed*/
			break;
	}

	/*Initiate the STK and choose the Clock source*/
	MSTK_voidInit();

}

ButtonsCode_t voidSaveData(void)
{
	u8 Local_u8Index;
	u8Data = 0;
	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (Local_u8Index=0; Local_u8Index<8; Local_u8Index++)
		{
			if (  (u32FrameData[17+Local_u8Index] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,Local_u8Index);
			}

			else
			{
				CLR_BIT(u8Data,Local_u8Index);
			}
		}
	}

	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
	return u8Data;
}


static void voidGetData()
{
	if (u8StartFlag == 0)
		{
			/* Start Timer */
			MSTK_voidSetIntervalSingle(150000,voidSaveData);
			u8StartFlag = 1;
		}

		else
		{
			u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
			MSTK_voidSetIntervalSingle(150000,voidSaveData);
			u8EdgeCounter++;
		}
}


/*
 * A function that used to control the timer , receive the data and determine whether it's 0 or 1
 */

void HIR_voidRemoteHandler()
{
	MEXTI_voidSetCallBack(voidGetData);

}




