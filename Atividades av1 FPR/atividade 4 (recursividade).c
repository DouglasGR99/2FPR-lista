/*

	Considere uma string s contendo apenas letras
	e algarismos. Desenvolver uma função
	recursiva que verifique se as letras de s estão
	em seu início (e, consequentemente, os
	algarismos ao seu final). Se estiverem, a função
	retornará 1; caso contrário, 0.

*/

#include <stdio.h>
#include <string.h>
#define TAM 20

//funcao iterativa (nao eh a solicitada mas fiz p auxiliar o planejamento da recursiva)
int letraNum(char s[]);

//funcao solicitada (com os dados do usuario)
int letraNumRec(char s[]);

//funcao recursiva propriamente dita(a outra chama essa)
int letraNumRecRec(char s[],int i,int tam);


void main()
{
	char s[TAM];
	
	printf("Insira uma palavra:\n");
	fflush;
	gets(s);
	if(letraNumRec(s))
	{
		printf("\nEsta ordenado");
	}
	else
	{
		printf("\nNao esta ordenado");		
	}
}

//funcao iterativa(mantive no arquivo para me ajudar a entender a logica futuramente)
int letraNum(char s[])
{
	int i,tam=strlen(s),asciiAtual,asciiPosterior;
	
	for(i=0;i<tam;i++)
	{
		asciiAtual=s[i];
		asciiPosterior=s[i+1];
		printf("\n asciiAtual===%d,asciiPosterior===%d",asciiAtual,asciiPosterior);
		if((asciiAtual>=48)&&(asciiAtual<=57)&&(asciiPosterior>57))
		{
			return 0;
		}
	}
	return 1;
}

//funcao solicitada (com os dados do usuario)
int letraNumRec(char s[])
{
	int i=0,tam=strlen(s)-1;
	letraNumRecRec(s,i,tam);
}


//funcao recursiva propriamente dita(a outra chama essa)
int letraNumRecRec(char s[],int i,int tam)
{
	int asciiAtual=s[i];
	int asciiPosterior=s[i+1];
	
	//caso base
	if(i==tam)
	{
		return 1;
	}
	else
	{
		//vendo se o caracter atual eh um numero e o proximo eh uma letra
		if((asciiAtual>=48)&&(asciiAtual<=57)&&(asciiPosterior>57))
		{
			return 0;
		}
	}
	return 	letraNumRecRec(s,i+1,tam);
}


