/************************************************************************************************************
 * Title		:	NVIC_interface																			*
 * File name	: 	NVIC_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	23 AUG, 2020 - 30 AUG, 2020																*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
 /***********************************************************************************************************
 * MNVIC_viodInit
 *			<Function>		used to initiate the external interrupts Group and Sub priorities
 *							return		void
 *							parameters	NONE
 *
 *	MNVIC_voidEnableInterrupt																	
 *			<Function> 		use this function to enable the external peripheral interrupts by 
 *							writing on NVIC_ISERx Register
 *										0 => has no effect										
 *										1 => Enable the external peripheral interrupt			
 *							return			void												
 *							parameters		1- Copy_u8PeripheralName									
 *																																									
 * MNVIC_voidDisableInterrupt																	
 *			<Function> 		use this function to enable the external peripheral interrupts by 
 *							writing on NVIC_ISERx Register
 *										0 => has no effect										
 *										1 => Disable the external peripheral interrupt			
 *							return			void												
 *							parameters		1- Copy_u8PeripheralName									
 *																								
 *																								
 * 	MNVIC_voidSetPendingFlag																	
 * 			<Function> 		use this function to Set Pending Flag for external peripheral 
 *							interrupts
 *										0 => has no effect										
 *										1 => Set pending flag									
 *							return			void												
 *							parameters		1- Copy_u8PeripheralName									
 * 																					 			
 * 																					 			
 * 	MNVIC_voidClearPendingFlag 																	
 * 			<Function> 		use this function to Clear Pending Flag for external peripheral 
 *							interrupts
 *										0 => has no effect										
 *										1 => clear pending flag									
 *							return			void												
 *							parameters		1- Copy_u8PeripheralName									
 * 																					 			
 * 																				 				
 * 																					 			
 * 	MNVIC_u8GetActiveFlag																		
 * 			<Function> 		use this function to Get the status of Active Flag for external 
 *							peripheral interrupts
 *										0 => interrupt is not active							
 *										1 => interrupt is active								
 *							return			u8													
 *							parameters		1- Copy_u8PeripheralName																						
 * 							Local variables	1- Local_u8Status 									
 * 																								
 * 	MNVIC_voidSetPriority
 *			<Function>		used to set the software priority for each external interrupt
 *							return			void
 *							parameters		Copy_s8PeripheralName	Copy_u8GroupPriority	Copy_u8SubPriority	Copy_u32GroupSubDistribution
 *							Local variables	1- Local_u8Priority
 * 																								
 * 																								
 ************************************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/**************** Vector table for NVIC peripherals (Register Description data sheet P.206) ****************/
#define			MNVIC_WWDG						0
#define			MNVIC_PVD						1
#define			MNVIC_TAMPER					2
#define			MNVIC_RTC						3
#define			MNVIC_FLASH						4
#define			MNVIC_RCC						5
#define			MNVIC_EXTI0						6
#define			MNVIC_EXTI1						7
#define			MNVIC_EXTI2						8
#define			MNVIC_EXTI3						9
#define			MNVIC_EXTI4						10
#define			MNVIC_DMA1_CHANNEL1				11
#define			MNVIC_DMA1_CHANNEL2				12
#define			MNVIC_DMA1_CHANNEL3				13
#define			MNVIC_DMA1_CHANNEL4				14
#define			MNVIC_DMA1_CHANNEL5				15
#define			MNVIC_DMA1_CHANNEL6				16
#define			MNVIC_DMA1_CHANNEL7				17
#define			MNVIC_ADC1_2					18
#define			MNVIC_USB_HP_CAN_TX				19
#define			MNVIC_USB_LP_CAN_RX0			20
#define			MNVIC_CAN_RX1					21
#define			MNVIC_CAN_SCE					22
#define			MNVIC_EXTI9_5					23
#define			MNVIC_TIM1_BRK					24
#define			MNVIC_TIM1_UP					25
#define			MNVIC_TIM1_TRIG_COM				26
#define			MNVIC_TIM1_CC					27
#define			MNVIC_TIM2						28
#define			MNVIC_TIM3						29
#define			MNVIC_TIM4						30
#define			MNVIC_I2C1_EV					31
#define			MNVIC_I2C1_ER					32
#define			MNVIC_I2C2_EV					33
#define			MNVIC_I2C2_ER					34
#define			MNVIC_SPI1						35
#define			MNVIC_SPI2						36
#define			MNVIC_USART1					37
#define			MNVIC_USART2					38
#define			MNVIC_USART3					39
#define			MNVIC_EXTI15_10					40
#define			MNVIC_RTCALARM					41
#define			MNVIC_USBWAKEUP					42
#define			MNVIC_TIM8_BRK					43
#define			MNVIC_TIM8_UP					44
#define			MNVIC_TIM8_TRIG_COM				45
#define			MNVIC_TIM8_CC					46
#define			MNVIC_ADC3						47
#define			MNVIC_FSMC						48
#define			MNVIC_SDIO						49
#define			MNVIC_TIM5						50
#define			MNVIC_SPI3						51
#define			MNVIC_UART4						52
#define			MNVIC_UART5						53
#define			MNVIC_TIM6						54
#define			MNVIC_TIM7						55
#define			MNVIC_DMA2_CHANNEL1				56
#define			MNVIC_DMA2_CHANNEL2				57
#define			MNVIC_DMA2_CHANNEL3				58
#define			MNVIC_DMA2_CHANNEL4_5			59

/***************************************** API Prototypes ***************************************************/

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

/* Function to define the number of groups and sub groups */
void MNVIC_voidInit(void);
/* Function to Enable the external peripheral interrupts */
void MNVIC_voidEnableInterrupt	(u8 Copy_u8PeripheralName);
/* Function to Disable the external peripheral interrupts */
void MNVIC_voidDisableInterrupt	(u8 Copy_u8PeripheralName);
/* Function to Set Pending Flag for external peripheral interrupts */
void MNVIC_voidSetPendingFlag	(u8 Copy_u8PeripheralName);
/* Function to Clear Pending Flag for external peripheral interrupts */
void MNVIC_voidClearPendingFlag	(u8 Copy_u8PeripheralName);
/* Function to return the status of Active Flag */
u8 MNVIC_u8GetActiveFlag		(u8 Copy_u8PeripheralName);
/* Function to Set priority for each interrupt and sub interrupt */
void MNVIC_voidSetPriority(s8 Copy_s8PeripheralName, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif
