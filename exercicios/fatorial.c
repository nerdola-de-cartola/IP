#include <stdio.h>

unsigned long calculaFatorial(unsigned int number);

int main(void)
{
	unsigned int number;
	unsigned long fatorial;

	printf("Number: ");
	scanf("%u", &number);
	fatorial = calculaFatorial(number);
	printf("!%u = %lu \n", number, fatorial);
}

unsigned long calculaFatorial(unsigned int number)
{
	if (number == 1)
	{
		return 1;
	}
	else
	{
		return number * calculaFatorial(number - 1);
	}
}