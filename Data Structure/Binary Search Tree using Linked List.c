/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void Insert();
void Inorder();
struct Node *Search();
struct Node *RInsert();
int Height();
struct Node *InPre();
struct Node *InSucc();
struct Node *Delete();

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root=NULL;

int main()
{
    struct Node *temp;

    root=RInsert(root,50);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,30);

/*  Insert(50);
    Insert(10);
    Insert(40);
    Insert(20);
    Insert(30); */

    Inorder(root);
    printf("\n");

    Delete(root,30);

    Inorder(root);
    printf("\n");

    temp = Search(20);
    if(temp!=NULL)
        printf("Element %d is found",temp->data);
    else
        printf("Element not found");

    return 0;
}

void Insert(int key)
{
    struct Node *t=root;       // t is for search & if not found insert at that location
    struct Node *r=NULL, *p;  // r is an tail pointer of t, it will be on t's parent

    if(root==NULL) // Inserting 1st node, when nothing was there
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p; // 1st and only node, therefore stating it as root
        return;
    }

    while(t!=NULL) // we can only insert at when t=NUll position
    {
        r=t;                // this means r will keep jumping on the node where t is pointing except the last one, when t became NULL r wont jump

        if(key < t->data) // this else-if is for when the key is found i.e. we cannot insert duplicate in B.S.T., so it will just return(exit from current function)
            t = t->lchild;
        else if(key > t->data)
            t = t->lchild;
        else
            return;
    }

    p = (struct Node *)malloc(sizeof(struct Node)); // when the key's not found we will create a doubly LL node, insert the data & make its prev & next point to NULL
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key < r->data) // Now we are checking that key(p) is less or greater than parent(r), if less then r who is parent( |L|parent(r)|R| ), then Left node will point to p(key)
        r->lchild = p;
    else         // if key(p) is greater then parents(r) Right node will point to p(key)
        r->rchild = p;
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

struct Node *Search(int key)
{
    struct Node *t=root;

    while(t!=NULL)
    {
        if(key==t->data)         // when the root is the key(the data we searching for)
            return t;
        else if(key < t->data) // if key is less than root, then start searching its left side, if left child dosen't matches, then we will start again saying left child as root and performing all the operations from the start
            t = t->lchild;
        else                 // if key is greater than root, then start searching its right side
            t = t->rchild;
    }
    return NULL;
};

struct Node *RInsert(struct Node *p, int key)
{
/* This is how we create a new node, after reaching at specific position(NULL or when value already exist just exit function) using BST rules,
    it will call itself creating a new Node then all the functions will repeat again. It will keep creating and inserting at ruled defined locations. */
    struct Node *t=NULL;

    if(p==NULL)  // when p's pointing to NULL we will keep creating new nodes and inserting data
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);   // calling itself to create a Left child node
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key); // calling itself to create a Right child node

    return p; // it will go back to its previous node(root), now roots prev or next will start pointing to the new node(L/R)
};

int Height(struct Node *p) // lets say we pass Left sub-tree topmost node
{
    int x=0,y=0; // we are starting Height from 0
    if(p==NULL)
        return -1;
    x = Height(p->lchild);  // it will keep calling its left child until it reaches NUll, then starts counting from last till root(parent)
    y = Height(p->rchild); // after its finished calling its left (the last left child whose R & L are NULL returns its value & save it in x)then it goes to the parent then start calling right child(the last right child whose R & L are NULL returns its value & save it in y)
    return x>y?x+1:y+1;   // it will only return the greater value comparing from R-child & L-childs height from the parent node(if parent is the root then the function ends, if not then parent is a R/L of some node, & it will get calculated as a child by aboves method)
}

struct Node *InPre(struct Node *p)  // means which value(should be present in the tree) just came BEFORE the value we are going to delete
{
    while(p && p->lchild != NULL) // right most child of left sub-tree will give In-Order predecessor
        p=p->rchild;
};

struct Node *InSucc(struct Node *p) // means which value(should be present in the tree) just came AFTER the value we are going to delete
{
    while(p && p->rchild != NULL) // left most child of right sub-tree will give In-Order successor
        p = p->lchild;
};

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q; // q is temporary pointer

    if(p==NULL)  // when no node is there
        return NULL;

    if(p->lchild == NULL && p->rchild == NULL) // when only one node(root) is there or its a last node .....(1)
    {
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)         // if the key is less than root, it will keep calling its left childs until it founds the key
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)  // if the key is greater than root, it will keep calling its right childs until it founds the key
        p->rchild = Delete(p->rchild, key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild)) // if the height of left sub-tree is greater then we will delete from left side, else when less or equal than delete from right side
        {
            q = InPre(p->lchild);  // finding the predecessor value and storing it in q
            p->data = q->data;    // replacing the value of node p's data to q's data.....(2)
            p->lchild = Delete(p->lchild, q->data);// It will call itself & keep replacing(2), until it reaches a node whose prev & next is NULL, then it will call eqn(1) & finally delete the last node
        }
        else
        {
            q = InSucc(p->rchild); // finding the sucsessor value and storing it in q
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
};
