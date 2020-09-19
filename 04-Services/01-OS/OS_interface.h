/************************************************************************************************************
 * Title		:	OS_interface																			*
 * File name	: 	OS_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	6 SEP, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u8 Copy_u8TaskName, u8 Copy_u8TaskPriority , u16 Copy_u16Priodicity, void (* FunctionPointer)(void), u8 Copy_u8FirstDelay);
static void SOS_voidScheduler(void);
void SOS_voidStart(void);
void SOS_voidKillTask(u8 Copy_u8TaskName);
void SOS_voidPauseTask(u8 Copy_u8TaskName);
void SOS_voidResumeTask(u8 Copy_u8TaskName);
#endif
