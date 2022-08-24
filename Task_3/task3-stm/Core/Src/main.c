#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {

	GPIO_Init('B', 3, INPUT, PULL_UP);
	GPIO_Init('B', 5, OUTPUT, PUSH_PULL);
	GPIO_Init('B', 6, OUTPUT, PUSH_PULL);
	GPIO_Init('B', 7, OUTPUT, PUSH_PULL);

    int i=0;
    int color_mix=0;
    while(1)
    {


    	if (GPIO_ReadPin('B', 3) == NOK)
    	{


    		for (i = 0; i <= 10000; i++)
    		{

    		}
    		if (GPIO_ReadPin('B', 3) == OK)
    		{
    			color_mix +=1;
    			switch(color_mix)
    			{
    			case 1:
    			{
    				GPIO_WritePin('B', 5, 0);
    				GPIO_WritePin('B', 6, 0);
    				GPIO_WritePin('B', 7, 0);
    				break;
    			}
    			case 2:
    			{
    				GPIO_WritePin('B', 5, 1);
    			    GPIO_WritePin('B', 6, 0);
    			    GPIO_WritePin('B', 7, 0);
    			    break;

    			 }
    			case 3:
    			{
    				GPIO_WritePin('B', 5, 0);
    				GPIO_WritePin('B', 6, 1);
    				GPIO_WritePin('B', 7, 0);
    				break;

    			}
    			case 4:
    			{
    				GPIO_WritePin('B', 5, 1);
    				GPIO_WritePin('B', 6, 1);
    				GPIO_WritePin('B', 7, 0);
    				break;
    			}
    			case 5:
    			{
    				GPIO_WritePin('B', 5, 0);
    				GPIO_WritePin('B', 6, 0);
    				GPIO_WritePin('B', 7, 1);
    				break;
    			}
    			case 6:
    			{
    				GPIO_WritePin('B', 5, 1);
    				GPIO_WritePin('B', 6, 0);
    				GPIO_WritePin('B', 7, 1);
    				break;
    			}
    			case 7:
    			{
    				GPIO_WritePin('B', 5, 0);
    				GPIO_WritePin('B', 6, 1);
    				GPIO_WritePin('B', 7, 1);
    				break;
    			}
    			default:
    			{
    				GPIO_WritePin('B', 5, 1);
    				GPIO_WritePin('B', 6, 1);
    				GPIO_WritePin('B', 7, 1);
    				color_mix=0;
    			}


    			}


    		}

    	}

    }



  return 0;
}
