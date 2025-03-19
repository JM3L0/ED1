#include<stdio.h>
#include<stdlib.h>

typedef struct NO{
    
    int valor;
    struct NO* proximo;

}NO;

typedef struct FILA{
    
    NO* primeio;
    NO* ultimo;

}FILA;

FILA* criar_fila();
void enfileirar(FILA* fila, int valor);
int vazia_fila(FILA* fila);
int desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);
void fila_crescente(FILA* fila);

int main(){

    FILA* fila = criar_fila();
    int num;

    while (scanf("%d", &num) == 1){
        enfileirar(fila, num);
    }while(getchar() != '\n');

    mostrar_fila(fila);
    
    printf("Fila em ordem crescente?\n\n");
    fila_crescente(fila);

    fila = liberar_fila(fila);

    mostrar_fila(fila);

    return 0;
}

FILA* criar_fila(){
    FILA* fila = malloc(sizeof(FILA));

    fila->primeio = NULL;
    fila->ultimo = NULL;

    return fila;
}

void enfileirar(FILA* fila, int valor){
    NO* novo = malloc(sizeof(NO));

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila->primeio != NULL){
        fila->ultimo->proximo = novo;
    }else{
        fila->primeio = novo;
    }
    
    fila->ultimo = novo;
}

int vazia_fila(FILA* fila){
    return (fila == NULL || fila->primeio == NULL);
}

int desenfileirar(FILA* fila){
    int valor;

    if (! vazia_fila(fila)){
        NO* aux = fila->primeio;

        valor = aux->valor;
        fila->primeio = aux->proximo;
        free(aux);
    }else{
        valor = -1;
    }
    return valor;
}

void mostrar_fila(FILA* fila){

    if (! vazia_fila(fila)){
        NO* aux = fila->primeio;

        printf("Inicio->");
        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("Fim\n\n");
    }else{
        printf("\nFila Vazia\n");
    }
}

FILA* liberar_fila(FILA* fila){
    NO* aux;

    while (! vazia_fila(fila)){
        aux = fila->primeio;
        fila->primeio = aux->proximo;
        free(aux);
    }

    free(fila);
    fila = NULL;

    return fila;
}

void fila_crescente(FILA* fila){

    if (! vazia_fila(fila)){
        NO* aux = fila->primeio;
        int valor = aux->valor;
        int verifica = 0;

        while (aux != NULL && verifica == 0){
            
            if (valor <= aux->valor){
                valor = aux->valor;
                aux = aux->proximo;
            }else{
                verifica = 1;
            }
        }
        
        if (verifica == 0){
            printf("Verdadeiro\n\n");
        }else{
            printf("Falso\n\n");
        }
    }
}

