#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vetor[3];
    struct Node* next;
} Node;

// Função para criar um novo nó com um vetor dado
Node* criarNo(int vetor[3]) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < 3; i++) {
        novoNo->vetor[i] = vetor[i];
    }
    novoNo->next = NULL;
    return novoNo;
}

// Função para adicionar um nó ao final da lista
void adicionarNo(Node** head, int vetor[3]) {
    Node* novoNo = criarNo(vetor);
    if (*head == NULL) {
        *head = novoNo;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
    }
}

// Função para imprimir a lista
void imprimirLista(Node* head) {
    while (head != NULL) {
        printf("[%d, %d, %d] ", head->vetor[0], head->vetor[1], head->vetor[2]);
        head = head->next;
    }
    printf("\n");
}

// Função para reorganizar a lista
void reorganizarLista(Node** head, int vetorBuscado[3]) {
    Node *temp = *head, *anterior = NULL, *ultimo = NULL;
    Node *inicioOriginal = *head;
    
    // Encontrando o nó com o vetor buscado e o último nó da lista
    while (temp != NULL) {
        ultimo = temp;
        if (temp->vetor[0] == vetorBuscado[0] && temp->vetor[1] == vetorBuscado[1] && temp->vetor[2] == vetorBuscado[2]) {
            break;
        }
        anterior = temp;
        temp = temp->next;
    }
    
    // Se o vetor buscado não for encontrado ou está no início, nada a ser feito
    if (temp == NULL || anterior == NULL) return;

    // Conectando a parte após o vetor buscado ao início da lista
    *head = temp;
    if (ultimo) ultimo->next = inicioOriginal;
    anterior->next = NULL; // Desconectar a lista antes do vetor encontrado
}

int main() {
    Node* head = NULL;

    int vetor1[] = {5, 3, 8};
    int vetor2[] = {2, 1, 6};
    int vetor3[] = {9, 4, 7};
    int vetor4[] = {10, 11, 12};
    int vetor5[] = {15, 14, 13};

    adicionarNo(&head, vetor1);
    adicionarNo(&head, vetor2);
    adicionarNo(&head, vetor3);
    adicionarNo(&head, vetor4);
    adicionarNo(&head, vetor5);

    printf("Lista original:\n");
    imprimirLista(head);

    int vetorBuscado[] = {9, 4, 7};
    reorganizarLista(&head, vetorBuscado);

    printf("Lista após reorganização:\n");
    imprimirLista(head);

    return 0;
}
