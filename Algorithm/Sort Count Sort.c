/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void CountSort();
int findMax();

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    CountSort(A,n);

    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void CountSort(int A[], int n)
{
    int i, j, max, *C;         // max to find the biggest element in Array A, using C pointer we will create an dynamic array of max+1 size
    max = findMax(A,n);
    C = (int *)malloc(sizeof(int)*(max+1));

    for(i=0; i<max+1; i++) // initializing Array C with value zero's
        C[i] = 0;

    for(i=0; i<n; i++)  // we will inc++ value zero in C at index(A[i]) if the value is present at A[i]
        C[A[i]]++;     // i.e. A[2] = 3 then we will inc++ index 3 at C[3] = 1, if A[4] = 3 then also C[3] = 2

    i=0,j=0;         // now for sorting we will point i on array A's starting index, while j on C's
    while(j<max+1)  // j will go till max
    {
        if(C[j]>0) // C's value greater then 0 means an element of that index exists in A
        {
            A[i++] = j; // we will copy the index number in A[i=0] then inc++ it to i=1 just after coyping
            C[j]--;    // now when the element is transfered no need for C[j] to be greater than 0, so we dec-- its value
        }
        else         // when we get on a index whose C[j=1]=0 we move to the next index i.e. j=2
            j++;
    }
}

int findMax(int A[], int n)// basic Max element finder algorithm in a Array
{
    int max = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}
