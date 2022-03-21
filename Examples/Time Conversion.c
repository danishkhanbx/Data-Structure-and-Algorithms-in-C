/* Aim: Converting time based on AM and PM(1 PM to 13 PM)
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>
int main()
{
    char s[10];
    gets(s);

    if(s[8]=='A')
    {
        if(s[0]=='1' && s[1]=='2')
        {
            s[0]=s[1]='0';
        }
    }
    else
    {
        if(s[1]=='8')
        {
            s[0]='2';
            s[1]='0';
        }
        else if(s[2]=='9')
        {
            s[0]='2';
            s[1]='1';
        }
        else if(!(s[0]=='1' && s[1]=='2'))
        {
            s[0]+=1;
            s[1]+=2;
        }
    }
    s[8]='\0';
    puts(s);

    return 0;
}

