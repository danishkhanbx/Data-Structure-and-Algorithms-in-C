/* Aim: Entered word,num,phrase,etc is Palindrome or not
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
int main(){
    char a[20],a_rev[20];
    int len_a=0,i;

        /*   gets(a);
    len_a = strlen(a);

    while(a[len_a]!='\0'){
        len_a++;
    }

    for(i=0;i<len_a;i++){
            if(a[i]!=a[len_a-1-i]){
                printf("String is not a Palindrome");
                return 0;
            }else{
                printf("String is an Palindrome");
                return 0;
            }
    }*/

    gets(a);

    strcpy(a_rev,a);      // a_rev=a
    strrev(a_rev);        //a_rev reverse will be equal to a

    if(strcmp(a,a_rev)==0){
                printf("Palindrome");

            }else{
                printf("Not an Palindrome");

            }


    return 0;
}


