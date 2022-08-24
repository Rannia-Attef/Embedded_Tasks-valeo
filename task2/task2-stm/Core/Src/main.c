#include "stm32f401cc_interface.h"

int main(void) {
	RCC_AHB1ENR |=(1<<1);

	GPIOB_MODER |=(0x01<<10);
	GPIOB_MODER |=(0x01<<12);
	GPIOB_MODER |=(0x01<<14);

	GPIOB_PUPDR|=(0x01<<6);

int j;
int count=0;
while (1) {
     if((GPIOB_IDR & (1<<3))==0x08)
     {
    	 for(j=0;j<=1500;j++)
    	 {

    	 }
    	 if((GPIOB_IDR &(1<<3))==0x00)
    	 {
    		 count +=1;
    		 switch(count)
    		 {
    		 case 1:
    		 {
    			 GPIOB_ODR =0;
    			 break;

    		 }
    		 case 2:
    		 {
    			 GPIOB_ODR =0;
    			 GPIOB_ODR |=(1<<5);
    			 break;
    		 }
    		 case 3:
    		 {
    			 GPIOB_ODR =0;
    			 GPIOB_ODR |=(1<<6);
    			 break;
    		 }
    		 case 4:
    		 {
    			 GPIOB_ODR =0;
    			 GPIOB_ODR |=(1<<7);

    			 break;
    		 }
    		 case 5:
    		 {
    			 GPIOB_ODR =0;
    			 GPIOB_ODR |=((1<<5)|(1<<6));

    			 break;
    		 }
    		 case 6:
    		 {
    			 GPIOB_ODR=0;
    			 GPIOB_ODR |=((1<<5)|(1<<7));
    			 break;
    		 }
    		 case 7:
    		 {
    			 GPIOB_ODR =0;

    			 GPIOB_ODR |=((1<<6)|(1<<7));
    			 break;
    		 }
    		 default:
    		 {
    			 GPIOB_ODR =0;
    			 GPIOB_ODR |=((1<<5)|(1<<6)|(1<<7));
    			 count =0;

    		 }
    		 }
    	 }
     }
  }
  return 0;

}










