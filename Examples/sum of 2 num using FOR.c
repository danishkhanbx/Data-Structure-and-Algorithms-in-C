/* Aim : Sum of all the no. between a to b
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a,b,i,ans=0;

    scanf("%d,%d",&a ,&b);

    for(i=a; i<=b; i++){
        ans = ans + i;

    }

    printf("Answer: %d", ans);

    return 0;
}
