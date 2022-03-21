/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void SelectionSort();
void Swap();

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3}, n=10;
    SelectionSort(A,n);

    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void SelectionSort(int A[], int n)
{
    int i, j, k;                  // i will point on first index of unsorted array, j is for comparison, & k will point on the least value in the unsorted array
    for(i=0; i<n-1; i++)         // we don't need to sort the last element it will be sorted when iteration is on i=n-2
    {
        for(j=k=i; j<n; j++)   // j & k will start from i, means when one element is sorted it will be stored at 0th index and no sorting will be performed on it
        {                     // when i=1 means 0th index is a sorted value and we should not disturb it, so j & k also start from index 1(unsorted Array)
            if(A[j] < A[k])  // j will start moving from i, while k will only move when the index value where j is pointing is lesser than where k is poining
                k = j;      // when k's value is bigger, it will send j to find any lesser value then current element to point on, when j finds it k starts pointing on it now
        }
        Swap(&A[i],&A[k]);// now i(index 1) should be swapped by lesser value of k, the lesser value will go on index 1 and versa,
    }                    // now index(0,1) is an sorted array and from their all the elements are unsorted, now i will point on index 2 and repeat all the operations then swap

}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
