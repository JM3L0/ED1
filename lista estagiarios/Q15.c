#include <stdio.h>

void ordenaVetor(int N, int *vet)
{
    int temp;
    int i = 0;

    while (i < N - 1){
        if (i >= 0 && vet[i] > vet[i + 1])
        {
            temp = vet[i + 1];
            vet[i + 1] = vet[i];
            vet[i] = temp;
            i--;
        }else{
            i++;
        }
    }
}

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

    ordenaVetor(N, vet_A);
    ordenaVetor(N, vet_B);

    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        if (vet_A[i] == vet_B[i])
        {
            cont++;
        }
    }

    if (cont == N)
    {
        printf("E permutacao\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", vet_A[i]);
        }
        printf("\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", vet_B[i]);
        }
    }
    else
    {
        printf("Nao eh permutacao\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", vet_A[i]);
        }
        printf("\n");
        for (int i = 0; i < N; i++)
        {
            printf("%d ", vet_B[i]);
        }
    }
    return 0;
}