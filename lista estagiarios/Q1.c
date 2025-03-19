#include <stdio.h>

int main()
{
    int vet[10], tamanho, maior_valor, posicao_maior, menor_valor = 0, posicao_menor = 0;

    scanf("%d", &tamanho);


    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vet[i]);
    }

    maior_valor = vet[0];
    menor_valor = vet[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (vet[i] > maior_valor)
        {
            maior_valor = vet[i];
            posicao_maior = i;
        }

        if (vet[i] < menor_valor)
        {
            menor_valor = vet[i];
            posicao_menor = i;
        }
    }

    printf("Maior valor: %d na posicao: %d\n", maior_valor, posicao_maior);
    printf("Menor valor: %d na posicao: %d\n", menor_valor, posicao_menor);

    return 0;
}