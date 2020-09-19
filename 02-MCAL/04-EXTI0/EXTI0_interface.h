/************************************************************************************************************
 * Title		:	EXTI_interface																			*
 * File name	: 	EXTI_interface.h																		*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	26 AUG, 2020 - 30 AUG, 2020																*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/
/************************************************************************************************************
 *	API Description
			MEXTI_voidInitiate
					<function>		used to initiate An external interrupt with the Trigger Mode
									( Rising - Falling - On change) 
									return				void
									parameters			void
									Local variables		NONE
			
			MEXTI_voidEnableEXTI
					<function>		used to enable the interrupt for an external line only
									return				void
									parameters			Copy_u8LineNum
									Local variables		NONE
			
			MEXTI_voidDisableEXTI
					<function>		used to disable the interrupt for an external line only
									return				void
									parameters			Copy_u8LineNum
									Local variables		NONE
			
			MEXTI_voidSwTriggerEXTI
					<function>		used to rise up the pending flag and fire an interrupt using software
									return				void
									parameters			Copy_u8LineNum
									Local variables		NONE
			
			MEXTI_voidSetSignalLatch
					<function>		used to set the Mode of an enabled external interrupt (must be enabled first)
									options for mode: (RISING_EDGE - FALLING_EDGE - ON_CHANGE)
									return				void
									parameters			Copy_u8LineNum		Copy_u8Mode
									Local variables		NONE
									
									
***********************************************************************************************************/

#ifndef EXTI0_INTERFACE_H
#define EXTI0_INTERFACE_H

/*A function to initiate the EXTI, it works on the line number and the mode */
void MEXTI_voidInit(void);
/*A function to enable the EXTI, it takes the line number*/
void MEXTI_voidEnableEXTI(u8 Copy_u8LineNum);
/*A function to disable the EXTI, it takes the line number*/
void MEXTI_voidDisableEXTI(u8 Copy_u8LineNum);
/*A function to set the MODE of the line number */
void MEXTI_voidSwTriggerEXTI(u8 Copy_u8LineNum);
/*A function to configure the line number and the mode at the same time */
void MEXTI_voidSetSignalLatch(u8 Copy_u8LineNum, u8 Copy_u8Mode);
/*ِA function to set the callback function to be executed if the interrupt is fired*/
void MEXTI_voidSetCallBack(void (* Copy_EXTI0Ptr) (void));



#define	LINE0			(0)
#define	LINE1			(1)
#define	LINE2			(2)
#define	LINE3			(3)
#define	LINE4			(4)
#define	LINE5			(5)
#define	LINE6			(6)
#define	LINE7			(7)
#define	LINE8			(8)
#define	LINE9			(9)
#define	LINE10			(10)
#define	LINE11			(11)
#define	LINE12			(12)
#define	LINE13			(13)
#define	LINE14			(14)
#define	LINE15			(15)



#define RISING_EDGE			(0)
#define FALLING_EDGE		(1)
#define ON_CHANGE			(2)

#endif
