/*
	
	Questão 04:
	Implementar uma função que remova todas as
	ocorrências de determinado caracter em uma
	string.

*/

#include <stdio.h>
#include <string.h>
void remChar(char a,char s[]);

void main()
{
	char a,s[30];
	
	printf("\nInsira uma palavra: ");
	fflush(stdin);
	gets(s);
	
	printf("\nInsira uma letra a ser removida: ");
	scanf("%c",&a);
	
	remChar(a,s);
	
	printf("%s",s);
}

void remChar(char a,char s[])
{
	int i,j,cont=0;
	
	for(i=0;i<(strlen(s));i++)
	{
		if(s[i]==a)
		{
			for(j=i;j<strlen(s);j++)
			{
				s[j]=s[(j+1)];
			}
		}
	}
	s[i]=('\0');
}
