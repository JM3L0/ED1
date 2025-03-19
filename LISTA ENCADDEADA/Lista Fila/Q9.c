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
int soma_afrente(NO* no, int quant);
void soma_movel(FILA* filaR, FILA* fila, int quant);

int main(){

    FILA* fila = criar_fila();
    FILA* filaR = criar_fila();
    int num;

    printf("Digite a fila: ");
    while (scanf("%d", &num) == 1){
        enfileirar(fila, num);
    }while(getchar() != '\n');

    printf("Digite a janela: ");
    scanf("%d", & num);

    soma_movel(filaR, fila, num);

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

int soma_afrente(NO* no, int quant){
    NO* aux = no;
    int soma = 0;
    int cont = 0;

    while (aux != NULL && cont < quant){
        soma = soma + aux->valor;
        aux = aux->proximo;
        cont++;
    }
    if (cont != quant){// se cont for diferente de quant quer dizer qeu ultrapassou o limite da lista
        soma = 0;
    }
    
    return soma;
}

void soma_movel(FILA* filaR, FILA* fila, int quant){

    if (!vazia_fila(fila)){
        NO* aux = fila->primeiro;
        int soma;

        while (aux != NULL){

            soma = soma_afrente(aux, quant);
            
            if (soma > 0){
                enfileirar(filaR, soma_afrente(aux, quant));
            }
            
            aux = aux->proximo;
        }
    }
}