#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NO)         REG |= (1 << BIT_NO)
#define CLR_BIT(REG,BIT_NO)         REG &= ~(1 << BIT_NO)
#define GET_BIT(REG,BIT_NO)         REG & (1 << BIT_NO)//0 1
#define TOG_BIT(REG,BIT_NO)         GET_BIT(REG,BIT_NO) == 1? SET_BIT(REG,BIT_NO):CLR_BIT(REG,BIT_NO)
#define SET_PORT(REG)               REG=255
#define CLR_PORT(REG)               REG=0

#endif
