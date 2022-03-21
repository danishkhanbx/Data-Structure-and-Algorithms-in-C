/* Aim : Diamond using patterns
   Author : Danish Khan */
#include <stdio.h>

int main(){

    int i,j,n,k,r=40;
//row=80 max for space width(horizontally)

    scanf("%d", &n);

    for(i=1;i<=n;i++){
        for(j=1;j<=r/2-i;j++){
            //space = total no. rows - row (i.e n-i)
            printf("*");
        }
//if k starts from k=0 use 2k+1 logic, if it starts from k=1 2k-1 use logic(i.e. i&j also starts from 0 or 1 )
        for(k=1;k<=2*i-1;k++){
            //stars = 2*rows-1 or 2*row+1 (2*i-1 or 2*i+1)
            printf(" ");
        }
         printf("\n");
    }

    for(i=n;i>=1;i--){
        for(j=1;j<=r/2-i;j++){
                printf(" ");
        }
        for(k=1;k<=2*i-1;k++){
            printf("*");
        }
         printf("\n");
    }
    return 0;
}

