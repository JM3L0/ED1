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
    novo->proximo = NULL;

    if (novo){
        novo->valor = valor;

        if(lista == NULL){
            return novo;
        }

        LSE* aux = lista;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }else{
        printf("Erro de alocacao");
    }

    return lista;
}

LSE* inserir_inicio(LSE* lista, int valor){
    LSE* novo = novo_no();

    if (novo){
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
        printf("Lista vazia\n");
    }else{
        LSE* aux = lista;
        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

LSE* mesclagem(LSE* lista, LSE* lista_incremental, LSE* lista_incremental2, int buscado){

    if (lista == NULL){
        printf("Lista principal vazia.\n");
        return lista;
    }
    
    LSE* anterior = NULL;
    LSE* atual = lista;
    LSE* proximo = lista->proximo;

    while (atual != NULL && atual->valor != buscado){
        anterior = atual;
        atual = atual->proximo;
        proximo = proximo->proximo;
    }

    LSE* inicioL2 = lista_incremental;
    LSE* finalL2 = lista_incremental;

    while (finalL2->proximo != NULL){
        finalL2 = finalL2->proximo;
    }

    LSE* inicioL3 = lista_incremental2;
    LSE* finalL3 = lista_incremental2;

    while (finalL3->proximo != NULL){
        finalL3 = finalL3->proximo;
    } 
    
    anterior->proximo = inicioL2;
    finalL2->proximo = atual;

    atual->proximo = inicioL3;
    finalL3->proximo = proximo;

    return lista;
}

LSE* libera_lista(LSE* lista){
   LSE* aux = lista;
    if (lista == NULL){
        printf("Lista Vazia\n");
    }else{
    
        while (aux != NULL){
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
    printf("Digite a lista\n");
    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }
    while (getchar() != '\n');

    LSE* lista_incremental = NULL;
    LSE* lista_incremental2 = NULL;
    int incremnetar;
    printf("Digite o numero a ser incrementadon\n");
    scanf("%d", &incremnetar);

    for (int i = 1; i <= incremnetar; i++){
        lista_incremental = inserir_final(lista_incremental, i);
        lista_incremental2 = inserir_final(lista_incremental2, i);
    }

    printar_lista(lista);
    printar_lista(lista_incremental);

    LSE* listaM = mesclagem(lista, lista_incremental, lista_incremental2, incremnetar);

    printar_lista(listaM);

    listaM = libera_lista(listaM);

    return 0;
}