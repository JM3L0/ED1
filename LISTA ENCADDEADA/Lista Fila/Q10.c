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
int eh_primo(int num);
void divide_primos_nao_primos(FILA* fila, FILA* primos, FILA* nao_primos);

int main(){

    FILA* fila = criar_fila();
    FILA* fila_Primos = criar_fila();
    FILA* fila_nPrimos = criar_fila();
    int num;

    printf("Digite a fila: ");
    while (scanf("%d", &num) == 1){
        enfileirar(fila, num);
    }while(getchar() != '\n');

    divide_primos_nao_primos(fila, fila_Primos, fila_nPrimos);

    printf("Primos: ");
    mostrar_fila(fila_Primos);
    printf("Nao Primos: ");
    mostrar_fila(fila_nPrimos);

    fila_Primos = liberar_fila(fila_Primos);
    fila_nPrimos = liberar_fila(fila_nPrimos);

    mostrar_fila(fila_Primos);
    mostrar_fila(fila_nPrimos);

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

int eh_primo(int num){
    int verifica = 1;

    if (num > 1){
        
        for (int i = 2; i*i <= num; i++){
            if (num % i == 0){
                verifica = 0;
            }
        }
    }else{
        verifica = 0;
    }
    return verifica;
}

void divide_primos_nao_primos(FILA* fila, FILA* primos, FILA* nao_primos){

    int valor;
    
    while (!vazia_fila(fila)){
        valor = desenfileirar(fila);

        if (eh_primo(valor)){
            enfileirar(primos, valor);
        }else{
            enfileirar(nao_primos, valor);
        }
    }
    fila = liberar_fila(fila);
}