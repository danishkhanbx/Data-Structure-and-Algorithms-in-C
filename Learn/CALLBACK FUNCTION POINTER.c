/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
int sum(int a, int b){
    return a+b;
}
void greetGMandExecute(int (*fptr)(int,int)){
    printf("Good Morning user\n");
    printf("The sum of 5 and 7 is %d\n",fptr(5,7));

}

void greetHelloandExecute(int (*fptr)(int,int)){
    printf("Hello user\n");
    printf("The sum of 5 and 7 is %d\n",fptr(5,7));
}


int main(){
    int (*ptr)(int,int);
    ptr=&sum;
    greetHelloandExecute(ptr);

    return 0;
}


