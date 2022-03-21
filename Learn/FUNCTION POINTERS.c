/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
int sum(int a, int b){
    return a+b;
}

int main(){
    int (*fptr) (int,int); //Declaring a function pointer
    fptr=&sum; // creating a function pointer
    int d=(*fptr)(4,6); // Dereferencing a function pointer
    printf("the value of d is %d\n",d);

    return 0;
}

