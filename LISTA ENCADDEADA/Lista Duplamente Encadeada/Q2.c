#include<stdio.h>
#include<stdlib.h>

typedef struct LDP{

    int valor;
    struct LDP* anterior;
    struct LDP* proximo;

}LDP;

LDP* novo_no(int valor);
LDP* inserir_ordenado(LDP* lista, int valor);
void printar_lista(LDP* lista);
LDP* liberar_lista(LDP*lista);
LDP* ultimo_no(LDP* lista);
LDP* mesclar_ordenado(LDP* lista1, LDP* lista2);

int main(){
    
    LDP* lista1 = NULL;
    LDP* lista2 = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista1 = inserir_ordenado(lista1, num);
    }while(getchar() != '\n');

    while (scanf("%d", &num) == 1){
        lista2 = inserir_ordenado(lista2, num);
    }while(getchar() != '\n');
    
    printar_lista(lista1);
    printar_lista(lista2);

    lista1 = mesclar_ordenado(lista1, lista2);
    
    printar_lista(lista1);

    lista1 = liberar_lista(lista1);

    printar_lista(lista1);
    
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

LDP* inserir_ordenado(LDP* lista, int valor){

    LDP* novo = novo_no(valor);

    if (lista == NULL){
        lista = novo;
    }else{

        LDP* aux = lista;

        while (aux != NULL && aux->valor < valor){//encontrar a posiçao certa para inserir
            aux = aux->proximo;
        }

        if(aux == lista){//caso a lista so tenha um nó

            novo->proximo = lista;
            lista->anterior = novo;
            lista = novo;

        }else if (aux == NULL){//caso inserir no final
            
            LDP* ultimo = ultimo_no(lista);

            ultimo->proximo = novo;
            novo->anterior = ultimo;

        }else{//casos do meio da lista

            novo->anterior = aux->anterior;
            novo->proximo = aux;
            aux->anterior->proximo = novo;
            aux->anterior = novo;

        }
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
        printf("NULL\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LDP* liberar_lista(LDP*lista){
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

LDP* mesclar_ordenado(LDP* lista1, LDP* lista2){

    LDP* auxL1 = lista1;
    LDP* auxL2 = lista2;

    LDP* lista_mesclada = NULL;

    if (lista1 != NULL){
        
        while (auxL1 != NULL){
            lista_mesclada = inserir_ordenado(lista_mesclada, auxL1->valor);
            auxL1 = auxL1->proximo;
        }

        lista1 = liberar_lista(lista1);
    }
    if (lista2 != NULL){
        
        while (auxL2 != NULL){
            lista_mesclada = inserir_ordenado(lista_mesclada, auxL2->valor);
            auxL2 = auxL2->proximo;
        }

        lista2 = liberar_lista(lista2);
    }
    return lista_mesclada;
}

// LDP* inserir_ordenado(LDP* lista, int valor) {
//     LDP* novo = novo_no(valor);

//     if (lista == NULL) {
//         // Lista vazia: o novo nó será o único nó da lista
//         return novo;
//     }

//     LDP* aux = lista;

//     // Encontrar a posição correta para inserção
//     while (aux != NULL && aux->valor < valor) {
//         aux = aux->proximo;
//     }

//     // Caso 1: Inserir no início da lista
//     if (aux == lista) {
//         novo->proximo = lista;
//         lista->anterior = novo;
//         return novo;  // O novo nó se torna o primeiro da lista
//     }

//     // Caso 2: Inserir no final da lista
//     if (aux == NULL) {
//         LDP* ultimo = lista;
//         while (ultimo->proximo != NULL) {
//             ultimo = ultimo->proximo;
//         }
//         ultimo->proximo = novo;
//         novo->anterior = ultimo;
//         return lista;  // Lista não muda, só adiciona o novo nó no final
//     }

//     // Caso 3: Inserir no meio da lista
//     novo->anterior = aux->anterior;
//     novo->proximo = aux;
//     aux->anterior->proximo = novo;
//     aux->anterior = novo;

//     return lista;
// }