/* Aim: Auto,Extern,Static,Register storage classes in C
   Author: Danish Khan */
#include<stdio.h>
// auto = works as normal function(has parameters & has a return type)
// register works same as static but faster because its closed to CPU

/* Extern takes global variable instead of local
int myfunc(int a,int b){
    extern int sum;
    return sum;
}
int sum=342;
int main(){

    int sum = myfunc(3,5);
    printf("The sum is %d", sum);*/

//  Static class
int myfunc(int a,int b){
    static int myVar;
    myVar++;
    printf("The myVar is %d\n", myVar);
    return myVar;
}
int main(){

    int myVar = myfunc(3,5);
    myVar = myfunc(3,5);
    myVar = myfunc(3,5);
    myVar = myfunc(3,5);

    return 0;
}


