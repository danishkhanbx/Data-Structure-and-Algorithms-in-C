/* Aim: We cannot resize array, but we can create a Big sized array & copy the small array elements to the big one
   Author: Danish Khan */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;
    int i;

    p=(int *)malloc(5*sizeof(int));
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    q=(int *)malloc(10*sizeof(int));
    for(i=0;i<5;i++)
        q[i]=p[i]; // copying p(small array) to q(big)

    free(p);     // deleting the array which used to point on
    p=q;        // p will now point on new big array
    q=NULL;    // q will stop pointing to the big array

    for(i=0;i<5;i++)
        printf("%d \n",p[i]);
    return 0;
}
