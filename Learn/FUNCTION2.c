/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>

void add_type2(int a, int b){
     int sum;
     sum=a+b;
     printf("sum=%d", sum);
}

int main(){
    int a,b;
    scanf("%d,%d",&a,&b);
    add_type2(a,b);

    return 0;
}

