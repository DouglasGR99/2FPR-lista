/*
	
	QUESTÃO 04:
	Fazer uma função que calcule o MDC (máximo
	divisor comum) entre dois números.

*/

#include <stdio.h>

int mdc(int n1,int n2);

void main()
{
	int n1,n2;
	printf("Insira n1 e n2:\n");
	scanf("%d%d",&n1,&n2);
	printf("\nO mdc dos numeros: %d",mdc(n1,n2));
}

int mdc(int n1,int n2){
	int i,j,res1,res2;
	
/*
	O primeiro numero que dividido pelos 2
	der resto = 0 sera o mdc.
*/
	
	for(i=n1;i>=1;i--)
	{
		
		res1=n1%i;
		printf("\ni=%d",i);
		for(j=n2;j>=1;j--)
		{
			
			res2=n2%j;
			printf(" j=%d",j);
			if(res1==0&&res2==0&&j==i)
			{
				return j;
			}
		}
	}
}
