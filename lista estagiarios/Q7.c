#include <stdio.h>

int main()
{

    int T;
    scanf("%d", &T);

    int vet[1000];

    int posicao = 0;

    while (posicao < 1000)
    {
        for (int i = 0; i < T; i++)
        {
            vet[posicao] = i;
            posicao++;
        }
    }

    for (int i = 0; i < 1000; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}