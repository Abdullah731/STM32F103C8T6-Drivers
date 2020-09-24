#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "USART_interface.h"


void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,MRCC_GPIOA);
	MRCC_voidEnableClock(MRCC_APB2,MRCC_USART1);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA,PIN0,OUTPUT_X2MHZ_PP);
	MUSART1_voidInit();

	u8 Received_Data=0;
	u8 x[] = "97";
	while(1)
	{
		MUSART1_voidTransmitData(x);
		MUSART1_u8ReceiveData(&Received_Data);
		if(Received_Data =='5')
		{
			MGPIO_voidSetPinValue(MGPIO_GPIOA,PIN0,HIGH);
		}
		else if(Received_Data == 'R')
		{
			MGPIO_voidSetPinValue(MGPIO_GPIOA,PIN0,LOW);
		}
	}

}
