/* Aim: void pointer helps type casting can turn one pointer into multiple data types
   Author: Danish Khan */
#include<stdio.h>
int main(){
    int a=477;
    float b=7.66;
    void *ptr;

    ptr=&a;
    printf("The value of a is: %d\n", *((int *)ptr));
    ptr=&b;
    printf("The value of b is: %f\n", *((float *)ptr));

    return 0;
}


