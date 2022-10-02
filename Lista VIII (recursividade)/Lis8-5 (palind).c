/*
	
	Questão 05:
	Dada uma string s, desenvolver uma função
	recursiva que determine se s é ou não um
	palíndromo.

*/
#include <stdio.h>
#include <string.h>

int pali(char s[],int ini,int fin);

void main()
{
	char s[30];
	printf("Insira uma palavra:\n");
	fflush(stdin);
	gets(s);
	int ini=0, fin=(strlen(s)-1);
	
	if(pali(s,ini,fin))
	{
		printf("\nE um palindromo");
	}
	else
	{
		printf("\nNao e um palindromo");
	}
}


int pali(char s[],int ini,int fin)
{
	printf("\n%s, %d, %d, %c, %c",s,ini,fin,s[ini],s[fin]);
	
	if(ini<=fin)
	{
		if(pali(s,(ini+1),(fin-1))==1)
		{
			printf("\nok");
			if((s[ini])!=(s[fin]))
			{
				printf("\n ini %c, fin %c",s[ini],s[fin]);
				printf(" retorno 0");
				return 0;	
			}
			else
			{
				printf(" retorno 1");
				return 1;
			}
		}
		else
		{
			printf("\nerro");
			return 0;
		}
	}
	printf("\n final da func");
}
