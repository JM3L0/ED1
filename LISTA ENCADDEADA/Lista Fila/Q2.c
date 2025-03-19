#include<stdio.h>
#include<stdlib.h>

typedef struct NO{

    int valor;
    struct NO* proxomo;

}NO;

typedef struct FILA{

    NO* primeiro;
    NO* ultimo;

}FILA;

FILA* criar_fila();
void enfileirar(FILA* fila, int valor);
int vazia(FILA* fila);
int desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);
int soma_elementos(FILA* fila);

int main(){
    FILA* fila = criar_fila();

    int num;

    while (scanf("%d", &num) == 1){
        enfileirar(fila, num);
    }while(getchar() != '\n');

    mostrar_fila(fila);

    num = soma_elementos(fila);
    printf("Soma dos elementos: %d", num);

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

void enfileirar(FILA* fila, int valor){
    NO* novo = malloc(sizeof(NO));

    novo->valor = valor;
    novo->proxomo = NULL;

    if (fila->primeiro != NULL){
        fila->ultimo->proxomo = novo;
    }else{
        fila->primeiro = novo;
    }
    
    fila->ultimo = novo;
}

int vazia(FILA* fila){
    return (fila == NULL || fila->primeiro == NULL);
}

int desenfileirar(FILA* fila){

    int valor;

    if (! vazia(fila)){
        NO* aux = fila->primeiro;

        valor = aux->valor;
        fila->primeiro = aux->proxomo;
        free(aux);

        if (fila->primeiro == NULL){
            fila->ultimo = NULL;
        }
        
    }else{
        valor = -1;
    }
    return valor;
}

void mostrar_fila(FILA* fila){

    if (! vazia(fila)){
        NO* aux = fila->primeiro;

        printf("\nInicio->");
        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proxomo;
        }
        printf("Final\n");
    }else{
        printf("\nFila Vazia\n");
    }
}

FILA* liberar_fila(FILA* fila){
    NO* aux;

    while (! vazia(fila)){
        aux = fila->primeiro;
        fila->primeiro = aux->proxomo;
        free(aux);
    }
    
    free(fila);
    fila = NULL;

    return fila;
}

int soma_elementos(FILA* fila){
    int soma, valor;
    
    if (! vazia(fila)){
        
        while (! vazia(fila)){
            valor = desenfileirar(fila);
            soma += valor;
        }
        
    }else{
        soma = -1;
    }
    return soma;
}