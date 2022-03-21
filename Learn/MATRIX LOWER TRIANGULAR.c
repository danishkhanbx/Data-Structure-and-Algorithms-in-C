/* Aim: Lower Triangular Matrix
        We will use formulas to find how many zero elements, non-zero elements should be there in the LTM, and in the matrix where it should print 0 & non-zero elements
         Zero elements = n*(n-1) / 2
         Non-zero elements = n*(n+1) / 2
        Connection formula between 1D array where we store non-zero elements and 2D Array of Matrix:
         Row Major: Index(A[i][j]) = [ i*(i-1)/2 ] + j-1
         Column Major: Index(A[i][j]) = [ n*(j-1) - (j-2)*(j-1)/2 ] + i-j
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void set();
int get();
void display();

struct Matrix
{
    int *A;
    int n;
};

int main()
{
    struct Matrix m;
    int i,j,x;

    printf("Enter Dimensions: ");
    scanf("%d",&m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));
    printf("Enter all Elements");
    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            scanf("%d",&x); // we take the elements as 2D array and store it in 1D array
            set(&m,i,j,x);
        }
    }
    printf("\n\n");
    display(m);
    printf("\n %d \n",get(m,4,2));

    return 0;
}

void set(struct Matrix *m, int i, int j, int x)
{
    if(i>=j)
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;   // this Column major formula will find the index in array A where we will store value x
}

int get(struct Matrix m, int i, int j)
{
    if(i>=j)
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
    else
        return 0;
}

void display(struct Matrix m)
{
    int i,j;
    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            if(i>=j)         // Lets say in a 4X4 LTM A[i][j] = a11, a21, a22, a31, a32, a33, a41, a42, a43, a44 are the non-zero elements
                printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
            else           // A[i][j] = a12, a13, a14, a23, a24, a34 are the zero elements
                printf("0 ");
        }
        printf("\n");
    }
}
