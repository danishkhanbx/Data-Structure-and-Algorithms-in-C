/* Aim : 1,6,9,12,15
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
      int a,b=1,i;

    printf("Enter last number:");
    scanf("%d", &a);

    printf("%d,",b);


    for(i=6;i<=a;i++){
            if(i%3==0){
              printf("%d,",i);
            }

    }
    return 0;
}
