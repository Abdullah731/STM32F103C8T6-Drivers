/************************************************************************************************************
 * Title		:	NVIC_private																			*
 * File name	: 	NVIC_private.h																			*
 * Author 		: 	Abdullah Mustafa																		*
 * Date			: 	23 AUG, 2020																			*
 * Version		: 	V2.0.0																					*
 * Description	:																							*
 * Compiler		:	Eclipse IDE																				*
 * Target		:	STM32F103 Microcontroller																*
 * Notes		:	None																					*
 *																											*
 ***********************************************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
/* 0xE000E100 : base Address of NVIC */

/* NVIC_ISER0 used to enable external peripheral interrupts from external interrupts 0 to external interrupts 31, has offset 0x00 */
#define NVIC_ISER0				*((volatile u32 *)(0xE000E100))
/* NVIC_ISER1 used to enable external peripheral interrupts from external interrupts 32 to external interrupts 59, has offset 0x04 */
#define NVIC_ISER1				*((volatile u32 *)(0xE000E104))
/* NVIC_ICER0 used to disable external peripheral interrupts from external interrupts 0 to external interrupts 31, has offset 0x80 */
#define NVIC_ICER0				*((volatile u32 *)(0xE000E180))
/* NVIC_ICER1 used to disable external peripheral interrupts from external interrupts 32 to external interrupts 59, has offset 0x84 */
#define NVIC_ICER1				*((volatile u32 *)(0xE000E184))
/* NVIC_ISPR0 used to Set Pending Flag for external interrupts from 0 to 31, has offset 0x100 */
#define NVIC_ISPR0				*((volatile u32 *)(0xE000E200))
/* NVIC_ISPR1 used to Set Pending Flag for external interrupts from 32 to 59, has offset 0x104 */
#define NVIC_ISPR1				*((volatile u32 *)(0xE000E204))
/* NVIC_ICPR0 used to Clear Pending Flag for external interrupts from 0 to 31, has offset 0x180 */
#define NVIC_ICPR0				*((volatile u32 *)(0xE000E280))
/* NVIC_ICPR1 used to Clear Pending Flag for external interrupts from 32 to 59, has offset 0x184 */
#define NVIC_ICPR1				*((volatile u32 *)(0xE000E284))
/* NVIC_IABR0 used to return the status of the interrupt active flag (Read only register) for external interrupts from 0 to 31, has offset 0x200 */
#define NVIC_IABR0				*((volatile volatile u32 *)(0xE000E300))
/* NVIC_IABR1 used to return the status of the interrupt active flag (Read only register) for external interrupts from 32 to 59, has offset 0x204 */
#define NVIC_IABR1				*((volatile volatile u32 *)(0xE000E304))
/* NVIC_IPRx Registers is used to define the priority of the External interrupts */
#define NVIC_IPR				((volatile u8 *)(0xE000E400))
/* Define The number of groups and sub */
#define MNVIC_GROUP_4_SUB_0		(0x05FA0300)
#define MNVIC_GROUP_2_SUB_2		(0x05FA0400)
#define MNVIC_GROUP_1_SUB_3		(0x05FA0500)
#define MNVIC_GROUP_0_SUB_4		(0x05FA0600)
#define MNVIC_GROUP_3_SUB_1		(0x05FA0700)




#endif
