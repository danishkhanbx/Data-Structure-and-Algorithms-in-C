/* Aim : Basic Calculator
   Author : Danish Khan */
#include<stdio.h>
int main(){
    char opr;
    float num1,num2,ans;

    printf("Select Operator:");
    scanf("%c", &opr);

    printf("Enter First number:");
    scanf("%f", &num1);

    printf("Enter Second number:");
    scanf("%f", &num2);

     switch(opr){
        case '+':
            printf("Answer is :%.2f", num1 + num2);
            break;

        case '-':
            printf("Answer is :%.2f", num1 - num2);
            break;
        case '*':
            printf("Answer is :%.2f", num1 * num2);
            break;
        case '/':
            printf("Answer is :%.2f", num1 / num2);
            break;
        case '%':
            printf("Answer is :%d", (int)num1 % (int)num2);
            break;
        default:
            printf("Invalid Operation");
            break;
    }

   return 0;
}
