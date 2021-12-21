#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    long int num;
    bool divisivel_por_3 = false;
    bool divisivel_por_5 = false;

    printf("Dite um número: ");
    scanf("%ld", &num);

    if (num % 3 == 0)
    {
        divisivel_por_3 = true;
    }
    if (num % 5 == 0)
    {
        divisivel_por_5 = true;
    }
    if (divisivel_por_3 && divisivel_por_5)
    {
        printf("O número %ld é divisível por 3 e por 5 \n", num);
    }
    else
    {
        printf("O número %ld não é divisível por 3 e por 5 \n", num);
    }
    
    return 0;
}
