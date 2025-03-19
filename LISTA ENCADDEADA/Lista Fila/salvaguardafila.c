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
int vazia(FILA* fila);
int desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);

int main(){

    FILA* fila = criar_fila();

    int num;

    while (scanf("%d", &num) == 1){
        enfileirar(fila, num);
    }while(getchar() != '\n');

    mostrar_fila(fila);

    num = desenfileirar(fila);
    printf("Desenfileirado: %d\n", num);
    num = desenfileirar(fila);
    printf("Desenfileirado: %d\n", num);
    num = desenfileirar(fila);
    printf("Desenfileirado: %d\n", num);
    num = desenfileirar(fila);
    printf("Desenfileirado: %d\n", num);
    num = desenfileirar(fila);
    printf("Desenfileirado: %d\n", num);

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
    novo->proximo = NULL;

    if (fila->primeiro != NULL){//caso a fila não esteja vazia

        fila->ultimo->proximo = novo;//aponto o ultimo para o novo

    }else{//caso a fila esteja vazia

        fila->primeiro = novo;//aponto o primeiro para o novo

    }
    
    fila->ultimo = novo;//como essa é uma condição que sempre vai aconter já que é a estrutura da fila 
                        //pode-se colocar ela fora de qualquer condição
}

int vazia(FILA* fila){
    return (fila == NULL || fila->primeiro == NULL);
}

int desenfileirar(FILA* fila){

    int valor;

    if (! vazia(fila)){
        NO* aux = fila->primeiro;//preciso dessa cara unicamente para dar o free no elemento desenfileirado 
        
        valor = aux->valor;//pego o valor rerirado
        fila->primeiro = aux->proximo;//passo o primeiro para o proximo
        free(aux);//libero o NO do valor ja coletado

        if (fila->primeiro == NULL){//caso a fila fique vazia
            fila->ultimo = NULL;//eu igualo o ultimo a null
        }
        
    }else{
        valor = -1;//caso esteja vazio finaliza erro
    }
    return valor;
}

void mostrar_fila(FILA* fila){//mostrar normal de pilha e lista nao tem segredo

    if (! vazia(fila)){
        NO* aux = fila->primeiro;

        printf("\nInicio->");
        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("Fim\n"); 

    }else{
        printf("\nFila Vazia\n");
    }
}

FILA* liberar_fila(FILA* fila){//a função retorna para poder printar sem problemas a fila depois
    NO* aux;                   //e para evitar o uso de ponteiro para ponteiro

    while (! vazia(fila)){
        aux = fila->primeiro;
        fila->primeiro = aux->proximo;
        free(aux);
    }

    free(fila);
    fila = NULL;

    return fila;
}
