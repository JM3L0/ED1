#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int info;
    struct LSE* proximo;
}LSE;

typedef struct Pilha{
    LSE* topo;
}Pilha;

///////// FUNÇÕES LISTA ////////////
LSE* novo_no_lista();
LSE* ultimo_no_lista(LSE* lista);
LSE* inserir_final_lista(LSE* lista, LSE* novo);
void printar_lista(LSE* lista);
LSE* liberar_lista(LSE* lista);

///////// FUNÇÕES PILHA ////////////
Pilha* criar_pilha();
Pilha* empilhar(Pilha* pilha, LSE* novo);
Pilha* desempilhar(Pilha* pilha);
void mostrar_pilha(Pilha* pilha);
Pilha* liberar_pilha(Pilha* pilha);

void menu();

int main() {
    Pilha* pilha = criar_pilha();
    int num, opcao = 1;

    while (opcao != 0) {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:{
            printf("\nDigite um numero para empilhar: ");
            scanf("%d", &num);
            LSE* novo = novo_no_lista();
            if(novo){
                novo->info = num;
                pilha = empilhar(pilha, novo);
                printf("Elemento empilhado com sucesso!\n\n");
            }
            break;
        }
        case 2:
            pilha = desempilhar(pilha);
            break;
        case 3:
            printf("\nEstado da pilha:\n");
            mostrar_pilha(pilha);
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            pilha = liberar_pilha(pilha);
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
    printf("1-> Empilhar\n");
    printf("2-> Desempilhar\n");
    printf("3-> Mostrar Pilha\n");
    printf("0-> Sair\n\n");
}

/////////////////////////////FUNÇÕES LISTA/////////////////////////////

LSE* novo_no_lista(){
    LSE* no = malloc(sizeof(LSE));

    if(no){
        no->proximo = NULL;
    }else{
        printf("Erro de alocacao\n");
    }

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

LSE* inserir_final_lista(LSE* lista, LSE* novo){
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

Pilha* criar_pilha(){
    Pilha* pilha = malloc(sizeof(Pilha));

    pilha->topo = NULL;

    return pilha;
}

Pilha* empilhar(Pilha* pilha, LSE* novo){
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return pilha;
}

Pilha* desempilhar(Pilha* pilha){
    if (pilha->topo != NULL){
        printf("\nDesempilhando elemento: %d\n\n", pilha->topo->info);

        LSE* temp = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(temp);
    }else{
        printf("Pilha Vazia\n\n");
    }

    return pilha;
}

void mostrar_pilha(Pilha* pilha){
    if (pilha->topo != NULL){
        printf("Estado da pilha (topo para base):\n");
        printar_lista(pilha->topo);
    }else{
        printf("\nPilha Vazia\n\n");
    }
}

Pilha* liberar_pilha(Pilha* pilha){
    if(pilha != NULL){
        pilha->topo = liberar_lista(pilha->topo);
        free(pilha);
    }
    printf("Pilha Liberada\n");
    return NULL;
}
