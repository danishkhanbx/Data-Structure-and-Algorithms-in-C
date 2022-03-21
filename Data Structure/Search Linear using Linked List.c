/* Aim: linear searching for an keyword in Linked list
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void create();
void search();
void displayList();

struct node
{
    int data;
    struct node *next;
}*last=NULL;

struct node *head;

int main ()
{
    int choice;
    printf("\n 1.Create\n 2.Search\n 3.Display\n 4.Exit\n");
    do
    {
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                search();
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("\n Thank you!!!\n");
                break;
            default:
                printf("\nPlease enter valid choice\n");
        }

    }while(choice != 4);

    return 0;
}
void create()
{
    int item;

    printf("\n Enter the item: ");
    scanf("%d",&item);
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else if(head==NULL) // first node
    {
        ptr->data = item;
        ptr->next = NULL;
        head=ptr;
        last=ptr;
        printf("...Node inserted\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = NULL;
        last->next=ptr;
        last=ptr;
        printf("...Node inserted\n");
    }
}

void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf(" Enter item which you want to search: ");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf(" Item found at location %d\n",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }

        if(flag==1)     // means we never found the value in while loop
        {
            printf("Item not found\n");
        }
    }
}
void displayList()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf(" %d,", temp->data);
        temp = temp->next;  // Move to next node
    }
    printf("\n");
}

