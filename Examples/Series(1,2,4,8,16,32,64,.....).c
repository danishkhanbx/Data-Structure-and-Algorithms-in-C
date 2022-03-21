/* Aim : 1,2,4,8,16,32,64,.....
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    float g,h,i;

    printf("Enter the Number for Exponential Power value:");
    scanf("%f",&g);

    for(i=0;i<=g;i++){
        h=pow(2,i);
        printf("%.2f,",h,i);
    }

   return 0;
}

