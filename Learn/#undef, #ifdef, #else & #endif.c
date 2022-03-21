/* Aim: C preprocessors
   Author: Danish Khan */
#include <stdio.h>
#define pi 3.14159
int main()
{
 #undef pi
 #ifdef pi
 printf("The value of pi is:%f\n",pi);
 #else
 printf("I don't no value of pi\n");
 #endif
 printf("Sorry\n");
 return 0;
}

