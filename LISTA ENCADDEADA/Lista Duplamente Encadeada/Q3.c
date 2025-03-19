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
LDP* remover_todos_buscados(LDP* lista, int buscado);


int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    printf("Digite um numero a ser removido totalmente da lista: ");
    scanf("%d", &num);

    lista = remover_todos_buscados(lista, num);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);

    return 0;
}

LDP* novo_no(int valor){
    LDP* no = malloc(sizeof(LDP));

    no->valor = valor;
    no->proximo = NULL;
    no->anterior = NULL;

    return no;
}

LDP* ultimo_no(LDP* lista){
    LDP* ultimo = lista;

    if (lista != NULL){
        
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

LDP* remover_todos_buscados(LDP* lista, int buscado){

    if (lista != NULL){
        LDP* atual = lista;
        LDP* aux;

        while (atual != NULL){
            
            if (atual->valor == buscado){

                if(atual->proximo == NULL && atual == lista){// caso so tenha um nó e esse no tenha que ser removido
                    
                    free(atual);
                    atual = NULL;
                    lista = NULL;

                }else if(atual == lista){//caso esteja no primeiro no da lista e tenha mais de um no

                    aux = atual;
                    atual = atual->proximo;
                    atual->anterior = aux->anterior;
                    lista = atual;
                    free(aux);

                }else if(atual->proximo == NULL){//caso seja o ultimo no da lista
                    
                    aux = atual;
                    atual = atual->anterior;
                    atual->proximo = aux->proximo;
                    free(aux);

                }else{//para os casos de remoções no meio da lista

                    aux = atual;
                    atual = atual->anterior;
                    atual->proximo = aux->proximo;
                    atual->proximo->anterior = atual;
                    free(aux);

                }   
            }else{

                atual = atual->proximo;

            }
        }
    }
    return lista;
}