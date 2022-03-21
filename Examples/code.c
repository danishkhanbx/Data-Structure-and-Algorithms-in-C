/* Aim: Creating Queue using array
   Author: Danish Khan */
#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0; // starting at index 0 for both of em
void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    printf("\t***MENU***");
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
                printf("Thank You!!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=4);
    return 0;
}

void enqueue()
{
    int ele;
    if(rear == SIZE) // when 5 = 5
        printf("Queue is Full");
    else
    {
        printf("Enter element to be Inserted: ");
        scanf("%d",&ele);
        queue[rear] = ele;
        printf("Element %d inserted\n",queue[rear]);
        rear++; // on to index 1

    }
}

void dequeue()
{
    if(front == rear) /// when 0 = 0
        printf("Queue is Empty\n");
    else
    {
        printf("Element %d deleted\n",queue[front]); // starting element deleted
        for(int i =0; i<rear-1; i++) // index 0 to 4
            queue[i] = queue[i+1]; /// after index 0 value is deleted, shifting index 1 to 0, similarly 2 to 1
        rear--; // last index get freed
    }
}

void display()
{
    if(front == rear)
        printf("Queue is Empty\n");
    else
    {
        for(int i=front; i<rear; i++) // from index 0 to less than rear(max 4)
            printf("%d ",queue[i]);
    }
}
