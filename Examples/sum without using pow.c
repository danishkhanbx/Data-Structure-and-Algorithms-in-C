/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>
int main(){
   /* int n,i,a,b,sum=0;*/

// from 1,2,3,4,....n
  /*scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum=sum+i;
    }
    printf("%d",sum);*/

// numbers between a to b
  /*scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++){
        sum=sum+i;
    }
    printf("%d",sum);*/

// square sum 1,4,9,25,36,...n
 /* scanf("%d",&n);  //can enter 1,2,3,.. any number it will square then sum up to that number from 1
    for(i=1;i<=n;i++){
        sum=sum+i*i;
    }
    printf("%d",sum);*/

// sum of 1,1/2,1/3,1/4,...,1/n  from 1 to 1/n
    float n,i,sum=0;
    scanf("%f",&n);
    for(i=1;i<=n;i++){
        sum= sum + (1/i);
    }
    printf("%f",sum);



    return 0;
}

