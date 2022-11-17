/*
	FAETERJ-Rio
	FPR - Manhã - 2022/2
	Data: 27/10/2022
	
	Lista de Exercícios X (Arquivos)
	
	Questão 03:
	Desenvolver uma função que, dado um arquivo texto, verifique 
	o número de letras existentes no mesmo (entendendo que no 
	arquivo podem existir letras, algarismos e símbolos).
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int numeroLetras (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	int quant;
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);

	//chamando a função
	quant = numeroLetras (nomeArq);
	
	//testando o retorno da função
	if (quant == -1)
	{
		printf ("\n\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\n\nForam encontradas %d letras no arquivo %s.", quant, nomeArq);
	}
}

//implementação das funções
int numeroLetras (char nomeArq[])
{
	//declaração de variáveis
	FILE *arq;		
	char caracter;
	int cont = 0;
		
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//testando se houve falha na abertura
	//if (arq == NULL)
	if (!arq)
	{
		return -1;
	}
	else
	{
		//lendo os elementos do arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)    //EOF - End Of File
		{
			//verificando se o caracter lido é uma letra
			if ((toupper(caracter) >= 'A') && (toupper(caracter) <= 'Z')) 
			{
				cont++;
			}
		}
		
		//fechar o arquivo
		fclose (arq);
				
		//retornando a quantidade de caracteres do arquivo
		return cont;
	}
}
