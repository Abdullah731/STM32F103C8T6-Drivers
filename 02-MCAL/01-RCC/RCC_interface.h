/************************************************************************************************************
 * Title		:	RCC_interface																			*
 * File name	: 	RCC_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	8 AUG, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*********************************** Buses Definition ************************************/ 
#define MRCC_AHB			0
#define MRCC_APB1			1
#define MRCC_APB2			2

/************************************ Peripherals ID for AHB *****************************/
#define 	MRCC_DMA1				0
#define		MRCC_DMA2				1
#define		MRCC_SRAM				2
#define		MRCC_FLITF				4
#define		MRCC_CRC				6
#define		MRCC_FSMC				8
#define		MRCC_SDIO				10

/*********************************** Peripherals ID for APB1 *****************************/
#define 	MRCC_TIM2				0
#define		MRCC_TIM3				1
#define		MRCC_TIM4				2
#define		MRCC_TIM5				3
#define		MRCC_TIM6				4
#define		MRCC_TIM7				5
#define		MRCC_TIM12				6
#define		MRCC_TIM13				7
#define		MRCC_TIM14				8
#define		MRCC_WWDG				11
#define		MRCC_SPI2				14
#define		MRCC_SPI3				15
#define		MRCC_USART2				17
#define		MRCC_USART3				18
#define		MRCC_USART4				19
#define		MRCC_USART5				20
#define		MRCC_I2C1				21
#define		MRCC_I2C2				22
#define		MRCC_USB				23
#define		MRCC_CAN				25
#define		MRCC_BKP				27
#define		MRCC_PWR				28
#define		MRCC_DAC				29

/*********************************** Peripherals ID for APB2 *****************************/
#define 	MRCC_AFIO				0
#define		MRCC_GPIOA				2
#define		MRCC_GPIOB				3
#define		MRCC_GPIOC				4
#define		MRCC_GPIOD				5
#define		MRCC_GPIOE				6
#define		MRCC_GPIOF				7
#define		MRCC_GPIOG				8
#define		MRCC_ADC1				9
#define		MRCC_ADC2				10
#define		MRCC_TIM1				11
#define		MRCC_SPI1				12
#define		MRCC_TIM8				13
#define		MRCC_USART1				14
#define		MRCC_ADC3				15
#define		MRCC_TIM9				19
#define		MRCC_TIM10				20
#define		MRCC_TIM11				21


void MRCC_voidInitSysClock(void);
	 
void MRCC_voidEnableClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName);
	 
void MRCC_voidDisableClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName);

#endif
