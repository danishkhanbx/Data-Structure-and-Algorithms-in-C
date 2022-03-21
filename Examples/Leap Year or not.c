
/* Aim :  WAP to check if the year entered is a leap year or not.
   Author : Danish Khan */
#include<stdio.h>
int main(){

   int Year;

   printf(" Enter Year:");
   scanf("%d",&Year);

   if(Year%400 == 0 || (Year%4 == 0 && Year%100!= 0)){
        printf("Its a leap year");
   }else{
        printf("The Year is Not a Leap Year");
   }

   return 0;
}
