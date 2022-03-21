/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>

int add_type4(int a, int b){
     return a+b;
}

int main(){
    int a,b,sum;
    scanf("%d,%d",&a,&b);
    sum=add_type4(a,b);
    printf("sum=%d", sum);

    return 0;
}

