/* Aim : sum of even and odd
   Author : Danish Khan */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a,b,i,ans=0;

    scanf("%d,%d",&a,&b);

    for(i=a;i<=b;i++){
        if(i%2!=0){
            continue;
       }

        ans = ans + i;
    }

    printf("Answer: %d", ans);




    return 0;
}
