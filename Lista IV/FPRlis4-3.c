	/*
	
	Questão 03:
	Desenvolver uma função que, dada uma string
	s, crie uma substring que inicie na posição p de
	s e contenha n caracteres.
	Observações: se p e/ou n forem inválidos, a
	substring será vazia; ii) se s não possuir n
	caracteres além de p, a substring a ser criada
	começará em p e terminará no final de s.

*/

#include <stdio.h>
#include <string.h>

void strEdit(char s[],int p, int n);

void main()
	{
	int p,n;
	char s[30];
	printf("\nInsira a palavra: ");
	fflush(stdin);
	gets(s);
	printf("\nInsira a posicao de inicio: ");
	scanf("%d",&p);
	printf("\nInsira quantas letras: ");
	scanf("%d",&n);
	
	strEdit(s,p,n);
	
}

void strEdit(char s[],int p, int n)
	{
	int i,j;
	char s2[30];
	
	if((p>=0)&&(n>0)&&(p<=strlen(s)))
	{
		for(i=p,j=0;i<(n+p);i++,j++)
		{ 
			s2[j]=s[i];
		}
	}
	else
	{
		s2[0]='\0';
		printf("\ns2 esta vazio.");
	}

	printf("%s",s2);
}
