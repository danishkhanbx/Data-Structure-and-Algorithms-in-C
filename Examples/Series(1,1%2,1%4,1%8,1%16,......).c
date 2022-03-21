/* Aim : 1,1/2,1/4,1/8,1/16,...
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int g,h,i;

    printf("Enter the Number for Exponential Power value:");
    scanf("%d",&g);

    for(i=0;i<=g;i++){
            h=pow(2,i);
            printf("1/%d,",h,i);
    }
  return 0;
}

