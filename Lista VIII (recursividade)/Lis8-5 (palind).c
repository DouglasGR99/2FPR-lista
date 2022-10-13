/*
	
	Questão 05:
	Dada uma string s, desenvolver uma função
	recursiva que determine se s é ou não um
	palíndromo.

*/
#include <stdio.h>
#include <string.h>

int palindromo(char s[]);
int paliRec(char s[],int ini,int fin);

void main()
{
	char s[30];
	printf("Insira uma palavra:\n");
	fflush(stdin);
	gets(s);
	
	if(palindromo(s))
	{
		printf("\nE um palindromo");
	}
	else
	{
		printf("\nNao e um palindromo");
	}
}


int palindromo(char s[])
{
	return paliRec(s,0,strlen(s)-1);
}


int paliRec(char s[],int ini,int fin)
{
	if(ini<=fin)
	{
		if(s[ini]!=s[fin])
		{
			if((s[ini])!=(s[fin]))
			{
				return 0;	
			}
			else
			{
				return paliRec(s,ini+1,fin-1);
			}
		}
		else
		{
			return 1;
		}
	}
}
