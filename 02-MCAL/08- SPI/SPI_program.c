/************************************************************************************************************
 * Title		:	MSPI_program																			*
 * File name	: 	MSPI_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	19 SEP, 2020																			*
 * Version		: 	v1.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/***************************************** SOURCE REVISION LOG *********************************************
*
*    Date   		 Version 	 	 Author          	 Description 
*  19 SEP, 2020  	  1.0 		Abdullah Mustafa 		Initial Release.
*
 **********************************************************************************************************/

 /**********************************************************************************************************
 *												Inclusions													
 **********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

 /**********************************************************************************************************
 *												Private Functions													
 **********************************************************************************************************/

static void MSPI_voidCallBack(u8);


 /**********************************************************************************************************
 *												API Definitions													
 **********************************************************************************************************/


void MSPI1_voidInit(void)
{
	MSPI1 -> CR1 = ((SPI1_BIDIMODE << BIDIMODE) | (SPI1_BIDIOE << BIDIOE) | (SPI1_CRCEN << CRCEN) |
					(SPI1_CRCNEXT << CRCNEXT) | (SPI1_DATA_FRAME_FORMAT << DFF) | (RXONLY << SPI1_RXONLY) |
					(SPI1_SSM << SSM) | (SPI1_SSI << SSI) | (SPI1_LSBFIRST << LSBFIRST) |
					(SPI1_SPE << SPE) | (BR0_bit << BR0) | (BR1_bit << BR1) | (BR2_bit << BR2) |
					(SPI1_MSTR << MSTR) | (SPI1_CPOL << CPOL) | (SPI1_CPHA << CPHA)
					);
}

void MSPI1_voidSendReceiveSynchronous(u8 Copy_u8DataToTransmit, u8 * Copy_Pu8DataToReceive)
{
	/* Clear for Slave Select Pin to be activated*/
	MSTK_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	/*Send Data to the Data Register of the SPI*/
	MSPI1 -> DR = Copy_u8DataToTransmit;
	/*Polling on the busy flag to finish*/
	while(GET_BIT(MSPI1 -> SR, BSY) == 1);
	/*Receive Data From Data Register*/
	*Copy_Pu8DataToReceive = MSPI1 -> DR;
	/* Set for Slave Select Pin*/
	MSTK_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

void MSPI1_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_voidCallBack)(u8))
{
	/* Clear for Slave Select Pin to be activated*/
	MSTK_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	/*Save the Callback function*/
	MSPI_voidCallBack = Copy_voidCallBack;
	/*Send Data to the Data Register of the SPI*/
	MSPI1 -> DR = Copy_u8DataToTransmit;
	/* Set for Slave Select Pin*/
	MSTK_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);	
}



void SPI1_IRQHandler(void)
{
	/*Clear Rx flag*/
	CLR_BIT(MSPI1 -> SR, RXNE);
	/*Receive the data from DR*/
	MSPI_voidCallBack(MSPI1 -> DR);
}