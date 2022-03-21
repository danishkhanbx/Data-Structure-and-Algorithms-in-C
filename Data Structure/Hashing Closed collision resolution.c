/** Aim: Closed Hashing is a collision resolving technique. It utilizes only the given space provided.
         It used Linear Probing, Quadratic Probing, & Double Hashing methods for resolution.
    Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int hash();
int hash2();
int Prime();
void Insert();
int probe();
int doublehash();
int Search();
void Display();
/** Deletion(): Deletion is not easy in Closed Hashing thats why we don't usually perform it in Closed Hashing.
                If one really wants to perform deletion, then after deleting each or a bunch of index value at the same time,
                takeout every value there is and reinserted it all again, its called Rehashing.                               */

int main()
{
    int HT[SIZE]={0}; // filling Hash Table indexes values as 0
    Insert(HT,12);

    Insert(HT,25);
    Insert(HT,35);
    Insert(HT,26);
    Display(HT);
    printf("\nKey found at Index %d\n",Search(HT,35));

    return 0;
}

int hash(int key)
{
    return key%SIZE;
}


// Insert the functions here for using different Closed Hashing methods

void Display(int H[])
{
    printf("      Index    Value\n");
    for(int i=0; i<SIZE; i++)
        printf("\t%d:\t%d\n",i+1,H[i]);
}

/** 1: Linear Probing
    Functions: hash(key) = key % Table SIZE
               HASH'(key) = [ hash(key) + f(i)] , where i=0,1,2,3,...
    Code:
void Insert(int H[], int key)
{
    int index = hash(key);
    if(H[index] != 0)          // if the index we want to store our value is already occupied, we use probing functions to find the index which can store the value
        index = probe(H,key); // the probe method will return INDEX number
    H[index] = key;          // after finding free index, we store the value in it
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while(H[ (index+i) % SIZE ] != 0) // if its not equal to zero thats means the index is Empty
        i++;                         // when its not empty we increase i value and do the calculation for finding an index to store value again
    return (index+i) % SIZE;        // it returns the index number where value is to be stored
}

int Search(int H[], int key)     // we search performing the same functions as insertion
{
    int index = hash(key);
    int i = 0;
    while(H[ (index+i) % SIZE ] != key)
        i++;
    return (index+i) % SIZE;
}
*/


/** 2: Quadratic Probing
    Functions: hash(key) = key % Table SIZE
               HASH'(key) = [ hash(key) + f(i*i)] , where i=0,1,2,3,...
    Code:
void Insert(int H[], int key)
{
    int index = hash(key);
    if(H[index] != 0)          // if the index we want to store our value is already occupied, we use probing functions to find the index which can store the value
        index = probe(H,key); // the probe method will return INDEX number
    H[index] = key;          // after finding free index, we store the value in it
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while(H[ (index+i*i) % SIZE ] != 0) // if its not equal to zero thats means the index is Empty
        i++;                           // when its not empty we increase i value and do the calculation for finding an index to store value again
    return (index+i*i) % SIZE;        // it returns the index number where value is to be stored
}

int Search(int H[], int key)       // we search performing the same functions as insertion
{
    int index = hash(key);
    int i = 0;
    while(H[ (index+i*i) % SIZE ] != key)
        i++;
    return (index+i*i) % SIZE;
}
*/


/** 3: Double Hashing
    Functions: H1(key) = key % Table SIZE
               H2(key) = Prime - (key % Prime) , where Prime = a prime number, which is just smaller then the Table SIZE
               HASH'(key) = [ H1(key) + i*H2(key)] , where i=0,1,2,3,...
   Code:
int hash2(int key)
{
    int x = Prime() - (key % Prime());
    return x;
}
int Prime()
{
    int i=SIZE;            // Prime = a prime number, which is just smaller then the Table SIZE
    while(i%2==0 || i%3==0)
        i--;

    return i;
}
void Insert(int H[], int key)
{
    int index = hash(key);
    if(H[index] != 0)               // if the index we want to store our value is already occupied, we use doublehash functions to find the index which can store the value
        index = doublehash(H,key); // the doublehash method will return INDEX number
    H[index] = key;               // after finding free index, we store the value in it
}

int doublehash(int H[], int key)
{
    int h1 = hash(key);
    int h2 = hash2(key);
    int i = 0;
    while(H[ (h1 + i*h2 )% SIZE ] != 0) // if its not equal to zero thats means the index is Empty
        i++;                           // when its not empty we increase i value and do the calculation for finding an index to store value again
    return (h1 + i*h2) % SIZE;        // it returns the index number where value is to be stored
}

int Search(int H[], int key)       // we search performing the same functions as insertion
{
    int h1 = hash(key);
    int h2 = hash2(key);
    int i = 0;
    while(H[ (h1 + i*h2)%  SIZE ] != key)
        i++;
    return (h1 + i*h2) % SIZE;
}
*/
