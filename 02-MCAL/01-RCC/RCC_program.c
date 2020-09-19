/************************************************************************************************************
 * Title		:	RCC_program																				*
 * File name	: 	RCC_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	8 AUG, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/***********************************************************************************************************
* API Description
*		MRCC_voidInitSysClock
*							<function>		used to configure the clock which will enter the processor
*											by controlling the (MRCC->CR) and (MRCC->CFGR) registers between
*											HSE
* 											HSI
* 											PLL
* 												RCC_PLL_IN_HSI_DIV_2
* 												RCC_PLL_IN_HSE_DIV_2
* 												RCC_PLL_IN_HSE
*								return 		void
*								parameters	void
*								variables 	NONE
*
*		MRCC_voidEnableClock
*							<function>		used to disable the clock on different Buses
*											by access and set the bit the corresponding register for each Bus.
*											Registers:		AHBENR		APB1ENR		APB2ENR
*							For AHB
*								DMA1	DMA2	SRAM	FLITF	CRC		FSMC	SDIO
*
*							For APB1
*								TIM2	TIM3	TIM4	TIM5	TIM6	TIM7	TIM12	TIM13	TIM14
*								WWDG	SPI2	SPI3	USART2	USART3	USART4	USART5	I2C1	I2C2
*								USB		CAN		BKP		PWR		DAC
*
*							For APB2
*								AFIO	GPIOA	GPIOB	GPIOC	GPIOD	GPIOE	GPIOF	GPIOG	ADC1
*								ADC2	TIM1	SPI1	TIM8	USART1	ADC3	TIM9	TIM10	TIM11
*
*								return				void
*								parameters			Copy_u8BusName, Copy_u8PeripheralName
*								Local variables		NONE
*
*		MRCC_voidDisableClock
*							<function>		used to disable the clock on different Buses
*											by access and set the bit the corresponding register for each Bus.
*											Registers:		AHBENR		APB1ENR		APB2ENR
*							For AHB
*								MRCC_DMA1	MRCC_MDMA2	MRCC_MSRAM	MRCC_MFLITF	MRCC_MCRC		MRCC_FSMC	MRCC_SDIO
*
*							For APB1
*								MRCC_TIM2	MRCC_TIM3	MRCC_TIM4	MRCC_TIM5	MRCC_TIM6	MRCC_TIM7	MRCC_TIM12	MRCC_TIM13
*								MRCC_TIM14	MRCC_WWDG	MRCC_SPI2	MRCC_SPI3	MRCC_USART2	MRCC_USART3	MRCC_USART4	MRCC_USART5
*								MRCC_I2C1	MRCC_I2C2	MRCC_USB	MRCC_CAN	MRCC_BKP	MRCC_PWR	MRCC_DAC
*
*							For APB2
*								MRCC_AFIO	MRCC_GPIOA	MRCC_GPIOB	MRCC_GPIOC	MRCC_GPIOD	MRCC_GPIOE	MRCC_GPIOF	MRCC_GPIOG
*								MRCC_ADC1	MRCC_ADC2	MRCC_TIM1	MRCC_SPI1	MRCC_TIM8	MRCC_USART1	MRCC_ADC3	MRCC_TIM9
*								MRCC_TIM10	MRCC_TIM11
*
*								return				void
*								parameters			Copy_u8BusName, Copy_u8PeripheralName
*								Local variables		NONE
*
***********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"


void MRCC_voidInitSysClock(void)
{
	/*Check if the clock type is configured as HSE Crystal*/
	#if 		MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL
	/* Enable HSE Crystal (With No BYPASS) From Register (MRCC->CR) */
		(MRCC->CR) = 0x00010000;
	/* Choosing HSE from bits 0 and 1 from register (MRCC->CFGR) */
		(MRCC->CFGR) = 0x00000001;
	/*Polling until the HSE Crystal clock becomes stable and ready*/
	//while(!(GET_BIT((MRCC->CR),17)));

	/*Check if the clock type is configured as HSE RC*/
	#elif 		MRCC_CLOCK_TYPE == MRCC_HSE_RC
		/* Enable HSE RC (With BYPASS) From Register (MRCC->CR) */
		(MRCC->CR) = 0x00050000;
		/* Choosing HSE from bits 0 and 1 from register (MRCC->CFGR) */
		(MRCC->CFGR) = 0x00000001;

	/*Check if the clock type is configured as HSI*/
	#elif		MRCC_CLOCK_TYPE == MRCC_HSI
		/* Enable HSI From Register (MRCC->CR) and set the default value for HSITRIM (0b10000)*/
		(MRCC->CR)	= 0x00000081;
		/* Choosing HSI from bits 0 and 1 from register (MRCC->CFGR) */
		(MMRCC->CFGR) = 0x00000000;
		/*Polling until the HSI clock becomes stable and ready*/
	//	while(!(GET_BIT((MRCC->CR),1)));

	/*Check if the clock type is configured as PLL*/
	#elif		RCC_CLOCK_TYPE == PLL
		/* if the user chose the input of PLL */
		(MRCC->CR) = 0x01000000;
		/* Choosing PLL from bits 0 and 1 from register (MRCC->CFGR) */
		(MRCC->CFGR) = 0x00000002;

		/*Check if the clock type is configured as PLL HSI divided by 3*/
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		(MRCC->CR) = 0x00000000;
		/* Choosing PLL from bits 0 and 1 from register (MRCC->CFGR) */
		(MRCC->CFGR) = 0x00000002;

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		(MRCC->CR) = 0x00000000;
		/* Choosing PLL from bits 0 and 1 from register (MRCC->CFGR) */
		(MRCC->CFGR) = 0x00030000;

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		(MRCC->CR) = 0x00000000;
		/* Choosing PLL from bits 0 and 1 from register (MRCC->CFGR) */
		(MRCC->CFGR) = 0x00010000;

		#else
			#error("You chose wrong PLL input ");
		#endif
	#else
		#error("You Chose Wrong Clock Type!");
	#endif
}

/*A function to Enable the clock for peripheral using the BusName and the peripheral name*/
void MRCC_voidEnableClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName)
{
	switch(Copy_u8BusName)
	{
		case MRCC_AHB	: SET_BIT(MRCC->AHBENR	,Copy_u8PeripheralName);		break;
		case MRCC_APB1	: SET_BIT(MRCC->APB1ENR	,Copy_u8PeripheralName);		break;
		case MRCC_APB2	: SET_BIT(MRCC->APB2ENR	,Copy_u8PeripheralName);	 	break;
	}
}

/*A function to Disable the clock for peripheral using the BusName and the PeripheralName*/
void MRCC_voidDisableClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName)
{
	switch(Copy_u8BusName)
	{
		case MRCC_AHB	: CLR_BIT(MRCC->AHBENR	,Copy_u8PeripheralName);		break;
		case MRCC_APB1	: CLR_BIT(MRCC->APB1ENR	,Copy_u8PeripheralName);		break;
		case MRCC_APB2	: CLR_BIT(MRCC->APB2ENR	,Copy_u8PeripheralName); 		break;
	}
}
