/* Aim : 4,5,16,25,64,125,.....
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a=4,b=5,c,d,u,i;

    printf("Enter the last power:");
    scanf("%d",&u);

    printf("%d,%d,",a,b);

    for(i=2;i<=u;i++){
            c=pow(a,i);
            d=pow(b,i);

            printf("%d,%d,",c,d,i);
         }



            return 0;
}
