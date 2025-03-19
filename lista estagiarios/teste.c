#include <stdio.h>

#define MAX 100

int main() {
    int tam;
    printf("Digite o tamanho do array: ");
    if (scanf("%d", &tam) != 1 || tam <= 0 || tam > MAX) {
        printf("Entrada inválida.\n");
        return 1;
    }

    int vet[MAX];

    printf("Digite os elementos do array: ");
    for (int i = 0; i < tam; i++) {
        if (scanf("%d", &vet[i]) != 1) {
            printf("Entrada inválida.\n");
            return 1;
        }
    }

    for (int j = 1; j < tam; j++) {
        if (vet[j - 1] == vet[j]) {
            for (int k = j - 1; k < tam - 1; k++) {
                vet[k] = vet[k + 1];
            }
            tam--;
            j--;
        }
    }

    printf("Array sem duplicatas: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}