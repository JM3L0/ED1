#include<stdio.h>
#include<stdlib.h>

typedef struct LDP{
    
    int valor;
    struct LDP* anterior;
    struct LDP* proximo;

}LDP;

LDP* novo_no(int valor);
LDP* ultimo_no(LDP* lista);
LDP* inserir_final(LDP* lista, int valor);
void printar_lista(LDP* lista);
LDP* liberar_lista(LDP* lista);
LDP* novo_no_apois_cada_no(LDP* lista, int valor);

int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    printf("Digite o valor a ser inserido apos cada no: ");
    scanf("%d", &num);

    lista = novo_no_apois_cada_no(lista, num);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);
    
    return 0;
}

LDP* novo_no(int valor){
    LDP* no = malloc(sizeof(LDP));

    no->valor = valor;
    no->anterior = NULL;
    no->proximo = NULL;

    return no;
}

LDP* ultimo_no(LDP* lista){
    LDP* ultimo = NULL;

    if (lista != NULL){
        ultimo = lista;

        while (ultimo->proximo != NULL){
            ultimo = ultimo->proximo;
        }
    }
    return ultimo;
}

LDP* inserir_final(LDP* lista, int valor){
    LDP* novo = novo_no(valor);

    if (lista == NULL){

        lista = novo;
    
    }else{

        LDP* ultimo = ultimo_no(lista);

        novo->proximo = ultimo->proximo;
        novo->anterior = ultimo;
        ultimo->proximo = novo;

    }
    return lista;
}

void printar_lista(LDP* lista){

    if (lista != NULL){
        
        LDP* aux = lista;

        printf("\nNULL<->");
        while (aux != NULL){

            printf("%d<->", aux->valor);
            aux = aux->proximo;

        }
        printf("NULL\n\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LDP* liberar_lista(LDP* lista){

    if (lista != NULL){
        LDP* aux;

        while (lista != NULL){
            
            aux = lista;
            lista = lista->proximo;
            free(aux);

        }
    }
    return lista;
}

LDP* novo_no_apois_cada_no(LDP* lista, int valor){

    if (lista != NULL){
        
        LDP* aux = lista;

        while (aux->proximo != NULL){
            
            LDP* novo = novo_no(valor);

            novo->anterior = aux;
            novo->proximo = aux->proximo;

            aux = aux->proximo;

            aux->anterior->proximo = novo;
            aux->anterior = novo;
        }

        LDP* novo = novo_no(valor);

        aux->proximo = novo;
        novo->anterior = aux;
    }
    return lista;
}