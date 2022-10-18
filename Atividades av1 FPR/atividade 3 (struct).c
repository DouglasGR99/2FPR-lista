/*

	Considere um vetor que armazene alguns
	dados coletados de um grupo de pessoas em
	uma pesquisa, a saber: nome, gênero, idade e
	altura.
	
	Desenvolver uma função que receba os
	parâmetros gênero, faixa de idade (idade inicial
	e idade final) e faixa de altura (altura inferior e
	altura superior) e retorne a quantidade de
	pessoas que atendem aos filtros por ele
	representados.
	
	Nota: caso o gênero especificado seja igual a
	M, serão considerados os homens que
	estiverem nas faixas de idade e altura
	especificadas; o mesmo ocorrerá com as
	mulheres, quando o gênero for F. Porém, se o
	gênero contiver qualquer valor diferente de M
	ou F, todas as pessoas que atenderem aos
	filtros de idade e altura serão contabilizadas.

*/

#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct{
	char nome[30];
	char genero;
	int idade;
	float altura;
}TPessoa;


//funcao soliciada
int filtroPessoa(char gen,int idaMax,int idaMin,float altMax,float altMin);
//funcao auxiliar
void preencherVetor(TPessoa grupo[]);
void exibirPessoa(TPessoa pessoa);
void exibirTodasPessoas(TPessoa grupo[]);


void main()
{
	char gen;
	int idaMax,idaMin;
	float altMax,altMin;
	
	printf("\nInsira os dados:");
	printf("\nGenero:");
	scanf("%c",&gen);
	printf("\nIdade maxima:");
	scanf("%d",&idaMax);
	printf("\nIade minima:");
	scanf("%d",&idaMin);
	printf("\nAltura maxima:");
	scanf("%f",&altMax);
	printf("\nAltura minima:");
	scanf("%f",&altMin);
	
	printf("\n Pessoas encontradas no parametro: %d",filtroPessoa(gen,idaMax,idaMin,altMax,altMin));
	
}

//funcao solicitada
int filtroPessoa(char gen,int idaMax,int idaMin,float altMax,float altMin)
{
	//declaracao de variaveis
	int i,cont=0;
	TPessoa grupo[TAM];
	
	//preenchimento do vetor
	preencherVetor(grupo);
	
	//inicio
	for(i=0;i<TAM;i++)
	{
		if((grupo[i].altura>=altMin)&&(grupo[i].altura<=altMax)&&(grupo[i].idade>=idaMin)&&(grupo[i].idade<=idaMax))
		{
			if((gen!='m')&&(gen!='f'))
			{
				cont++;
			}
			else
			{
				if(grupo[i].genero==gen)
				{
					cont++;
				}
			}
		}
	}

	return cont;
}

//funcao auxiliar
void preencherVetor(TPessoa grupo[])
{
	//1a pessoa
	strcpy(grupo[0].nome,"Renato");
	grupo[0].genero='m';
	grupo[0].idade=27;
	grupo[0].altura=1.65;
	
	//2a pessoa
	strcpy(grupo[1].nome,"Paula");
	grupo[1].genero='f';
	grupo[1].idade=12;
	grupo[1].altura=1.30;
	
	//3a pessoa
	strcpy(grupo[2].nome,"Luis");
	grupo[2].genero='m';
	grupo[2].idade=18;
	grupo[2].altura=1.80;
	
	//4a pessoa
	strcpy(grupo[3].nome,"Maria");
	grupo[3].genero='f';
	grupo[3].idade=22;
	grupo[3].altura=1.50;
	
	//5a pessoa
	strcpy(grupo[4].nome,"Ben");
	grupo[4].genero='m';
	grupo[4].idade=30;
	grupo[4].altura=1.95;
}

void exibirPessoa(TPessoa pessoa)
{
	printf("\n o nome eh %s",pessoa.nome);
	printf("\n o genero eh %c",pessoa.genero);
	printf("\n a idade eh %d",pessoa.idade);
	printf("\n a altura eh %.2f",pessoa.altura);


}

void exibirTodasPessoas(TPessoa grupo[])
{

	int i, quantidade=TAM;

	for (i=0;i<quantidade;i++)
	{
		exibirPessoa (grupo[i]);
		printf("\n");
	}
}

