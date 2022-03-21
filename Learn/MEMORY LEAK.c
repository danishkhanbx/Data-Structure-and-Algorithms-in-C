/* Aim: We need to free the dynamically allocated memory, if we don't .exe file after each run keeps on getting bigger & bigger until there's no more place left in the system
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,i=0;
    int *i2;
    while(i< 45683){
        printf("Welcome to code with DK\n");
        i2= malloc(65738 * sizeof(int));
        if(i%100==0){
            getchar();
        }
        i++;
        free(i2);  // without this we will encounter a situation of memory leak
    }

    return 0;
}

