#include<stdio.h>
#include<stdlib.h>

void InserctionSort (int vet[], int n);

int main(){

    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet [n];

    for (int i = 0; i < n; i++){
        printf("Digite o elemento %d:", i+1);
        scanf("%d", &vet[i]);
    }

    InserctionSort(vet, n);

    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}

void InserctionSort (int vet[], int n){

    int j, chave;

    for (int i = 1; i < n; i++){
        chave = vet[i];
        j = i-1;

        while (j >= 0 && vet[j] > chave){
            vet[j+1] = vet[j];
            j = j-1;
        }
        
        vet[j+1] = chave;
    }
}