#include <stdio.h>

#define PI 3.14

float calculaCircunferencia(float raio);
float calculaArea(float raio);

int main(void)
{
	float raio;
	printf("Raio da circunferência: ");
	scanf("%f", &raio);

	float circunferencia = calculaCircunferencia(raio);
	float area = calculaArea(raio);

	printf("Comprimento da circunferência: %.2fm\n", circunferencia);
	printf("Área da circunferência: %.2fm^2\n", area);
		
}

float calculaCircunferencia(float raio)
{
	return 2 * raio * PI;
}

float calculaArea(float raio)
{
	return PI * raio * raio;
}
