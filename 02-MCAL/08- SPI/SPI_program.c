/***********************************************************************************************************
* Title			:	SPI_program																			   
* File name		: 	SPI_program.c																		   
* Author 		: 	Abdullah Mustafa																	   
* Date			: 	19 SEP, 2020																		   
* Version		: 	V1.0.0																				   
* Description	:																						   
* Compiler		:	Eclipse IDE																			   
* Target		:	STM32F103 Microcontroller															   
* Notes			:	None																				   
***********************************************************************************************************/
/***************************************** SOURCE REVISION LOG *********************************************
*
*    Date   		 Version 	 	 Author          	 Description 
*  19 SEP, 2020  	 1.0.0   	Abdullah Mustafa 		Initial Release.
*
 **********************************************************************************************************/
 /**********************************************************************************************************
 *												Inclusions													
 **********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

void 

void MSPI1_voidInit(void)
{
	SPI -> CR1 = 0x000023F;	
}


void MSPI1_voidSendReceiveSynchronous(u8 Copy_u8DataToTransmit, u8 * Copy_Pu8DataToReceive)
{
	/* Clear for Slave Select Pin*/
	MSTK_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	/*Send Data*/
	MSPI1 -> DR = Copy_u8DataToTransmit;
	/*Polling on the busy flag to finish*/
	while(GET_BIT(MSPI1 -> SR, 7) == 1);
	/*Receive Data From Data Register*/
	*Copy_Pu8DataToReceive = MSPI1 -> DR;
	/* Set for Slave Select Pin*/
	MSTK_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

void MSPI1_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_voidCallBack)(u8))
{

}



void SPI_IRQHandler(void)
{

}