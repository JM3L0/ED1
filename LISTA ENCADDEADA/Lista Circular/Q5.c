#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{
    
    int valor;
    struct LEC* proximo;

}LEC;

LEC* novo_no(int valor){
    LEC* no = malloc(sizeof(LEC));
    no->valor = valor;
    no->proximo = no;
    return no;
}

LEC* inserir_final(LEC* lista, int valor){
    LEC* novo = novo_no(valor);

    if (lista == NULL){
        lista = novo;
    }else{
        LEC* ultimo = lista;

        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }

        ultimo->proximo = novo;
        novo->proximo = lista;
    }
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
        }while (aux != lista);
        printf("Inicio\n\n");
    }
}

LEC* liberar_lista(LEC* lista){
    if (lista != NULL){
        LEC* aux = lista;
        LEC* temp;

        do{
            temp = aux;
            aux = aux->proximo;
            free(temp);

        } while (aux != lista); 
        lista = NULL;
    }
    return lista;
}

LEC* remover_elemento_repetidos(LEC* lista){
    LEC* atual = lista;
    LEC* percorre = NULL;
    LEC* proximo = NULL;

    while (atual->proximo != lista)
    {
        percorre = atual;
        proximo = percorre->proximo;
        while (proximo != lista)
        {
            if (proximo->valor == atual->valor)
            {
                percorre->proximo = proximo->proximo;
                free(proximo);
                proximo = percorre->proximo;
            }else{
                percorre = proximo;
                proximo = percorre->proximo;
            }
        }
        atual = atual->proximo;
    }
    return lista;
}

int main(){

    LEC* lista = NULL;

    int num;

    while(scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    lista = remover_elemento_repetidos(lista);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);
    return 0;
}

