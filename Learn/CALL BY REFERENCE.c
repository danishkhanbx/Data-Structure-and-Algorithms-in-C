/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
void changevalue(int* address){
   *address=78639;
}
int main(){
    int a=9;
    printf("The value of a now is %d\n",a);
    changevalue(&a);
    printf("The value of a now is %d",a);
    return 0;
}


