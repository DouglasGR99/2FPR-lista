/*
	
	QUESTÃO 01:
	Desenvolver uma função que exiba os múltiplos
	de N compreendidos no intervalo definido por
	A e B.

*/

#include <stdio.h>

void exibir(int n,int a, int b);

void main()
{
	int n,a,b;
	
	printf("insira \"valores\" para n, a e b:\n");
	scanf("%d%d%d",&n,&a,&b);
	exibir(n,a,b);
}


void exibir(int n,int a, int b)
{
	int i;
	for(i=a;i<=b;i++)
	{
		if(i%n==0)
		{
			printf(" %d",i);
		}
	}
}
