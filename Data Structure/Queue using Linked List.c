/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
int dequeue();
void display();

struct Node
{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("Deleted: %d\n",dequeue());
    display();

    return 0;
}

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)    // t's touching NULL address in the last node
        printf("\nQueue is Full");
    else         // inserting in the last i.e. after rear, means can only insert at the back
    {
        t->data = x;         // New node will always have NULL address as a pointer
        t->next = NULL;
        if(front == NULL)  // means it is the first node getting inserted
            front = rear = t;
        else
        {
            rear->next = t;  // now the last person(rear) is pointing to t
            rear = t;       // now t becomes the last person, so we move the rear mark on t
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node *t;
    if(front == NULL)  // if theres a node present, front wont be NULL
        printf("\nQueue is Empty");
    else             // we will take t pointer, and point it on the front, cause only front deletion is possible
    {
        x = front->data;
        t = front;             // now t's on front node
        front = front->next;  // moving front to front-1 node
        free(t);             // now t's disconnected from the queue, now we can deallocate it
    }
    return x;
}

void display()
{
    struct Node *p = front; // from front to rear
    while(p)               // until p's available i.e. is present or not NULL
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

