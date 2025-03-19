#include<stdio.h>
#include<stdlib.h>

typedef struct LDE{

    int valor;
    struct LDE* anterior;
    struct LDE* proximo;

}LDE;

LDE* novo_no(){
    LDE* no = malloc(sizeof(LDE));
    return no;
}

LDE* inserir_inicio(LDE* lista, int valor){

    LDE* novo = novo_no();

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if(lista == NULL){
        lista = novo;
    }else{
        novo->proximo = lista;
        lista->anterior = novo;
        lista = novo;
    }

    return lista;
}

LDE* inserir_final(LDE* lista, int valor){

    LDE* novo = novo_no();

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if(lista == NULL){
        lista = novo;
    }else{

        LDE* aux = lista;

        while (aux->proximo !=  NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo;
        novo->anterior = aux;
    }

    return lista;
}

void imprimir_lista(LDE* lista){

    LDE* aux = lista;

    printf("NULL <=> ");
    while (aux != NULL){
        printf("%d <=> ", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

void imprimir_invertido(LDE* lista){

    LDE* aux = lista;

    while (aux != NULL){
        aux = aux->proximo;
    }

    while (aux->anterior != NULL){
        printf("%d<=>", aux->valor);
        aux = aux->anterior;
    }
    printf("NULL\n");
}

int main(){

    LDE* lista = NULL;
    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }
    while(getchar() != '\n');

    imprimir_lista(lista);
    

    return 0;
}