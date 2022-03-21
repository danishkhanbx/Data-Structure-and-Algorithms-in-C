/* Aim:
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create();
void insert();
int  Delete();
void display();
int  length();

int main()
{
     int A[]={3,4,5};
    create(A,3);
    insert(first,3,70);
    insert(first,4,7);
    insert(first,5,60);
    printf("Element in the list: ");
    display(first);

    printf("\n\nDeleted Element %d\n",Delete(first,4));
    display(first);

    printf("\n\nDeleted Element %d\n",Delete(first,3));
    display(first);

    return 0;
}

void create(int A[], int n)
{
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL; // when only one data is there prev & next will be Null
    last = first;                    // last will be first cause only 1 node is there

    for(int i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node)); // new node t is created
        t->data = A[i];
        t->next = last->next; // in t's next copying previous(last) node next address, now t's next is NULL
        t->prev = last;      // in t's prev adding last nodes address, so now t next points to lasts next node and prev to previous node which is only last node
        last->next = t;     // now last next will point to t
        last = t;          // now last will point on t, as t becomes new last for next node ,and previous 5th now automatically becomes 6th position
    }
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if(index < 0 || index > length(p))
        return;
    if(index == 0)              // inserting before first or at index 0
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;    // new node at index 0 will have prev node as NULL
        t->next = first;  // t is now pointing to first, which is on still previous node at index 0
        first->prev = t; // now changing first prev from NULL to t's address
        first = t;      // now first is pointing on t, as t is the new first
    }
    else
    {
        for(int i=0; i<index-1; i++)  // it will point on one position before inserting index
            p=p->next;               // lest say p's at position 4 and new insertion(t) should took place between 4 and 5
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;              // now t's prev contains p's(4) address
        t->next = p->next;       // t's next is pointing to p's(4) next(5)
        if(p->next)             // checking if p's(4) next(5) is not NULL means another node(5) is present, then only we can make the prev of 5th position point to t
            p->next->prev = t; // means position 5th prev node now contains t's address
        p->next = t;          // now p(4) is pointing to t which is the new 5th position
    }
}

int Delete(struct Node *p, int position)
{
    int x = -1;
    if(position < 1 || position > length(p))
        return -1;

    if(position == 1)
    {
        first = first->next;      // first pointing on position 2 now
        if(first)                // if position second exists
            first->prev = NULL; // first prev should always be NULL
        x = p->data;
        free(p);
    }
    else
    {
        for(int i=0; i<position-1; i++)
            p = p->next;                // lest say p's at position 3 and deletion of t(4) now take place, and position 5th may exists
        p->prev->next = p->next;       // means 3's next should point on 5 or NULL now
        if(p->next)                   // if p's next(4) is not NULL then
            p->next->prev = p->prev; // means position 5th's prev node now point on 3rd node
        x = p->data;
        free(p);                   // now p(4) is not reachable from 3 or 5, therefore deleting p(4). Now 5 will automatically become 4th
    }
    return x;
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int length(struct Node *p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next ;
    }
    return len;
}
