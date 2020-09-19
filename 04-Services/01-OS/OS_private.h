/************************************************************************************************************
 * Title		:	OS_private																				*
 * File name	: 	OS_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	6 SEP, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
	u8 				TaskName					;
	u16				Priodicity					;
	void 			(* FunctionPointer)(void)	;
	u8 				FirstDelay					;
	TaskState_t 	State						;

}Task;

typedef enum
{
	Dormant,
	Ready,
	Running,
	Waiting,
	Suspense,

}TaskState_t;




#endif
