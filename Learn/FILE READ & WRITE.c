/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
int main(){

    FILE *ptr=NULL;

    // **** Reading a File ****
    char string[68];
  //char string[68]="This content was produced by for write purpose"; // just add this statement in output without modifying the .txt file
    ptr = fopen("FILE_IO.txt", "r"); // r = reading the given or created text file
    fscanf(ptr,"%s", string);
    printf("The content of this file has %s\n",string);


    // **** Writing a File ****
/*  char string[68]="This content was produced by for write purpose"; // modifies the content to "xyz" in the previous statement
    ptr = fopen("FILE_IO.txt", "w"); // w = write the content in the file while erasing which is already there
    fprintf(ptr,"%s", string);*/


    // **** Read & Write at the same time File ****
/*  char string[68]="This content was produced by for write purpose"; // add the content to "xyz" in the previous statement
    ptr = fopen("FILE_IO.txt", "a"); // a = r + w + without erasing the given content
    fprintf(ptr,"%s", string);*/

    return 0;
}


