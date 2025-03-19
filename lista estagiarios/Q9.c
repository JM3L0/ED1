#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int vet[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vet[i]);
    }

    int soma = 0;

    for (int i = 0; i < N; i++)
    {
        if (vet[i] % 2 == 0)
        {
            soma += vet[i];
        }
    }

    printf("%d", soma);

    return 0;
}