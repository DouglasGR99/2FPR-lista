/*
	
	QUESTÃO 02:
	Desenvolver uma função que, dada uma matriz
	M15×20, determine se um número X se encontra
	na linha L da matriz.

*/
#include <stdio.h>
#include <time.h>
#define L 15
#define C 20

//funcao pedida
int verificar(float m[L][C],float x,int l);
// funçao preencher matriz(random)
void fillMat(float mat[L][C]);
// funçao exibir matriz
void prtMat(float mat[L][C]);

void main()
{
	float m[L][C],x;
	int l;
	
	//funcoes para preencher e printar
	fillMat(m);
	prtMat(m);
	
	printf("\nInsira o numero a ser buscado: ");
	scanf("%f",&x);
	printf("\nInsira a linha: ");
	scanf("%d",&l);
	
	//fazendo e verificando funcao
	if(verificar(m,x,l)==1)
	{
		printf("\nConsta.");
	}
	else
	{
		printf("\nNao consta.");
	}
	
}


int verificar(float m[L][C],float x,int l)
{
	int i;
	for(i=0;i<C;i++)
	{
		if((m[l][i])==x)
		{
			return 1;
		}
	}
	return 0;
}


void fillMat(float mat[L][C])
{
	int i,j;
	
	srand (time(NULL));
	
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			mat[i][j]=rand()%10;
		}
	}
}



void prtMat(float mat[L][C])
{
	int i,j;
	
	printf("\nElementos da matriz:\n");
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			printf(" %.2f ",mat[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
}
