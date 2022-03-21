/* Aim :Armstrong number or not
   Author : Danish Khan */
#include <stdio.h>

int main(){
    int n,r,i,sum=0;
    printf("Enter n value:");
    scanf("%d",&n);

    i=n;
    do{
    r=i%10;
    sum=sum+r*r*r;
    i=i/10;
    }while(i>0);

    if(n==sum){
        printf("The number is a Armstrong number");
    }else{
         printf("The number is NOT an Armstrong number");
    }

    return 0;
}

