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
void SelectionSortLista(LSE* lista);

int main(){

    LSE* lista = NULL;
    int num;

    while (scanf("%d", &num) == 1 ){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    SelectionSortLista(lista);

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

void SelectionSortLista(LSE* lista){
    LSE* aux = lista;
    LSE* aux2;
    LSE* menor;
    int temp;

    while (aux->proximo != NULL){
        menor = aux;
        aux2 = aux->proximo;
        while (aux2 != NULL){
            if (aux2->valor < menor->valor){
                menor = aux2;
            }
            aux2 = aux2->proximo;
        }

        if (menor != aux){
            temp = aux->valor;
            aux->valor = menor->valor;
            menor->valor = temp;
        }
        aux = aux->proximo;
    }
}