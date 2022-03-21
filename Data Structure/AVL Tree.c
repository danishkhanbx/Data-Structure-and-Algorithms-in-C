/* Aim: AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

struct Node *RInsert();
int NodeHeight();
int BalanceFactor();
struct Node *LLRotation();
struct Node *LRRotation();
struct Node *RRRotation();
struct Node *RLRotation();
void Inorder();

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root=NULL;

int main()
{
    root = RInsert(root,50);
    RInsert(root,10);
    RInsert(root,20);
    Inorder(root);

    return 0;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if(p==NULL)  // when p's pointing to NULL we will keep creating new nodes and inserting data
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 0;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);   // calling itself to create a Left child node
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key); // calling itself to create a Right child node

    p->height = NodeHeight(p);
/* BF = hl - hr : if the value is positive, means its heavy on left, if its negative its heavy on right & 0 means equal(hl = hr)
*/
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) // it means its heavy on left side
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) // it means its heavy on left then right
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1) // it means its heavy on right side
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1) // it means its heavy on right then left
        return RLRotation(p);
    return p; // it will go back to its previous node(root), now roots prev or next will start pointing to the new node(L/R)
}

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : -1; // if p is not NUlL & p's lchild is there then keep counting, until it reaches null
    hr = p && p->rchild ? p->rchild->height : -1; // first it goes from: parent-> L-child(till NULL)-> parent-> R-child(till NULL)

    return hl > hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl-hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root==p)
        root=pl;

    return pl;
}

struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root==p)
        root=pr;

    return pr;
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root==p)
        root = plr;

    return plr;
}

struct Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root==p)
        root = prl;

    return prl;
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

/*
   Insertion:
   We can insert any value which will be sorted and added to its sorted location using Binary Search Tree insert operation
   Then, if the tree get imbalanced by insertion we will use Rotations for balancing the tree, it reduces the height of the tree and makes operations(of DS) easier. */

/**
   Deletion:
   We can delete any key value, if the tree get unbalanced then we perform rotation and balanced it.
   If we remove from the right side the tree got heavy towards left, & if we remove from the left side the tree got heavy towards right.
   When we remove from the right we perform LL or LR rotation, if we remove from the left we perform RR or RL rotation.  */
