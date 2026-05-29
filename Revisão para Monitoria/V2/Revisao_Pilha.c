#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int info;
    struct LSE* proximo;
}LSE;

typedef struct Pilha{
    LSE* topo;
    struct Pilha* proximo;
}Pilha;

///////// FUNÇÕES LISTA ////////////
LSE* novo_no_lista(int valor);
LSE* ultimo_no_lista(LSE* lista);
LSE* inserir_final_lista(LSE* lista, int valor);
void printar_lista(LSE* lista);
LSE* liberar_lista(LSE* lista);

///////// FUNÇÕES PILHA ////////////
Pilha* novo_no_pilha(LSE* lista);
Pilha* empilhar(Pilha* topo, LSE* lista);
Pilha* desempilhar(Pilha* topo);
void mostrar_pilha(Pilha* topo);

void menu();

int main() {
    LSE* lista = NULL;
    Pilha* pilha = NULL;
    int num, opcao = 1;

    while (opcao != 0) {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nDigite os numeros para a lista (finalize com 0):\n");
            while (scanf("%d", &num) == 1 && num != 0) {
                lista = inserir_final_lista(lista, num);
            }
            while(getchar() != '\n');
            printf("\nLista criada com sucesso!\n\n");
            break;
        case 2:
            printf("\nLista atual:\n");
            printar_lista(lista);
            break;
        case 3:
            if(lista != NULL){
                pilha = empilhar(pilha, lista);
                lista = NULL;
                printf("\nLista empilhada com sucesso.\n\n");
            }else{
                printf("\nLista vazia! Crie uma lista primeiro.\n\n");
            }
            break;
        case 4:
            pilha = desempilhar(pilha);
            break;
        case 5:
            printf("\nEstado da pilha:\n");
            mostrar_pilha(pilha);
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpção invalida.\n\n");
            break;
        }
    }
    return 0;
}

void menu(){
    printf("\n-------MENU PILHA-------\n");
    printf("1-> Criar lista\n");
    printf("2-> Mostrar Lista\n");
    printf("3-> Empilar\n");
    printf("4-> Desempilhar\n");
    printf("5-> Mostrar Pilha\n");
    printf("0-> Sair\n\n");
}

/////////////////////////////FUNÇÕES LISTA/////////////////////////////

LSE* novo_no_lista(int valor){
    LSE* no = malloc(sizeof(LSE));

    no->info = valor;
    no->proximo = NULL;

    return no;
}

LSE* ultimo_no_lista(LSE* lista){
    LSE* ultimo = NULL;

    if (lista != NULL){
        ultimo = lista;

        while (ultimo->proximo != NULL){
            ultimo = ultimo->proximo;
        }
    }
    return ultimo;
}

LSE* inserir_final_lista(LSE* lista, int valor){
    LSE* novo = novo_no_lista(valor);

    if (lista == NULL){
        lista = novo;
    }else{
        LSE* ultimo = ultimo_no_lista(lista);
        ultimo->proximo = novo;
    }
    return lista;
}

void printar_lista(LSE* lista){
    if (lista != NULL){
        LSE* aux = lista;

        while (aux != NULL){
            printf("%d->", aux->info);
            aux = aux->proximo;
        }
        printf("NULL\n\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LSE* liberar_lista(LSE* lista){
    LSE* aux = lista;

    if (lista != NULL){
        while(lista != NULL){
            aux = lista;
            lista = lista->proximo;
            free(aux);
        }
    }
    lista = NULL;
    return lista;
}

/////////////////////////////FUNÇÕES PILHA/////////////////////////////

Pilha* novo_no_pilha(LSE* lista){
    Pilha* no_pilha = malloc(sizeof(Pilha));

    no_pilha->topo = lista;
    no_pilha->proximo = NULL;

    return no_pilha;
}

Pilha* empilhar(Pilha* topo, LSE* lista){
    Pilha* novo = novo_no_pilha(lista);

    if (topo == NULL){
        topo = novo;
    }else{
        novo->proximo = topo;
        topo = novo;
    }

    return topo;
}

Pilha* desempilhar(Pilha* topo){
    if (topo != NULL){
        printf("\nDesempilhando elemento:\n");
        printar_lista(topo->topo);

        topo->topo = liberar_lista(topo->topo);

        Pilha* novo_topo = topo->proximo;
        free(topo);

        topo = novo_topo;
        printf("\n");
    }else{
        printf("Pilha Vazia\n\n");
    }

    return topo;
}

void mostrar_pilha(Pilha* topo){
    if (topo != NULL){
        printf("Estado da pilha do topo para a base\n\n");

        Pilha* atual = topo;
        int posicao = 1;

        while (atual != NULL){
            printf("Elemento %d:\n", posicao);
            printar_lista(atual->topo);
            atual = atual->proximo;
            posicao++;
        }
        printf("\n");
    }else{
        printf("\nPilha Vazia\n");
    }
}
