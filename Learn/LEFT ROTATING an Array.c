/* Aim : Rotating linear array left by a factor d
   Author : Danish Khan */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,d;

    printf("Enter no. of elements:");
    scanf("%d",&n);

    int arr[n],rev[n];

    for(i=0;i<n;i++)
        {
            printf("Enter no. %d:",i+1);
            scanf("%d",&arr[i]);
        }

    printf("Enter no. of elements to left rotate:");
    scanf("%d",&d);

    for(i=0;i<n;i++)
        {
    /** arr[(0+2)%5] = 2 so that the value at OG arrays index 2
         will be transfered to new array rev[0] index */
            rev[i]=arr[(i+d)%n];
        }

    for(i=0;i<n;i++)
        {
            printf("%d ",rev[i]);
        }

    return 0;
}


