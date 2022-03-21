/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
/*typedef long int sint;  // renaming data type by something else
int main(){

    sint a;
    printf("%d",a=9);*/

struct Date {
    int date;
    int month;
    int year;
};

struct Student {
    char name[20];
    int roll_no;
    struct Date dob;     // alias name date of birth
    struct Date doa;     // date of admission
    struct Date dol;     // date of leaving
} s1,s2,s3;


int main(){

   // struct Student s1;    can do it in struct also
    scanf("%d",&s1.dob.month);
    printf("%d",s1.dob.month);

    return 0;
}
