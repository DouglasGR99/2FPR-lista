/*

	Questão 02:
	Dada uma string s, desenvolver uma função
	que determine se s é ou não um palíndromo.
	Observação: uma string s será um palíndromo
	quando seus caracteres formarem a mesma
	sequência, independente se s é percorrida da
	esquerda para direita ou vice-versa.

*/

#include <stdio.h>
#include <string.h>

int pali(char s[]);

void main()
{
	char s[30];
	printf("Insira uma palavra:\n");
	fflush(stdin);
	gets(s);
	if(pali(s)){
		printf("\nE um palindromo");
	}
	else
	{
		printf("\nNao e um palindromo");
	}
	
}

int pali(char s[])
	{
	int i,j;
	for(i=(strlen(s)-1),j=0;i>=0;i--,j++)
	{
		if((s[i])!=(s[j]))
		{
			return 0;
		}
	}
	return 1;
}
