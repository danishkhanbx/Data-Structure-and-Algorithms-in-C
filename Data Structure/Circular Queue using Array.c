/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

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
    int x;
    if((front==0 && rear==SIZE-1) || (rear+1==front)) /// front is at 0 index and rear is at 4th index i.e size-1 || rear is at 3 index & front at 4
        printf("Queue is Full\n");
    else
    {
        printf("Enter element to be inserted: ");
        scanf("%d",&x);
        if(rear==-1)   /// means empty starting at 0 index
            front=0,rear=0;
        else if(rear==SIZE-1) /// at the last index, so resetting it to 0, if its empty is found out at above if condiotion
            rear=0;
        else                // else normal insertion
            rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    int a;
    if(front==-1)  // no element is there, if only 1 element is inserted, front will become 0
        printf("Queue is Empty\n");
    else
    {
        a=queue[front];  // saving front value in a to delete
        if(front==rear)     /// only 1 element is there after deleting it, it should be reset to -1 to declare its Empty
            front=-1, rear=-1;
        else if(front==SIZE-1) /// front is at last index, so it should jump to 0 if element is there which is found out at above if condiotion
            front =0;
        else               // normal deletion
            front++;
        printf("Element %d deleted\n",a);
    }
}

void display()
{
    int i,j;
    if(front==-1 && rear==-1)
        printf("Queue is Empty\n");
    else if(front > rear)   /// let front at index 3 & rear at 2
    {
        for(i=front; i<SIZE; i++)  /// displaying index 3,4
            printf("%d ",queue[i]);
        for(j=0; j<=rear; j++)      /// displaying index 0,1,2
            printf("%d ",queue[j]);
    }
    else                           // normal display from 0 to max index acquired
    {
        for(i=front; i<=rear; i++)
            printf("%d ",queue[i]);
    }
    printf("\n");
}
