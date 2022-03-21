
/* Aim : WAP to calculate the sum and average of three numbers entered by the user. */
#include<stdio.h>
int main()
{
    int a,b,c,sum;
    float average;

    printf("*** Sum and Average Calculator\n\n ***");

    printf("Enter the Three Numbers seperated by comma :");
    scanf("%d,%d,%d", &a,&b,&c);

    sum = a + b + c;
    printf("The Sum is: %d\n", sum);

    average =(float)sum/3;
    printf("The average is: %.1f", average);

    return 0;
}
