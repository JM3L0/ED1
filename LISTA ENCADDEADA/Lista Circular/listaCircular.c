#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{
    int valor;
    struct LEC* proximo;
}LEC;

LEC* novo_no(){
    LEC* no = malloc(sizeof(LEC));
    return no;
}
// lista é a minha cabeça da lista 
LEC* inserir_final(LEC* lista, int valor){
    LEC* novo = novo_no();
    novo->valor = valor;

    if (lista == NULL){
        novo->proximo = novo;
        lista =  novo;
    }else{
        LEC* aux = lista;
        while (aux->proximo != lista){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
    novo->proximo = lista;
    return lista;
}

void printar_lista(LEC* lista){

    if (lista == NULL){
        printf("Lista Vazia\n\n");
    }else{
        LEC* aux = lista;

        do{
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }while(aux != lista);
        printf("INICIO\n\n");
    }
}
// melhor jeito que consegui para liberar uma lista circular
LEC* libera_lista(LEC* lista){

    if(lista != NULL){
        LEC* aux = lista;
        LEC* proximo;

        do{
            printf("%d ", aux->valor);
            proximo =  aux->proximo;
            free(aux);
            aux = proximo;
            
        } while (aux != lista);
    }

    return NULL;
}

int main(){

    LEC* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }
    while (getchar() != '\n');
    
    printar_lista(lista);

    lista = libera_lista(NULL);

    printar_lista(lista);

    return 0;
}