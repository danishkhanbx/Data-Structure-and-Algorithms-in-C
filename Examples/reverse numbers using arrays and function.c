/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
    printf("%d,", arr[i]);
    }
    printf("\n");
}

void scan_array(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
    printf("Enter no. %d:",i+1);
    scanf("%d", &arr[i]);
    }

}

int main(){
    int n,i, num[100], rev[100];

    printf("Enter no. of elements:");
    scanf("%d", &n);

    scan_array(num,n);


    printf("\nOriginal Array:");
    print_array(num,n);

    for(i=0;i<n;i++){
        rev[i]=num[n-i-1];
    }
    printf("\nReverse Array :");
    print_array(rev,n);

    return 0;
}

