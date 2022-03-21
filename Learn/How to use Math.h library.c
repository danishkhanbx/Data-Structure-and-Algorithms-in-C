/* Aim : Math.h Library
   Author : Danish Khan */
#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,d,e,g,h,i,j,k,l;

    printf("******ROUNDING OFF*****\n");
    b=round(8.99);
    printf("Round of value is : %.1f\n\n", b);

    printf("*****SQUARE ROOTING*****\n");
    printf("Please Enter any number to find Square root:");
    scanf("%f", &a);
    c=sqrt(a);
    printf("Square root of %f is :%f\n\n",a,c);

    printf("*****VALUE FOR TRIGONOMETRIC FUCTIONS*****\n");
    printf("Enter angle in radians :");
    scanf("%f",&d);
    e= sin(d);
    printf("Sine value for %.3f is :%.4f\n\n",d, e);


    printf("*****POWER VALUE*****\n");
    printf("Enter the Number for Exponential Power value:");
    scanf("%f",&base);
    scanf("%f",&power);
    h=pow(base,power);
    printf("%.2f to the 4rd power is :%.2f\n\n",g,h);


    printf("******FLOORING******\n");
    printf("Enter the number to be floored :");
    scanf("%f",&i);
    j=floor(i);
    printf("The Floor of %.4f is %.0f:\n\n",i,j);


    printf("******CEILING******\n");
    printf("Enter the number to be ceiled:");
    scanf("%f",&k);
    l=ceil(k);
    printf("And the celing of %.4f is %.0f",k,l);





   return 0;
}
