/* Aim: Use of sizeof() variable, data type, expression, pointers and limit library
   Author: Danish Khan */
#include<stdio.h>
#include<limits.h>
int main(){
    // sizeof()
    char c;
    short s;

    printf("Size of char: %d byte(s)\n",sizeof(c));
    printf("Size of short:%d byte(s)\n",sizeof(s));
    printf("Size of float:%d bytes\n\n",sizeof(float));


    // limits.h library
    printf("Signed short min value:  %d\n",SHRT_MIN);
    printf("Signed short max value:   %d\n",SHRT_MAX);
    printf("Unsigned short max value: %u\n",SHRT_MAX);

    return 0;
}

