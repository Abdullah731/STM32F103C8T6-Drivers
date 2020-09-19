/************************************************************************************************************
 * Title		:	LED_interface																			*
 * File name	: 	LED_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	31 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


void LED_voidLedOn(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutputMode);
void LED_voidLedOff(u8 Copy_u8PortName, u8 Copy_u8PinNum);
void LED_voidLedToggle(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8DelayTime);

#endif
