#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int info;
    struct LSE* proximo;
}LSE;

typedef struct Fila{
    LSE* inicio;
    LSE* fim;
}Fila;

///////// FUNÇÕES LISTA ////////////
LSE* novo_no_lista(int valor);
void printar_lista(LSE* lista);
LSE* liberar_lista(LSE* lista);

///////// FUNÇÕES FILA ////////////
Fila* criar_fila();
Fila* enfileirar(Fila* fila, int valor);
Fila* desenfileirar(Fila* fila);
void mostrar_fila(Fila* fila);
Fila* liberar_fila(Fila* fila);

void menu();

int main() {
    Fila* fila = criar_fila();
    int num, opcao = 1;

    while (opcao != 0) {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:{
            printf("\nDigite um numero para enfileirar: ");
            scanf("%d", &num);
            fila = enfileirar(fila, num);
            printf("Elemento enfileirado com sucesso!\n\n");
            break;
        }
        case 2:
            fila = desenfileirar(fila);
            break;
        case 3:{
            if(fila->inicio != NULL){
                printf("\nPrimeiro elemento da fila: %d\n\n", fila->inicio->info);
            }else{
                printf("\nFila vazia!\n\n");
            }
            break;
        }
        case 4:
            printf("\nEstado da fila:\n");
            mostrar_fila(fila);
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            fila = liberar_fila(fila);
            break;
        default:
            printf("\nOpção invalida.\n\n");
            break;
        }
    }
    return 0;
}

void menu(){
    printf("\n-------MENU FILA-------\n");
    printf("1-> Enfileirar\n");
    printf("2-> Desenfileirar\n");
    printf("3-> Ver primeiro elemento\n");
    printf("4-> Mostrar Fila\n");
    printf("0-> Sair\n\n");
}

/////////////////////////////FUNÇÕES LISTA/////////////////////////////

LSE* novo_no_lista(int valor){
    LSE* no = malloc(sizeof(LSE));

    no->info = valor;
    no->proximo = NULL;

    return no;
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
        printf("Fila Vazia\n\n");
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

/////////////////////////////FUNÇÕES FILA/////////////////////////////

Fila* criar_fila(){
    Fila* fila = malloc(sizeof(Fila));

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

Fila* enfileirar(Fila* fila, int valor){
    LSE* novo = novo_no_lista(valor);

    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    return fila;
}

Fila* desenfileirar(Fila* fila){
    if(fila->inicio == NULL){
        printf("Fila Vazia!\n\n");
    }else{
        LSE* temp = fila->inicio;
        printf("\nDesenfileirando elemento: %d\n\n", temp->info);

        fila->inicio = fila->inicio->proximo;

        if(fila->inicio == NULL){
            fila->fim = NULL;
        }

        free(temp);
    }

    return fila;
}

void mostrar_fila(Fila* fila){
    if(fila->inicio == NULL){
        printf("Fila Vazia\n\n");
    }else{
        printf("Estado da fila (inicio para fim):\n");
        printar_lista(fila->inicio);
    }
}

Fila* liberar_fila(Fila* fila){
    if(fila != NULL){
        fila->inicio = liberar_lista(fila->inicio);
        fila->fim = NULL;
        free(fila);
    }
    printf("Fila Liberada\n");
    return NULL;
}
