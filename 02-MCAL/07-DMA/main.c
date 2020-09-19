#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "DMA_interface.h"



void main(void)
{

	u32 Arr1[1000] = {0};
	u32 Arr2[1000];

	u32 Arr3[1000] = {0};
	u32 Arr4[1000];

	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_AHB,MRCC_DMA1);

	MNVIC_voidEnableInterrupt(MNVIC_DMA1_CHANNEL1);

	MDMA_voidChannelInit();
	MDMA_voidChannelStart(Arr1, Arr2, 1000);

	for(u16 i = 0; i<1000; i++)
	{
		Arr4[i] = Arr3[i];
	}

	while(1);
}


void DMA1_Channel1_IRQHandler(void)
{
	/*Clear GIF*/
	DMA -> IFCR = (1 << 0);
	/*Clear TC*/
	DMA -> IFCR = (1 << 1);
}
