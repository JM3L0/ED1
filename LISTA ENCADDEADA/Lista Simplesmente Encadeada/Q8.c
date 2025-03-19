#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LSE {
    char nome[50];
    struct LSE* proximo;
} LSE;

LSE* novo_no() {
    LSE* no = malloc(sizeof(LSE));
    return no;
}

LSE* inserir_inicio(LSE* lista, char nome[50]) {
    LSE* novo = novo_no();
    if (novo) {
        strcpy(novo->nome, nome);
        novo->proximo = lista;
        lista = novo;
    } else {
        printf("Erro de alocacao\n");
    }
    return lista;
}

// Função para adicionar um nó no final da lista
void adicionar_no(LSE** lista, char nome[50]) {
    LSE* novo = novo_no();
    if (novo) {
        strcpy(novo->nome, nome);
        novo->proximo = NULL;

        if (*lista == NULL) {
            *lista = novo;
        } else {
            LSE* atual = *lista;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }
    } else {
        printf("Erro de alocacao\n");
    }
}

// Função para inverter os nós anterior e posterior ao nó escolhido
void reorganizar_nomes(LSE* lista, char* nome_a_buscar) {
    LSE* atual = lista;
    LSE* anterior = NULL;

    // Busca o nó que contém o nome_a_buscar
    while (atual != NULL && strcmp(atual->nome, nome_a_buscar) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Verificar se o nó foi encontrado e se há nós anterior e posterior para inverter
    if (atual == NULL || atual->proximo == NULL || anterior == NULL) return;

    LSE* proximo = atual->proximo;
    LSE* proximo_proximo = proximo->proximo;

    // Inverte o anterior e o próximo do nó escolhido
    anterior->proximo = proximo;
    proximo->proximo = atual;
    atual->proximo = proximo_proximo;
}

// Função para imprimir a lista
void imprimir_lista(LSE* lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
    } else {
        LSE* aux = lista;
        while (aux != NULL) {
            printf("%s -> ", aux->nome);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

// Função para liberar a memória da lista
void liberar_lista(LSE* lista) {
    LSE* aux = lista;
    LSE* aux2;
    while (aux != NULL) {
        aux2 = aux;
        aux = aux->proximo;
        free(aux2);
    }
}

int main() {
    LSE* lista = NULL;
    int n;
    char nome[50];

    printf("Digite o numero de nomes na lista: ");
    scanf("%d", &n);
    getchar();  // Limpar o buffer

    for (int i = 0; i < n; i++) {
        printf("Digite o nome %d: ", i + 1);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  // Remover o '\n' do final
        adicionar_no(&lista, nome);
    }

    // Nome a buscar para reorganizar
    printf("Digite o nome que deseja reorganizar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    reorganizar_nomes(lista, nome);

    // Imprimir a lista reorganizada
    printf("Lista reorganizada:\n");
    imprimir_lista(lista);

    // Liberar memória da lista
    liberar_lista(lista);

    return 0;
}
