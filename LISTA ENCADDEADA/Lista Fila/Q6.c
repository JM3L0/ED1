#include<stdio.h>
#include<stdlib.h>

typedef struct NO{

    int valor;
    struct NO* proximo;

}NO;

typedef struct FILA{

    NO* primeiro;
    NO* ultimo;

}FILA;

FILA* criar_fila();
void enfileirar(FILA* fila, int valor);
int vazia_fila(FILA* fila);
int desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);
void junta_filas(FILA* filaR, FILA* fila1, FILA* fila2);

int main(){

    FILA* fila1 = criar_fila();
    FILA* fila2 = criar_fila();
    FILA* filaR = criar_fila();
    int num;

    printf("Digite a fila 1: ");
    while (scanf("%d", &num) == 1){
        enfileirar(fila1, num);
    }while(getchar() != '\n');

    printf("Digite a fila 2: ");
    while (scanf("%d", &num) == 1){
        enfileirar(fila1, num);
    }while(getchar() != '\n');

    printf("\nFilas jusntas\n");

    junta_filas(filaR, fila1, fila2);

    mostrar_fila(filaR);

    filaR = liberar_fila(filaR);

    mostrar_fila(filaR);

    return 0;
}

FILA* criar_fila(){
    FILA* fila = malloc(sizeof(FILA));

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

void enfileirar(FILA* fila, int valor){
    NO* novo = malloc(sizeof(NO));

    novo->valor = valor;
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

int desenfileirar(FILA* fila){
    int valor;

    if (!vazia_fila(fila)){
        NO* aux = fila->primeiro;

        valor = aux->valor;
        fila->primeiro = aux->proximo;
        free(aux);
    }else{
        valor = -1;
    }
    return valor;
}

void mostrar_fila(FILA* fila){

    if (! vazia_fila(fila)){
        NO* aux = fila->primeiro;

        printf("\nInico->");
        while (aux != NULL){
            printf("%d->", aux->valor);
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

void junta_filas(FILA* filaR, FILA* fila1, FILA* fila2){
    

    while (!vazia_fila(fila1)){
        enfileirar(filaR, desenfileirar(fila1));
    }

    while (!vazia_fila(fila2)){
        enfileirar(filaR, desenfileirar(fila2));
    }
    
    fila1 = liberar_fila(fila1);
    fila2 = liberar_fila(fila2);
}