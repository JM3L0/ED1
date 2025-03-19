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
int existe(FILA* fila, int valor);
void aparece_nas_duas(FILA* filaR, FILA* fila1, FILA* fila2);

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
        enfileirar(fila2, num);
    }while(getchar() != '\n');

    aparece_nas_duas(filaR, fila1, fila2);

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

int existe(FILA* fila, int valor){
    int existe = 0;

    if (!vazia_fila(fila)){
        NO* aux = fila->primeiro;
        
        while (aux != NULL && existe == 0){
            if (aux->valor == valor){
                existe = 1;
            }else{
                aux = aux->proximo;
            }
        }
    }
    return existe;
}

void aparece_nas_duas(FILA* filaR, FILA* fila1, FILA* fila2){

    if (!vazia_fila(fila1) && !vazia_fila(fila2)){
        NO* aux_F2 = fila2->primeiro;

        while (aux_F2 != NULL){//so preciso percorrer uma aqui 

            if (existe(fila1, aux_F2->valor)){//pois percorro a outra na funçao existe()
                enfileirar(filaR, aux_F2->valor);
            }
            aux_F2 = aux_F2->proximo;
        }
    }
}
