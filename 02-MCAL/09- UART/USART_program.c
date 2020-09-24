/************************************************************************************************************
 * Title		:	USART_program																			*
 * File name	: 	USART_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	23 SEP, 2020																			*
 * Version		: 	v1.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 ***********************************************************************************************************/

 /***************************************** SOURCE REVISION LOG *********************************************
 *
 *    Date			Version			Author			  Description 
 *  23 SEP, 2020	  1.0		Abdullah Mustafa	Initial Release.
 *
 **********************************************************************************************************/
 
 /**********************************************************************************************************
 *												Inclusions													
 **********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"



void 	MUSART1_voidInit(void)
{
	/*Configure the Baud rate = 9600, using 8MHz fcpuclk... BRR = 0x341*/
	MUSART1 -> BRR = 0x341;
	/*Configure the USART on this configurations
	 *	1- Enable Rx
	 *	2- Enable Tx
	 *	3- Enable USART peripheral
	 **/
	SET_BIT(MUSART1 -> CR1, 2);
	SET_BIT(MUSART1 -> CR1, 3);
	SET_BIT(MUSART1 -> CR1, 13);
	/*Reset the Status Register (SR)*/
	MUSART1 -> SR = 0x00000000;
	/*Set the GPIO pins of Tx to be Output PP operates at 50MHz*/
	MGPIO_voidSetPinDirection(MUSART_USART1_TX_PIN,OUTPUT_X50MHZ_PP);
	/*Set the GPIO pins of Rx to be INPUT FLOATING*/
	MGPIO_voidSetPinDirection(MUSART_USART1_RX_PIN,INPUT_FLOATING);
}

void 	MUSART1_voidTransmitData(u8 * Copy_u8PDataArr)
{
	/*Transmit the Array*/
	u8 Local_u8i = 0;
	/*Check for the NULL Character*/
	while(Copy_u8PDataArr[Local_u8i] != '\0')
	{
		MUSART1 -> DR = Copy_u8PDataArr[Local_u8i];
		/*polling on the TC (Transmission Complete) flag in SR*/
		while(GET_BIT(MUSART1 -> SR,6) == 0);
		Local_u8i++;
	}
}

void MUSART1_u8ReceiveData(u8 * Copy_u8PDataReceived)
{
	/*polling on the RXNE (Receive Complete) flag in SR*/
	while(GET_BIT(MUSART1 -> SR,5) == 0);
	/*Return the first 8-bit from the DR and store it in the Address of the Passed variable*/
	*Copy_u8PDataReceived = (0xFF & (MUSART1 -> DR));
}
