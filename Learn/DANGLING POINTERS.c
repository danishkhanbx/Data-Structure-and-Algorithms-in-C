/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

int sum=34
int *funcDangling(){
    int a,b,sum2;
    a=63;
    b=76;
    sum=a+b;
    return &sum;
}

int main2(){
    // Case 1: Deallocation of a memory block
    int *ptr=(int *)malloc(7* sizeof(int));
    ptr[0]=65;
    ptr[1]=56;
    ptr[2]=64;
    ptr[3]=75;
    free(ptr); // ptr is a new dangling pointer

    // Case 2: Function returning local variable address
    int *dangptr=funcDangling(); // dangptr is now a dangling pointer
    int *danglingptr3;

    // Case 3: If a variable goes out of scope
    {
        int a=12;
        danglingptr3=&a;
    }
    // Here variable a goes out of scope which means danglingptr3 is pointing to a location which is freed and hence danglingptr3 is now dangling point

    return 0;
}


