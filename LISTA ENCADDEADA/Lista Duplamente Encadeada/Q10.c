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
LDP* busca_valor(LDP* lista, int buscado);
LDP* inserir_listas_antes_e_depois(LDP* lista, int valor);

int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    printf("Digite o numero a ser buscado na lista: ");
    scanf("%d", &num);

    lista = inserir_listas_antes_e_depois(lista, num);

    printar_lista(lista);

    lista = liberar_lista(lista);

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
    LDP* ultimo = NULL;

    if (lista != NULL){
        ultimo = lista;

        while (ultimo->proximo != NULL){
            ultimo = ultimo->proximo;
        }
    }
    return ultimo;
}

LDP* inserir_final(LDP* lista, int valor){
    LDP* novo = novo_no(valor);

    if (lista == NULL){

        lista = novo;
    
    }else{

        LDP* ultimo = ultimo_no(lista);

        novo->proximo = ultimo->proximo;
        novo->anterior = ultimo;
        ultimo->proximo = novo;

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
    }
    return lista;
}

LDP* busca_valor(LDP* lista, int buscado){
    LDP* aux = NULL;

    if (lista != NULL){

        aux = lista;
        int achou = 0;

        while (aux != NULL && achou == 0){
            if (aux->valor == buscado){
                achou = 1;
            }else{
                aux = aux->proximo;
            }
        }
    }
    return aux;
}

LDP* inserir_listas_antes_e_depois(LDP* lista, int valor){

    if (lista != NULL){
        LDP* ponto_chave = busca_valor(lista, valor);
        LDP* lista_aux1 = NULL;
        LDP* lista_aux2 = NULL;

        if (ponto_chave != NULL){
            
            for (int i = 0; i < valor; i++){
                lista_aux1 = inserir_final(lista_aux1, i+1);
                lista_aux2 = inserir_final(lista_aux2, i+1);
            }
        }

        LDP* final_lista1 = ultimo_no(lista_aux1);
        LDP* final_lista2 = ultimo_no(lista_aux2);
        
        if (ponto_chave->anterior == NULL){
             
            final_lista1->proximo = ponto_chave;
            ponto_chave->anterior = final_lista1;

            final_lista2->proximo = ponto_chave->proximo;
            final_lista2->proximo->anterior = final_lista2;

            ponto_chave->proximo = lista_aux2;
            lista_aux2->anterior = ponto_chave;

            lista = lista_aux1;

        }else if (ponto_chave->proximo == NULL){
            
            ponto_chave->proximo = lista_aux2;
            lista_aux2->anterior = ponto_chave;

            ponto_chave->anterior->proximo = lista_aux1;
            lista_aux1->anterior = ponto_chave->anterior;

            final_lista1->proximo = ponto_chave;
            ponto_chave->anterior = final_lista1;
            ponto_chave->proximo = lista_aux2;

        }else{

            lista_aux1->anterior = ponto_chave->anterior;
            ponto_chave->anterior->proximo = lista_aux1;
            final_lista1->proximo = ponto_chave;

            lista_aux2->anterior = ponto_chave;
            ponto_chave->proximo->anterior = final_lista2;
            final_lista2->proximo = ponto_chave->proximo;

            ponto_chave->anterior = final_lista1;
            ponto_chave->proximo = lista_aux2;

        }
    }
    return lista;
}