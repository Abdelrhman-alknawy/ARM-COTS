#include"../../include/LIB/STD_TYPES.h"
#include"../../include/LIB/BIT_MATH.h"
#include"../../include/MCAL/RCC/RCC_Interface.h"

#include"../../include/MCAL/RCC/RCC_Config.h"
#include"../../include/MCAL/RCC/RCC_Private.h"

//Enable system clk
void RCC_voidInitSysClk(void)
{

#if RCCCLKSRC == HSE_CRYSTAL

	SET_BIT(RCC_CR,16);

	CLR_BIT(RCC_CR,18);

	SET_BIT(RCC_CFGR,0);

	CLR_BIT(RCC_CFGR,1);

#elif 	RCCCLKSRC == HSI

	SET_BIT(RCC_CR,0);

	CLR_BIT(RCC_CFGR,0);

	CLR_BIT(RCC_CFGR,1);
#elif 	RCCCLKSRC == HSE_RC

	SET_BIT(RCC_CR,16);

	SET_BIT(RCC_CR,18);

	SET_BIT(RCC_CFGR,0);

	CLR_BIT(RCC_CFGR,1);
#elif RCCCLKSRC==PLL

#error "Invalid RCC CONFIGERED"

#endif
}


/*
 * SWC :RCC_voidEnablePeriheralClk
 *
 *I/P : BUSID : AHB1,AHB2 ,APB1,APB2
 *	  : Copy_u8PeripheralId :0 -31
 * 				*/
void RCC_voidEnablePeriheralClk(u8 Copy_u8BusId,u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId > 31 )
	{
		/*Nothing 	*/
	}
	else
	{
		switch(Copy_u8BusId)
		{
		case AHB1 :
					SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralId);	break;
		case AHB2 :	SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralId);		break;
		case APB1 :	SET_BIT(RCC_APB1ENR,Copy_u8PeripheralId);		break;
		case APB2 :	SET_BIT(RCC_APB2ENR,Copy_u8PeripheralId);		break;
		}
	}
}
/*
 * SWC :RCC_voidDisablePeriheralClk
 *
 *I/P : BUSID : AHB1,AHB2 ,APB1,APB2
 *	  : Copy_u8PeripheralId :0 -31
 * 				*/
void RCC_voidDisablePeriheralClk(u8 Copy_u8BusId,u8 Copy_u8PeripheralId)
{


		if(Copy_u8PeripheralId > 31 )
		{
			/*Nothing 	*/
		}
		else
		{
			switch(Copy_u8BusId)
			{
			case AHB1 :
						CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralId);	break;
			case AHB2 :	CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralId);		break;
			case APB1 :	CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralId);		break;
			case APB2 :	CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralId);		break;
			}
		}
}


