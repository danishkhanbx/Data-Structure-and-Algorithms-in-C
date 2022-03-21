/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
struct Product{
    int srno;
    char name[20];
    float amount;
};
void print_product(struct Product x){
    printf("%d\n",x.srno);
    printf("%s\n",x.name);
    printf("%.2f\n",x.amount);


}

int main(){
    struct Product p1={1, "Apple", 239.99};
    struct Product p2;

    p2=p1;
    print_product(p1);
//  print_product(p2);

    return 0;
}

