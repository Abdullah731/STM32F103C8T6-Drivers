/************************************************************************************************************
 * Title		:	IR_private																				*
 * File name	: 	IR_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	12 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef	IR_PRIVATE_H
#define	IR_PRIVATE_H

typedef enum
{
	PWR			 =  69 ,
	MODE         =  70 ,
	MUTE         =  71 ,
	PLAY_RESUME  =  68 ,
	LEFT	     =  64 ,
	RIGHT        =  67 ,
	EQ           =  7  ,
	VOLUME_DOWN  =  21 ,
	VOLUME_UP    =  9  ,
	ZERO         =  22 ,
	RPT          =  25 ,
	U_USD        =  13 ,
	ONE          =  12 ,
	TWO          =  24 ,
	THREE        =  94 ,
	FOUR         =  8  ,
	FIVE         =  28 ,
	SIX          =  90 ,
	SEVEN        =  66 ,
	EIGHT        =  82 ,
	NINE         =  74 ,
}ButtonsCode_t;




#endif


