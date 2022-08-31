/*
	
	Questão 03:
	Desenvolver uma função, em C, que, dada uma
	string s e dada uma posição p desta string, crie duas
	novas strings: s1 com os caracteres de s das
	posições 0 a p-1; e s2 com os caracteres de s da
	posição p à última.
	Nota: Caso p seja uma posição inválida, a função
	deverá retornar o valor 0; caso contrário,
	procederá com a criação das duas strings e
	retornará o valor 1.

*/

#include <stdio.h>
#include <string.h>

int pivisor(char s[],int p);

void main()
{
	char s[30];
	int p;
	printf("\nInsira palavra: ");
	fflush(stdin);
	gets(s);
	printf("\nInsira posicao de quebra: ");
	scanf("%d",&p);

	printf("\no retorno e %d.",pivisor(s,p));
}

int pivisor(char s[],int p)
{
	int i,j;
	char s1[30],s2[30];
	
	if((p<0)||(p>strlen(s)))
	{
		return 0;
	}
	else
	{
		//criando a primeira string
		for(i=0;i<p;i++)
		{
			s1[i]=s[i];
		}
		s1[i]=('\0');
		
		//criando s2
		for(i=p,j=0;i<strlen(s);i++,j++)
		{
			s2[j]=s[i];
		}
		s2[i]=('\0');
		
		printf("\ns1 = %s",s1);
		printf("\ns2 = %s",s2);
	}
	return 1;
}
