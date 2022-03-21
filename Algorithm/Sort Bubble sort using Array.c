/* Aim: Sorting Algorithm using Bubble Sort  Author: Danish Khan */
#include <stdio.h>
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
    printf("Enter no. %d: ",i+1);
    scanf("%d", &arr[i]);
    }
}
void sort_array(int arr[],int n){
    int i,j,temp;
     for(i=0;i<n-1;i++){             //Repeating: 1 element sorted at i=0, repeating the sorting for i=1 till n-1 times cause the last element will automatically get sorted
        for(j=0;j<n-i-1;j++){       //Swapping: when 1 element sorted we don't need to compare it again, so we minus by i(no. of elements yet sorted), when 0 nothing sorted yet
            if(arr[j] > arr[j+1]){ // for ascending order index 0 should be less than 1, so if it's greater than we swap
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int n,a[20];
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    scan_array(a,n);
    printf("Original array: ");
    print_array(a,n);
    sort_array(a,n);
    printf("Sorted array: ");
    print_array(a,n);
    return 0;
}
