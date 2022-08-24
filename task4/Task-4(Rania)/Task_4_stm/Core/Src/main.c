/*
 * Author: Rania Atef
 * Date: 29/12/2021
 *
 */


#include "GPIO.h"
#include "EXTI_REGS.h"




void SevenSeg_configuration(void);
void PushButtons_configuration(void);
void Counter_fun(void);
void Increment_ISR(void);
void Decrement_ISR(void);


unsigned char count = 0;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(void) {
	// ........>        set configurations

	EXTI_EnableClock();
	EXIT_INIT(1, 0, FALLING);   //set pin0 on port B  (increment button)
	EXIT_INIT(1, 1, FALLING);   //set pin1 on port B (decrement button)
	SevenSeg_configuration();
	PushButtons_configuration();

  while(1)
  {
	  Counter_fun();
  }
  return 0;
}

void SevenSeg_configuration(void)
{
	GPIO_EnableClock(0);
	for (unsigned char i = 0; i < 7; i++)
	{

		GPIO_Init(0, i, OUTPUT, PUSH_PULL);
	}
}

void PushButtons_configuration(void)
{
	GPIO_EnableClock(1);
	GPIO_Init(1, 0, INPUT, PULL_UP);
	GPIO_Init(1, 1, INPUT, PULL_UP);
}

void Counter_fun(void)
{
	for (unsigned char i = 0; i < 7; i++)
	{
		GPIO_WritePin(0, i, (sevenSegHex[count] & (1 << i)) >> i);
	}
}

void Increment_ISR(void)
{

	(*EXTI_PR) |= (0x01 << 0x00);  //clear pending flag (button_inc)
	if (count <9)
	{
		count=count+1;
	}

}

void Decrement_ISR(void)
{


	(*EXTI_PR) |= (0x01 << 0x01);     //clear pending flag (button_dec)
	if (count >0)
	{
		count=count-1;

	}



 }





