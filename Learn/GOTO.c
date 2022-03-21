/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
int main(){
    int n,i,j;
    for(i=0;i<9;i++){
         printf("%d\n",i);
        for(j=0;j<9;j++){
            printf("Enter the number. enter 0 to exit:");
            scanf("%d",&n);
            if(n==0){
              goto end;
            }
        }
    }
    end:

    return 0;
}


