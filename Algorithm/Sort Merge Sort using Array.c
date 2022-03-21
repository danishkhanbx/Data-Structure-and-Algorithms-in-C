/* Aim: Performing MergeSort in a Single Array
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void IMergeSort();
void RMergeSort();
void Merge();

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10, i;

    RMergeSort(A,n);

    for(i=0; i<10; i++)
        printf("%d ",A[i]);
    printf("\n");

    return 0;
}

void Merge(int A[], int l, int mid, int h)
{
    int i=l, j=mid+1, k=l;  // let A[10]: in A i will be pointing on 0 index & j will be on 6, & k will be pointing on 0 index of B.
    int B[100];            // we need another array to copy the compared elements, after sorting is completed we will cop B into A
                          // We will compare i & j, if j greater we will copy i in k and inc++ i & k to index 1 and same when i is greater we will copy j in k and inc++ j & k
    while(i<=mid && j<=h)// i should be between 0 to mid whereas j(mid+1 to h)
    {
        if(A[i] < A[j])// when j is greater are copying i in k and inc++ i & k's indexes else means i is greater then we copy j in k and inc++ j & k's indexes
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    // when either one of the lists ended we copy the rest of remaining(either 0-mid or mid+1-h) lists in B
    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];

    for(int i=l; i<=h; i++) // after sorting and merging is done in B, we copy B's element in A index by index, so A get sorted too
        A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for(p=2; p<=n; p=p*2) // even: 1 element list is implicitly sorted, now we will start sorting 2 elements lists at a time -> then 4(merging previous 2 & 2) -> 8(previous 4 & 4)
    {
        for(i=0; i+p-1<=n; i=i+p)// when p=2: l=0, h=1 & mid = 1 then we will send this to merge function(it will compare the elements and send the sorted version) then save it in A
        {                       // l=2, h=3 & m=3 then it will sort this list then l=4, h=5 & m=5 and so on like this making lists of 2 elements and sorting them in their new respective index
            l = i;             // when p=4: l=0, h=3 & m=2 sort then l=4, h=7 & m=6 sort then store them at their new indexes
            h = i+p-1;        // when p=8: l=0, h=7 & m=4
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)                    // when odd elements(i.e 9) are their in the array do the 2,4,8,.. thing, after sorting 8 elements, send 0-7 index and 8's index for 2-way merging
        Merge(A,0,p/2-1,n); // 9, 0, 3, 8(the odd one out element to be sorted with the rest of sorted array)
}

void RMergeSort(int A[], int l, int h)
{
    int mid;
    if(l < h)
    {
        mid = (l+h)/2;              // finding the mid of the passed array. The mid will lead to the creation of 2 separate array lists
        RMergeSort(A, l, mid);     // sending the first & second half seprately of the array to get divided again and again till reaches 1 element
        RMergeSort(A, mid+1, h);  // in returning time we will start comparing the elements and sorting them. First 2-2 lists of elements then 4-4 lists of elements
        Merge(A, l, mid, h);     // and so on.. Calling time we divide till 1 Returning time we compare(sort) an merge
    }
}
