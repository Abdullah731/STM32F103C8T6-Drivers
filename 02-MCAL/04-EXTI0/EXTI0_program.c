/************************************************************************************************************
 * Title		:	EXTI_program																			*
 * File name	: 	EXTI_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020 - 30 AUG, 2020																*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI0_interface.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h"

#define NULL		(void * )0

static void (*EXTI0_CallBack)(void) = NULL;

/*A function to initiate the EXTI, it works on the line number and the mode while the preprocessor time*/
void MEXTI_voidInit(void)
{
	/*Check Which of the External interrupt is enable*/
	#if		EXTI_LINE == LINE0
			SET_BIT(EXTI -> IMR ,LINE0 );
	#elif	EXTI_LINE == LINE1
			SET_BIT(EXTI -> IMR ,LINE1 );
	#elif	EXTI_LINE == LINE2
			SET_BIT(EXTI -> IMR , LINE2 );
	#else
		#error ("Wrong External Interrupt Line !")
	#endif

	/*Check if RISING MODE is enabled or not and if yes enable it by set the no. of EXTI_LINE in Reg RTSR */
	#if	EXTI_MODE == RISING_EDGE
		SET_BIT(EXTI -> RTSR,EXTI_LINE);
	/*Check if FALLING MODE is enabled or not and if yes enable it by set the no. of EXTI_LINE in Reg FTSR */
	#elif	EXTI_MODE == FALLING_EDGE
		SET_BIT(EXTI -> FTSR,EXTI_LINE);
	/* Check if ON_CHANGE mode is choice , if yes then we will enable the rising and the falling edges*/
	#elif	EXTI_MODE == ON_CHANGE
		/*Enable the RISING_EDGE*/
		SET_BIT(EXTI -> RTSR,EXTI_LINE);
		/*Enable the FALLING_EDGE*/
		SET_BIT(EXTI -> FTSR,EXTI_LINE);
	#else
		#error ("Wrong External interrupts Sense Mode!")
	#endif
}

/* A function to enable the EXTI, it takes the line number*/
void MEXTI_voidEnableEXTI(u8 Copy_u8LineNum)
{
	SET_BIT(EXTI -> IMR, Copy_u8LineNum);
}

/* A function to disable the EXTI, it takes the line number*/
void MEXTI_voidDisableEXTI(u8 Copy_u8LineNum)
{
	CLR_BIT(EXTI -> IMR, Copy_u8LineNum);
}

/* A function to fire the pending flag and make a Software interrupt */
void MEXTI_voidSwTriggerEXTI(u8 Copy_u8LineNum)
{
	SET_BIT(EXTI -> SWIER, Copy_u8LineNum);
}

/*A function to configure the line number and the sense mode in the run time */
void MEXTI_voidSetSignalLatch(u8 Copy_u8LineNum, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
	/* Check if RISING MODE is enabled or not and if yes enable it by set the no. of EXTI_LINE in Reg RTSR */
	case RISING_EDGE:
		SET_BIT(EXTI -> RTSR,Copy_u8LineNum);
		break;

	/* Check if FALLING MODE is enabled or not and if yes enable it by set the no. of EXTI_LINE in Reg FTSR */
	case FALLING_EDGE:
		SET_BIT(EXTI -> FTSR,Copy_u8LineNum);
		break;

	case ON_CHANGE:
		/*Enable the RISING_EDGE*/
		SET_BIT(EXTI -> RTSR,Copy_u8LineNum);
		/*Enable the FALLING_EDGE*/
		SET_BIT(EXTI -> FTSR,Copy_u8LineNum);
		break;

	default:
		/* An error code to be displayed */
	break;
	}
}


void MEXTI_voidSetCallBack(void (* Copy_EXTI0Ptr) (void))
{
	EXTI0_CallBack = Copy_EXTI0Ptr;
}



void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	/*Clear Pending Flag*/
	SET_BIT(EXTI -> PR, 0);
}


/*In main function */
/**

MEXTI_voidSetCallBack(//asm el function ely m7tag yt3mlha execute lma el interrupt y7sl);




*/
