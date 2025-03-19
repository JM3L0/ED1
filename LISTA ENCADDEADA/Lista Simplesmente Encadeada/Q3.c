#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int valor;
    struct LSE* proximo;
}LSE;

LSE* novo_no(){
    LSE* no = malloc(sizeof(LSE));
    return no;
}

LSE* inserir_final(LSE* lista, int valor){
    LSE* novo = novo_no();
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista == NULL){
        return novo;
    }

    LSE* aux = lista;

    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    
    aux->proximo = novo;

    return lista;
}

void media_lista(LSE* lista){
    LSE* aux = lista;

    float soma = 0;
    int i = 0;

    while(aux != NULL){
        printf("%d\n", i);
        soma = soma + aux->valor;
        i++;
        aux = aux->proximo;
    }

    printf("\n\nMedia = %f\n", soma/i);
    printf("Soma: %f\n", soma);
    printf("%d\n", i);

}

void printar_lista(LSE* lista){
    LSE* aux = lista;

    if (lista == NULL){
        printf("Lista Vazia!!\n");
        return;
    }
    

    while(aux != NULL){
        printf("%d->", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL");
}

LSE* libera_lista(LSE* lista){
    LSE* aux = lista;

    if (lista == NULL){
        printf("Lista vazia!!\n");
    }else{

        while (aux != NULL){
            LSE* proximo = aux->proximo;
            free(aux);
            aux = proximo;
        }
        printf("Lista liberada!!\n");
        lista = NULL;
    }
    return lista;
}


int main(){

    LSE* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }
    while (getchar() != '\n');

    printar_lista(lista);

    media_lista(lista);
    
    lista = libera_lista(lista);
    
    return 0;
}