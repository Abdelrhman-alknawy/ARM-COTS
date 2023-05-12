#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

//#include "../../LIB/STD_TYPES.h"


#define AHB1    0
#define AHB2    1
#define APB1    2
#define APB2    3

void RCC_voidInitSysClk(void); //Enable system clk


/*
 * SWC :RCC_voidEnablePeriheralClk
 *
 *I/P : BUSID : AHB1,AHB2 ,APB1,APB2
 *	  : Copy_u8PeripheralId :0 -31
 * 				*/
void RCC_voidEnablePeriheralClk(u8 Copy_u8BusId,u8 Copy_u8PeripheralId);
/*
 * SWC :RCC_voidDisablePeriheralClk
 *
 *I/P : BUSID : AHB1,AHB2 ,APB1,APB2
 *	  : Copy_u8PeripheralId :0 -31
 * 				*/
void RCC_voidDisablePeriheralClk(u8 Copy_u8BusId,u8 Copy_u8PeripheralId);



#endif
