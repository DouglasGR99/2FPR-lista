/*

	Desenvolver uma função que, dada uma string
	s, determine se todos os seus caracteres são
	distintos.

*/
#include <stdio.h>
#include <string.h>
#define TAM 20
#define FALSE 0
#define TRUE 1

//funcao solicitada
int distintos(char s[]);

void main()
{
	
	char s[TAM];
	printf("\nInsiraum nome: ");
	fflush(stdin);
	gets(s);
	printf("\nO retorno eh %d.",distintos(s));
}

int distintos(char s[])
{
	int i,j,tamanho=strlen(s);
	
	for(i=0;i<tamanho;i++)
	{
		for(j=0;j<tamanho;j++)
		{
			if((s[i]==s[j])&&(i!=j))
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

