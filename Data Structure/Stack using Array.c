/* Aim: push, pop, display in stack
   Author: Danish Khan */
#include<stdio.h>
#include<conio.h>
int stack[100], choice, top, size, element, i;
/*
 * stack[] is an linear array to store values
 * choice = declares and execute the options user wants to execute
 * top = is an index that returns the value of highest element in the array if no element is there top is declared to be -1
 * element = the character that user wants to add, remove or view
 */

 void push(void);
 void pop(void);
 void display(void);

int main()
{

    top = -1;

    printf("\n Enter the size of STACK[max=100]: ");
    scanf("%d",&size);

    printf("\n\t STACK OPERATIONS USING ARRAY");
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
                push();
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
                printf("\n\t Enter a valid number(1\2\3\4)");
        }
    }
    while(choice!=4);

    return 0;
}

void push()
{
        if(top==size-1)
        {
            printf("stack is full");
        }
        else
        {
            printf(" Enter the value to be pushed:");
            scanf("%d",&element);
            top++;
            stack[top]=element;
        }
}


void pop()
{
        if(top<=-1)
        {
            printf("stack is empty");
        }
        else
        {
            printf("\n\t Element %d is popped out", stack[top]);
            top--;
        }
}

void display()
{
        if(top>=0)
        {
            printf("\n The elements in the STACK\n");
            for(i=top; i>=0; i--)
                printf("\n%d",stack[i]);

            printf("\n Select Next Choice");
        }
        else
            printf("\n The STACK is empty");
}

