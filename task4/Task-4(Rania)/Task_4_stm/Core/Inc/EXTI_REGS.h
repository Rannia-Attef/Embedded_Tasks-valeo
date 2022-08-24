
/*
 * Author: Rania Atef
 * Date: 29/12/2021
 *
 */



#ifndef INConfig_EXTI_H_
#define INConfig_EXTI_H_

#define GPIO_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

// clock of sys config
# define RCC_APB2ENR 	(GPIO_REG(0x40023800,0x44))

//sys config external interrupt registers
# define SYSCFG_EXTICR1 (GPIO_REG(0x40013800,0x08))
# define SYSCFG_EXTICR2 (GPIO_REG(0x40013800,0x0C))
# define SYSCFG_EXTICR3 (GPIO_REG(0x40013800,0x10))
# define SYSCFG_EXTICR4 (GPIO_REG(0x40013800,0x14))

// EXIT registers
# define EXTI_IMR 	(GPIO_REG(0x40013C00 ,0x00))
# define EXTI_EMR 	(GPIO_REG(0x40013C00 ,0x04))
# define EXTI_RTSR 	(GPIO_REG(0x40013C00 ,0x08))
# define EXTI_FTSR 	(GPIO_REG(0x40013C00 ,0x0C))
# define EXTI_SWIER (GPIO_REG(0x40013C00 ,0x10))
# define EXTI_PR 	(GPIO_REG(0x40013C00 ,0x14))

// NVIS
# define NVIC_ISER0	(GPIO_REG(0xE000E100 ,0x00))
# define NVIC_ISER1	(GPIO_REG(0xE000E100 ,0x04))
# define NVIC_ISER2	(GPIO_REG(0xE000E100 ,0x08))
# define NVIC_ISER3	(GPIO_REG(0xE000E100 ,0x0C))


void EXTI_EnableClock(void);
void EXIT_INIT(char Port, int EXTX, char state);


#define EXTI0 0x00
#define EXTI1 0x01
#define EXTI2 0x02
#define EXTI3 0x03

// to set state options
#define FALLING 0x01
#define RISSING 0x02

#define RISING_MASK(state) ((state>>1) & 1)
#define FALLING_MASK(state)  (state&1)


#endif /* INConfig_EXTI_H_ */
