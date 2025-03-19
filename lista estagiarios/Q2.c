#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    int vet[100];

    for (int i = 0; i < 100; i++)
    {
        int numero_aleatorio = (rand() % 100) + 1;
        vet[i] = numero_aleatorio;
    }

    int N;

    scanf("%d", &N);

    for (int i = 0; i < 100; i++)
    {
        if (vet[i] <= N)
        {
            printf("Posicao: %d, Valor: %d\n", i, vet[i]);
        }
    }

    return 0;
}