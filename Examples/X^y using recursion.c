/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<conio.h>
#include<math.h>
int powers(int x,int y){

    if(y==0){
        return 1;
    }
    return x*powers(x,y-1);
}

void main(){
    int x,y,ans;

    printf("Enter  base value :");
    scanf("%d",&x);
    printf("Enter power value :");
    scanf("%d",&y);
    ans = powers(x,y);
    printf("%d^%d = %d",x,y,ans);

    return 0;
}

