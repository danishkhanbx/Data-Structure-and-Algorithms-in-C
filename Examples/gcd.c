/* Aim : GCD & LCD of a given numbers
   Author : Danish Khan */
#include <stdio.h>


int main(){
    int a,b,c,i=2,gcd=1,lcm;

    printf("Enter two numbers (a,b):");
    scanf("%d,%d",&a,&b);

    while(i<=a && i<=b){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
        i++;
    }
    printf("GCD = %d\n", gcd);

    lcm=a*b/gcd;
    printf("LCM = %d", lcm);

    return 0;
}
