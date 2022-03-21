/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int i,j,k,n;

     scanf("%d",&n);

     for(i=n-1;i>=0;i--){
         for(j=1;j<=i;j++){
                printf(" ");
         }
         for(k=n-i;k>=1;k--){
                printf("*");
         }
         printf("\n");
     }





    return 0;
    }
