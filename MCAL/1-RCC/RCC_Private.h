/*******************************************************************************************************/
/* Author            : Abdelrhman elknawy                                                              */
/* Version           : V0.0.0                                                                          */
/* Data              : 10 May 2023                                                                     */
/* Description       : MRCC_Privite.h --> implementations                                              */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	YES                                                                */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	NO                                                                 */
/*                                                                                                     */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                    Macros Base Address Of RCC Registers                             */
/*******************************************************************************************************/


#define MRCC_BASE_ADDRESS     0x40023800

/*******************************************************************************************************/
/*                                    Macros Of RCC Register Map                                       */
/*******************************************************************************************************/
/*AHB1 BUS 	*/

#define RCC_CR                      (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x00)))// Control REGISTER
#define RCC_PLLCFGR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x04)))
#define RCC_CFGR                    (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x08)))
#define RCC_CIR                     (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x0C)))
#define RCC_AHB1RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x10)))
#define RCC_AHB2RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x14)))
#define RCC_APB1RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x20)))
#define RCC_APB2RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x24)))
#define RCC_AHB1ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x30))) // AHB1 ENABLE REGISTER
#define RCC_AHB2ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x34)))
#define RCC_APB1ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x40)))
#define RCC_APB2ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x44)))
#define RCC_AHB1LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x50)))
#define RCC_AHB2LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x54)))
#define RCC_APB1LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x60)))
#define RCC_APB2LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x64)))
#define RCC_BDCR                    (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x70)))
#define RCC_CSR                     (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x74)))
#define RCC_SSCGR                   (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x80)))
#define RCC_PLLI2SCFGR              (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x84)))
#define RCC_DCKCFGR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x8c)))



#define 	HSI			0
#define  	HSE_RC		1
#define		HSE_CRYSTAL	2
#define     PLL         3