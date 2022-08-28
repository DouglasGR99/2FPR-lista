/*

	QUESTÃO 1
	Suponha que não existem as funções strlen,
	strcpy, strcat, strcmp. Pede-se então a
	implementação de funções que tenham o mesmo
	objetivo daquelas.

*/

#include <stdio.h>
#include <string.h>
#define TAM 30

int len(char s[]);
void cpy(char s1[],char s2[]);
void cat(char s1[],char s2[]);
int cmp(char s1[],char s2[]);


void main(){
	int opc,retorno;;
	char s1[TAM],s2[TAM];
	printf("Insira uma palavra para s1 e outra para s2:\n");
	fflush(stdin);
	gets(s1);
	gets(s2);
	printf("Realizar:\n strlen = 1\n strcpy = 2\n strcat = 3\n strcmp = 4\n\n");
	scanf("%d",&opc);
	
	switch(opc){
		case 1:printf("\n o tamanho e: %d",len(s1));
			break;
			
		case 2:cpy(s1,s2);
			break;
			
		case 3:cat(s1,s2);
			break;
			
		case 4: 
			retorno=cmp(s1,s2);
			if (retorno == 0){
				printf ("\n\nAs strings %s e %s sao iguais!",s1,s2);
			}
			else{
				printf ("\n\nAs strings %s e %s nao sao iguais!",s1,s2);
				printf (" (retorno = %d)",retorno);
			}
			break;
			
	}
	
	printf("\n %s",s1);
	printf(" %s",s2);
}


int len(char s[]){
	int i;
	
	for(i=0;s[i]!='\0';i++);
	return i;
}



void cpy(char s1[],char s2[]){
	int i;
	
	//s2[i]==0
	for(i=0;s2[i];i++){
		s1[i]=s2[i];
	}
	
	//s1 nao fica com o resto de s2
	s1[i]='\0';
}


void cat(char s1[],char s2[]){
	int i,j;
	for (i=len(s1),j=0;s2[j];i++,j++){
		s1[i] = s2[j];
	}
	s1[i]='\0';
}


int cmp(char s1[],char s2[]){
	int i;
	for (i=0;(s1[i]==s2[i])&&(s1[i])&&(s2[i]);i++);
	return s1[i]-s2[i];
}
