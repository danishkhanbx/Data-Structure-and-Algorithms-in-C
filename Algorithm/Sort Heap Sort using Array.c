/* Aim: Binary Heap Insertion, Deletion and Traverse
        Min-Heap(ascending array) & Max-Heap(descending array)
e.g. Max Heap [index 0 to 4 will be treated as Heap DS & 5 to 7 as Normal Stack Array, we neglect index 0 we store 0 at it & in case of traverse or deletion we don't really include it]
                                  ________________________            ______________|________                          _________________|______                               ___________|___________
 Normal Array before any operaton|__|__|__|__|__|__|__|__| ---> Heap |_0|__|__|__|__|__|__|__| Normal ---> Heap inc+1 |_0|__|__|__|__|__|__|__| Normal dec-1 ---> Heap dec-2 |_0|__|__|__|__|__|__|__| Normal inc+2
                                  0 1  2  3  4  5  6  7               0  1  2  3  4| 5  6  7                           0  1  2  3  4  5 |6  7                                 0  1  2  3 |4  5  6  7
If we want to inserted something, we will inserted it at Normal, then perform insert heap min or max function to place it properly then we inc++ the size of Heap and dec-- the size of Normal Array.
If we want to delete something, we will delete from the root or index 1(which is the highest in case of Max & lowest in Min) and store the value in temp then rearrange the Heap,
then we dec-- the size of Heap and inc++ the size of Normal Array. Then we store the root value in the newly generated normal index, when we keep deleting from Heap & storing at Normal Array,
the Normal Array part will be sorted in ascending order(descending order in case of Min-Heap) this type of sorting of Array is called as Heap Sort.
Its Binary Heap so every index will have parent & its child, when we divide that index by 2(i.e. i/2) we get parent, when we multiply(i.e. i*2) we get child, when Index gets out of bound or is Empty means parent/child does not exists.
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>

void Insert();
int Delete();

int main()
{
    int H[] = {0,10,20,30,25,5,40,35}; // it is stored as a Normal array, to store it as a Heap we need to perform some operations

    for(int i=2; i<=7; i++) // we ignore index 0, we will perform Heap insert function in reference to index 1, thats why 1 is not included, even if we include 1 it will be the same
        Insert(H,i);       // we pass the array in which we need to perform operations and index of Normal array of which value will be operated and converted into Binary Heap

//  printf("Deleted value %d\n",Delete(H,7));
    for(int i=7; i>1; i--)  // sending the array & highest index(lowest value) available in Heap Array so when we delete the lowest index(highest value) we can copy the high index value into low
        Delete(H,i);       // with each deletion the highest index of Heap array dec-- and Normal inc++

    for(int i=1; i<=7; i++)
        printf("%d ",H[i]);
    printf("\n");

    return 0;
}

void Insert(int A[], int n) // when we copy the values from Normal Array to Heap Array the index needed to be updated according Binary Heap rules
{
    int i=n, temp;        // i store the index, whereas temp stores the value at that given index
    temp = A[i];

    while(i>1 && temp>A[i/2]) // we will only apply Binary Heap rules when the index is equal to or greater than 1 & the newly inserted value is greater than its parent
    {
        A[i] = A[i/2]; // when parent value is less we swap parent child value, now parent holds child's value
        i = i/2;      // now we change the index which was passed as parameter by dividing it by 2 so it become parent index, in case of odd no. e.g. 3.5 we take Ceil value i.e. 3
    }
    A[i] = temp;    // now the parent hold child value cause we store child in temp and updated index(i) by its parent index(i/2)
}

int Delete(int A[], int n)
{
    int i, j, temp, val;

    val = A[1];    // we only delete from top root or highest index
    A[1] = A[n];  // now the 1st index is Empty we copy the last element of Heap array to index 1 or deleted index, now the size of Heap is dec-- & Noraml inc++
    A[n] = val;  // the last index from where we copy the above is now a Normal Stack Array index, now we store the deleted values at the newly empty respective index
                // then Normal Array part will be sorted in ascending order(descending order in case of Min-Heap) this type of sorting of Array is called as Heap Sort.
    i = 1;     // parent
    j = i*2;  // its child(if i is even its a left child else right child)

    while(j < n-1)          // it will continue until the index of j is less than Heap array i.e. when n=7(7 will be deleted) the last child will be n=4(L) & n=5(R), and n=6 will be LL, LR, RL, or RR
    {
        if(A[j+1] > A[j]) // we compare the left(j) and right(j+1) child if j+1 is greater we will take change the value of left child(j) from j to j+1
            j = j+1;
        if(A[i] < A[j]) // now if the parent is also less than its child(j from above it will be either j or j+1), we swap the child and parent to make the array complaint of Binary rules
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i = j;    // now the parent becomes the child and child becomes the parent the values are updated
            j = 2*j; // with the updated i and j the while loop continuous, now the previous child will become parent and it will compare itself with its child
        }
        else       // when parent is greater than its child we will break, now it will move to the greater among the two childrens, it will start a new compare with child as a parent and grandchilds as child's
            break;
    }
    return val;// returns the value of deleted element from the Binary Heap Array
}
