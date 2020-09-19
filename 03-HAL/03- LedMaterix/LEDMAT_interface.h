/************************************************************************************************************
 * Title		:	LEDMAT_interface																		*
 * File name	: 	LEDMAT_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	1 SEP, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef LEDMAT_INTERFACE_H
#define LEDMAT_INTERFACE_H

void HLEDMAT_voidInit();
void HLEDMAT_voidDisplayCharacter(u8 *Copy_u8DataArr);
void HLEDMAT_DisplayString(void);
#endif
