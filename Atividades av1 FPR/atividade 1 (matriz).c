/*

	Dada uma matriz MLINHAxCOLUNA, onde LINHA e
	COLUNA são constantes, e uma linha L,
	desenvolver uma função que retorne um vetor
	de tamanho COLUNA contendo, em cada
	posição, a quantidade de vezes que os
	elementos da linha L encontram-se nas demais
	linhas da matriz.

*/
#include <stdio.h>

#include <time.h>

#define L 6
#define C 4

//funçao solicitada
void matCont(int m[L][C],int l,int vet[C]);

// funçao preencher matriz(random)
void fillMat(int mat[L][C]);
// funçao exibir matriz
void prtMat(int mat[L][C]);

void main()
{
	int m[L][C],l,i,vet[C];
	
	//preencher
	fillMat(m);
	//printar
	prtMat(m);
	
	printf("\nqual linha\n");
	scanf("%d",&l);
	matCont(m,l,vet);
	
	for(i=0;i<C;i++)
	{
		printf(" %d",vet[i]);
	}
	
	
}


void matCont(int m[L][C],int l,int vet[C])
{
	int i,j,k,cont,atual;
	
	//lendo primeiro a linha descrita
	for(i=0;i<C;i++)
	{
		//o numero que vai ser buscado em toda matriz:
		atual=m[l][i];
		
		//cont sera reiniciado toda vez
		cont=0;
		
		//lendo as linhas	
		for(j=0;j<L;j++)
		{
			//garantindo que ele não vai contar a linha l
			if(j!=l)
			{
				//lendo as colunas
				for(k=0;k<C;k++)
				{
					//testando se o numero lido bate com o atual
					if(m[j][k]==atual)
					{
						cont++;
					}
				}
			}
		}
		//atribuindo valores ao vetor
		vet[i]=cont;
	}	
}



//preencher
void fillMat(int mat[L][C])
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

//printar
void prtMat(int mat[L][C])
{
	int i,j;
	
	printf("\nElementos da matriz:\n");
	for(i=0;i<L;i++)
	{
		for(j=0;j<C;j++)
		{
			printf(" %d ",mat[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
}

