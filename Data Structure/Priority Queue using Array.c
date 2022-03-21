/* Aim: Implementing Priority Queue's operations using Arrays & Structures
   Author: Danish Khan */
#include<stdio.h>
#include<conio.h>

void insert();
int getHighestPriority();
void deleteHighestPriority();
void display();

int rear = -1, front = -1;
struct priorityqueue         // using structures can access its element using ' . '(full stop)
{
    int ele;
    int priority;
} pq[5];

int main()
{
    int ch, p, ele;
    printf("***Menu***");
    printf("\n1.Insert\n2.GetHighestPriority\n3.DeleteHighestPriority\n4.Display\n5.Exit");
    do
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);
         switch(ch)
         {
         case 1:
             insert();
             break;
         case 2:
             if(rear==-1)
                printf("Priority Queue is Empty!!!\n");
            else
            {
                p=getHighestPriority();
                printf("\nHighest Priority = %d", p);
            }
            break;
         case 3:
             deleteHighestPriority();
             break;
         case 4:
            display();
            break;
         case 5:
            printf("Thank You!!\n");
            break;
        default:
            printf("Invalid choice");
         }
    }while(ch!=5);
    return 0;
}

void insert()
{
    int p, ele;
    if(rear==4)
        printf("Priority Queue is Full!!!\n");
    else
    {
        printf("Enter element to Insert: ");  // taking the value and priority(descending priority) from the user higher value as high priority
        scanf("%d",&ele);
        printf("Enter Priority: ");
        scanf("%d",&p);
        rear = rear + 1;
        pq[rear].ele = ele;
        pq[rear].priority = p;
    }
}

int getHighestPriority()
{
    int i, p = -1;
     if(rear!=-1)
     {
         for(i=0;i<=rear; i++)
         {
             if(pq[i].priority > p)  // if the value in previous index is lesser than current index, p's value updated its for descending priority queue. For ascending just change the operator to <
                p = pq[i].priority;
         }
     }
     return p;
}

void deleteHighestPriority()
{
    int i, j, p, ele;
    p= getHighestPriority();
   if(rear == -1)
       printf("Priority Queue is Empty!!!\n");
   else
    {
        int c;
        for(i=0; i<=rear; i++)          // searching for at which index highest priority value is
        {
            if(pq[i].priority == p)   // when it matches
            {
                c = i;              // storing index location
                ele = pq[i].ele;   // storing index location value
            }
        }
        for(i=c; i<=rear; i++)  // lets say 3 index is removed and now its empty
        {                      // moving value and priority from index 4 to index 3 and similarly others
             pq[i].ele = pq[i+1].ele;
             pq[i].priority = pq[i+1].priority;
        }
        rear--;            // freeing 1 space
        printf("Element %d is Deleted\n",ele);
    }
}

void display()
{
    if(rear == -1)
        printf("Priority Queue is Empty!!!\n");
    else
    {
        printf("Priority Queue: ");
        for(int i=0; i<=rear; i++)
            printf("ele: %d , priority: %d | ", pq[i].ele, pq[i].priority);
        printf("\n");
    }
}
