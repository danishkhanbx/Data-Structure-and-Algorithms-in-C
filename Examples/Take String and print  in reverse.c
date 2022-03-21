/* Aim: Taking from user & printing it in reverse
   Author: Danish Khan */
#include <stdio.h>
int main(){
    char a[20];
    int len=0,i;

    printf("Enter string to reverse: ");
    gets(a);

    while(a[len]!='\0'){
        len++;
    }
    printf("Length of the string: %d\n",len);

    printf("Reversed String: ");
    for(i=0;i<len;i++){
        printf("%c",a[len-1-i]);
    }
    printf("\n");

 /* printf("Reversed String: ");
    for(i=len-1;i>=0;i--){
        printf("%c",a[i]);
    }*/


    return 0;
}
