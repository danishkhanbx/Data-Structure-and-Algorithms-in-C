/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>

int Max();
int Min();
void Display();

struct Array
{
    int A[10];
    int size;
    int length;
};

int main()
{
    struct Array a = { {2,3,9,16,18,21,28,32,35} ,10,9};
    Display(a);
    printf("\nMax: %d",Max(a));            // passing the whole Array a
    printf("\nMin: %d",Min(a));

    return 0;
}

int Max(struct Array arr)
{
    int max = arr.A[0];              // we will declare index 0 element as max, then using loop we will compare 0 index with the rest of it
    for(int i=0; i<arr.length; i++) // if we found an element which is greater than index 0 element we will that in max and continue forward
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
}

void Display(struct Array arr)
{
    printf("Elements: ");
    for(int i=0; i<arr.length; i++)
        printf("%d ",arr.A[i]);
}

