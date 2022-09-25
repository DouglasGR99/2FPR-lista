/*

	QUESTÃO 02:
	Implementar uma função que converta
	determinada temperatura em graus Celsius
	para graus Fahrenheit.

*/

#include <stdio.h>

float celToFah(float cel);

void main()
{
	float cel;
	printf("Insira temperatura em celsius:\n");
	scanf("%f",&cel);
	printf("%.2f graus fahrenheit.",celToFah(cel));
}

float celToFah(float cel)
{
	float fah;
	return fah=(cel*9/5)+32;
}
