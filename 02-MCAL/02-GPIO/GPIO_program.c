/***********************************************************************************************************
 * Title		:	GPIO_program																		
 * File name	: 	GPIO_program.h																		
 * Author 		: 	Abdullah Mustafa																	
 * Date			: 	17 AUG, 2020																		
 * Version		: 	V1.0.0																				
 * Description	:																						
 * Compiler		:	Eclipse IDE																			
 * Target		:	STM32F103 Microcontroller															
 * Notes		:	None																				
 *																										
 **********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



/*A function used to set the pin direction using the Mode and port and pin number*/
void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case MGPIO_GPIOA:
		if(Copy_u8Pin <= 7)
		{
			/* Reset the 4 bits of the pin in the CRL Register */
			GPIOA_CRL &=~((0b1111) << (Copy_u8Pin * 4));
			/* Set the 4 bits of the pin in the CRL Register */
			GPIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15)
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			/* Reset the 4 bits of the pin in the CRL Register */
			GPIOA_CRH &=~ ((0b1111) << (Copy_u8Pin * 4));
			/* Set the 4 bits of the pin in the CRL Register */
			GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		break;

	case MGPIO_GPIOB:
		if(Copy_u8Pin <= 7)
		{
			/* Reset the 4 bits of the pin in the CRL Register */
			GPIOB_CRL &=~((0b1111) << (Copy_u8Pin * 4));
			/* Set the 4 bits of the pin in the CRL Register */
			GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15)
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			/* Reset the 4 bits of the pin in the CRL Register */
			GPIOB_CRH &=~ ((0b1111) << (Copy_u8Pin * 4));
			/* Set the 4 bits of the pin in the CRL Register */ 
			GPIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		break;


	case MGPIO_GPIOC:
		if(Copy_u8Pin <= 7)
		{
			/* Reset the 4 bits of the pin in the CRL Register */
			GPIOC_CRL &=~((0b1111) << (Copy_u8Pin * 4));
			/* Set the 4 bits of the pin in the CRL Register */
			GPIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		else if(Copy_u8Pin <= 15)
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			/* Reset the 4 bits of the pin in the CRL Register */
			GPIOC_CRH &=~ ((0b1111) << (Copy_u8Pin * 4));
			/* Set the 4 bits of the pin in the CRL Register */
			GPIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4));
		}
		break;

	default:
		/*An error to get displayed*/
		break;

	}
}

/*A function used to set the value for specific output pin*/
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case MGPIO_GPIOA:
		if(Copy_u8Value == HIGH)
		{
			/*Set the corresponding bit of the pin in BSRR register*/
			GPIOA_BSRR = (1 << Copy_u8Pin);
		}
		else if(Copy_u8Value == LOW)
		{
			/* Set the corresponding bit in BRR Register */
			GPIOA_BRR = (1 << Copy_u8Pin);
		}
		break;
	case MGPIO_GPIOB:
		if(Copy_u8Value == HIGH)
		{
			/*Set the corresponding bit of the pin in BSRR register*/
			GPIOB_BSRR = (1 << Copy_u8Pin);
		}
		else if(Copy_u8Value == LOW)
		{
			/* Set the corresponding bit in BRR Register */
			GPIOB_BRR = (1 << Copy_u8Pin);
		}
		break;
	case MGPIO_GPIOC:
		if(Copy_u8Value == HIGH)
		{
			/*Set the corresponding bit of the pin in BSRR register*/
			GPIOC_BSRR = (1 << Copy_u8Pin);
		}
		else if(Copy_u8Value == LOW)
		{
			/* Set the corresponding bit in BRR Register */
			GPIOC_BRR = (1 << Copy_u8Pin);
		}
		break;
	default:
	/*An error to be displayed*/
		break;
	}
}
/*A function used to toggle the bit*/
void MGPIO_voidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch (Copy_u8Port) {
	case MGPIO_GPIOA:
				TOG_BIT(GPIOA_ODR, Copy_u8Pin);
				break;
	case MGPIO_GPIOB:
				TOG_BIT(GPIOB_ODR, Copy_u8Pin);
				break;
	case MGPIO_GPIOC:
				TOG_BIT(GPIOC_ODR, Copy_u8Pin);
				break;
	default:
		/*An error to be displayed*/
				break;
	}
}


/*A function used to get the value for a specific input pin*/
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	/* Declare a variable to store the returned data */
	u8 Local_u8GPIOResult = 0;
	switch(Copy_u8Port)
	{
	case MGPIO_GPIOA:
		Local_u8GPIOResult = GET_BIT(GPIOA_IDR, Copy_u8Pin);
		break;
	case MGPIO_GPIOB:
		Local_u8GPIOResult = GET_BIT(GPIOB_IDR, Copy_u8Pin);
		break;
	case MGPIO_GPIOC:
		Local_u8GPIOResult = GET_BIT(GPIOC_IDR, Copy_u8Pin);
		break;
	default:
		/*An error to be displayed*/
		break;
	}
return Local_u8GPIOResult;
}
