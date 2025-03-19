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
LSE* MergeSort(LSE* lista);
LSE* dividir(LSE* lista);
LSE* mesclar(LSE* lista1, LSE* lista2);

int main(){

    LSE* lista = NULL;
    int num;

    while (scanf("%d", &num) == 1 ){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    lista = MergeSort(lista);

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

LSE* MergeSort(LSE* lista){

    //caso base: lista com 0 ou 1 so elemento
    if (lista == NULL || lista->proximo ==  NULL){
        return lista;
    }
    
    //Passo 1: Divide a lista ao meio
    LSE* segunda_metade = dividir(lista);

    //Passo 2: Ordenar as duas metades
    lista = MergeSort(lista);
    segunda_metade = MergeSort(segunda_metade);

    //Passo 3: Mesclar as duas metades ordenadas
    return mesclar(lista, segunda_metade);
}

LSE* dividir(LSE* lista){

    //Caso não seja possivel dividir
    if (lista == NULL || lista->proximo == NULL){
        return NULL;
    }

    LSE* meio = lista;
    LSE* fim = lista->proximo;

    //Encontrar meio da lista
    while (fim != NULL && fim->proximo != NULL){
        meio = meio->proximo;
        fim = fim->proximo->proximo;
    }

    //Desconectar a lista em duas partes
    LSE* segunda_metade = meio->proximo;
    meio->proximo = NULL;
    
    return segunda_metade;
}

LSE* mesclar(LSE* lista1, LSE* lista2){
    LSE* resultado = NULL;

    //Caso base: uma das duas listas estar vazia;
    if(lista1 == NULL) return lista2;
    if(lista2 == NULL) return lista1;

    //Ordena os elementos e mescla
    if (lista1->valor <= lista2->valor){
        resultado = lista1;
        resultado->proximo = mesclar(lista1->proximo, lista2);
    }else{
        resultado = lista2;
        resultado->proximo = mesclar(lista1, lista2->proximo);
    }
    
    return resultado;
}