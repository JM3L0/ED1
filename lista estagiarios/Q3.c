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

    int i = 0, j = N - 1, temp;

    while (i < j)
    {
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;

        i++;
        j--;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}