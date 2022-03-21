/* Aim: Graph traversal using Depth First Search & Breadth First Search techniques
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
/* Graph:
        1
       / \
      2   3
       \ /
        4
       / \
      5   6           */

void BFS();
void DFS();
void enqueue(int);
int dequeue();

struct Node           // ....Queues code
{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

int main()
{
    // Adjacency Matrix of the Graph
    int G[7][7] = { {0,0,0,0,0,0,0}, // because the edge(node) number is starting from 1 we left index[i,j] 0 as 0
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0} };
    BFS(G,5,7);             // we calls the function sending the Array, Root(start) node, & size of the array
    printf("\n");
    DFS(G,4,7);

    return 0;
}

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0}; // creating an visited array starting index from 0 to 6 index, and marking all the values as 0(not visited)

    printf("%d ",i);    // the root(start) node(edge) will be passed here, then we mark the root as visited
    visited[i]=1;      // In visited array of i index marking the value as 1(visited)
    enqueue(i);       // enqueue the visited root node, because it is yet to be completely explore

    while(front!=NULL)   // until the Queue is completely empty, means no node is remained to be completely explored
    {
        i = dequeue(); // we dequeue the front value and start exploring it....(1)
        for(j=1; j<n; j++)
        {
            if(G[i][j]==1 && visited[j]==0) // G[i][j]==1 means there is an edge&& visited[j]==0 means its not visited yet,
            {                              // we will not visit the node if either one of these is true G[i][j]==0 or visited[j]==1
                printf("%d ",j);
                visited[j] = 1;
                enqueue(j);             // we enqueue the new nodes(can be more than 1) in Queue, then Goto equation (1)
            }
        }
    }
}

void DFS(int G[][7], int start, int n) // we perform DFS using recursion which implicitly calls Stack. Stack will push the nodes then pop it(in LIFO order) to visit it completely.
{
    static int visited[7] = {0};     // static: A static int variable remains in memory while the program is running. Static variables (like global variables) are initialized as 0 if not initialized explicitly.
    int j;

    if(visited[start]==0)
    {
        printf("%d ",start);
        visited[start] = 1;

        for(j=1; j<n; j++)
        {
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n); // it will send a new value(j) instead of start and recursion will perform all the operations again and again until theres no new node to be visited
        }
    }
}


/* QUEUE: Using Queue(LL) for BFS traversal.
          In Queue we enqueue the edge(node) which is to be explored & dequeue the node which is fully explored. */
void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)    // t's touching NULL address in the last node
        printf("\nQueue is Full");
    else         // inserting in the last i.e. after rear, means can only insert at the back
    {
        t->data = x;         // New node will always have NULL address as a pointer
        t->next = NULL;
        if(front == NULL)  // means it is the first node getting inserted
            front = rear = t;
        else
        {
            rear->next = t;  // now the last person(rear) is pointing to t
            rear = t;       // now t becomes the last person, so we move the rear mark on t
        }
    }
}

int dequeue()
{
    int x=-1;
    struct Node *t;
    if(front == NULL)  // if theres a node present, front wont be NULL
        printf("\nQueue is Empty");
    else             // we will take t pointer, and point it on the front, cause only front deletion is possible
    {
        x = front->data;
        t = front;             // now t's on front node
        front = front->next;  // moving front to front-1 node
        free(t);             // now t's disconnected from the queue, now we can deallocate it
    }
    return x;
}
