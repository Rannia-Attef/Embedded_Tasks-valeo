#include <stdio.h>

int main()
{

    int i;
    int num;
    float exponant_x = 1 ;
    float new_term =1 ;
    float z;

    printf("Please enter the exponent(x) ");
    scanf("%f",&z);
    printf("Please enter the number of terms ");
    scanf("%d",&num);

    for(i= 1; i<num ;i++)
    {
        new_term =new_term * (z/i);
        exponant_x= exponant_x + new_term;
    }

    printf("the result equals %f",exponant_x);
    return 0;
}
