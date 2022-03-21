/* Aim : Tricks
   Author : Danish Khan */
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
  float a=1234.123;
//  a=12345678912345.1234; or a=123456789.123; or a=12345678.123; or a=1234567.123; all of them with different outputs
// format to 2 decimal places, but the whole string occupies 10 characters. If there's not enough numbers, then spaces are used to left of the numbers.
// OUTPUT:___1234.13 (i.e 10 spaces assigned with 2 decimal place starting from left including dot. & decimal places)
    printf("\n%10.2f\n",a);


/// can add whatever between \"____\" or \'____\'
    printf("\"Danish Khan\"");
    printf("\n");
    printf("\'&(D@nish Khan)\'");

    return 0;
}

