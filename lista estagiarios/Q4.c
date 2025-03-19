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

    for (int i = 0; i < N; i++)
    {
        printf("%d ", (vet[i] * -1));
    }

    return 0;
}