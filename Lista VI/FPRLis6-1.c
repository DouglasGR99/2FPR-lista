/*
	
	QUESTÃO 01:
	Faça uma função que, dada uma matriz M8×5 de
	reais, gere a matriz Mt,sua transposta.

*/
#include <stdio.h>
#include <time.h>
#define L 8
#define C 5

//função objetivo
void transp(float m[8][5],float mt[C][L]);

//funções auxiliares
void fillMat(float mat[L][C]);
void prtMat(float mat[L][C]);
void prtMatTransp(float mat[C][L]);



void main()
{
	float m[L][C],mt[C][L];
	
	fillMat(m);
	prtMat(m);
	transp(m,mt);
	prtMatTransp(mt);
}


void transp(float m[L][C], float mt[C][L])
{
	int i,j;
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			mt[j][i]=m[i][j];
		}
	}
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

void prtMatTransp(float mat[C][L])
{
	int i,j;
	
	printf("\nElementos da matriz transposta:\n");
	for(i=0;i<C;i++)
	{
		for(j=0;j<L;j++)
		{
			printf(" %.2f ",mat[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
}
