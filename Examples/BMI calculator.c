/* Aim : WAP to find the body mass index of the user. Also find the category of BMI.
   Author : Danish Khan */
#include<stdio.h>
int main()
{
    float height, weight, bmi;

    /*printf("Enter height:");*/
    scanf("%f",&height);
    /*printf("Enter weight:");*/
    scanf("%f",&weight);

    bmi=weight/(height*height);
    printf("Your BMI is %.1f\n", bmi);


    if(bmi < 16){
        printf("You are Severe Thinness");
    }else if(bmi >= 16 && bmi < 17){
        printf("You are Moderate Thinness");
    }else if(bmi >= 17 && bmi < 18.5){
        printf("You are Mild Thinness");
    }else if(bmi >= 18.5 && bmi < 25){
        printf("You are Normal");
    }else if(bmi >= 25 && bmi < 30){
        printf("You are Overweight");
    }else if(bmi >= 30 && bmi < 35){
        printf("You are Obese Class I");
    }else if(bmi >= 35 && bmi <= 40){
        printf("You are Obese Class II");
    }else{
        printf("You are Obese Class III");
    }


   return 0;
}

