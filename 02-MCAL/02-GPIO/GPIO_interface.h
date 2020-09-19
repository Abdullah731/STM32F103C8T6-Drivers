/************************************************************************************************************
 * Title		:	GPIO_interface																			*
 * File name	: 	GPIO_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	17 AUG, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/***********************************************************************************************************
	API Description
*		MGPIO_voidSetPinDirection
*					<function>			used to set the pin direction whether it is output or input with
*										modes, by accessing the CRL and CRH registers.
*							return				void
*							parameters			Copy_u8Port		Copy_u8Pin		Copy_u8Mode
*							Local variables		NONE
*
*		MGPIO_voidSetPinValue
*					<function>			used to set the value for a specific output pin using the BRR and
*										BSRR registers.
*							return				void
*							parameters			Copy_u8Port		Copy_u8Pin		Copy_u8Value
*							Local variables		NONE
*
*		MGPIO_voidTogglePin
*					<function>			used to toggle the pin from high to low and vice versa using the ODR
*										register.
*							return				void
*							parameters			Copy_u8Port		Copy_u8Pin
*							Local variables		NONE
*
*		MGPIO_u8GetPinValue
*					<function>			used to get the value for a specific input pin using the IDR register.
*							return				u8
*							parameters			Copy_u8Port		Copy_u8Pin
*							Local variables		Local_u8GPIOResult
***********************************************************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define MGPIO_GPIOA		0
#define MGPIO_GPIOB		1
#define MGPIO_GPIOC		2

#define MGPIO_PIN0		0
#define MGPIO_PIN1		1
#define MGPIO_PIN2		2
#define MGPIO_PIN3		3
#define MGPIO_PIN4		4
#define MGPIO_PIN5		5
#define MGPIO_PIN6		6
#define MGPIO_PIN7		7
#define MGPIO_PIN8		8
#define MGPIO_PIN9		9
#define MGPIO_PIN10		10
#define MGPIO_PIN11		11
#define MGPIO_PIN12		12
#define MGPIO_PIN13		13
#define MGPIO_PIN14		14
#define MGPIO_PIN15		15

#define HIGH		1
#define LOW			0

/********************************** INPUT MODE WITH 10MHZ SPEED ***********************************/
#define INPUT_ANALOG		(0b0000)
#define INPUT_FLOATING		(0b0100)
#define INPUT_PULLUPDWN		(0b1000)

/********************************** OUTPUT MODE WITH 10MHZ SPEED ***********************************/
#define OUTPUT_X10MHZ_PP	(0b0001)
#define OUTPUT_X10MHZ_OD	(0b0101)
#define OUTPUT_X10MHZ_AFPP	(0b1001)
#define OUTPUT_X10MHZ_AFOD	(0b1101)



/********************************** OUTPUT MODE WITH 2MHZ SPEED ***********************************/
#define OUTPUT_X2MHZ_PP		(0b0010)
#define OUTPUT_X2MHZ_OD		(0b0110)
#define OUTPUT_X2MHZ_AFPP	(0b1010)
#define OUTPUT_X2MHZ_AFOD	(0b1110)

/********************************** OUTPUT MODE WITH 50MHZ SPEED ***********************************/
#define OUTPUT_X50MHZ_PP	(0b0011)
#define OUTPUT_X50MHZ_OD	(0b0111)
#define OUTPUT_X50MHZ_AFPP	(0b1011)
#define OUTPUT_X50MHZ_AFOD	(0b1111)





void	MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void	MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void	MGPIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);
u8		MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif
