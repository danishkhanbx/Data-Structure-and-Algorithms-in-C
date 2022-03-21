/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>

int add_type3(){
     int a,b,sum;
     scanf("%d,%d",&a,&b);
     sum=a+b;
     return sum;
}

int main(){
    int sum;
    sum=add_type3();
    printf("sum=%d", sum);

    return 0;
}

