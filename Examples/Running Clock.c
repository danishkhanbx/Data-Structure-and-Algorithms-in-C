/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<windows.h>
struct time_struct{
    int hour;
    int min;
    int sec;

};

int main(){
    struct time_struct t1={11,59,58};

    while(1){
        printf("               \r");
        t1.sec++;
        if(t1.sec>=60){
            t1.sec=00;
            t1.min++;
        }
        if(t1.min>=60){
            t1.min=00;
            t1.hour++;
        }
        if(t1.hour>=24){
            t1.sec=00;
            t1.min=00;
            t1.hour=00;
        }
        Sleep(1000);
        printf("%d:%d:%d",t1.hour,t1.min,t1.sec);
    }


    return 0;
}

