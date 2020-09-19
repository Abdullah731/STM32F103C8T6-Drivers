/************************************************************************************************************
 * Title		:	IR_config																				*
 * File name	: 	IR_config.h																				*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	12 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/


#ifndef	IR_CONFIG_H
#define	IR_CONFIG_H

/*Define where the IR receiver connected to the mcu*/
/* Options:
 * 		EXTI0 ... EXTI16
 * */
#define HIR_EXTI_LINE		(EXTI0)
/*Define the PORT and PIN for the IR receiver, please choose the port and pin separated by comma ',' */
#define HIR_PORT_PIN		(GPIOA,PIN0)


#endif
