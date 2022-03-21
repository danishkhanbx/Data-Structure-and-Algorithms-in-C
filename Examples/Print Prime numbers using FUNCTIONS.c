/* Aim : Print prime numbers between two number enter by user
   Author : Danish Khan */
#include <stdio.h>
int check_prime(int a){
    int i;
    for(i=2;i<a;i++){
            if(a%i==0){
            return 0;
        }
    }
        return 1;
}
int main(){
    int m,n,i;

    printf("Enter the starting and ending number (m,n):");
    scanf("%d,%d",&m,&n);

    for(i=m;i<=n;i++){
           if(check_prime(i)==1){
            printf("%d ", i);
            }
    }
    return 0;
}
