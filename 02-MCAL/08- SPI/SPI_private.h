/************************************************************************************************************
 * Title		:	SPI_private																				*
 * File name	: 	SPI_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	18 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	SPI_PRIVATE_H
#define	SPI_PRIVATE_H


typedef struct 
{
	volatile u32	CR1			;
	volatile u32	CR2			;
	volatile u32	SR			;
	volatile u32	DR			;
	volatile u32	CRCPR		;
	volatile u32	RXCRCR		;
	volatile u32	TXCRCR		;
	volatile u32	I2SCFGR		;
	volatile u32	I2SPR		;
}SPI_Registers_t;

#define MSPI		((volatile SPI_Registers_t *)0x40013000)


#endif