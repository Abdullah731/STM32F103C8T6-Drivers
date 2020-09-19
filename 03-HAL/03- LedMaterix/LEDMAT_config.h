/************************************************************************************************************
 * Title		:	LEDMAT_config																			*
 * File name	: 	LEDMAT_config.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	1 SEP, 2020																				*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
#ifndef LEDMAT_CONFIG_H
#define LEDMAT_CONFIG_H

/*please define the Rows pin pair... PORT,PIN */
#define LEDMAT_ROW0_PIN		GPIOA,PIN0
#define LEDMAT_ROW1_PIN		GPIOA,PIN1
#define LEDMAT_ROW2_PIN		GPIOA,PIN2
#define LEDMAT_ROW3_PIN		GPIOA,PIN3
#define LEDMAT_ROW4_PIN		GPIOA,PIN4
#define LEDMAT_ROW5_PIN		GPIOA,PIN5
#define LEDMAT_ROW6_PIN		GPIOA,PIN6
#define LEDMAT_ROW7_PIN		GPIOA,PIN7

/*please define the Colums pin pair... PORT,PIN */

#define LEDMAT_COL0_PIN		GPIOB,PIN0
#define LEDMAT_COL1_PIN		GPIOB,PIN1
#define LEDMAT_COL2_PIN		GPIOB,PIN5
#define LEDMAT_COL3_PIN		GPIOB,PIN6
#define LEDMAT_COL4_PIN		GPIOB,PIN7
#define LEDMAT_COL5_PIN		GPIOB,PIN8
#define LEDMAT_COL6_PIN		GPIOB,PIN9
#define LEDMAT_COL7_PIN		GPIOB,PIN10



#endif
