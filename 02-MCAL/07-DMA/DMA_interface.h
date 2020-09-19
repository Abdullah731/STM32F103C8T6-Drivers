/************************************************************************************************************
 * Title		:	DMA_interface																			*
 * File name	: 	DMA_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	16 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	DMA_INTERFACE_H
#define	DMA_INTERFACE_H

/*Function to initiate the channel of the DMA*/
void 	MDMA_voidChannelInit(void);
/**/
void 	MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress, u32 * Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength);


#endif
