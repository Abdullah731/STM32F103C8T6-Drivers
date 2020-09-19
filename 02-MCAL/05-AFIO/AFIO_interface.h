/************************************************************************************************************
 * Title		:	MAFIO_interface																			*
 * File name	: 	MAFIO_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/************************************************************************************************************
	API Description
			MAFIO_voidSetEXTIConfig
					<function>			used to set the configuration of the desired pin to enter the MUX of
										External line.
									return				void
									parameters			Copy_u8LineNum		Copy_u8PortName
									Local variables		Local_u8RegIndex	Local_u8Port
 ***********************************************************************************************************/

#ifndef MAFIO_INTERFACE_H
#define MAFIO_INTERFACE_H

void MAFIO_voidSetEXTIConfig(u8 Copy_u8LineNum, u8 Copy_u8PortName);


#endif