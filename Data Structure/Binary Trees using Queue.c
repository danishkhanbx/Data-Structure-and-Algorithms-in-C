/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void create();
void enqueue();
struct Node *dequeue();
int isEmpty();
void Treecreate();
void Preorder();
void Inorder();
void Postorder();
void Levelorder();

struct Node *root=NULL;

struct Node              // .......(1)
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// creating a queue, whose size we will take from user
struct Queue
{
    int size;
    int front;
    int rear;
    // it means inside an structure there is an dynamic Circular Queue which holds address of the nodes in the tree made of doubly linked list
    struct Node **Q;  // pointer to an *Queue + pointer to an struct Node (from 1)
};

int main()
{
    Treecreate();

    Preorder(root);
    printf("\n");

    Inorder(root);
    printf("\n");

    Postorder(root);
    printf("\n");

    Levelorder(root);
    printf("\n");


    return 0;
}

void create(struct Queue *q, int size) // creating a whole new Queue array
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size*sizeof(struct Node *)); // we are creating a **doubly linked list node, whose address is stored in *Queue
}

// its a circular queue so we are using mod to get back to index 0
void enqueue(struct Queue *q, struct Node *x)
{
    if((q->rear+1)%q->size == q->front) // because its in a q structure we cannot access it directly, it just means rear+1 %size = front
        printf("Queue is Full");       // it will be full when front is at(0 is min or 7 is max) and rear is at(1 or 0) respectively, rear must be on (2 or 1), a gap of 1 empty index will be there
    else
    {
        q->rear = (q->rear+1)%q->size; // now rear will move to +1 location that means it start filling from index 1 leaving index 0 empty i.e. from 3 to 4 or 7 to 0 respectively
        q->Q[q->rear] = x;            // now inserting element at new rear
    }
}

struct Node *dequeue(struct Queue *q) // it will be deleting a whole node in a tree made of linked list whose addresses are stored in a Circular Queue
{
    struct Node *x = NULL;
    if(q->front == q->rear)        // at the start front will always be pointing on an empty box, means rear start filling from index 1, therefore we will do front+1
        printf("Queue is Empty");
    else
    {
        q->front = (q->front+1)%q->size;  // now front will move to +1 location i.e. from 3 to 4 or 7 to 0 respectively
        x = q->Q[q->front];              // now taking the element from where front is pointing
    }
    return x;
};

int isEmpty(struct Queue q)
{
    return q.front==q.rear; // thats how we access non pointer elements from a structure
}

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node)); // creating a root node
    root->data = x;                                   // inserting x in the data section
    root->lchild = root->rchild = NULL;              // storing NULL in prev and next sections of a doubly linked list node
    enqueue(&q,root);                               //storing the address of the root node in Circular Queue

    while(!isEmpty(q))       // until the Circular Queue have space left, we can add n number of right and left child nodes
    {
        p = dequeue(&q);   // removing the front element of CQ which is the address of root and giving it to p, now p's pointing to root node

        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x); // we are using -1 as NULL to declared the end, means there will be no node after present(current node on which we are)
        if(x!=-1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t); // storing the new nodes address for later use
        }

        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q,100);

    printf("%d ",root->data);
    enqueue(&q,root);  // on index 0 we are storing roots address

    while(!isEmpty(q))
    {
        root = dequeue(&q);  // we are on root now, it will send us to its left child first then it right child (Q is empty now)
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild); // on index 1 we are storing roots left child address
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild); // on index 2 we are storing roots right child address
        }
    /* Now two address are there in the Queue on index 1(left child), on 2(right child).
     *We will first dequeue left child and make it as root and print its very own left and right child, then stores there addresses at index 3 and 4.
 i.e. we will say Left child as root, p is now on Left child(now root)-> then repeat the same steps , we will go to Roots(Lchild) left and right node if present we will print it
     *After that index 0 and 1 are empty now we will dequeue index 2 and prints its left and right, then store there address at index 5(R->left) and 6(R->right).
     * This is how the equation will keep going on until it reaches NULL(-1 in this program) and stop storing the addresses of Right and Left childs or when the Queue got full
     */
    }
}
