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
void eh_palindramo(LDP* lista);

int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    eh_palindramo(lista);

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

void eh_palindramo(LDP* lista){
    
    if (lista != NULL){

        LDP* esquerda = lista;
        LDP* direita = ultimo_no(lista);
        int verifica = 1;

        while(esquerda != direita && esquerda->proximo != direita){
            
            if (esquerda->valor != direita->valor){
                verifica = 0;
            }
            
            esquerda = esquerda->proximo;
            direita = direita->anterior;

        }
        
        if (verifica == 1){
            printf("Eh palindrama\n\n");
        }else{
            printf("Nao eh palindrama\n\n");
        }
    }else{
        printf("Eh palindrama\n\n");
    }
}