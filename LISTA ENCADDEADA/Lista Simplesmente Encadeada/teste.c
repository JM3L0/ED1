#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 3

typedef struct Lista_vetores {
    int vetor[TAM];
    struct Lista_vetores *proximo;
} Lista_vetores;

// Função para criar um novo nó com um vetor dado
Lista_vetores* criarNo(int vetor[TAM]) {
    Lista_vetores* novoNo = (Lista_vetores*)malloc(sizeof(Lista_vetores));
    for (int i = 0; i < TAM; i++) {
        novoNo->vetor[i] = vetor[i];
    }
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para adicionar um nó ao final da lista
void adicionar_vetor(Lista_vetores **head, int vetor[TAM]) {
    Lista_vetores* novoNo = criarNo(vetor);
    if (*head == NULL) {
        *head = novoNo;
    } else {
        Lista_vetores* temp = *head;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

// Função para imprimir a lista
void printar_lista_vetor(Lista_vetores* head) {
    Lista_vetores* temp = head;
    while (temp != NULL) {
        printf("[%d, %d, %d] ", temp->vetor[0], temp->vetor[1], temp->vetor[2]);
        temp = temp->proximo;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void liberar_memoria_vetor(Lista_vetores* head) {
    Lista_vetores* temp;
    while (head != NULL) {
        temp = head;
        head = head->proximo;
        free(temp);
    }
}

// Função para comparar vetores
bool comparar_vetores(int vetor_lista[TAM], int vetor[TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] != vetor_lista[i]) {
            return false;
        }
    }
    return true;
}

// Função para reorganizar a lista
void reorganizar_lista(Lista_vetores **head, int vetorBuscado[TAM]) {
    Lista_vetores *temp = *head, *anterior = NULL, *ultimo = NULL;
    Lista_vetores *inicioOriginal = *head;
    
    // Encontrar o nó com o vetor buscado e o último nó da lista
    while (temp != NULL) {
        ultimo = temp;
        if (comparar_vetores(temp->vetor, vetorBuscado)) {
            break;
        }
        anterior = temp;
        temp = temp->proximo;
    }
    
    // Se o vetor buscado não for encontrado ou está no início, nada a ser feito
    if (temp == NULL || anterior == NULL) return;

    // Conectar a parte após o vetor buscado ao início da lista
    *head = temp;
    if (ultimo) ultimo->proximo = inicioOriginal;
    anterior->proximo = NULL; // Desconectar a lista antes do vetor encontrado
}

int main() {
    Lista_vetores *list = NULL;
    int Vetor1[5][TAM] = {
        {5, 3, 8},
        {2, 1, 6},
        {9, 4, 7},
        {10, 11, 12},
        {15, 14, 13}
    };

    int vetor_escolhido[TAM] = {9, 4, 7};

    for (int i = 0; i < 5; i++) {
        adicionar_vetor(&list, Vetor1[i]);
    }
    
    printf("Lista original:\n");
    printar_lista_vetor(list);

    reorganizar_lista(&list, vetor_escolhido);

    printf("Lista após reorganização:\n");
    printar_lista_vetor(list);

    liberar_memoria_vetor(list);

    return 0;
}
