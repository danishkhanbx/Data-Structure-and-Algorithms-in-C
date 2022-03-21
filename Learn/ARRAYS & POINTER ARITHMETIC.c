
/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
int main(){

    int arr[]={1,2,3,4,5,6};
    int *arrayptr= arr;

    printf("Value at position 3 of the array is %d\n", arr[3]);
    printf("The address of the first element of the array is %d\n", &arr[0]);
    printf("The address of the first element of the array is %d\n", arr);
    printf("The address of the second element of the array is %d\n", &arr[1]);
    printf("The address of the second element of the array is %d\n", arr+1);
    printf("The address of the third element of the array is %d\n", &arr[2]);
    printf("The address of the third element of the array is %d\n", arr+2);
    // arr--; wont work but
    //arrayptr++; will work

    printf("The value at address of first element of the array is %d\n", *(&arr[0]));
    printf("The value at address of first element of the array is %d\n", arr[0]);
    printf("The value at address of first element of the array is %d\n", *(arr));
    printf("The value at address of second element of the array is %d\n", *(&arr[1]));
    printf("The value at address of second element of the array is %d\n", arr[1]);
    printf("The value at address of second element of the array is %d\n", *(arr+1));

    return 0;
}

