/* Aim: String uses and examples
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
int main(){
    char a[20],b[20];
    int len_a=0,len_b=0;

// reverse of words
 /* gets(a);         //enter the word
    strrev(a);       //reverse
    puts(a);*/

// find out if the two strings are same or not i.e. a=a
    gets(a);        //enter the words
    gets(b);
    len_a = strlen(a);
    len_b = strlen(b);

    if(strcmp(a,b)==0){
        printf("Strings are equal");
    }else{
        printf("Strings are not equal");
    }

    return 0;
}


