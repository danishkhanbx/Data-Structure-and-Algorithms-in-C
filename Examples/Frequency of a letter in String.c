/* Aim: frequency of a word in a sentence, word, letter
   Author: Danish Khan */
#include<stdio.h>
#include<string.h>

int main()
{
    char line[100], ch;
	int i, count=0;

	printf("\n Enter words: ");
	gets(line);

	printf("\n Enter a character(case sensitive) to find its frequency: ");
	scanf("%c",&ch);

	for(i = 0; i<strlen(line) ; i++)
	{
		if(ch == line[i])
            count+=1;
	}
	printf("\n The frequency of %c is %d\n", ch, count);

    return 0;
}
