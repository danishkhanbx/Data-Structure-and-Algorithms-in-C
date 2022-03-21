/* Aim : Even & Odd with only if
   Author : Danish Khan */
#include<stdio.h>
int main()
{
    int a;

    printf("Enter a Number:");
    scanf("%d", &a);

    if(a%2 == 0){
            printf("Even");
    }
    if(a%2 != 0){
         printf("Odd");

    }

   return 0;
}
