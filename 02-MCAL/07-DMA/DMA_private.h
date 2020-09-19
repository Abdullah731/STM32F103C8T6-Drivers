/************************************************************************************************************
 * Title		:	DMA_private																				*
 * File name	: 	DMA_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	16 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	DMA_PRIVATE_H
#define	DMA_PRIVATE_H

/*Define a structure for the channel registers*/
typedef struct
{
	volatile u32		CCR;
	volatile u32		CNDTR;
	volatile u32		CPAR;
	volatile u32		CMAR;
	volatile u32		Reserved;


}DMA_Channel;

/*Define the DMA data type for the whole register*/
typedef struct
{
	volatile u32 		ISR;
	volatile u32 		IFCR;
	DMA_Channel			Channel[7];
}DMA_t;

/*Define the base address of the DMA*/
#define	DMA				((volatile DMA_t *)0x40020000)



#endif
