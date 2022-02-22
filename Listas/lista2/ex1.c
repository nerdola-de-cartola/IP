#include <stdio.h>

int main(void) {
    int total_de_leituras;
    scanf("%d", &total_de_leituras);

    double temp_fahrenheit[total_de_leituras];
    double temp_celsius[total_de_leituras];

    int i;
    while (i < total_de_leituras)
    {
        scanf("%lf", &temp_fahrenheit[i]);
        temp_celsius[i] = 5*(temp_fahrenheit[i] - 32) / 9;
        i++;
    }
    
    int j;
    while (j < total_de_leituras)
    {
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", temp_fahrenheit[j], temp_celsius[j]);
        j++;
    }
    
    return 0;
}