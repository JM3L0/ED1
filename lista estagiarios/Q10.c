#include <stdio.h>

int main()
{

    int N;
    scanf("%d", &N);

    int vet_A[N], vet_B[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vet_A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vet_B[i]);
    }

    int vet_C[N];

    for (int i = 0; i < N; i++)
    {
        vet_C[i] = vet_A[i] + vet_B[i];
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", vet_C[i]);
    }

    return 0;
}