/** Prims Algorithm:-
      Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree
      that includes every vertex, where the total weight of all the edges in the tree is minimized. The steps for implementing Prim's algorithm are as follows:
      1. Initialize the minimum spanning tree with a vertex chosen at random.
      2. Find all the edges that connect the tree to new vertexes , find the minimum and add it to the tree.
      3. Keep repeating step 2 until we get a minimum spanning tree.
    Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
#define I INT_MAX                                 // I: infinity i.e. the infinity value for int data type is Max-Int

int cost[][8] = { {I, I, I, I, I, I, I, I},     // we are representing the graph as a 2D array inside program, which is adjacency matrix for this graph
                  {I, I,25, I, I, I, 5, I},    // This matrix is a Symmetric matrix,so we will only take upper or lower triangle into consideration(we taking UTM).
                  {I,25, I,12, I, I, I,10},   // we have vertexes starting from 1 to 7, so we are not going to use 0 row, column & or indexes of any array
                  {I, I,12, I, 8, I, I, I},
                  {I, I, I, 8, I,16, I,14},
                  {I, I, I, I,16, I,20,18},
                  {I, 5, I, I, I,20, I, I},
                  {I, I,10, I,14,18, I, I} };

/* For edges 1-7 we will need 0-7 index whose size will be 8. Near array will be initialized with infinity, when we have selected an initial vertex we will mark both of
   those edge index numbers as 0. lets say we mark index 1 & 6 as 0 then we will find among the remaining index which is not marked as 0 yet who is nearer to 1 or 6.
   If an index such as 2 have a direct connection with one of the edges we will mark 1 in index 2 of near, same goes for 6. If no index is near we will either mark 1 or 6 replacing I.
   Now the repeating steps will start, find out which edge have the min cost among the marked arrays exception we will not include the index whose marked as I & 0.
   i.e. index:value == 0:I, 1:0, 2:1=25, 3:1||6, 4:1||6, 5:6=20, 6:0, 7:1||6. We will treat index-value = cost as connected edges, we got only two cost 25 & 20 -> 25 > 20 is min
   so we select edge 5-6, so we mark 5,6 in t[0,1]=5 & t[1,1]=6 and mark index 5 in near as 0 cause 6 is already marked as 0. Now the repeatation goes on of finding the whose
   near to 0 value indexes and marking them with the index value -> finding the smallest vertex among these then saving the values in t[][] & near & so on -> until t gets full. */
int near[8] = {I,I,I,I,I,I,I,I};

/* Minimum Cost Spanning Trees 2D array: We will be storing tree in 2 rows & 6 columns array.We will select minimum cost edge and store that edge value in it,
   then using that initial edge we will find the next connected and min cost edge then store it in the array, then using the available edges we will find another connected edge,
   it will keep going until we have selected |E|-1 = 6 edges such as the edges docent make a cycle.  */
int t[2][6];

int main()
{
    int i, j, k, u, v, n=7, min=I; // n: no. of edges 1 to 7,

    for(i=1; i<=n; i++)          // this 2 for loop is for finding min cost vertex for initialization of spanning tree & we will be storing the edges indexes for further use
    {
        for(j=i; j<=n; j++)    // this will only take upper triangular matrix elements
        {
            if(cost[i][j] < min)
            {               // storing the index number in u & v of and value
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;                               // spanning tree initialized with u as 1 & v as 6 in t[][] array
    t[1][0] = v;
    near[u] = near[v] = 0;                   // marking 0 in near index number u & v
    for(i=1; i<=n; i++)                     // initial finding of near elements from initial vertex
    {
        if(near[i]!=0)                    // we will only find the near for the indexes whose value is !0 i.e. they already have founded all their nearer  vertex &
        {                                // the vertex index is already included in array t[][]
            if(cost[i][u] < cost[i][v]) // let i=2 cause 1 is 0 in near, u=1 & v=6 i.e. initial vertex, then index 2,1=25 & 2,6=I : 25<I, now we mark 1(u) in index 2 of near array
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // now for finding remaining edges of spanning tree using initialize values
    for(i=1; i<n-1; i++) // index 0 of t is already founded & filled, thats why we are starting from index 1
    {
        min = I;
        for(j=1; j<=n; j++)                            // to find the next min value connected vertex
        {                                             // in near the index, value(in that index) are making an vertex in real time cost array[index of near][value in that index]
            if(near[j]!=0 && cost[j][near[j]] < min) // we will copy the min vertex value in min and keep comparing it with the next (index,value)=vertex value of the tree
            {                                       // the (index,value)=0 are already sorted so we don't include them while finding the next min value
                k = j;
                min = cost[j][near[j]];
            }
        }

        t[0][i] = k;            // k is index of near and near[k] is value inside that index
        t[1][i] = near[k];     // storing the edges in the spanning tree
        near[k] = 0;          // now k in included in spanning tree, therefore mark it as 0 i.e. the vertex with edge k is included in the spanning tree

        for(j=1; j<=n; j++) // updation of the near Array because 1 more value is marked as 0 i.e. included in the tree, so we need to confirm that
        {                  // the near Array indexes is near to k or previous edges
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]]) // let k=5, j=2 & near[2]=1 -> 2,5=I & 2,1=25 -> I > 25 so no updation will be done
                near[j] = k;                               //  if j,k < j,near[j] then we will update the value in j index in near as k
        }
    }

    for(i=0; i<n-1; i++) // printing the spanning tree with 2 rows(0,1) & 6 columns(n-2=6)
        printf("(%d, %d)\n",t[0][i],t[1][i]);

    return 0;
}
