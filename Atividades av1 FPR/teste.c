/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	
	Lista de Exercícios VI (Structs)
	
	Questão 01:
	Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de structs contendo as seguintes 
	informações, para cada veículo: placa, modelo, marca, cor, quilometragem, ano modelo/fabricação (deve ser um 
	struct), valor e tipo (usado ou 0 km, conforme o valor do campo quilometragem). 
	
	Pede-se a declaração de uma variável que represente o estoque de veículos da loja, incluindo todas as 
	declarações de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
		i.	Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor 
		    não superior a x reais;
		ii.	Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
		iii.Retirar do estoque um determinado veículo, dada a sua placa.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

#define TRUE 1
#define FALSE 0

//definição de tipos
typedef enum {ZERO, USADO} tipoCarro;

typedef struct {			//representa os anos de modelo e fabricação do carro
	int anoModelo;
	int anoFabricacao;
} TAno;

typedef struct {			//representa um carro e todas as suas informações
	char placa[10];
	char modelo[20];
	char marca[20];
	char cor[20];
	float km;
	TAno ano;
	float valor;
	tipoCarro tipo;	
} TCarro;

//protótipos das funções
int exibirCarros (TCarro ag[], int quantidade, char modelo[20], int anoI, int anoF, float valorLimite);
void reajustarCarros0km (TCarro ag[], int quantidade);
int removerCarroEstoque (TCarro ag[], int *quantidade, char placa[]);

void preencherVetor (TCarro ag[]);
void exibirDadosCarro (TCarro carro);
void exibirTodosCarros (TCarro ag[], int quantidade);

//main
void main ()
{
	//declaração de variáveis
	TCarro agencia[TAM];	
	int quantCarros = TAM, quant;
	
	//preenchendo o vetor para que as demais funções possam ser testadas
	preencherVetor (agencia);
		
	//exibindo os carros que atenderem aos filtros definidos
	
	//Chamada 1
	printf ("Chamada 1 (exibindo carros por filtro):\n");
	quant = exibirCarros (agencia, quantCarros, "HB20", 2016, 2020, 38000);
	
	if (quant == 0)
	{
		printf ("\n\tNenhum carro atende aos filtros especificados.");
	}
	
	//Chamada 2
	printf ("Chamada 2 (exibindo carros por filtro):\n");
	quant = exibirCarros (agencia, quantCarros, "CRETA", 2016, 2020, 38000);
	
	if (quant == 0)
	{
		printf ("\n\tNenhum carro atende aos filtros especificados.");
	}
	
	//chamando a função que reajustará os carros 0km
	reajustarCarros0km (agencia, quantCarros);
	
	//exibindo os carros após o reajuste
	printf ("\n\nExibindo os carros apos o reajuste:\n");
	exibirTodosCarros (agencia, quantCarros);

	//Chamada 1
	printf ("Chamada 1 (remvendo carro do estoque):\n");
	if (removerCarroEstoque (agencia, &quantCarros, "XYZ 1234") == TRUE)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agencia, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca não localizada!\n\n");
	}
	
	//Chamada 2
	printf ("Chamada 2 (remvendo carro do estoque):\n");
	if (removerCarroEstoque (agencia, &quantCarros, "CDE 3456") == TRUE)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agencia, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca não localizada!\n\n");
	}
}

//implementação das funções

void preencherVetor (TCarro ag[])
{
	//1º carro
	strcpy (ag[0].placa, "ABC 1234");
	strcpy (ag[0].modelo, "HB20");
	strcpy (ag[0].marca, "HYUNDAI");
	strcpy (ag[0].cor, "PRATA");
	ag[0].km = 20000;
	ag[0].ano.anoModelo = 2016;
	ag[0].ano.anoFabricacao = 2015;
	ag[0].valor = 25000;
	ag[0].tipo = USADO;	
	
	//2º carro
	strcpy (ag[1].placa, "BCD 2345");
	strcpy (ag[1].modelo, "CIVIC");
	strcpy (ag[1].marca, "HONDA");
	strcpy (ag[1].cor, "BRANCA");
	ag[1].km = 0;
	ag[1].ano.anoModelo = 2022;
	ag[1].ano.anoFabricacao = 2022;
	ag[1].valor = 90000;
	ag[1].tipo = ZERO;	
	
	//3º carro
	strcpy (ag[2].placa, "CDE 3456");
	strcpy (ag[2].modelo, "HB20");
	strcpy (ag[2].marca, "HYUNDAI");
	strcpy (ag[2].cor, "PRETA");
	ag[2].km = 45000;
	ag[2].ano.anoModelo = 2017;
	ag[2].ano.anoFabricacao = 2017;
	ag[2].valor = 35000;
	ag[2].tipo = USADO;	
	
	//4º carro
	strcpy (ag[3].placa, "EFG 4567");
	strcpy (ag[3].modelo, "HB20");
	strcpy (ag[3].marca, "HYUNDAI");
	strcpy (ag[3].cor, "AZUL");
	ag[3].km = 58000;
	ag[3].ano.anoModelo = 2019;
	ag[3].ano.anoFabricacao = 2018;
	ag[3].valor = 40000;
	ag[3].tipo = USADO;	
	
	//5º carro
	strcpy (ag[4].placa, "FGH 5678");
	strcpy (ag[4].modelo, "ECOSPORT");
	strcpy (ag[4].marca, "FORD");
	strcpy (ag[4].cor, "VERDE");
	ag[4].km = 0;
	ag[4].ano.anoModelo = 2022;
	ag[4].ano.anoFabricacao = 2022;
	ag[4].valor = 85000;
	ag[4].tipo = ZERO;	
}

void exibirDadosCarro (TCarro carro)
{
	printf ("\nPlaca: %s\n", carro.placa);
	printf ("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf ("Cor: %s\n", carro.cor);
	printf ("km: %.2f\n", carro.km);
	printf ("Ano: %d/%d\n", carro.ano.anoFabricacao, carro.ano.anoModelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: ");
	printf (carro.tipo==USADO?"Usado\n\n":"Zero\n\n");	
}

void exibirTodosCarros (TCarro ag[], int quantidade)
{
	//declaração de variáveis
	int i, cont=0;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (ag[i]);
	}
}

/*Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor 
  não superior a x reais.*/
int exibirCarros (TCarro ag[], int quantidade, char modelo[20], int anoI, int anoF, float valorLimite)
{
	//declaração de variáveis
	int i, cont=0;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro armazenado na posição 'i' atende aos filtros
		if ((strcmp(ag[i].modelo,modelo)==0) && 		//verificando o modelo
		    (ag[i].ano.anoFabricacao >= anoI) && 
			(ag[i].ano.anoFabricacao <= anoF) &&		//verificando o ano de fabricação
			(ag[i].valor <= valorLimite))				//verificando o valor do carro
		{
			exibirDadosCarro (ag[i]);
			cont++;
		}
	}
	
	//retornando a quantidade de carros exibidos
	return cont;
}
  
//Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%.
void reajustarCarros0km (TCarro ag[], int quantidade)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro é zero
		if (ag[i].tipo == ZERO)
		{
			ag[i].valor = 1.025*ag[i].valor;
		}
	}	
}

//Retirar do estoque um determinado veículo, dada a sua placa.
int removerCarroEstoque (TCarro ag[], int *quantidade, char placa[])
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<*quantidade;i++)
	{
		//verificando se a placa foi encontrada
		if (strcmp(ag[i].placa, placa)==0)
		{
			//copiando o último carro para a posição sendo removida
			ag[i] = ag[(*quantidade)-1];
			
			//atualizando a quantidade de carros
			(*quantidade)--;
			
			//retornando TRUE, pois houve sucesso na tentativa de remoção
			return TRUE;
		}
	}	
	
	//fracasso na tentativa de remoção
	return FALSE;
}

