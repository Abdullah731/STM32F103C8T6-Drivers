/************************************************************************************************************
 * Title		:	MSPI_private																			*
 * File name	: 	MSPI_private.h																			*
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
 *    Date			Version			Author			  Description 
 *  19 SEP, 2020	  1.0		Abdullah Mustafa	Initial Release.
 *
 **********************************************************************************************************/

#ifndef	MSPI_PRIVATE_H
#define	MSPI_PRIVATE_H

/************************** Register Description Of SPI Peripheral *****************************/
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
}MSPI_Registers_t;

/*********************** Define the base address of each SPI peripheral ************************/
#define MSPI1		((volatile MSPI_Registers_t *)0x40013000)
#define MSPI2		((volatile MSPI_Registers_t *)0x40003800)

/**************************************** Bits definition *************************************/
/*CR1 Register*/
#define CPHA       0
#define CPOL       1
#define MSTR       2
#define BR0		   3
#define BR1		   4
#define BR2		   5
#define SPE        6
#define LSBFIRST   7
#define SSI        8
#define SSM        9
#define RXONLY     10
#define DFF        11
#define CRCNEXT    12
#define CRCEN      13
#define BIDIOE     14
#define BIDIMODE   15

/*CR2 Register*/
#define RXDMAEN    0
#define TXDMAEN    1
#define SSOE       2
#define ERRIE      5
#define RXNEIE     6
#define TXEIE      7

/*SR Register*/
#define RXNE       0
#define TXE        1
#define CHSIDE     2
#define UDR        3
#define CRCERR     4
#define MODF       5
#define OVR        6
#define BSY        7



#endif