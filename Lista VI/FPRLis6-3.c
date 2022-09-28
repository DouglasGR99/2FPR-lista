/*

	QUESTÃO 03:
	Desenvolver uma função que gere a seguinte
	matriz M5?5:
	1 2 3 4 5
	2 3 4 5 6
	3 4 5 6 7
	4 5 6 7 8
	5 6 7 8 9

*/
#include <stdio.h>
#define L 5
#define C 5

//funcao pedida
void crescer(float m[L][C]);
// funçao exibir matriz
void prtMat(float mat[L][C]);


void main()
{
	float m[L][C];
	crescer(m);
	prtMat(m);
}


void crescer(float m[L][C])
{
	int i,j;
	float num;
	for(i=0;i<L;i++)
	{
		num=i+1;
		for(j=0;j<C;j++)
		{
			m[i][j]=num;
			num++;
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
