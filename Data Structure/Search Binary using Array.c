/* Aim: For Binary Search array must be in sorted(ascending) order
   Author: Danish Khan */
#include<stdio.h>

int BinarySearch();
int RBinarySearch();
void Display();

struct Array
{
    int A[10];
    int size;
    int length;
};

int main()
{
    struct Array arr={{2,3,9,16,18,21,28,32,35},10,9};
    printf("16 is at Index %d\n",BinarySearch(arr,16));
//  printf("16 is at Index %d\n",RBinarySearch(arr.A,0,arr.length,16));
    Display(arr);

    return 0;
}

int BinarySearch(struct Array arr, int key) // passing the whole array structure which automatically consist the values
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)                      // it will continue from l<h til l=h, when l>h means value is not present.
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])       // we keep dividing the present index in 2 and searching only the middle of the indexes
            return mid;
        else if(key<arr.A[mid]) // we move h from length-1(higher) to mid-1(lower) index, because the value is small then mid
            h=mid-1;
        else                  // we move l from 0(lower) to mid+1(higher) index, because the value is bigger then mid
            l=mid+1;
    }
    return -1;
}

int RBinarySearch(int a[],int l, int h, int key) // passing only array and values seprately
{
    int mid=0;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else
            return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}

void Display(struct Array arr)
{
    printf("\nElements are:\n");
    for(int i=0; i<arr.length; i++)
        printf("%d ",arr.A[i]);   // arr is contains A[], size, length values, we only need to print A[]
}

/** If the programmer is giving the input in code itself, its mandatory to align the values in sorted format.
    If we are taking Array values from user. User should input it in sorted ascending order.
    If the user is unable to input in sorted order, we take the input apply BUBBLE Sort Algorithm and save it in the same array.
    Then Perform Binary Search */
