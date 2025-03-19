#include<stdio.h>
#include<stdlib.h>

typedef struct LDP{

    int valor;
    struct LDP* anterior;
    struct LDP* proximo;

}LDP;

LDP* novo_no(int valor);
LDP* ultimo_no(LDP* lista);
LDP* inserir_final(LDP* lista, int valor);
void printar_lista(LDP* lista);
LDP* liberar_lista(LDP* lista);
LDP* remover_duplicatas(LDP* lista);

int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    lista = remover_duplicatas(lista);

    printar_lista(lista);

    lista =liberar_lista(lista);

    printar_lista(lista);
    
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

LDP* inserir_final(LDP* lista, int valor){
    LDP* novo = novo_no(valor);

    if (lista == NULL){
        
        lista = novo;

    }else{
        LDP* ultimo = ultimo_no(lista);

        ultimo->proximo = novo;
        novo->anterior = ultimo;
    }
    return lista;
}

void printar_lista(LDP* lista){

    if (lista != NULL){
        LDP* aux = lista;

        printf("NULL<->");
        while (aux != NULL){
            printf("%d<->", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LDP* liberar_lista(LDP* lista){

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

LDP* remover_duplicatas(LDP* lista){//as vezez é mais eficas tartar as execoes primeiro e verificar se so isso nao resolve


    if (lista != NULL){
        LDP* atual = lista;
        LDP* aux;

        while (atual != NULL){
            aux = atual->proximo;

            while (aux != NULL){

                if (atual->valor == aux->valor){

                    LDP* duplicata = aux;
                    aux = aux->proximo;

                    if (duplicata->anterior != NULL){
                        duplicata->anterior->proximo = duplicata->proximo;
                    }

                    if (duplicata->proximo != NULL){
                        duplicata->proximo->anterior = duplicata->anterior;
                    }
                    free(duplicata);

                }else{
            
                    aux = aux->proximo;
                }
            }
            atual = atual->proximo;
        }
    }
    return lista;
}