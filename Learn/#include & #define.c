/* Aim: Various use of #define & #include libraries
   Author: Danish Khan */
#include<stdio.h>
#include "#definelibrary.c"
# define PI 3.14
# define SQUARE(r) r*r
int main(){
    float var=PI;
    int r=4;
    int *ptr=funcDangling();
    printf("The value of PI is %f\n",var);
    printf("The area of this circle is %f\n",PI*SQUARE(r));

    return 0;
}


