#include<stdio.h>
#include<stdlib.h>

void SelectionSort (int vet[], int n);

int main(){

    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet [n];

    for (int i = 0; i < n; i++){
        printf("Digite o elemento %d:", i+1);
        scanf("%d", &vet[i]);
    }

    SelectionSort(vet, n);

    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}

void SelectionSort (int vet[], int n){
    for (int i = 0; i < n-1; i++){
        int menor = i;
        for (int j = i + 1; j < n; j++){
            if (vet[j] < vet[menor]){
                menor = j;
            }
        }

        if (menor != i){
            int temp = vet[menor];
            vet[menor] = vet[i];
            vet[i] = temp;
        }
    }
}