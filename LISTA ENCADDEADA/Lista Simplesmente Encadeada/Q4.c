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

LSE* inseir_inicio(LSE* lista, int valor){
    LSE* novo = novo_no();

    if (novo){//Equivalente a um if(novo != NULL)
        novo->valor = valor;
        novo->proximo = lista;
        lista = novo;
        
    }else{
        printf("Erro de alocacao\n");
    }
    
    return lista;
}

void printar_lista(LSE* lista){

    if (lista == NULL){
        printf("Lista Vazia");
    }else{
    
        LSE* aux = lista;

        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

LSE* remove_duplicatas(LSE* lista){
    LSE* aux = lista;

    while (aux != NULL){
        LSE* aux2 = aux->proximo;
        LSE* anterior = aux;
        while (aux2 != NULL){
            if(aux2->valor == aux->valor){
                anterior->proximo = aux2->proximo;
                free(aux2);
                aux2 = anterior->proximo;
            }else{
                anterior = aux2;
                aux2 = aux2->proximo;
            }
        }
        aux = aux->proximo;
    }
    return lista;
}

LSE* libera_lista(LSE* lista){
    LSE* aux = lista;
    if (lista == NULL)
    {
        printf("Lista Vazia\n\n");
    }else{
    
        while (lista != NULL){
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
    LSE* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista =  inseir_inicio(lista, num);
    }

    while (getchar() != '\n');

    printar_lista(lista);

    lista = remove_duplicatas(lista);

    printar_lista(lista);

    lista = libera_lista(lista);
    
    return 0;
}