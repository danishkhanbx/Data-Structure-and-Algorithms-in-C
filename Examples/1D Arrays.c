/* Aim : Code
   Author : Danish Khan */
#include <stdio.h>
#include <stdlib.h>
void print_array(int sub[],int n){
    int i;
    for(i=0;i<n;i++){
    printf("%d,", sub[i]);
    }


}

int main(){
    int i,n=6;
    int sub[]={6,7,4,8,4,2};
    int stud[]={3,4,4,8,8,8};

    print_array(sub,n);
    print_array(stud,n);


    /*for(i=0;i<n;i++){
    printf("%d", sub[i]);
     if(i<n-1){
        printf(",");
    }
    }*/


    return 0;
}
