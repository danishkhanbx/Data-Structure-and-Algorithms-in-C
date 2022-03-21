/* Aim : 1,4,7,10,13,16,19,...
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a,i;

    printf("Enter last number:");
    scanf("%d", &a);



    for(i=0;i<=a;i++){
            if(i%3==1){
                    printf("%d,",i);

            }

    }

   return 0;
}
