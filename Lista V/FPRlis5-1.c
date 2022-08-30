/*
	
	Questão 01:
	Implementar uma função que, dada uma string
	s, determine a quantidade de caracteres
	distintos em s.

*/

#include <stdio.h>
#include <string.h>
int distint(char s[]);

void main()
{
	char s[30];
	printf("\nInsiraum nome: ");
	fflush(stdin);
	gets(s);
	printf("\n%d digitos diferentes.",distint(s));
}

int distint(char s[])
{
	int i,j,cont=strlen(s);
	for(i=0;i<strlen(s);i++)
	{
		for(j=(i+1);j<strlen(s);j++)
		{
			if(s[j]==s[i])
			{
				cont--;
				break;
			}
		}
	}
	return cont;
}
