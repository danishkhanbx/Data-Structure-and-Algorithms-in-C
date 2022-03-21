/* Aim : WAP to calculate the perimeter and area of a circle with the help of constants. The radius is to be taken as an integer input. Take Pi = 3.14. */
#include<stdio.h>
int main()
{
    int radius;
    float perimeter,area;
    const float pi=3.14;
    printf("*** Circle Area Calculator\n\n ***");
    printf("Enter the Radius of the Circle=");
    scanf("%d",&radius);
    perimeter=2*pi*radius;
    printf("The Perimeter of the Circle= %.2f\n", perimeter);
    area=pi*radius*radius;
    printf("The Area of the Circle= %.2f", area);
   return 0;
}
