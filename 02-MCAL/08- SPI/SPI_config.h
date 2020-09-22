/************************************************************************************************************
 * Title		:	SPI_config																				*
 * File name	: 	SPI_config.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	19 SEP, 2020																			*
 * Version		: 	v1.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 * 																											*
 ***********************************************************************************************************/
 /***************************************** SOURCE REVISION LOG *********************************************
 *
 *    Date			Version			Author			  Description 
 *  19 SEP, 2020	 1.0		Abdullah Mustafa	Initial Release.
 *
 **********************************************************************************************************/
#ifndef	SPI_CONFIG_H
#define	SPI_CONFIG_H

/*Preprocessor Constants*/
#define	MSPI_SPI1						1
#define	MSPI_SPI2						2
#define	MSPI_SPI_ALL					3
#define MSPI_SPI_MODE_SLAVE  			0
#define MSPI_SPI_MODE_MASTER 			1

/*Define how many SPI used*/
#define MSPI_SPI_USED					MSPI_SPI1

#define MSPI_SPI1_MODE  				SPI_MODE_MASTER
#define MSPI_SPI2_MODE  				SPI_MODE_SLAVE

/*Set The number Of Slaves and The NSS Pins*/
#define SPI1_NUMBER_OF_SLAVES  1
#define SPI2_NUMBER_OF_SLAVES  1

/* Define the AFIO for SPI Pins */
/* Options:
 *	0: Connection 1
 *			SPI1
 *				MOSI_PIN        PINA7
 *				MISO_PIN        PINA6
 *				CLK_PIN         PINA5
 *				NSS_PIN         PINA4
 *			SPI2
 *				MOSI_PIN        PINB15
 *				MISO_PIN        PINA14
 *				CLK_PIN         PINB13
 *				NSS_PIN         PINB12
 *
 *	1: Connection 2
 *			SPI1
 *				MOSI_PIN        PINB5
 *				MISO_PIN        PINB4
 *				CLK_PIN         PINB3
 *				NSS_PIN         PINA15
 */
#define SPI_1_AFIO_MAPPING	   0
/*Define The GPIO Pins for Slave Select Pin, please pair the pins GPIOx,PINx*/
#define SPI1_NSS_1_PIN         		GPIOA,PIN2
#define SPI2_NSS_1_PIN         		GPIOA,PIN15

#if (MSPI_SPI_USED == MSPI_SPI1)
	#if (MSPI_SPI1_MODE == SPI_MODE_MASTER)
			static u8 SPI1_SelectSlavePins[SPI1_NUMBER_OF_SLAVES + 1] = {SPI1_NSS_1_PIN};
	#endif
#elif (MSPI_SPI_USED == MSPI_SPI2)
	#if (MSPI_SPI2_MODE == SPI_MODE_MASTER)
			static u8 SPI2_SelectSlavePins[SPI2_NUMBER_OF_SLAVES + 1] = {SPI2_NSS_1_PIN};
	#endif
#elif (MSPI_SPI_USED == MSPI_SPI_ALL)
	#if (MSPI_SPI1_MODE == SPI_MODE_MASTER)
		static u8 SPI1_SelectSlavePins[SPI1_NUMBER_OF_SLAVES + 1] = {SPI1_NSS_1_PIN};
	#endif
	#if (MSPI_SPI2_MODE == SPI_MODE_MASTER)
		static u8 SPI2_SelectSlavePins[SPI2_NUMBER_OF_SLAVES + 1] = {SPI2_NSS_1_PIN};
	#endif
#endif

/******************************************** Configurations for SPI 1 ***************************************/
#ifdef	MSPI_SPI_USED == MSPI_SPI1

/*
 *  To Configure the network to be Full or Half Duplex
 *	 	0: 2-line unidirectional data mode selected
 *		1: 1-line bidirectional data mode selected
 */
#define SPI1_BIDIMODE         0

/*
 *	To configure the node to Recieve or Transmite Only
 *		0: Output disabled (receive-only mode) 
 *		1: Output enabled (transmit-only mode)
 */
#define SPI1_BIDIOE           0

/*
 *  To Enable/Disable the CRC Hardware Calculations
 *  	0: CRC calculation disabled
 *	  	1: CRC calculation enabled 
 */
#define SPI1_CRCEN            0

/*
 *	CRC transfer next
 *		0: Data phase (no CRC phase) 
 *		1: Next transfer is CRC (CRC phase)
*/
#define SPI1_CRCNEXT          0

/*
 *	To Configure the size of Data to be transmit or receive
 *		0: 8-bit data frame format is selected for transmission/reception
 *		1: 16-bit data frame format is selected for transmission/reception
 */
#define SPI1_DATA_FRAME_FORMAT     0

/*
 *	To Configure the output Pin of SPI to be Enable(in case of Transmit and receive)
 *	or to be Disabled (in case of Receive Only), This bit combined with the BIDImode 
 *	bit selects the direction of transfer in 2-line unidirectional mode.
 *		0: Full duplex (Transmit and receive)
 *		1: Output disabled (Receive-only mode) 
 */
#define SPI1_RXONLY           0


/*
 *	To configure the Slave Select Pin to be controlled with the hardware or by using 
 *  software (By Developer).
 * 		0: Software slave management disabled (controlled by Hardware)
 *		1: Software slave management enabled  (controlled by software)
 */
#define SPI1_SSM              0

/*
 *	This bit has an effect only when the SSM bit is set (Controlled by SW), The value 
 *	of this bit is forced onto the NSS pin and the IO value of the NSS pin is ignored.
 */
#define SPI1_SSI              0

/*
 *	To configure Which bit will be send first, the MSb or the LSb
 * 		0: MSB transmitted first
 *		1: LSB transmitted first
 */
#define SPI1_LSBFIRST         0

/*
 *	To Enable/Disable the SPI peripheral.
 *		0: Peripheral disabled
 *		1: Peripheral enabled
 */
#define SPI1_SPE              1

/*
 *	The choose the Baud rate prescalar
 *		000: fPCLK/2
 * 		001: fPCLK/4
 *		010: fPCLK/8
 *		011: fPCLK/16
 *		100: fPCLK/32
 *		101: fPCLK/64
 *		110: fPCLK/128
 *		111: fPCLK/256 
 */
#define BR0_bit     0
#define BR1_bit     0
#define BR2_bit     0

/*
 *	To configure the Node Mode to be Master or Slave Node
 *		0: Slave configuration
 *		1: Master configuration
 */
#define SPI1_MSTR             1

/*
 *	To Configure the Clock Polarity.
 *		0: CK to 0 when idle, So the idle will be low and the leading edge will be at rising edge 
 *  	1: CK to 1 when idle, So the idle will be high and the leading edge will be at falling edge
 */	
#define SPI1_CPOL             0

/*
 *	To configure the Clock Phase.
 *		0: The first clock transition is the first data capture edge. (Write then Read)
 *  	1: The second clock transition is the first data capture edge (Read then Write)
 */
#define SPI1_CPHA             0

/*REG CR2 Configuration*/
/*
 *	To configure the Tx buffer empty interrupt enable.
 *		0: TXE interrupt masked 
 *  	1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
 */
#define SPI1_TXEIE            0

/*
 *	To configure the Rx buffer empty interrupt enable.
 *		0: RXE interrupt masked 
 *  	1: RXE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 */
#define SPI1_RXNEIE           0

/*
 *	To configure the Error interrupt enable.
 *		0: Error interrupt is masked (Disabled)
 *		1: Error interrupt is enabled
 */		
#define SPI1_ERRIE            0

/*
 *	To configure the Select slave output enable
 *		0: SS output is disabled in master mode and the cell can work in multimaster configuration
 *		1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work 
 *		in a multimaster environment.
 */
#define SPI1_SSOE             0

/*
 *	When this bit is set, the DMA request is made whenever the TXE flag is set.
 *		0: Tx buffer DMA disabled
 *		1: Tx buffer DMA enabled
 */
#define SPI1_TXDMAEN          0

/*
 *	When this bit is set, the DMA request is made whenever the RXNE flag is set.
 *		0: Rx buffer DMA disabled
 *		1: Rx buffer DMA enabled
 */
#define SPI1_RXDMAEN          0

#endif
/******************************************** Configurations for SPI 2 ***************************************/
#ifdef	MSPI_SPI_USED == MSPI_SPI2

/*
 *  To Configure the network to be Full or Half Duplex
 *	 	0: 2-line unidirectional data mode selected
 *		1: 1-line bidirectional data mode selected
 */
#define SPI2_BIDIMODE         0

/*
 *	To configure the node to Recieve or Transmite Only
 *		0: Output disabled (receive-only mode) 
 *		1: Output enabled (transmit-only mode)
 */
#define SPI2_BIDIOE           0

/*
 *  To Enable/Disable the CRC Hardware Calculations
 *  	0: CRC calculation disabled
 *	  	1: CRC calculation enabled 
 */
#define SPI2_CRCEN            0

/*
 *	CRC transfer next
 *		0: Data phase (no CRC phase) 
 *		1: Next transfer is CRC (CRC phase)
*/
#define SPI2_CRCNEXT          0

/*
 *	To Configure the size of Data to be transmit or receive
 *		0: 8-bit data frame format is selected for transmission/reception
 *		1: 16-bit data frame format is selected for transmission/reception
 */
#define SPI2_DATA_FRAME_FORMAT     1

/*
 *	To Configure the output Pin of SPI to be Enable(in case of Transmit and receive)
 *	or to be Disabled (in case of Receive Only), This bit combined with the BIDImode 
 *	bit selects the direction of transfer in 2-line unidirectional mode.
 *		0: Full duplex (Transmit and receive)
 *		1: Output disabled (Receive-only mode) 
 */
#define SPI2_RXONLY           0


/*
 *	To configure the Slave Select Pin to be controlled with the hardware or by using 
 *  software (By Developer).
 * 		0: Software slave management disabled (controlled by Hardware)
 *		1: Software slave management enabled  (controlled by software)
 */
#define SPI2_SSM              0

/*
 *	This bit has an effect only when the SSM bit is set (Controlled by SW), The value 
 *	of this bit is forced onto the NSS pin and the IO value of the NSS pin is ignored.
 */
#define SPI2_SSI              0

/*
 *	To configure Which bit will be send first, the MSb or the LSb
 * 		0: MSB transmitted first
 *		1: LSB transmitted first
 */
#define SPI2_LSBFIRST         1

/*
 *	To Enable/Disable the SPI peripheral.
 *		0: Peripheral disabled
 *		1: Peripheral enabled
 */
#define SPI2_SPE              1

/*
 *	The choose the Baud rate prescalar
 *		000: fPCLK/2
 * 		001: fPCLK/4
 *		010: fPCLK/8
 *		011: fPCLK/16
 *		100: fPCLK/32
 *		101: fPCLK/64
 *		110: fPCLK/128
 *		111: fPCLK/256 
 */
#define SPI2_BR               000

/*
 *	To configure the Node Mode to be Master or Slave Node
 *		0: Slave configuration
 *		1: Master configuration
 */
#define SPI2_MSTR             1

/*
 *	To Configure the Clock Polarity.
 *		0: CK to 0 when idle, So the idle will be low and the leading edge will be at rising edge 
 *  	1: CK to 1 when idle, So the idle will be high and the leading edge will be at falling edge
 */	
#define SPI2_CPOL             0

/*
 *	To configure the Clock Phase.
 *		0: The first clock transition is the first data capture edge. (Write then Read)
 *  	1: The second clock transition is the first data capture edge (Read then Write)
 */
#define SPI2_CPHA             1

/*REG CR2 Configuration*/
/*
 *	To configure the Tx buffer empty interrupt enable.
 *		0: TXE interrupt masked 
 *  	1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
 */
#define SPI2_TXEIE            0

/*
 *	To configure the Rx buffer empty interrupt enable.
 *		0: RXE interrupt masked 
 *  	1: RXE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 */
#define SPI2_RXNEIE           0

/*
 *	To configure the Error interrupt enable.
 *		0: Error interrupt is masked (Disabled)
 *		1: Error interrupt is enabled
 */		
#define SPI2_ERRIE            0

/*
 *	To configure the Select slave output enable
 *		0: SS output is disabled in master mode and the cell can work in multimaster configuration
 *		1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work 
 *		in a multimaster environment.
 */
#define SPI2_SSOE             0

/*
 *	When this bit is set, the DMA request is made whenever the TXE flag is set.
 *		0: Tx buffer DMA disabled
 *		1: Tx buffer DMA enabled
 */
#define SPI2_TXDMAEN          0

/*
 *	When this bit is set, the DMA request is made whenever the RXNE flag is set.
 *		0: Rx buffer DMA disabled
 *		1: Rx buffer DMA enabled
 */
#define SPI2_RXDMAEN          0

#endif

/******************************** Configurations for SPI 1 and SPI 2 (ALL USED) **********************/
/************************** SPI 1 **************************/
#ifdef	MSPI_SPI_USED == MSPI_SPI_ALL

/*
 *  To Configure the network to be Full or Half Duplex
 *	 	0: 2-line unidirectional data mode selected
 *		1: 1-line bidirectional data mode selected
 */
#define SPI1_BIDIMODE         0

/*
 *	To configure the node to Recieve or Transmite Only
 *		0: Output disabled (receive-only mode) 
 *		1: Output enabled (transmit-only mode)
 */
#define SPI1_BIDIOE           0

/*
 *  To Enable/Disable the CRC Hardware Calculations
 *  	0: CRC calculation disabled
 *	  	1: CRC calculation enabled 
 */
#define SPI1_CRCEN            0

/*
 *	CRC transfer next
 *		0: Data phase (no CRC phase) 
 *		1: Next transfer is CRC (CRC phase)
*/
#define SPI1_CRCNEXT          0

/*
 *	To Configure the size of Data to be transmit or receive
 *		0: 8-bit data frame format is selected for transmission/reception
 *		1: 16-bit data frame format is selected for transmission/reception
 */
#define SPI1_DATA_FRAME_FORMAT     1

/*
 *	To Configure the output Pin of SPI to be Enable(in case of Transmit and receive)
 *	or to be Disabled (in case of Receive Only), This bit combined with the BIDImode 
 *	bit selects the direction of transfer in 2-line unidirectional mode.
 *		0: Full duplex (Transmit and receive)
 *		1: Output disabled (Receive-only mode) 
 */
#define SPI1_RXONLY           0


/*
 *	To configure the Slave Select Pin to be controlled with the hardware or by using 
 *  software (By Developer).
 * 		0: Software slave management disabled (controlled by Hardware)
 *		1: Software slave management enabled  (controlled by software)
 */
#define SPI1_SSM              0

/*
 *	This bit has an effect only when the SSM bit is set (Controlled by SW), The value 
 *	of this bit is forced onto the NSS pin and the IO value of the NSS pin is ignored.
 */
#define SPI1_SSI              0

/*
 *	To configure Which bit will be send first, the MSb or the LSb
 * 		0: MSB transmitted first
 *		1: LSB transmitted first
 */
#define SPI1_LSBFIRST         1

/*
 *	To Enable/Disable the SPI peripheral.
 *		0: Peripheral disabled
 *		1: Peripheral enabled
 */
#define SPI1_SPE              1

/*
 *	The choose the Baud rate prescalar
 *		000: fPCLK/2
 * 		001: fPCLK/4
 *		010: fPCLK/8
 *		011: fPCLK/16
 *		100: fPCLK/32
 *		101: fPCLK/64
 *		110: fPCLK/128
 *		111: fPCLK/256 
 */
#define SPI1_BR               000

/*
 *	To configure the Node Mode to be Master or Slave Node
 *		0: Slave configuration
 *		1: Master configuration
 */
#define SPI1_MSTR             1

/*
 *	To Configure the Clock Polarity.
 *		0: CK to 0 when idle, So the idle will be low and the leading edge will be at rising edge 
 *  	1: CK to 1 when idle, So the idle will be high and the leading edge will be at falling edge
 */	
#define SPI1_CPOL             0

/*
 *	To configure the Clock Phase.
 *		0: The first clock transition is the first data capture edge. (Write then Read)
 *  	1: The second clock transition is the first data capture edge (Read then Write)
 */
#define SPI1_CPHA             1

/*REG CR2 Configuration*/
/*
 *	To configure the Tx buffer empty interrupt enable.
 *		0: TXE interrupt masked 
 *  	1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
 */
#define SPI1_TXEIE            0

/*
 *	To configure the Rx buffer empty interrupt enable.
 *		0: RXE interrupt masked 
 *  	1: RXE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 */
#define SPI1_RXNEIE           0

/*
 *	To configure the Error interrupt enable.
 *		0: Error interrupt is masked (Disabled)
 *		1: Error interrupt is enabled
 */		
#define SPI1_ERRIE            0

/*
 *	To configure the Select slave output enable
 *		0: SS output is disabled in master mode and the cell can work in multimaster configuration
 *		1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work 
 *		in a multimaster environment.
 */
#define SPI1_SSOE             0

/*
 *	When this bit is set, the DMA request is made whenever the TXE flag is set.
 *		0: Tx buffer DMA disabled
 *		1: Tx buffer DMA enabled
 */
#define SPI1_TXDMAEN          0

/*
 *	When this bit is set, the DMA request is made whenever the RXNE flag is set.
 *		0: Rx buffer DMA disabled
 *		1: Rx buffer DMA enabled
 */
#define SPI1_RXDMAEN          0

/************************** SPI 2 **************************/
/*
 *  To Configure the network to be Full or Half Duplex
 *	 	0: 2-line unidirectional data mode selected
 *		1: 1-line bidirectional data mode selected
 */
#define SPI2_BIDIMODE         0

/*
 *	To configure the node to Recieve or Transmite Only
 *		0: Output disabled (receive-only mode) 
 *		1: Output enabled (transmit-only mode)
 */
#define SPI2_BIDIOE           0

/*
 *  To Enable/Disable the CRC Hardware Calculations
 *  	0: CRC calculation disabled
 *	  	1: CRC calculation enabled 
 */
#define SPI2_CRCEN            0

/*
 *	CRC transfer next
 *		0: Data phase (no CRC phase) 
 *		1: Next transfer is CRC (CRC phase)
*/
#define SPI2_CRCNEXT          0

/*
 *	To Configure the size of Data to be transmit or receive
 *		0: 8-bit data frame format is selected for transmission/reception
 *		1: 16-bit data frame format is selected for transmission/reception
 */
#define SPI2_DATA_FRAME_FORMAT     1

/*
 *	To Configure the output Pin of SPI to be Enable(in case of Transmit and receive)
 *	or to be Disabled (in case of Receive Only), This bit combined with the BIDImode 
 *	bit selects the direction of transfer in 2-line unidirectional mode.
 *		0: Full duplex (Transmit and receive)
 *		1: Output disabled (Receive-only mode) 
 */
#define SPI2_RXONLY           0


/*
 *	To configure the Slave Select Pin to be controlled with the hardware or by using 
 *  software (By Developer).
 * 		0: Software slave management disabled (controlled by Hardware)
 *		1: Software slave management enabled  (controlled by software)
 */
#define SPI2_SSM              0

/*
 *	This bit has an effect only when the SSM bit is set (Controlled by SW), The value 
 *	of this bit is forced onto the NSS pin and the IO value of the NSS pin is ignored.
 */
#define SPI2_SSI              0

/*
 *	To configure Which bit will be send first, the MSb or the LSb
 * 		0: MSB transmitted first
 *		1: LSB transmitted first
 */
#define SPI2_LSBFIRST         1

/*
 *	To Enable/Disable the SPI peripheral.
 *		0: Peripheral disabled
 *		1: Peripheral enabled
 */
#define SPI2_SPE              1

/*
 *	The choose the Baud rate prescalar
 *		000: fPCLK/2
 * 		001: fPCLK/4
 *		010: fPCLK/8
 *		011: fPCLK/16
 *		100: fPCLK/32
 *		101: fPCLK/64
 *		110: fPCLK/128
 *		111: fPCLK/256 
 */
#define SPI2_BR               000

/*
 *	To configure the Node Mode to be Master or Slave Node
 *		0: Slave configuration
 *		1: Master configuration
 */
#define SPI2_MSTR             1

/*
 *	To Configure the Clock Polarity.
 *		0: CK to 0 when idle, So the idle will be low and the leading edge will be at rising edge 
 *  	1: CK to 1 when idle, So the idle will be high and the leading edge will be at falling edge
 */	
#define SPI2_CPOL             0

/*
 *	To configure the Clock Phase.
 *		0: The first clock transition is the first data capture edge. (Write then Read)
 *  	1: The second clock transition is the first data capture edge (Read then Write)
 */
#define SPI2_CPHA             1

/*REG CR2 Configuration*/
/*
 *	To configure the Tx buffer empty interrupt enable.
 *		0: TXE interrupt masked 
 *  	1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
 */
#define SPI2_TXEIE            0

/*
 *	To configure the Rx buffer empty interrupt enable.
 *		0: RXE interrupt masked 
 *  	1: RXE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 */
#define SPI2_RXNEIE           0

/*
 *	To configure the Error interrupt enable.
 *		0: Error interrupt is masked (Disabled)
 *		1: Error interrupt is enabled
 */		
#define SPI2_ERRIE            0

/*
 *	To configure the Select slave output enable
 *		0: SS output is disabled in master mode and the cell can work in multimaster configuration
 *		1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work 
 *		in a multimaster environment.
 */
#define SPI2_SSOE             0

/*
 *	When this bit is set, the DMA request is made whenever the TXE flag is set.
 *		0: Tx buffer DMA disabled
 *		1: Tx buffer DMA enabled
 */
#define SPI2_TXDMAEN          0

/*
 *	When this bit is set, the DMA request is made whenever the RXNE flag is set.
 *		0: Rx buffer DMA disabled
 *		1: Rx buffer DMA enabled
 */
#define SPI2_RXDMAEN          0

#endif

#endif