/************************************************************************************************************
 * Title		:	DMA_program																				*
 * File name	: 	DMA_program.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	16 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"


void 	MDMA_voidChannelInit(void);
{
	/*
	 * 1- m2m
	 * 2- very high pirority
	 * 3- source size , destination size = 32 bit
	 * 4- SINC(MINC), PINC(DINC)
	 * 5- No Circular
	 * 6- Direction
	 * 7- Transfer interrupt Enable
	 */
	#if(CHANNEL_ID == 1)
		DMA -> CHANNEL[0].CCR =
	#else

	#endif

}

void 	MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress, u32 * Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/*Disable the Channel*/
	CLR_BIT(DMA -> Channel[0].CCR, 0);
	/*Write the Source address*/
	DMA -> Channel[0].CPAR = Copy_Pu32SourceAddress;
	/*Write the Source address*/
	DMA -> Channel[0].CMAR = Copy_Pu32DestinationAddress;
	/*Set the Block Length*/
	DMA -> Channel[0].CNDTR = Copy_u16BlockLength;
	/*Enable the Channel*/
	SET_BIT(DMA -> Channel[0].CCR, 0);

}
