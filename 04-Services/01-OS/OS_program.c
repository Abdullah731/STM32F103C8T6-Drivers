#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL	(void *)0

/*Define an array of Task structure*/
static Task	OS_Tasks[NUMBER_OF_TASKS] = {NULL};



void SOS_voidCreateTask(u8 Copy_u8TaskName,u8 Copy_u8TaskPriority , u16 Copy_u16Priodicity, void (* FunctionPointer)(void), u8 Copy_u8FirstDelay)
{
	OS_Tasks[Copy_u8TaskPriority].TaskName			= Copy_u8TaskName;
	OS_Tasks[Copy_u8TaskPriority].priodicity 		= Copy_u16Priodicity;
	OS_Tasks[Copy_u8TaskPriority].FunctionPointer	= FunctionPointer;
	OS_Tasks[Copy_u8TaskPriority].State				= Ready;

}

void SOS_voidStart(void)
{
	/*initialization part of OS*/
	MSTK_voidInit();
	/*define the tick time to be 1ms periodic on HSE (8MHz) divided by 8 -> 1000 microseconds = 1ms*/
	MSTK_voidSetIntervalPeriodic(1000,SOS_voidScheduler);

}
volatile u8 Local_u8TaskCounter = 0;
/*
void SOS_voidScheduler(void)
{
	u8 i = 0;
	for(i = 0; i < NUMBER_OF_TASKS; i++)
	{
		/*Check if the periodicity of the task is come or not
		if((TickCounts % OS_Tasks[i].priodicity) == 0)
		{
			OS_Tasks[i].FunctionPointer();
		}
	}
	Local_u8TaskCounter++;
}*/
static void SOS_voidScheduler(void)
{
	u8 i = 0;
	for(i = 0; i < NUMBER_OF_TASKS; i++)
	{
		if((OS_Tasks[i].FunctionPointer != NULL) && ((OS_Tasks[i].State == Ready) || (OS_Tasks[i].State == Dormant)))
		{
			if(OS_Tasks[i].FirstDelay == 0)
			{
				OS_Tasks[i].FirstDelay = (OS_Tasks[i].priodicity - 1);
				OS_Tasks[i].FunctionPointer();
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}
		}
	}
}





void SOS_voidKillTask(u8 Copy_u8TaskName)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUMBER_OF_TASKS; Local_u8LoopCounter++)
	{
		if(OS_Tasks[Local_u8LoopCounter].TaskName == Copy_u8TaskName)
		{
			OS_Tasks[Local_u8LoopCounter].TaskName = NULL;
			OS_Tasks[Local_u8LoopCounter].priodicity = NULL;
			OS_Tasks[Local_u8LoopCounter].FunctionPointer = NULL;
		}
		else
		{
			/*Nothing to do ..!*/
		}
	}
}





void SOS_voidPauseTask(u8 Copy_u8TaskName)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUMBER_OF_TASKS; Local_u8LoopCounter++)
	{
		if(OS_Tasks[Local_u8LoopCounter].TaskName == Copy_u8TaskName)
		{
			OS_Tasks[Local_u8LoopCounter].State = Suspense;
		}
	}
}

void SOS_voidResumeTask(u8 Copy_u8TaskName)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUMBER_OF_TASKS; Local_u8LoopCounter++)
	{
		if(OS_Tasks[Local_u8LoopCounter].TaskName == Copy_u8TaskName)
		{
			OS_Tasks[Local_u8LoopCounter].State = Ready;
			SOS_voidScheduler();
		}
	}
}
