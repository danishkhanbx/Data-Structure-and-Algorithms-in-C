/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void Insertion(int A[], int n)
{
    for(int i=0; i<n; i++)       // first time(i=0) while wont run, thats why it will only assign values int the first run
    {
       int j = i-1;            // j will be present one position before i, so that i & j can be compared
       int x = A[i];          // x = i
       while(j>-1 && A[j]>x) // this loop will move the small element forward in the array, it will continue from index 0 till j(index 2's value) is greater than i(index 3)
       {
           A[j+1] = A[j];  // j will be copied in index i(j+1), we already saved index i value in x
           j--;           // now j will move to index 1(example), then we will compare index 1 & 2
       }                 // when the while loop ends means we have an empty index and all the greater elements are already forwarded or no space left(in case of Array),
       A[j+1] = x;      // now j will be copied to this empty index there we will store i(x)
    }
}

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3}, n=10;
    Insertion(A,n);

    for(int i=0; i<10; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

