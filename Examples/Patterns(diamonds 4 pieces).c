/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>

int main (){
    int i,j,k,n;

    scanf("%d", &n);

/* *
   **
   ***
   ****
   *****  */
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

 /* *****
    ****
    ***
    **
    *  */
    /*for(i=n;i>0;i--){
        for(j=i;j>0;j--){
            printf("*");
        }
        printf("\n");
    }

/*     *
      **
     ***
    ****
   *****  */

    /*for(i=1;i<=n;i++){
        for(j=i;j<n;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("*");
        }
        printf("\n");
    }*/

/* *****
    ****
     ***
      **
       *  */
      /*for(i=n;i>=1;i--){
        for(j=i;j<n;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("*");
        }
        printf("\n");
    }*/
   return 0;
}





