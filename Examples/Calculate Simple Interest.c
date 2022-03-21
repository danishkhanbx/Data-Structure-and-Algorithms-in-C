/* Aim: WAP to calculate the simple interest taking principal,rate of interest and no. of years as inputs from user. */
#include<stdio.h>
int main()
{
   int principal_amount,time_in_years;
   float rate_of_interest,simple_interest;
   printf(" *** Simple Interest Calculator ***\n\n ");
   printf("Enter the Principal :");
   scanf("%d",&principal_amount);
   printf("Enter the Rate of Interest:");
   scanf("%f",&rate_of_interest);
   printf("Enter the Period:");
   scanf("%d",&time_in_years);
   simple_interest=(principal_amount*rate_of_interest*time_in_years)/100;
   printf("Calculated Simple Interest: %.2f", simple_interest);
   return 0;
}
