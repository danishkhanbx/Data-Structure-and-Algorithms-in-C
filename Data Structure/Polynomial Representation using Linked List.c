/* Aim: Representation, Addition(of two), and Evaluation of POLYNOMIALS using Linked List
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void create();
void display();
long Evaluate();

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly=NULL;

int main()
{
    create();
    printf("\n");
    display(poly);  // *p3 points to sum, so in other words if we print *p3 it will print the values in sum

    printf("\n%ld\n",Evaluate(poly,1));

    return 0;
}

void create()
{
    struct Node *t, *last=NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d",&num);

    printf("Enter each term with Coefficient & Exponent\n");
    for(i=0; i<num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff, &t->exp);
        t->next = NULL;
        if(poly==NULL)         // first node
            poly = last = t;
        else
        {
            last->next = t;   // last node will point to t now
            last = t;         // t becomes the new last
        }
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%dx^%d + ",p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Evaluate(struct Node *p, int x)
{
    long val=0;
    while(p)
    {
        val+= p->coeff*pow(x,p->exp);
        p = p->next;
    }
    return val;
}
