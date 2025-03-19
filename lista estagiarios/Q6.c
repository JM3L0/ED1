#include <stdio.h>

int main()
{
    float vet[10];

    scanf("%f", &vet[0]);

    for (int i = 1; i < 100; i++)
    {
        vet[i] = vet[i - 1] / 2;
    }

    for (int i = 0; i < 100; i++)
    {
        printf("%f ", vet[i]);
    }

    return 0;
}