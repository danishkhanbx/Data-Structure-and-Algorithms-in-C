/* Aim: searching for a vehicle in a search bar of a website or an app
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
struct vehicle{
    char brand[20];
    char model[20];
    char color[20];
    int serial_no;
    float average;
};
int main(){
    struct vehicle veh1;

    printf("Enter Vehicle Data: \n");
    printf("Brand: ");
    gets(veh1.brand);
    printf("Model: ");
    gets(veh1.model);
    printf("color: ");
    gets(veh1.color);
    printf("Serial Number: ");
    scanf("%d", &veh1.serial_no);
    printf("Average: ");
    scanf("%f", &veh1.average);

    printf("\n\nVehicle Data:\n");
    printf("Brand & Model: %s  (%s).",veh1.brand, veh1.model);
    printf(" The car is of %s color.",veh1.color);
    printf(" The Serial no. of the car is: %d.", veh1.serial_no);
    printf(" The Car gives an average of %f Km/L.",veh1.average);

    return 0;
}


