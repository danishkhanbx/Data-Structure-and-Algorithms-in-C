/* Aim: teachers name,DOB,pan no.,address,salary
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
struct teacher{
    char name[30];
    char pan_number[12];
    char DOB[11];
    float salary;
};
int main(){
    struct teacher t1={"Dan","6TR778YUY78","20/1/1996",10000};

    printf("Name      : %s\n",t1.name);
    printf("Pan Number: %s\n",t1.pan_number);
    printf("DOB       : %s\n",t1.DOB);
    printf("Salary    : %f",t1.salary);

    return 0;
}
