/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void Create();
int Max();
int Min();
int RMax();
int RMin();

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

int main()
{
    int A[]={3,5,7,10,25,8,32,2};
    Create(A,8);
    printf("Max %d\n",Max(first));
    printf("Min %d\n",Min(first));
    printf("Max %d\n",RMax(first));
    printf("Min %d\n",RMin(first));
     printf("%d",INT_MAX);

    return 0;
}

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data =  A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Max(struct Node *p)
{
    int max = INT_MIN;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Min(struct Node *p)
{
    int min = INT_MAX;
    while(p)
    {
        if(p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int RMax(struct Node *p)  // this will go till Null then max = INT-MIN value, at the time of returning we will start comparing then
{                        // the first comparison will be last element(p->data) vs. max(MIN-INT value)
    int max = 0;        // if the data is greater, then we will store it in max otherwise we wont change it, then we compare max with second last element
    if(p==0)           // and it goes on till the first element, if every element is less then MIN-INT then it will display -2147483648
        return INT_MIN;
    max = RMax(p->next);
    if(max > p->data)
        return max;
    else
        return p->data;
}

int RMin(struct Node *p) // this will go till Null then min = INT-MAX value, at the time of returning we will start comparing then
{                       // the first comparison will be last element(p->data) vs. min(MAX-INT value)
    int min = 0;       // if the data is lesser, then we will store it in min otherwise we wont change it, then we compare min with second last element
    if(p==0)          // and it goes on till the first element, if every element is greater then MAX-INT then it will display 2147483647
        return INT_MAX;
    min = RMin(p->next);
    if(min < p->data)
        return min;
    else
        return p->data;
}

