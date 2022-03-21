/* Aim: linear searching for an keyword in an array
   Author: Danish Khan */
#include<stdio.h>
int main()
{
    int size, find, key=0, i;
    /*size is used for declaring the size of array
     * find = enter the number to be found
     * key is for declaring that number is founded by the loop */

    printf("Enter the size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter the elements one by one: \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter element to be found: ");
    scanf("%d",&find);

   ///  Linear search begins
    for(i=0;i<size;i++)
    {
        if(arr[i] == find)
            {
                key=1;
                break;
            }
    }

    if(key == 1)
    {
       printf("Element %d is present in the array at position %d",find,i+1);
    }
    else
        printf("Element not present in the array");
    return 0;
}
