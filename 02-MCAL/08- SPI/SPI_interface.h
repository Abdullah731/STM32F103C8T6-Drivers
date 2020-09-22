/************************************************************************************************************
 * Title		:	SPI_interface																			*
 * File name	: 	SPI_interface.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	19 SEP, 2020																			*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 * LOG			:	v1.0	:	Initial creation															*
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
void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynchronous(u8 Copy_u8DataToTransmit, u8 * Copy_Pu8DataToReceive);
void MSPI1_voidSendReceiveAsynchronous(u8 Copy_u8DataToTransmit, void (*Copy_voidCallBack)(void));


#endif