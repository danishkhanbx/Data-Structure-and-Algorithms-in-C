/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<conio.h>
#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0, i;
void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    printf("\t\t***MENU***");
    printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank You!!");
                break;
            default:
                printf("Invalid choice");
        }
    }while(choice!=4);
    return 0;
}

void enqueue()
{
    int ele;
    if(rear==SIZE)
        printf("Overflow");
    else
    {
        printf("Enter element to be Inserted: ");
        scanf("%d",&ele);
        queue[rear] = ele;
        rear++;
    }
}

void dequeue()
{
    if(front == rear)
        printf("\nUnderflow");
    else
    {
        printf("Element %d deleted\n",queue[front]);
        for(i=0; i<rear-1; i++)
            queue[i] = queue[i+1];
        rear--;
    }
}

void display()
{
    if(front == rear)
        printf("Underflow");
    else
    {
        for(i=front;i<rear;i++)
            printf("%d ",queue[i]);
    }
}
