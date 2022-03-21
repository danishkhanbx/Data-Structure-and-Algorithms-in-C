/* Aim: Diagonal Matrix
        In a Diagonal Matrix except the diagonal element all the other elements are zero.
        So when we store the matrix(2D Array) it will take space of n*n*size-of-data-type-of-n.
        To save space & to optimized search, we take 1D array and save only diagonal elements and set up a connection formula between 2D & 1D Array.
        Now it will only take n*size-of-data-type-of-n space and search operation will we faster.
   Author: Danish Khan */
#include<stdio.h>

void set();
int get();
void display();

struct Matrix
{
    int A[10]; // Array will store diagonal elements
    int n;    // Dimension
};

int main()
{
    struct Matrix m;
    m.n=4;  // Dimensions n x n = 4 x 4

    set(&m,1,1,5);   // we are passing address of the structure which will further access array, and store value 5 there
    set(&m,2,2,8);  // A[i,j]==2,2 is row(i) & column(j) value respectively, means at A[2,2] we will store value 8
    set(&m,3,3,9);
    set(&m,4,4,12);

    printf("%d \n",get(m,2,2));
    display(m);

    return 0;
}

void set(struct Matrix *m, int i, int j, int x)
{
    if(i==j)            // if i = j means diagonal element then only we save the value x in array A[10]
        m->A[i-1] = x; // means the i passed as parameter is 1, and index in an Array starts from 0, so we store value x at index 0
}

int get(struct Matrix m, int i, int j)
{
    if(i==j)
        return m.A[i-1];
    else
        return 0;
}

void display(struct Matrix m)
{
    int i,j;
    for(i=0; i<m.n; i++)       // from 0 till dimension n(i)
    {
        for(j=0; j<m.n; j++) // from 0 till dimension n(j)
        {
            if(i==j)       // a11, a22, a33, a44 are the diagonal elements
                printf("%d ",m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
