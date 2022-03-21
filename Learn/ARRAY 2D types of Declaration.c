/* Aim: There are 3 types of 2D-Array Initialization
   Author: Danish Khan */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
// 1: In Stack(Static):
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};

/* 2: In Stack & Heap (Static & Dynamic):
      In stack we create an Array of Size 3(i.e index 0, 1, 2). In Heap we create an Array of Size 4(i.e index 0, 1, 2, 3).
      Each Stack Array Index will hold the address of index 0 of Heap Array( i.e Stack A[0] will point to Heap A[0], using 0 we can access 1,2,3 of Heap Arrays). */
    int *B[3];
    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

/* 3: In Heap(Dynamic);
      In Heap we create an Scalar Array(X) which will hold the address of index 0 of Size 3 Array( which we create in Heap).
      The Size 3 Array will point to Size 4 Array(which we also create in Heap). i.e Size 3 A[0] will point to Size B[0], using 0 we can access 1,2,3 of Size 4 Arrays
      Similar A[1] will point to C[0]->|1|2|3| & A[2] will point to D[0]->|1|2|3|
      |C|---> |C[0]|---> |B[0]|B[1]|B[2]|B[3]|
              |C[1]|---> |E[0]|E[1]|E[2]|E[3]|
              |C[2]|---> |D[0]|D[1]|D[2]|D[3]|
*/
    int **C;                              // C is a pointer which holds the address of C[0] which is also a pointer
    C = (int **)malloc(3*sizeof(int *)); // **C will directly access B[0], *C will directly access C[0]
    C[0]=(int *)malloc(4*sizeof(int));  // C[0] is a pointer which holds the address of B[0]
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

// printing
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }

    return 0;
}
