#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    
    char* nome;
    struct NO* proximo;

}NO;

typedef struct FILA{
    
    NO* primeiro;
    NO* ultimo;

}FILA;

FILA* criar_fila();
void enfileirar(FILA* fila, char* nome);
int vazia_fila(FILA* fila);
char* desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);

int main(){

    FILA* fila = criar_fila();

    enfileirar(fila, "Ana");
    mostrar_fila(fila);
    enfileirar(fila, "Beto");
    mostrar_fila(fila);
    enfileirar(fila, "Carla");
    mostrar_fila(fila);
    desenfileirar(fila);
    mostrar_fila(fila);
    enfileirar(fila, "Davi");
    mostrar_fila(fila);
    desenfileirar(fila);
    mostrar_fila(fila);

    fila = liberar_fila(fila);

    mostrar_fila(fila);

    return 0;
}

FILA* criar_fila(){
    FILA* fila = malloc(sizeof(FILA));

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

void enfileirar(FILA* fila, char* nome){
    NO* novo = malloc(sizeof(NO));

    novo->nome = nome;
    novo->proximo = NULL;

    if (fila->primeiro != NULL){
        fila->ultimo->proximo = novo;
    }else{
        fila->primeiro = novo;
    }
    fila->ultimo = novo;
}

int vazia_fila(FILA* fila){
    return(fila == NULL || fila->primeiro == NULL);
}

char* desenfileirar(FILA* fila){

    char* nome;

    if (!vazia_fila(fila)){
        NO* aux = fila->primeiro;

        nome = aux->nome;
        fila->primeiro = aux->proximo;

        free(aux);
    }else{
        nome = NULL;
    }
    return nome;
}

void mostrar_fila(FILA* fila){

    if (! vazia_fila(fila)){
        NO* aux = fila->primeiro;

        printf("\nInico->");
        while (aux != NULL){
            printf("[%s]->", aux->nome);
            aux = aux->proximo;
        }
        printf("Final\n");
    }else{
        printf("Fila vazia\n\n");
    }
}

FILA* liberar_fila(FILA* fila){
    NO* aux;

    while (!vazia_fila(fila)){
        aux = fila->primeiro;
        fila->primeiro = aux->proximo;
        free(aux);
    }

    free(fila);
    fila = NULL;
    
    return fila;
}


