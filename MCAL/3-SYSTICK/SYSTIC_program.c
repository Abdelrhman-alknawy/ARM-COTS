#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "stm32f401cc.h"

#include "SYSTIC_interface.h"
#include "SYSTICK_config.h"
#include "SYSTIC_private.h"


static void (*STK_CallBack) (void);
static u8 STK_u8ModeOfInterval;

void STK_voidInit(void)
{
#if STK_CLK_SRC == MSTK_SRC_AHB
	/*Set Clock source AHB , Disable STK , Disable STK Interrupt*/
	SYSTICK ->CTRL = 0x00000004;
#else
	/*Set Clock source AHB/8 , Disable STK , Disable STK Interrupt*/
	SYSTICK -> CTRL = 0;
#endif
}

/***********************************************************************/

/***********************************************************************/
void STK_voidSetBusyWait(u32 Copy_Ticks)
{
	/*Load Ticks To Load Reg*/
	SYSTICK -> LOAD = Copy_Ticks ;

	/*Start Timer*/
	SET_BIT(SYSTICK -> CTRL , 0);

	/*Wait Till Flag is raised*/
	while((GET_BIT(SYSTICK -> CTRL , 16)) == 0 );

	/*Stop Timer*/
	CLR_BIT(SYSTICK -> CTRL , 0);
	SYSTICK -> LOAD = 0;
	SYSTICK -> VAL = 0;
}

/***********************************************************************/

/***********************************************************************/
void STK_voidSetIntervalSingle(u32 Copy_Ticks , void(*Copy_ptr)(void))
{
	/*Disable Timer*/
	CLR_BIT( SYSTICK -> CTRL , 0 );
	SYSTICK -> VAL = 0;

	/*Load Ticks To load Reg*/
	SYSTICK -> LOAD = Copy_Ticks;

	/*Start Timer*/
	SET_BIT(SYSTICK -> CTRL , 0 );

	/*Save callback*/
	STK_CallBack = Copy_ptr;

	/*Set Mode to signal*/
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;

	/*Enable STK interrupt*/
	SET_BIT(SYSTICK -> CTRL , 1);
}

/***********************************************************************/

/***********************************************************************/
void STK_voidSetIntervalPeriodic(u32 Copy_Ticks , void(*Copy_ptr)(void))
{
	/*Load Tick TO Load REG*/
	SYSTICK -> LOAD = Copy_Ticks;

	/*Start Timer*/
	SET_BIT(SYSTICK -> CTRL , 0 );

	/*Save callback*/
	STK_CallBack = Copy_ptr;

	/*Set Mode to signal*/
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;

	/*Enable STK interrupt*/
	SET_BIT(SYSTICK -> CTRL , 1);
}

/***********************************************************************/

/***********************************************************************/
void STK_voidStopInternal(void)
{

}

/***********************************************************************/

/***********************************************************************/
u32 STK_u32GetElaspedTime(void)
{
	u32 Local_Elapsed =0;
	Local_Elapsed = SYSTICK -> LOAD - SYSTICK -> VAL;
	return Local_Elapsed;
}

/***********************************************************************/

/***********************************************************************/
u32 STK_u32GetRemainTime(void)
{
	u32 Local_Remain =0;
	Local_Remain = SYSTICK -> VAL;
	return Local_Remain;
}
