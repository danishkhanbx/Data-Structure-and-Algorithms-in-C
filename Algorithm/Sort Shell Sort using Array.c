/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void ShellSort();

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10, i;
    ShellSort(A,n);

    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void ShellSort(int A[], int n)
{
    int gap, i, j, temp;
    for(gap=n/2; gap>=1; gap/=2)  // let n=10 then the gap we go from 5, 2(floor value), 1
    {
        for(i=gap; i<n; i++)// i= index 5, when i=2 -> j=4 then the comparison of index 0,2,4,6,8 will take place @ j=0(j=1 i=1,3,5,7,9), we compare 0,2(0<2) then 2,4(2>4) then swap 2,4 then again compare 0&2(0<2)
        {                  // lets say index 6,8(6>8) are swapped then we will check 4&6 if 4>6 then we swap 4,6 then again we compare 2,4 if(2<4) then we move on to the 4,6 then 6,8 comparison again
            temp = A[i];
            j = i-gap;                // j= index 0
            while(j>=0 && A[j]>temp) // when j(index 0) have greater element then i(index 5) we swap them using temp
            {
                A[j+gap] = A[j];   // j+gap = i <- j
                j = j-gap;        // now j value became -5 it will exit, it wont exit when i=10, j=5 then j becomes index 0 then their will be comparison between index 0 & 5
            }
            A[j + gap] = temp;  // when j exited while loop j was equal to -5, now  j+gap = 0 = j(before while loops j) <- i
        }
    }
}
