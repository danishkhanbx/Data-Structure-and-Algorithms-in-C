#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n,int k) {
  int i,j,m1=0,m2=0,m3=0,a=i&j,b=i|j,c=i^j;

  for(i=1;i<=n;i++){
      for(j=i+1;j<=n;j++){
          if(i&j<k && i&j>m1)
              m1=a;

          if(i|j<k && i|j>m2)
              m2=b;

          if(i^j<k && i^j>m3)
              m3=c;
            }
            printf("%d\n",m1);
            printf("%d\n",m2);
            printf("%d",m3);
     }

}


int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    calculate_the_maximum(n,k);





    return 0;
}

