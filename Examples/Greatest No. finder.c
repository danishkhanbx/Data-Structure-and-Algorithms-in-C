/* Aim : find greatest no.*/
#include<stdio.h>
int main()
{
    int a,b,c,greatest;
    printf("Enter two numbers (a b c):");
    scanf("%d ,%d ,%d",&a, &b, &c);
    /*greatest = a>b && a>c ? a: (b>a && b>c ? b: c);*/
    greatest = a>b?(a>c?a:c): (b>c?b:c);

    printf("Greatest is: %d", greatest);

    return 0;
}
