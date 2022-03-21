/* Aim: Open Hashing is a collision resolving technique. It used Chaining method for resolution. It utilizes more space then given.
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int hash();
void Insert();
void SortedInsert();
void Delete();
void del();
void Display();
struct Node *Search();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *HT[SIZE];

int main()
{
    for(int i=0; i<SIZE; i++) // filling the Tables index values as NULL
        HT[i] = NULL;

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,32);
    Display();

    Delete(HT,12);
    Display();
    Search( HT[hash(22)], 22); // finding out which index contains x value then passing the index to be searched

    return 0;
}

int hash(int key)     // Hashing Function
{
    return key%SIZE;  // Modulus function: mod(key) key % Table SIZE
}

void Insert(struct Node *H[], int key) // passed the Hash Table and the key
{
    int index = hash(key);           // we hash the key using modulus function to find the index and store it
    SortedInsert(&H[index], key);   // sending the index of hash table and the key to be inserted
}

void SortedInsert(struct Node **H,int x) // *H is a pointer to certain index in the Hash Table means it points to the hashed index, **H means the index will point to the new LL node
{
    struct Node *t, *q=NULL, *p=*H; // q is tailing pointer, p will be pointing to index of Hash table, which will point to the LL of this index

    t=(struct Node *)malloc(sizeof(struct Node)); // t's the temporary node creator, then we chain t to the given index and rename that added nodes
    t->data = x;
    t->next = NULL;

    if(*H==NULL) // when theres no Node present the index will be NULL, so we add our first node
        *H=t;   // the given index from Insert() function will point to t, now Hash Tables certain Index points to t
    else
    {
        while(p && p->data < x) /// loop will continue until p<x or p reaches NULL, e.g. Insert 5 in LL = [1,2,3,4,6]
        {
            q = p;             // q is on index 3 value 4
            p = p->next;      // p is on index 4 value 6, now the while loop ends because p is greater than x
        }
        // Now we have reached or insert destination
        if(p==*H)          // if we are inserting at the 1st node and replacing the previous 1st as 2nd
        {
            t->next = *H;// H holds the previous 1st node address, so new 1st will now point to previous 1st which is 2nd node now
            *H = t;     // Hash tables given index will point to new 1st node now
        }
        else          // inserting at the end or any other given in between positions
        {
            t->next = q->next; // t which is the new 4th(value 5) index will point to previous 4th(value 6), value 6 will become 5th index
            q->next = t;      // 3rd index(value 4) will now point on new 4th(value 5) index
        }
    }
}

void Delete(struct Node *H[], int key) // passed the Hash Table and the key
{
    int index = hash(key);           // we hash the key using modulus function to find the index and store it
    del(&H[index], key);   // sending the index of hash table and the key to be inserted
}

void del(struct Node **H,int key)
{
    struct Node *q=NULL, *p=*H;
    int x=-1;
    if(*H==NULL)
        printf("the list is Empty\n");
    else
    {
        while(p && p->data != key)
        {
            q = p;
            p = p->next;
        }
        if(p==*H)
        {
            q=p; // p is on index 0 and q is too
            x=q->data;
            p=p->next; // p is on index 1 now
            *H=p; // H is pointing to p now
            q->next=NULL;
            free(q);
            printf("%d Deleted\n",x);
        }
        else // p is now pointing the index to be deleted, and q is on p's previous index
        {
            q->next=p->next; // q is now pointing to new index which is after p
            x=p->data;
            p->next=NULL;
            free(p);
            printf("%d Deleted\n",x);
        }
    }
}

void Display()
{
    int i;
    for(i=0; i<SIZE; i++)
    {
        struct Node *temp = HT[i]; // temp will point to Hash Tables one index at a time, and print if any LL linked there
        printf("HT[%d]-->",i);
        while(temp!=NULL) // printing LL values until it reaches NULL
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

struct Node *Search(struct Node *p, int key) // simple search operation, we are taking the hashed index address which will point to LL's nodes which should contain the value
{
     do
       {
           if(p!=NULL)
           {
               if(key==p->data)
                   printf("Element %d is at %d Index",p->data,hash(key));
               p=p->next;
           }
           else
              printf("Element Not found");
       }while(p!=NULL);
}
