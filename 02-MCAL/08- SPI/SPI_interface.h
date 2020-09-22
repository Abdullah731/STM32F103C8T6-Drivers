/************************************************************************************************************
 * Title		:	SPI_interface																			*
 * File name	: 	SPI_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	19 SEP, 2020																			*
 * Version		: 	v1.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 * LOG			:	v1.0	:	Initial creation															*
 ***********************************************************************************************************/

 /***************************************** SOURCE REVISION LOG *********************************************
 *
 *    Date			Version			Author			  Description 
 *  19 SEP, 2020	  1.0		Abdullah Mustafa	Initial Release.
 *
 **********************************************************************************************************/

/************************************************************************************************************
 *	API Description
 *			MSPI1_voidInit
 *					<Function>				A function used to initiate the SPI peripheral to be operates
 *											at this configurations
 *												- 2 Directional lines (Full duplex)
 *												- No CRC
 *												- 8-bit frame formate
 *            									- Transmit and receive
 *            									- NSS controlled by SW
 *            									- MSb Sent first
 *            									- SPI enable
 *            									- Baudrate at fclk/2
 *            									- Master Node
 *            									- Low Idle 
 *            									- Write then Read
 *            									- No interrupts
 *            					return	 		void
 *            					parameters		void
 *            					Local Var		NONE	
 *
 * 			MSPI1_voidSendReceiveSynchronous
 * 					<Function>				used to send and receive data using the polling mechanizm
 * 											and waiting for the BUSY flag.
 * 								return				void
 * 								parameters			Copy_u8DataToTransmit, Copy_Pu8DataToReceive
 * 								Local Var			NONE
 * 			
 * 			MSPI1_voidSendReceiveAsynchronous
 * 					<Function>				used to send and receive data using the interrupt mechanizm.
 * 								return				void
 * 								parameters			Copy_u8DataToTransmit, (*Copy_voidCallBack)(void)
 * 								Local Var			NO					
 ***********************************************************************************************************/

#ifndef	SPI_INTERFACE_H
#define	SPI_INTERFACE_H
/*A function that initiate the SPI peripheral to operates in this options
 * No Bidirectional Mode (Full Duplex) -> Bit(15) = 0; Bit(14) = 0;
 * No CRC,								  Bit(13) = 0; Bit(12) = 0;
 * 8-bit frame formate					  Bit(11) = 0;
 * Master and Slave Node				  Bit(10) = 0;
 * Slave Select pin controlled by S.W  	  Bit(9)  = 1; Bit (8) = 0;
 * MSbit First							  Bit(7)  = 0;
 * Disable SPI							  Bit(6)  = 0;
 * Baud rate: clk over 256				  Bit(5:3)  = 111;
 * Master Node							  Bit(2)	= 1;
 * Clock Polarity (IDLE Low Level)		  Bit(1)	= 1;						   
 * Clock Phase	  (Clock Phase is 1)	  Bit(0)	= 1;
 * 
 */
/******************************************************************************
* Configuration Constants
*******************************************************************************/
//SPI1 PINS
#if SPI_1_AFIO_MAPPING == 0
#define SPI_1_MOSI_PIN        PINA7
#define SPI_1_MISO_PIN        PINA6
#define SPI_1_CLK_PIN         PINA5
#define SPI_1_NSS_PIN         PINA4
#endif
//SPI2 PINS
#define SPI_2_MOSI_PIN        PINB15
#define SPI_2_MISO_PIN        PINA14
#define SPI_2_CLK_PIN         PINB13
#define SPI_2_NSS_PIN         PINB12
//SPI Pins after Mapping
#if SPI_1_AFIO_MAPPING == 1
#define SPI_1_MOSI_PIN        PINB5
#define SPI_1_MISO_PIN        PINB4
#define SPI_1_CLK_PIN         PINB3
#define SPI_1_NSS_PIN         PINA15
#endif


void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynchronous(u8 Copy_u8DataToTransmit, u8 * Copy_Pu8DataToReceive);
void MSPI1_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_voidCallBack)(void));


#endif