/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void create();
void Insert();
int  Delete();
void Display();
int  Length();

struct Node
{
    int data;
    struct Node* next;
}*Head;

int main()
{
    int A[]={3,4,5};
    create(A,3);
    Insert(Head,3,70);
    Insert(Head,4,7);
    Insert(Head,5,60);
    printf("Element in the list: ");
    Display(Head);

    printf("\n\nDeleted Element %d\n",Delete(Head,4));
    Display(Head);

    printf("\n\nDeleted Element %d\n",Delete(Head,3));
    Display(Head);

    return 0;
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;  // if its the only one, then its pointing to itself
    last = Head;     // last node pointing to head

    for(i=1; i<n; i++)  /// adding at the end (appending)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next; // t(lets say 3) is the new last node, so it should point to first i.e. last next always contain first's address.
        last->next = t;     /// last become second last(lets say 2) and its pointing to 3 now instead of 1.
        last = t;  // now t is named as last
    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > Length(p))
        return ;
    if(index == 0)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        if(Head==NULL)  // if only one node is there i.e. Node = | data | NuLL |
        {
            Head=t;
            Head->next = Head;
        }
        else    // inserting after the last or before the head, it will be the same in circular i.e. before head can also be called as last
        {
            while(p->next!=Head)   // moving at the last node
                p=p->next;
            p->next = t;         // last node now will point to t
            t->next = Head;     // t is now the new head or last node, as it points on the head, and if we declare Head=t it will be 1'st otherwise last
            Head = t;         /// remove it, to declare t as new last
        }
    }
    else
    {
        for(i=0; i<index-1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int position)
{
    struct Node *q;
    int i, x;

    if(position < 0 || position > Length(Head))
        return -1;
    if(position == 1)
    {
        if(Head == p)  // means Head is the only node present
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next; // last will now point to 2nd position
            free(Head);
            Head = p->next;     // now 2nd position will become 1st(head)
        }
    }
    else
    {
        for(i=0; i < position-2; i++) // it will point a position before(3rd) the actual node to be deleted(4th)
            p = p->next;
        q = p->next;         // now q is on the node to be deleted(4th)
        p->next = q->next;  // now p's(3rd) pointing to 5th node
        x = q->data;
        free(q);          // deleting 4th node, so 5th is now the new 4th
    }
    return x;
}

void Display(struct Node *p)
{
   do     // it wont check the conditions first time, but after finishing the whole list when it will came back to head it will stop
   {
       printf("%d ",p->data); // printing the data and moving on
       p=p->next;
   }while(p!=Head);
}

int Length(struct Node *p) // taking first node
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}
