/***********************************************************************************************
 * Title		:	NVIC_program																
 * File name	: 	NVIC_program.c																
 * Author 		: 	Abdullah Mustafa															
 * Date			: 	23 AUG, 2020																
 * Version		: 	V1.0.0																		
 * Description	:																				
 * Compiler		:	Eclipse IDE																	
 * Target		:	STM32F103 Microcontroller													
 * Notes		:	None																		
 *																								
 ***********************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	/* el function httms7 b3den 3l4an to3tbr m4 s7 f hn3rf el reg hna dlw2te*/
	#define SCB_AIRCR	*((volatile u32 *)(0xE000ED0C))
	/* Set the number of groups and subs to the SCB_AIRCR */
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRUBTION;

}
/*A function to enable the NVIC interrupt*/
/*Options for Peripheral Name:
	MNVIC_WWDG				MNVIC_PVD				MNVIC_TAMPER			MNVIC_RTC				MNVIC_FLASH
	MNVIC_RCC				MNVIC_EXTI0				MNVIC_EXTI1				MNVIC_EXTI2				MNVIC_EXTI3
	MNVIC_EXTI4				MNVIC_DMA1_CHANNEL1		MNVIC_DMA1_CHANNEL2		MNVIC_DMA1_CHANNEL3		MNVIC_DMA1_CHANNEL4
	MNVIC_DMA1_CHANNEL5		MNVIC_DMA1_CHANNEL6		MNVIC_DMA1_CHANNEL7		MNVIC_ADC1_2			MNVIC_USB_HP_CAN_TX
	MNVIC_USB_LP_CAN_RX0	MNVIC_CAN_RX1			MNVIC_CAN_SCE			MNVIC_EXTI9_5			MNVIC_TIM1_BRK
	MNVIC_TIM1_UP			MNVIC_TIM1_TRIG_COM		MNVIC_TIM1_CC			MNVIC_TIM2				MNVIC_TIM3
	MNVIC_TIM4				MNVIC_I2C1_EV			MNVIC_I2C1_ER			MNVIC_I2C2_EV			MNVIC_I2C2_ER
	MNVIC_SPI1				MNVIC_SPI2				MNVIC_USART1			MNVIC_USART2			MNVIC_USART3
	MNVIC_EXTI15_10			MNVIC_RTCALARM			MNVIC_USBWAKEUP			MNVIC_TIM8_BRK			MNVIC_TIM8_UP
	MNVIC_TIM8_TRIG_COM		MNVIC_TIM8_CC			MNVIC_ADC3				MNVIC_FSMC				MNVIC_SDIO
	MNVIC_TIM5				MNVIC_SPI3				MNVIC_UART4				MNVIC_UART5				MNVIC_TIM6
	MNVIC_TIM7				MNVIC_DMA2_CHANNEL1		MNVIC_DMA2_CHANNEL2		MNVIC_DMA2_CHANNEL3		MNVIC_DMA2_CHANNEL4_5
*/
void MNVIC_voidEnableInterrupt(u8 Copy_u8PeripheralName) /* u8 because we have only from 0 to 59 external interrupt */
{
	/* Check if the number is from 0 to 31 to access the ISER0, else if it is from 32 to 59 then we will access ISER1 */
	if(Copy_u8PeripheralName <= 31)
	{
		/* Set bit in Register NVIC_ISER0 by writing 1 to enable the external peripheral interrupt */
		NVIC_ISER0 = (1 << Copy_u8PeripheralName);
	}
	else if(Copy_u8PeripheralName <= 59)
	{
		/* if we got a interrupt number 32, then we need to set bit 0 in the register so we have to sub 32 from the entered number */
		Copy_u8PeripheralName -= 32;
		/* Set bit in Register NVIC_ISER1 by writing 1 to enable the external peripheral interrupt */
		NVIC_ISER1 = (1 << Copy_u8PeripheralName);
	}
	else
	{
		/* Code for error or do nothing */
	}
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8PeripheralName) /* u8 because we have only from 0 to 59 external interrupt */
{
	/* Check if the number is from 0 to 31 to access the ICER0, else if it is from 32 to 59 then we will access ICER1 */
	if(Copy_u8PeripheralName <= 31)
	{
		/* Set bit in Register NVIC_ICER0 by writing 1 to disable the external peripheral interrupt */
		NVIC_ICER0 = (1 << Copy_u8PeripheralName);
	}
	else if(Copy_u8PeripheralName <= 59)
	{
		/* if we got a interrupt number 32, then we need to clear bit 0 in the register so we have to sub 32 from the entered number */
		Copy_u8PeripheralName -= 32;
		/* Clear bit in Register NVIC_ICER1 by writing 1 to disable the external peripheral interrupt */
		NVIC_ICER1 = (1 << Copy_u8PeripheralName);
	}
	else
	{
		/* Code for error or do nothing */
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralName)
{
	/* Check if the interrupt number is from 0 to 31*/
	if(Copy_u8PeripheralName <=31)
	{
		NVIC_ISPR0 = (1 << Copy_u8PeripheralName);
	}
	else if(Copy_u8PeripheralName <= 59)
	{
		Copy_u8PeripheralName -= 32;
		NVIC_ISPR1 = (1 << Copy_u8PeripheralName);
	}
	else
	{
		/* Code for error or do nothing*/
	}
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralName)
{
	/* Check if the interrupt number is from 0 to 31*/
	if(Copy_u8PeripheralName <=31)
	{
		NVIC_ICPR0 = (1 << Copy_u8PeripheralName);
	}
	else if(Copy_u8PeripheralName <= 59)
	{
		Copy_u8PeripheralName -= 32;
		NVIC_ICPR1 = (1 << Copy_u8PeripheralName);
	}
	else
	{
		/* Code for error or do nothing*/
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralName)
{
	/* Declare variable to save the status of active flag*/
	u8 Local_u8Status = 0;
	/* Check if the interrupt number is from 0 to 31*/
	if(Copy_u8PeripheralName <=31)
	{
		/* read the value of interrupt number from Interrupt Active Bit Register (IABR0) and save this value in the Status variable */
		Local_u8Status = GET_BIT(NVIC_IABR0, Copy_u8PeripheralName);
		/* Return the value of the Status variable */

	}
	else if(Copy_u8PeripheralName <= 59)
	{
		/* read the value of interrupt number from Interrupt Active Bit Register (IABR1) and save this value in the Status variable */
		Local_u8Status = GET_BIT(NVIC_IABR1, Copy_u8PeripheralName);
		/* Return the value of the Status variable */

	}
	else
	{
		/* Code for error or do nothing*/
	}
	return Local_u8Status;
}


void MNVIC_voidSetPriority(s8 Copy_s8PeripheralName, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
	/* An equation to get the Value of the priority that will be entered in PR register*/
	u8 Local_u8Priority = ( Copy_u8SubPriority | (Copy_u8GroupPriority << ((MNVIC_GROUP_SUB_DISTRUBTION - 0x05FA0300) / 256)));
	/*Core peripheral so we have to check the ID for the interrupt which must be less than zero for internal interrupts*/
	
	
	/*For external interrupts so we have to check the ID for the interrupt which must be more than zero for external interrupts*/
	if(Copy_s8PeripheralName >= 0)
	{
		NVIC_IPR[Copy_s8PeripheralName] = (Local_u8Priority << 4);
	}
	
	else
	{
		/* Code to be displayed if there is an error*/
	}
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRUBTION;
	
}
