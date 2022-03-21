/* Aim : WAP to find if the entered number is a prime number or not.
   Author : Danish Khan */
#include <stdio.h>

int main(){
    int a,i;

    scanf("%d", &a);

    for(i=2;i<a;i++){
        if(a%i==0){
            break;
        }
    }

    if(a==i){
            printf("The number is a Prime Number");

    }else{
    printf("The number is not a Prime Number");

    }

    return 0;
}
