/************************************************************************************************************
 * Title		:	MAFIO_private																			*
 * File name	: 	MAFIO_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020 																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
#ifndef MAFIO_PRIVATE_H
#define MAFIO_PRIVATE_H


typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}MAFIO_t;

/* Define a pointer to structure which points to the base address of AFIO register */
#define MAFIO ((volatile MAFIO_t *) 0x40010000)




#endif