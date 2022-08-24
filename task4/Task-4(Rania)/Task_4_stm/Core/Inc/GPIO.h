/*
 * Author :Rania
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H

#include "stm32f401xc.h"

// ############## MEMORY MAP ################
#define GPIO_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

// CLOCK REGISTER
#define RCC_AHB1ENR 		(GPIO_REG(0x40023800,0x30))

// PORT A REGISTERS
#define GPIOA_MODER 	(GPIO_REG(0x40020000,0x00))
#define GPIOA_OTYPER 	(GPIO_REG(0x40020000,0x04))
#define GPIOA_OSPEEDR 	(GPIO_REG(0x40020000,0x08))
#define GPIOA_PUPDR 	(GPIO_REG(0x40020000,0x0C))
#define GPIOA_IDR 		(GPIO_REG(0x40020000,0x10))
#define GPIOA_ODR 		(GPIO_REG(0x40020000,0x14))
#define GPIOA_BSRR 		(GPIO_REG(0x40020000,0x18))
#define GPIOA_LCKR 		(GPIO_REG(0x40020000,0x1C))
#define GPIOA_AFRL 		(GPIO_REG(0x40020000,0x20))
#define GPIOA_AFRH 		(GPIO_REG(0x40020000,0x24))

// PORT B REGISTERS
#define GPIOB_MODER 	(GPIO_REG(0x40020400,0x00))
#define GPIOB_OTYPER 	(GPIO_REG(0x40020400,0x04))
#define GPIOB_OSPEEDR 	(GPIO_REG(0x40020400,0x08))
#define GPIOB_PUPDR 	(GPIO_REG(0x40020400,0x0C))
#define GPIOB_IDR 		(GPIO_REG(0x40020400,0x10))
#define GPIOB_ODR 		(GPIO_REG(0x40020400,0x14))
#define GPIOB_BSRR 		(GPIO_REG(0x40020400,0x18))
#define GPIOB_LCKR 		(GPIO_REG(0x40020400,0x1C))
#define GPIOB_AFRL 		(GPIO_REG(0x40020400,0x20))
#define GPIOB_AFRH 		(GPIO_REG(0x40020400,0x24))

// Mask
#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

// Functions
void GPIO_EnableClock(unsigned int PortID);
void GPIO_Init(unsigned int PortID, unsigned char PinNum, unsigned char PinDir,unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned int PortID, unsigned char PinNum,
                            unsigned char Data);
unsigned char GPIO_ReadPin(unsigned int PortID, unsigned char PinNum);

#endif /* GPIO_H */
