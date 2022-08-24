/*
 * Author: Rania Atef
 * Date: 29/12/2021
 *
 */


#include "EXTI_REGS.h"


unsigned char * EXTI[4]={SYSCFG_EXTICR1,SYSCFG_EXTICR2,SYSCFG_EXTICR3,SYSCFG_EXTICR4};


void EXTI_EnableClock(void)

{
	(*RCC_APB2ENR) |= (0x01 << 14);
}

void EXIT_INIT(char Port, int EXTX, char state)
{
	(*SYSCFG_EXTICR1) |= Port<<(4*EXTX);
	(*EXTI_IMR) |=(1<<EXTX);
	(*EXTI_FTSR) |= ((FALLING_MASK(state)) << EXTX);
	(*NVIC_ISER0)|=1<<(EXTX+6);
}
