/*
	
	QUESTÃO 01:
	Faça uma função que, dada uma matriz M8×5 de
	reais, gere a matriz Mt,sua transposta.

*/
#include <stdio.h>
#include <time.h>

void fillMat(int mat[8][5],int lin,int col);
void prtMat(int mat[8][5],int lin,int col);
void transp(float M[8][5],int lin,int col);


void main()
{
	float M[8][5];
	
	fillMat(M,8,5);
	prtMat(M,8,5);

	transp(M,8,5);
	
}


void transp(float M[8][5],int lin,int col)
{
	int i,j;
	float Mt[5][8];
}
