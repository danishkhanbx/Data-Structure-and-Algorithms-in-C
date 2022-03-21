/* Aim :  Factorial using Recursion
   Author : Danish Khan */
#include <stdio.h>
int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n,fact;
    printf("Enter a number :");
    scanf("%d",&n);
    fact = factorial(n);
    printf("The Factorial is :%d", fact);



    return 0;
}


