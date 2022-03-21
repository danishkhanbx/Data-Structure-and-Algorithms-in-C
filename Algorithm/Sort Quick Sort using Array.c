/* Aim: QuickSort with Pivot as a first element
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void QuickSort();
int Partition();
void Swap();

int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3,INT_MAX}, n=11;  // INT-MAX is the infinity element we use to find smaller element from its side
    QuickSort(A, 0, n-1);

    for(int i=0; i<n-1; i++)                           // n-1 is for we don't want to print INT-MAX value
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void QuickSort(int A[], int l, int h) // the Original Array will keep dividing into small-small arrays and the sorted element will stored at index j
{                                    // when calling it will be sorting 1 element in the first call, 2 elements in the second, 4 in the third, 8 in the fourth
    int j;                          // when it reaches NULL, it will start returning and merging arrays from small to Original Array at the end all the elements will be sorted in the OG Array
    if(l<h)
    {
        j = Partition(A, l, h); // after finding the middle element we store that at j index in the OG Array, we get 0-3 index array & 5-8 index array after Partitioning
        QuickSort(A, l, j);    // in the 0-3 & 5-8 array we will again find partition element and divide these arrays further till one element remaining which is implicitly sorted
        QuickSort(A, j+1, h); // when we find sorted element(Partition point) at index j, we store the element of j(lets say index 5) at the index 5 of Original array
    }
}

int Partition(int A[], int l, int h)
{
    int pivot = A[l];   // taking first element as Pivot
    int i = l, j = h;  // i is to find closest greater element then pivot from l, j is to find closest lesser element then pivot from h

    do
    {
        do{ i++;}while( A[i] <= pivot ); // when i is pointing on a element which is greater than pivot we exit, i is still on the exit condition index
        do{ j--;}while( A[j] > pivot ); // when j is pointing on a element which is lesser than pivot we exit, j is still on the exit condition index

        if(i < j)
            Swap(&A[i], &A[j]); // i is pointing on a greater element at the start of array, while j is on lesser element at the ends of array, so we need to swap them
    }while(i < j);             // we will continue till index of i is lesser than j, if j became lesser than we interchange pivot and j index value
    Swap(&A[l], &A[j]);       // the new swapped element in j is sorted, thats why j is the middle element where partition is supposed to happen

    return j;               // we will return the sorted elements index, so that we can divide the array  into small parts and then conquer(sort) them and store them in the OG Array
}

void Swap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}
