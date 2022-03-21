/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
int main(){
    /* use of malloc
    int *ptr;
    int n,i;

    printf("Enter the size of the array you want to create\n");
    scanf("%d",&n);

    ptr=(int *)calloc(n, sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter the value no %d of this array\n",i);
        scanf("%d",&ptr[i]);
    }

    for(i=0;i<n;i++){
     printf("Enter the value no %d of this array is %d\n",i,ptr[i]);
    }*/

    //use of calloc
    int *ptr;
    int n,i;

    printf("Enter the size of the array you want to create: ");
    scanf("%d",&n);

    ptr=(int *)calloc(n, sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter the value no. %d of this array: ",i);
        scanf("%d",&ptr[i]);
    }

    for(i=0;i<n;i++){
     printf("Enter the value no %d of this array is: %d\n",i,ptr[i]);
    }

    //use of realloc
    printf("Enter the size of the new array you want to create: ");
    scanf("%d",&n);

    ptr=(int *)realloc(ptr, n*sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter the new value no. %d of this array: ",i);
        scanf("%d",&ptr[i]);
    }

    for(i=0;i<n;i++){
     printf("Enter the value no %d of this array is: %d\n",i,ptr[i]);
    }

    free(ptr);

    return 0;
}


