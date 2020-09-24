/************************************************************************************************************
 * Title		:	USART_private																			*
 * File name	: 	USART_private.h																			*
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

#ifndef	USART_PRIVATE_H
#define	USART_PRIVATE_H

typedef struct
{
	volatile	u32		SR;
	volatile	u32		DR;
	volatile	u32		BRR;
	volatile	u32		CR1;
	volatile	u32		CR2;
	volatile	u32		CR3;
	volatile	u32		GBPR;	
}MUSART_t;

#define		MUSART1		((volatile MUSART_t *)(0x40013800))

#define DISABLE		0
#define ENABLE		1

/*Define the USART GPIO pin*/
/*USART1*/
#if 	USART_AFIO_CONFIG == DISABLE
	#define 	MUSART_USART1_TX_PIN		MGPIO_GPIOA,PIN9
	#define 	MUSART_USART1_RX_PIN		MGPIO_GPIOA,PIN10
#elif	USART_AFIO_CONFIG == ENABLE
	#define MUSART_USART1_TX_PIN		MGPIO_GPIOA,PIN6
	#define MUSART_USART1_RX_PIN		MGPIO_GPIOA,PIN7
#else
	#error("Wrong USART Pin Configurations")
#endif

/*USART2*/
#define MUSART_USART2_TX_PIN		(GPIOA,PIN2)
#define MUSART_USART2_RX_PIN		(GPIOA,PIN3)
/*USART3*/
#define MUSART_USART3_TX_PIN		(GPIOB,PIN10)
#define MUSART_USART3_RX_PIN		(GPIOB,PIN11)

#endif
