/* Aim : WAP to print Fibonacci Series till number entered by the user is reached.
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a=0,b=1,c,d,i;

    printf("Enter the last value upto calculate the series:");
    scanf("%d",&d);

    printf("%d,%d,",a,b);


     for(i=0;i<=d;i++){
            a=a+b;
            b=b+a;
            c=a+b;
            printf("%d,%d,",a,b,c,i);

     }

    return 0;
}

