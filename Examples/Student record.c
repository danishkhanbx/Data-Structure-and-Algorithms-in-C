/* Aim: First three toppers
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
struct student_record{
     char name[20];
     int roll_no;
     float marks;
};
int main(){
    struct student_record student[10],temp;
    int i,j;

    printf("Enter Student Details:\n\n");
    for(i=0;i<10;i++){
        printf("Student %d",i+1);
        printf("\nEnter student name:");
        scanf("%s", student[i].name);
        printf("Enter student roll no:");
        scanf("%d", &student[i].roll_no);
        printf("Enter student marks:");
        scanf("%f", &student[i].marks);
        printf("\n");
    }
    for(i=0;i<9;i++){
        for(j=0;j<9-i;j++){
            if(student[j].marks<student[j+1].marks){
                temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
    printf("First Three Toppers\n");
    printf("1st : %s\n",student[0].name);
    printf("2st : %s\n",student[1].name);
    printf("3st : %s\n",student[2].name);

    return 0;
}

