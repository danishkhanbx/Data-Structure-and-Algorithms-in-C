/* Aim: predefined processors
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("File name is %s\n",__FILE__); // to find what file(named) we are using now
    printf("Today's date is %s\n",__DATE__); // DD-MM-YYYY
    printf("Time now is %s\n",__TIME__);  // HH:MM::SS
    printf("Line no. is %d\n",__LINE__); // which line this code right now is
    printf("ANSI: %d\n",__STDC__); // output=1 if we are using it


    return 0;
}

