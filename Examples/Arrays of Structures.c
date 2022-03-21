/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
struct Product{
    int srno;
    char name[20];
    float amount;
};
void print_product(struct Product x){
    printf("Product serial no.: %d\n",x.srno);
    printf("Product name: %s\n",x.name);
    printf("Product amount is: %.2f\n",x.amount);
}

int main(){
    struct Product prd[10];
    int n,i;

    printf("Enter no. of products:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
    scanf("%d",&prd[i].srno);
    scanf("%s",prd[i].name);
    scanf("%f",&prd[i].amount);
    }

    print_product(prd[0]);

    return 0;
}

