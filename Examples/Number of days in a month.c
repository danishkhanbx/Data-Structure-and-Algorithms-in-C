/* Aim : Use of Switch, brake, default 2
   Author : Danish Khan */
#include<stdio.h>
int main(){
    int a;

    scanf("%d", &a);

    switch(a){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Days = 31");
            break;




        case 2:
            printf("Days = 28/29");
            break;


        case 4:
        case 6:
        case 9:
        case 11:
            printf("Days = 30");
            break;


        default:
            printf("Oops...");
    }


   return 0;
}
