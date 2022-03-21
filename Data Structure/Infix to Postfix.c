/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<ctype.h> /// for isalnum(char) = this character is alphabet or number
#define SIZE 100
char stack[100];
int top=-1;

void push(char ele)
{
   if(top==SIZE-1)
    printf("Overflow");
   else
   {
       top++;
       stack[top]=ele;
   }
}

char pop()
{
   if(top==-1)
    printf("Underflow");
   else
    return stack[top--];
}

int priority(char ele)
{
    if(ele =='(')
        return 0;
    if(ele =='+' || ele =='-') // lowest precedence
        return 1;
    if(ele =='*' || ele =='/')
        return 2;
    if(ele == '^') // exponent operator, highest precedence
		return 3;
    return 0;   // else return 0 if element not met
}

int main()
{
    char exp[100];
    char *e, ele;

    printf("Enter the expression :: "); // reading expression in the string exp
    scanf("%s",exp);

    e=exp; /// e is pointing to the first element of exp

    while(*e != '\0') // keep reading until the last element & calculate
    {
        if(isalnum(*e)) // is e alphabet or numerical
            printf("%c",*e);
        else if(*e == '(')
                    push(*e);
        else if(*e == ')')
        {
            while( (ele=pop()) != '(') // popping & printing till left parenthesis is met
                    printf("%c",ele);
        }
        else
        {
            /** While adding OPERANDS the priority of top element should be
                less than the element to be added, else we have to pop all
                the elements in the stack */
            while(priority(stack[top])>= priority(*e))
                printf("%c",pop());
            push(*e); /// if it is less we add it in the stack
        }
        e++; /// next character
    }

    /** popping and printing all remaining the elements in the stack till its
        empty, after pointer e reads every expression from the given INFIX */
    while(top != -1)
        printf("%c",pop());

    return 0;
}


