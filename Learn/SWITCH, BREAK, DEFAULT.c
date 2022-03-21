
/* Aim : Use of Switch, brake, default
   Author : Danish Khan */
#include<stdio.h>
int main(){
    int a;

    scanf("%d", &a);

    switch(a){
        case 1:
            printf("Jan");
            break;
        case 2:
            printf("Feb");
             break;
        case 3:
            printf("March");
             break;
        case 4:
            printf("April");
             break;
        case 5:
            printf("May");
             break;
        case 6:
            printf("Jun");
             break;
        case 7:
            printf("July");
             break;
        case 8:
            printf("Aug");
        case 9:
            printf("Sep");
        case 10:
            printf("Oct");
        case 11:
            printf("Nov");
        case 12:
            printf("Dec");

        default:
            printf("Oops...");
    }


   return 0;
}
