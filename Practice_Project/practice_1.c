/*
    Param Pathak
    8/27/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int isgoat(int x)
{
    return x + 3;
}



int main(void)
{   
    int x;

    printf("Enter the value for x\n");

    scanf("%d",&x);

    x = isgoat(x);

    printf("%d\n",x);
   

    if (x < 0)
    {
        printf("You are the goat throat");
    }
       
    else
    {
    while(5)
    {
        printf("I am the goat");
        if (x < 1)
        {
            return 5;
        }
    }

    }
   
     return 0; 
   
    }

