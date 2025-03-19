#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    
    int valor;
    struct LSE* proximo;

}LSE;

LSE* novo_no(int valor);
LSE* ultimo_no(LSE* lista);
LSE* inserir_final(LSE* lista, int valor);
void printar_lista(LSE* lista);
LSE* liberar_lista(LSE* lista);
LSE* BubbleSortLista(LSE* lista);

int main(){

    LSE* lista = NULL;
    int num;

    while (scanf("%d", &num) == 1 ){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    lista = BubbleSortLista(lista);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);
    
    return 0;
}

LSE* novo_no(int valor){
    LSE* no = malloc(sizeof(LSE));

    no->valor = valor;
    no->proximo = NULL;

    return no;
}

LSE* ultimo_no(LSE* lista){
    LSE* ultimo = lista;

    if (lista != NULL){
        while (ultimo->proximo != NULL){
            ultimo = ultimo->proximo;
        }
    }
    return ultimo;
}

LSE* inserir_final(LSE* lista, int valor){
    LSE* novo = novo_no(valor);

    if (lista == NULL){
        lista = novo;
    }else{
        LSE* ultimo = ultimo_no(lista);
        ultimo->proximo = novo;
    }
    return lista;
}

void printar_lista(LSE* lista){

    if (lista != NULL){
        LSE* aux = lista;

        printf("Inicio->");
        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LSE* liberar_lista(LSE* lista){

    if (lista != NULL){
        LSE* aux;

        while (lista != NULL){
            aux = lista;
            lista = lista->proximo;
            free(aux);
        }
        lista = NULL;
    }
    return lista;
}

LSE* BubbleSortLista(LSE* lista){
    LSE* aux1 = lista;
    LSE* aux2;
    int temp;

    while (aux1 != NULL){
        aux2 = aux1->proximo;

        while (aux2 != NULL){

            if (aux1->valor > aux2->valor){
                
                temp = aux1->valor;
                aux1->valor = aux2->valor;
                aux2->valor = temp;

            }
            aux2 = aux2->proximo;
        }
        aux1 = aux1->proximo;
    }
    return lista;
}