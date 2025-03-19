#include<stdio.h>

typedef struct{
    int id;
    char nome[50];
    float preco;
}Produto;

int main(){

    int n;
    scanf("%d", &n);

    Produto produto[n];

    for (int i = 0; i < n; i++){
        printf("Digite o Id do produto: ");
        scanf("%d", &produto[i].id);
        printf("Digite o nome: ");
        scanf(" %[^\n]", produto[i].nome);
        printf("Digite o preco: ");
        scanf("%f", &produto[i].preco);
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("Id do produto: %d\n", produto[i].id);
        printf("Nome do produto: %s\n", produto[i].nome);
        printf("Preco do produto: %.2f\n", produto[i].preco);
    }

    printf("\n");
    
    return 0;
}