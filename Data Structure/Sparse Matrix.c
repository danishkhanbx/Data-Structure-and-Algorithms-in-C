/* Aim: Sparse Matrix
        A sparse matrix is a matrix that is comprised of mostly zero values.
        Therefore we create a 2D-Array to store only non-zero elements, it saves space and make accessing elements faster.
   Author: Danish Khan
           |s|
            |
            |                             k
structure- ___ Sparse                     | 0   1    2    3    4
     m    |___|                          __________________________
     n    |___|                         i| i0 | i1 | i2 | i3 | i4 |
     num  |___|                         j| j0 | j1 | j2 | j3 | j4 |
     ele  |___|--------------------->A: x| x00| x11| x22| x33| x44|
                                         |________________________|
 m = total number of rows
 n = total number of columns
 num = total number of non-zero elements present in the matrix
*/

#include<stdio.h>
#include<stdlib.h>

void create();
struct Sparse *add();
void display();

struct Sparse
{
    int m;
    int n;
    int num;               // total non-zero elements are there
    struct Element *ele;  // now we enter num numbers of non-zero elements giving its coordinates i,j and value x
};

struct Element
{
    int i;   // row
    int j;  // column
    int x; // data at [i,j]
};

int main()
{
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1,&s2);  // s3 will now point to sum

    printf("\nFirst Matrix\n");
    display(s1);

    printf("\nSecond Matrix\n");
    display(s2);

    printf("\nSum Matrix\n");
    display(*s3); // *s3 points to sum, so in other words if we print *s3 it will print the values in sum

    return 0;
}

void create(struct Sparse *s)             // its a pointer which will point to structure s(view diagram).
{
    printf("\nEnter Dimensions mXn: "); // lets say we enter 4 4
    scanf("%d%d",&s->m,&s->n);         // we pass the address of m and n in structure s
    printf("Number of non-zero: ");   // non-zero elements as 4
    scanf("%d",&s->num);

    s->ele = (struct Element *)malloc(s->num*sizeof(struct Element)); // this will create a Array A(Fig.1), A[ 3 rows, num+1 columns]
    printf("Enter non-zero elements[row column element]:\n");        // and the index 0,1,2,3,4 will hold the coordinates of data i.e. i,j & data itself i.e. x
    for(int i=0; i<s->num; i++)
        scanf("%d%d%d",&s->ele[i].i, &s->ele[i].j, &s->ele[i].x);  // we will enter total of 4 non-zero elements 1-by-1
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;

    if(s1->n != s2->n && s1->m != s2->m) // Matrix addition can only happen when both the Matrices have the same dimensions
        return NULL;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));

    while(i<s1->num && j<s2->num)                // when either one of the structure(s1 or s2) reaches their 2D-Array end, means no addition of same Aij locations is remaining, then we stop the loop
    {
        if(s1->ele[i].i < s2->ele[i].i)        // if s1 have a11 at index 0 & s2 have a21 at index 0 we first add s1's a11 data[i,j,x] in sum index 0 then move s1 to index 1 & sum to index 1
            sum->ele[k++] = s1->ele[i++];
        else if(s1->ele[i].i > s2->ele[j].i) // if s1 have a32 & s22 have a12
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if(s1->ele[i].j < s2->ele[j].j)        // if s1 have a11 at index 0 & s2 have a12 at index 0 we first add s1's a11 data[i,j,x] in sum index 0 then move s1 to index 1 & sum to index 1
                sum->ele[k++] = s1->ele[i++];
            else if(s1->ele[i].j > s2->ele[j].j) // if s1 have a32 & s2 have a31
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];    // when s1 have a41 & s2 have a41
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x; // we add s1 and s2's x values and store it in k then increments s1,s2 and sum
            }
        }
    }
    // when either one of the matrices ended we copy the rest of remaining(either s1 or s2) matrix in sum
    for(; i<s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for(; j<s2->num; j++)
        sum->ele[k++] = s2->ele[j];

    sum->m = s1->m;  // we assign dimensions to sum structure from either one of the structure(s1 or s2)
    sum->n = s1->n;
    sum->num = k;  // sum will have k number of non-zero elements, as k counts the total no. of non-zero elements inserted.

    return sum; // returning sum's address
}

void display(struct Sparse s)
{
    int i,j,k=0;                                    // k points to index 0 of 2D-Array A

    for(i=0; i<s.m; i++)
    {
        for(j=0; j<s.n; j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)  // when Matrix aij = 2D-Array Aij at k=0, it will print x at given i,j of Array A then next comparison will happen at k=1, if not aij++ according to the loop and k remains 0
                printf("%d ",s.ele[k++].x);    // lets say we are at Matrix a00 , then we check Array A index 0(k pointer) if 0,0 is found in i,j of A[0] we print x of 0,0 coordinates & then me move k from 0 index to index 1
            else                              // when a Matrix element[i,j] is found at Array A[i,j] we do not compare that A[index] after that in the entire function
                printf("0 ");
        }
        printf("\n");
    }
}
