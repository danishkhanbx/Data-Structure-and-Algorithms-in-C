/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
int main(){
    FILE *ptr=NULL;

    // read mode
//  ptr=fopen("FILE_IO.txt","r");

    // write mode
//  ptr=fopen("FILE_IO.txt","w");

     // r+ mode
//  ptr=fopen("FILE_IO.txt","r+");

    // w+ mode
//  ptr=fopen("FILE_IO.txt","w+");


      // a+ mode
//    ptr=fopen("FILE_IO.txt","a+");

    char c=fgetc(ptr);
    printf("This character I read was: %c\n",c);

    char str[65];
    fgets(str,4,ptr);
    printf("The string is: %s\n",str);

 /* fputc('o',ptr);
    fputs("Hello Mr. xyz",ptr);*/

    fclose(ptr);

    return 0;
}

