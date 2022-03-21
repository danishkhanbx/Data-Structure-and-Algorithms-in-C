/* Aim: push, pop, display in stack
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

int choice;
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int);
void pop();
void display();

int main()
{
    int element;
    printf("\n\t STACK OPERATIONS USING LINKED LIST");
    printf("\n\t ----------------------------");
    printf("\n\t 1.PUSH");
    printf("\n\t 2.POP");
    printf("\n\t 3.DISPLAY");
    printf("\n\t 4.EXIT");

    do
    {
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf(" Enter the value to be pushed:");
                scanf("%d",&element);
                push(element);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\n\t EXIT");
                break;

            default:
                printf("\n Enter a valid number(1\2\3\4)");
        }
    }
    while(choice!=4);

    return 0;
}

void push(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        printf(" Stack is Full\n");
    else
    {
        t->data  = x;
        t->next = top ;
        top = t;
    }
}

void pop()
{
    struct Node *t;
    int x=-1;

    if(top==NULL)
        printf(" Stack is Empty\n");
    else{
        t=top;
        top = top->next;
        x = t->data;
        printf(" Element %d is popped out\n", x);
        free(t);
    }
}

void display()
{
    struct Node *p;
    p=top;
    if(top==NULL)
        printf(" Stack is Empty\n");
    else
    {
        while(p!=NULL)
        {
        printf(" %d",p->data);
        p = p->next;
        }
        printf("\n");
    }
}
