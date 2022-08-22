/*

	QUESTÃO 03:
	Desenvolver uma função que calcule o n-ésimo
	termo da sequência de Fibonacci.

*/

#include <stdio.h>

int fibonacci(int n);

void main(){
	int n;
	printf("Insira o termo:\n");
	scanf("%d",&n);
	printf("\nO N-esimo termo e %d.",fibonacci(n));
}

int fibonacci(int n){
	int i,j=0,k=1,l=0;
	for(i=0;i<=n;i++){
		
		l=k;
		k=j;
		j=k+l;
	
	}
	return l;
}
