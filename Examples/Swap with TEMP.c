/* Aim : swap 2 no. */
#include<stdio.h>
int main()
{
    int a,b,temp;
    printf("Enter two numbers (a,b):");
    scanf("%d,%d", &a,&b);

    printf("Before Swapping;\n");
    printf("Number 1:%d\n", a);
    printf("Number 2:%d\n\n", b);

    temp = a;
    a = b;
    b = temp;

    printf("After Swapping:\n");
    printf("Number 1:%d\n", a);
    printf("Number 2:%d\n\n", b);


   return 0;
}
