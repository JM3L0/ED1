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

    int x;

    scanf("%d", &x);

    for (int i = 0; i < N; i++)
    {
        if (vet[i] % x == 0)
        {
            vet[i] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", vet[i]);
    }

    return 0;
}