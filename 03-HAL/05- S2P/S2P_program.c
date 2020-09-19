#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "S2P_interface.h"
#include "S2P_config.h"
#include "S2P_private.h"


void HS2P_voidSendSynchronous (u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter = 0;
	u8 Local_u8Bit = 0;
	for(Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
	{
		/*Send bit by bit starting from the MSb*/
		Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_s8Counter);
		MGPIO_voidSetPinValue(HS2P_SERIAL_DATA_PIN,Local_u8Bit);
		/*Send Pulse to Shift Clock*/
		MGPIO_voidSetPinValue(HS2P_SHIFT_CLOCK_PIN,HIGH);
		/*Wait for 1 microseconds*/
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HS2P_SHIFT_CLOCK_PIN,LOW);
		/*Wait for 1 microseconds*/
		MSTK_voidSetBusyWait(1);
	}
	/*Send Pulse to Shift Clock*/
	MGPIO_voidSetPinValue(HS2P_STORE_CLOCK_PIN,HIGH);
	/*Wait for 1 microseconds*/
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HS2P_STORE_CLOCK_PIN,LOW);
	/*Wait for 1 microseconds*/
	MSTK_voidSetBusyWait(1);

}
