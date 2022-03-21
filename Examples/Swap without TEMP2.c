
/* Aim : swap 2 no.without temp  with div& mul*/
#include<stdio.h>
int main()
{
    int a,b,temp;
    printf("Enter two numbers (a,b):");
    scanf("%d,%d", &a,&b);

    printf("Before Swapping;\n");
    printf("Number 1:%d\n", a);
    printf("Number 2:%d\n\n", b);

    a=a*b;
    b=a/b;
    a=a/b;

    printf("After Swapping:\n");
    printf("Number 1:%d\n", a);
    printf("Number 2:%d\n\n", b);


   return 0;
}
