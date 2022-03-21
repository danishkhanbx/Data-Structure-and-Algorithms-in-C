/* Aim: Use of NULL pointer
   Author: Danish Khan */
#include<stdio.h>
int main(){
    int a=99;
 // int *ptr=&a;
    int *ptr=NULL;

    if(ptr!= NULL){
        printf("The address of a is: %d\n", *ptr);
    }else{
        printf("The pointer is a null pointer and cannot be dereferenced");
    }

    return 0;
}

