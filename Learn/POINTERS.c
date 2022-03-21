/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
int main(){
    int a=78;
    int *ptra=&a;
    int *ptr2=NULL;

    printf("The address of pointer to a is %p\n",&ptra); // & = address of p
    printf("The address of a is %p\n",&a);
    printf("The address of pointer to a is %p\n",ptr2);
    printf("The address of a is %p\n",ptra); // ptra = address of a
    printf("The value of a is %d\n",*ptra); // *ptra = value of a
    printf("The value of a is %d\n", a);
    return 0;
}

