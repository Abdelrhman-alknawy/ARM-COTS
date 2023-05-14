/********************************************************************************/
/* 					Author :	Ahmed Elsherbiny                                */
/********************************************************************************/
#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H

#include "STD_TYPES.h"


void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_Ticks);
void STK_voidSetIntervalSingle(u32 Copy_Ticks , void(*Copy_ptr)(void));
void STK_voidSetIntervalPeriodic(u32 Copy_Ticks , void(*Copy_ptr)(void));
void STK_voidStopInternal(void);
u32 STK_u32GetElaspedTime(void);
u32 STK_u32GetRemainTime(void);


#define MSTK_SRC_AHB			1
#define MSTK_SRC_AHB_PRES8		0

#define STK_CLK_SRC				MSTK_SRC_AHB

#define STK_SINGLE_INTERVAL		0
#define STK_PERIOD_INTERVAL		1


#endif


