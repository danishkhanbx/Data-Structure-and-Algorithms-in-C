/* Aim: Calculating the value of Postfix expression like computers do
   Author: Danish Khan */
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define SIZE 100

int stack[SIZE];
int top=-1;

void push(int ele)
{
    if(top==SIZE-1)
        printf("Overflow");
    else
    {
        top++;
        stack[top]=ele;
    }
}

int pop()
{
    if(top < 0)
        printf("Underflow");
    else
        return stack[top--];
}

void display()
{
    printf("\n Stack S= ");
    for(int i=0;i<=top;i++)
        printf(" | %d",stack[i]);
}

int main()
{
    char postfix[SIZE]={'\0'},ele;
    int num1, num2, i, ans;

    printf("\n Enter Postfix Expression: ");
    scanf("%s",postfix);
    printf("\n Postfix Expression: %s",postfix);

    i=0;
    while(i<=strlen(postfix)-1) // from 0 till the length of the postfix expression
    {
        ele=postfix[i];
        if(isdigit(ele)) // if its a digit then push it into the stack
        {
            push(ele-'0'); /// let element = 7 then 55(ASCII of 7) - 48(ASCII of 0) = 7
        }
        else   // popping the top 2 numbers and performing the given calculations
        {
            num1=pop();
            num2=pop();

            switch(ele)
            {
                case '^':
                    ans = pow(num2,num1);
                    break;
                case '*':
                    ans = num2 * num1;
                    break;
                case '/':
                    ans = num2 / num1;
                    break;
                case '+':
                    ans = num2 + num1;
                    break;
                case '-':
                    ans = num2 - num1;
                    break;
            }
            push(ans); // storing it in new top of the stack
        }
        display(); // this will display all the integers stored in the stack i.e. [ bottom | x | y | top ] depending on how many are present in the stack
        i++; // scanning the next element
    }
    printf("\n Result= %d",pop()); // at the end of all calculations one last pop and print
    return 0;
}

