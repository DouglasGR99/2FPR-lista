/*
	Questão 01:
	Desenvolver uma função recursiva que
	determine o número de caracteres comuns
	entre duas strings s1 e s2.
*/

#include <stdio.h>
#include <string.h>

int charRec(char s1[],char s2[],int i,int j,int soma);
int charComum(char s1[],char s2[]);

void main()
{
	char s1[30],s2[30];
	printf("Insira uma palavra:\n");
	fflush(stdin);
	gets(s1);
	printf("Insira outra palavra:\n");
	fflush(stdin);
	gets(s2);
	
	printf("\n letras em comum:%d",charComum(s1,s2));
}


int charComum(char s1[],char s2[])
{
	int soma=0;
	return charRec(s1,s2,strlen(s1)-1,strlen(s2)-1,soma);
}

int charRec(char s1[],char s2[],int i,int j,int soma)
{
	printf("\n s1=%c s2=%c",s1[i],s2[j]);

	if(i>=0)
	{
		if(j>=0)
		{
			if(i!=j)
			{
				if(charRec(s1,s2,i,j-1,soma))
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
		if(charRec(s1,s2,i-1,j,soma))
		{
			return 1;
		}
	}
	printf("\n");
	return 0;
}
