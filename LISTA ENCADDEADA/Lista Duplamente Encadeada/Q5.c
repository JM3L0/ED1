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
LDP* rotacionar_direita(LDP* lista);

int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    printf("Quantas vezes deseja rotacionar: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++){
        
        lista = rotacionar_direita(lista);

    }

    printar_lista(lista);

    lista =liberar_lista(lista);

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
    LDP* ultimo = lista;

    while (ultimo->proximo != NULL){
        ultimo = ultimo->proximo;
    }
    return ultimo;
}

LDP* inserir_final(LDP* lista, int valor){
    LDP* novo = novo_no(valor);

    if (lista == NULL){
        
        lista = novo;

    }else{
        LDP* ultimo = ultimo_no(lista);

        ultimo->proximo = novo;
        novo->anterior = ultimo;
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
        lista = NULL;
    }
    return lista;
}

LDP* rotacionar_direita(LDP* lista){

    if (lista != NULL && lista->proximo != NULL){
        
        LDP* ultimo = ultimo_no(lista);

        ultimo->anterior->proximo = ultimo->proximo;
        ultimo->proximo = lista;
        ultimo->anterior = lista->anterior;
        lista->anterior = ultimo;
        lista = ultimo;
    }
    return lista;
}