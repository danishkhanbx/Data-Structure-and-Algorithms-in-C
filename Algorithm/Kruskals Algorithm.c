/** Kruskal's Algorithm:-
      Kruskal's algorithm finds a minimum spanning forest of an undirected edge-weighted graph. If the graph is connected, it finds a minimum spanning tree.
      It is a greedy algorithm in graph theory as in each step it adds the next lowest-weight edge that will not form a cycle to the minimum spanning forest.
      The steps for implementing Kruskal's algorithm are as follows:
      1. Sort all the edges from low weight to high
      2. Take the edge with the lowest weight and add it to the spanning tree. If adding the edge created a cycle, then reject this edge.
      3. Keep adding edges until we reach all vertexes.
    Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
#define I 65535

int find();
void join();

int edge[9][3]  = { {1,2,28}, {1,6,10}, {2,3,16},      // {1,2,28}: { edge 1: edge[][0], edge 2: edge[][1], vertex cost: edge[][2] }
                    {2,7,14}, {3,4,12}, {4,5,22},     // columns are fixed with 0,1,2 while rows are from 0 to 8
                    {4,7,18}, {5,6,25}, {5,7,24} };  // from this we will find minimum cost then perform conditional operations on it then add it in the spanning tree

/* Set is to find whose parent is who, if the value in the index is negative then the index number vertex is it owns parent, if it is some positive number
   then that index number vertex is its parent. We initialize set with everyone been their own parent. It is also used for detecting a cycle
   lets say if two index have same value we should not join them because it will make a cycle. When it is not making a cycle we will use Union function lets say 1,6 vertex &
   make the lesser(child 1) value vertex point to higher(parent 6), then we include both the vertex in t[0][0]=1 & t[1][0]=6 and mark the children value index in included as 1.
   Now in set at index 6 add -1(6's index value) + -1(1's index value) = -2 means 6 is parent of itself, at index 1 change value from -1 to 6 means 1 is children of 6.
   Then find the next min cost vertexes then perform all the operations again. */
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

/* Included array is to mark that we have previous selected that edge or not, when we take first time {1,2,28} either we add it in the spanning tree or not,
   we will mark 1 at index 0 of included array and in future operations we will not even look at it.*/
int included[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

/* Minimum Cost Spanning Trees 2D array: We will be storing tree in 2 rows & 6 columns array.We will select minimum cost edge and store that edge value in it,
   then using that initial edge we will find the next connected and min cost edge then store it in the array, then using the available edges we will find another connected edge,
   it will keep going until we have selected |E|-1 = 6 edges such as the edges docent make a cycle.  */
int t[2][7];

int main()
{
    int u=0, v=0, i, j, k=0, min=65535, n=9; // i is to point on spanning tree t[][], n = no. of vertexes, e = no. of edges, u & v = to access cost matrix
    i=0;
    while(i<6)                             // we will only need 6 vertexes(0 to 5)
    {
        min=65535;
        for(j=0; j<n; j++)
        {
            if(included[j]==0 && edge[j][2]<min) // loop will only run when index j of included array has value 0 & j,column(2) = vertex cost should be less then stored min
            {
                u = edge[j][0];       // storing the j, column 1 & 2 which will give the edge of min vertex cost
                v = edge[j][1];
                min = edge[j][2];   // storing j, column 2 which points to the vertex cost of the column 1 & 2 edges in min
                k = j;             // storing the unique row value in k, at the end of this loop when we have founded the least available value at row j,
            }                     // we need to mark 1 in included array at index j, so in future we don't check this row for finding min cost cause we already had
        }

        if(find(u) != find(v)) // we are finding parent of edge u & v, when their parent are same we don't use join function cause it will create a cycle
        {
            t[0][i] = u;     // storing the edges in the spanning tree & then joining them and marking them 1 included for no further involvement
            t[1][i] = v;    // i=0, storing these edges at t[0][0] & t[0][1]
            join(find(u), find(v));
            included[k] = 1;
            i++;        // now we will store at index t[0][1] & t[1][1]
        }
        else         // when their parent are same, we will mark it 1 in included array for no further involvement
            included[k] = 1;
    }

    printf("Spanning Tree\n");
    for(i=0; i<6; i++)              // printing the spanning tree with 2 rows(0,1) & 6 columns(0 to 5)
        printf("%d %d\n",t[0][i],t[1][i]);

    return 0;
}

int find(int u)            // to find the parent of any edge, we goto the edge number index in set, the value thats stored in the index is its parent
{                         // let set(index, value): (1, 6) -> (6, 7)-> (7, -3), u=1
    int x=u, v=0;

    while(set[x] > 0)  // set[1] = 6 i.e. it is not the parent -> then we will do set[6] = 7 -> then set[7] = -3 means it is the parent. Parent found edge 7 & index 7 of set.
        x = set[x];

    return x;
}

void join(int u, int v)        // for joining two edges, let u=1 & v=6
{
    if(set[u] < set[v])      // when value in index 1 is less then value in index 6
    {
        set[u] += set[v];  // then we add the value in index 1 + the value in index 6 and store it in index 1
        set[v] = u;       // and then change the value in index 6 as u i.e. 1
    }
    else                // else when u > v  or u = v, then we will take v(6) as parent which is higher index value and the rest is just reverse of the above
    {                  // add two index value and store it in 6 & change in index 1 value to 6(v) from whatever it may be
        set[v] += set[u];
        set[u] = v;
    }
}
