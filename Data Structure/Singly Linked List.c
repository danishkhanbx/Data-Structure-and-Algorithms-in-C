/* Aim: Basic operations of Singly Linked List
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void create();
void Insert();
int  Delete();
void Display();
int  count();

struct Node       // it will be renewed i.e. Node(data+next) for every new linked list is created using malloc
{
    int data;             // to store data of every element
    struct Node *next;   // to store next(address of next node)
}*first=NULL;          /// creating first(only store next) which will store first nodes address and point to it

int main()
{
    int A[]={3,4,5};
    create(A,3);
    Insert(first,3,70);
    Insert(first,4,7);
    Insert(first,5,60);
    printf("Element in the list: ");
    Display(first);

    printf("\n\nDeleted Element %d\n",Delete(first,4));
    Display(first);

    printf("\n\nDeleted Element %d\n",Delete(first,3));
    Display(first);


    return 0;
}

void create(int A[], int n)
{
    struct Node *t, *last;                             // last(data + previous next or NULL)
    first=(struct Node*)malloc(sizeof(struct Node));  // created a new struct node(data+next) and allocated it memory and storing its address in first which was EMPTY
    first->data=A[0];
    first->next=NULL;
    last=first;  // since, there is only one node now first & last is pointing to the same location

    for(int i=1; i<n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t; // previous node's next which was null i.e.last is storing new node t's address
        last=t;      // now last pointing to t(data + NULL)
    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
/** can only insert between index 0 and last i.e. if count is 8 can insert between 0-8 index for only Insert function Empty cases,
       if there is an list using create function just increase its spaces and add whichever index u want      */
    if(index < 0 || index > count(p))
        return;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0) // at the start case
    {
        t->next=first; // storing first address in t's link
        first=t;      // first pointer is like a arrow on previous 1st node(holds address of first node) now changed addressed to t's
    }
    else
    {
        for(int i=0; i<index-1; i++) // to go on 3 index & 4 location it will only take 3 steps required(count using fingers) cause the first dose not move
            p=p->next;    // now on 3rd index which holds node(data + 0x)
        t->next=p->next; // now giving t's next 0x address
        p->next=t;      // and replacing 0x with Tx which is the address of new node added
    }
}

int Delete(struct Node *p,int position)  // taking address of first pointer & and the position which needed to be deleted
{
    struct Node *q=NULL;  /// q is tailing pointer
    int x=-1, i;

    if(position  < 1 || position  > count(p))
        return -1;

    if(position == 1)  // here we taking position since it starts with 1 to n number
    {
        q=first;              // pointing q to first location
        x=first->data;       // storing 1st location data in x
        first=first->next;  // moving first to new first, since position 1st is going to be deleted and position 2nd will become 1st
        free(q);           // deallocating q's dynamic memory
        return x;
    }
    else
    {
        for(i=0; i<position -1; i++)  // lets say position 4th index 3
        {
            q=p;                 // q will go till position 3th index 2
            p=p->next;          // p will be on position 4th index 3
        }
        q->next=p->next;   // q will be storing and pointing to position 5th index 4 address now, not to position 4th index 3
        x=p->data;
        free(p);         // freeing position 4 index 3, now position 5th will become 4th & index 4 will become 3
        return x;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
/** now p is pointing to next node, lets say p's pointing address(currently on) is 0x whose next link is 1x,
      so now p is taking 1x as pointing address i.e p's pointing address updated. Now p is on 1x whose link address is 2x  */
        p=p->next;
    }
}

int count(struct Node *p) // counting number of nodes present in the list
{
    int c=0;  // counter
    while(p) // while p is true i.e. not NULL
    {
        c++;
        p=p->next;
    }
    return c;
}
