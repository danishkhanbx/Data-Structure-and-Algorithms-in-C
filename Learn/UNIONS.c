/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
union product {
    char name[20];
    int serial_no;
};

int main(){
    union product p1;

   /* p1.serial_no=456;
    printf("%d",p1.serial_no);*/

    strcpy(p1.name, "Apple");
    printf("%s",p1.name);

    return 0;
}

