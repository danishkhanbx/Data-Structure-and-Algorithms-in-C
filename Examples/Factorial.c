/* Aim : factorial of an number
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a,i,ans=1;

    scanf("%d",&a );

    for(i=a;i>0;i--){
        ans = ans*i;

    }

    printf("Answer: %d", ans);

    return 0;
}

