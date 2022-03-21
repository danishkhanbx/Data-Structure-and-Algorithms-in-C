/* Aim: Code
   Author: Danish Khan */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main()
{
    int i,j,k, R, N;
    struct str t;

    gets(N);
    gets(R);
    gets(t.A);

    for(int i = 0; i < A.length(); i++)
    {
        for(int j = i+1; j <= A.length(); j++)
        {
            for(k=0; k<=R; k++)
                k = A.substring(i,j);
        }
    }
    for(k=0; k<=R; k++)
        System.out.println(A.substring(i,j));


    return 0;
}*/
int main()
{
   char str[1000], sub[1000];
   int N, R, c = 0;

   scanf("%d", &N);
   scanf("%d", &R);
   gets(str);

   char *pt;
    pt = strtok (str,",");
    while (pt != NULL) {
        int a = atoi(pt);
        printf("%d\n", a);
        pt = strtok (NULL, ",");
    }

   return 0;
}
