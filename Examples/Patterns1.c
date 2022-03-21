/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>

int main(){
    int n,i,j;


     scanf("%d",&n);
     for(i=n;i>=1;i--){
         for(j=1;j<=i;j++){
                if(j%2==0){
                printf("#");
                }else{
                printf("*");
                }
         }

        printf("\n");
     }



    return 0;

}

