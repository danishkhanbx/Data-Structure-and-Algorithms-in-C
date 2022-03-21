/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>

struct id {
    int roll_no;
    char uin[8];
    int seat_no;
};

struct student {
    char name[20];
    struct id;
    float marks;
};

int main(){
    struct student s1;

    scanf("%f",&s1.marks);
    printf("Student marks is %f\n",s1.marks);

    scanf("%d",&s1.roll_no);
    printf("Student Roll number is %d\n",s1.roll_no);

    scanf("%s",&s1.uin);
    printf("Student UIN is %s\n",s1.uin);

    return 0;
}

