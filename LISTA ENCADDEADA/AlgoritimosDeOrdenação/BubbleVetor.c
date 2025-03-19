#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int vet[], int n);

int main(){


    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite o vetor:\n");

    for (int i = 0; i < n; i++){
        printf("Digite o elemento %d: ", i+1);
        scanf("%d", &vet[i]);
    }

    bubble_sort(vet, n);

    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void bubble_sort(int vet[], int n){

    int temp;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            
            if (vet[i] > vet[j]){
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}