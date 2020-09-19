/************************************************************************************************************
 * Title		:	IR_program																				*
 * File name	: 	IR_program.c																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	1 SEP, 2020																				*
 * Version		: 	V1.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

void voidGetFrame(void)
{
	asm("NOP");
}


void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, GPIOA);

	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_X2MHZ_PP); // RED
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_X2MHZ_PP); // GREEN
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_X2MHZ_PP); // BLUE
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInitiate();
	/*Enable EXTI0 From NVIC*/
	MNVIC_viodInit();
	MNVIC_voidEnableInterrupt(EXTI0);
	/*Initialize the STK and enable it on AHB/8*/
	MSTK_voidInit();

	while(1)
	{

	}






}