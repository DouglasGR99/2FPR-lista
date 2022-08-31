/*
	
	Questão 02:
	Implementar uma função que, dadas duas
	strings s1 e s2, crie uma nova string – s3 –
	contendo todos os caracteres de s1 que não
	estejam em s2.
	Nota: em s3, não devem existir caracteres
	repetidos.

*/

#include <stdio.h>
#include <string.h>
void string3(char s1[],char s2[]);

void main()
{
	char s1[30],s2[30];
	printf("\nInsira s1: ");
	fflush(stdin);
	gets(s1);
	printf("\nInsira s2: ");
	gets(s2);
	
	string3(s1,s2);
}

void string3(char s1[],char s2[])
{
	char s3[30];
	int i,j,k=0,l,m,n,cont;
	
	//criando s3, mas ainda com char repetidos
	for(i=0;i<strlen(s1);i++)
	{
		cont=0;
		
		for(j=0;j<strlen(s2);j++)
		{
			if(s2[j]==s1[i])
			{
				cont++;
			}
		}
		if(cont==0)
		{
			s3[k]=s1[i];
			k++;
		}
	}
	s3[k]=('\0');
	
	//removendo char repetidos
	for(l=0;l<strlen(s3);l++)
	{
		for(m=(l+1);m<strlen(s3);m++)
		{
			if(s3[m]==s3[l])
			{
				for(n=m;n<strlen(s3);n++)
				{
					s3[n]=s3[(n+1)];
				}
			}
		}
	}
	s3[l]=('\0');
	printf("\n\n%s",s3);
}

