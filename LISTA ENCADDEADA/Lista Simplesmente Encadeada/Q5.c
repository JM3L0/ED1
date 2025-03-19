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

LSE* insere_inicio(LSE* lista, int valor){
    
    LSE* novo = novo_no();

    if (novo){
        novo->valor = valor;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro de alocacao");
    }
    
    return lista;
}

void printar_lista(LSE* lista){
    if (lista == NULL){
        printf("Lista Vazia!");
    }else{
        LSE* aux = lista;

        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n"); 
    }
}

LSE* lista_mesclada(LSE* lista1, LSE* lista2){
    LSE* aux = lista1;

    while (aux->proximo != NULL){
        aux = aux->proximo;
    }
    
    aux->proximo = lista2;

    return lista1;
}

LSE* libera_lista(LSE* lista){
    LSE* aux = lista;

    if (lista == NULL)
    {
        printf("Lista Vazia\n\n");
    }else{
    
        while(aux != NULL){
            lista = lista->proximo;
            free(aux);
            aux = lista;
        }
        printf("Lista liberada\n");
        lista = NULL;
    }
    return lista;
}

int main(){

    LSE* lista1 = NULL;

    LSE* lista2 = NULL;

    int num;

    printf("Digite a lista 1\n");
    while (scanf("%d", &num) == 1){
        lista1 = insere_inicio(lista1, num);
    }
    while(getchar() != '\n');

    printf("Digite a lista 2\n");
    while (scanf("%d", &num) == 1){
        lista2 = insere_inicio(lista2, num);
    }
    while(getchar() != '\n');

    printar_lista(lista1);
    printar_lista(lista2);

    LSE* listaM = lista_mesclada(lista1, lista2);

    printar_lista(lista1);
    printar_lista(lista2);

    printar_lista(listaM);

    listaM = libera_lista(listaM);

    printar_lista(listaM);
    return 0;
}