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

LEC* remover_todos_buscados(LEC* lista, int buscado){

    if (lista == NULL){
        printf("Lista Vazia!");
    }else{
        LEC* aux = lista;
        LEC* ultimo = lista;

        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }

        while (lista != NULL && lista->valor == buscado){

            if(lista == ultimo){

                lista = NULL;

            }else{

                aux = lista;
                lista = lista->proximo;
                ultimo->proximo =  lista;
                free(aux);

            }
        }

        if (lista != NULL){
            aux = lista;

            do{
                
                LEC* proximo = aux->proximo;

                if (proximo->valor == buscado){
                    
                    aux->proximo = proximo->proximo;
                    free(proximo);

                    if (proximo == ultimo){
                        ultimo = aux;
                    }
                    
                }else{
                    aux = aux->proximo;
                }
                
            } while (aux->proximo != lista);   
        }
    }
    return lista;
}

void printar_lista(LEC* lista){

    if (lista == NULL){
        printf("lista Vazia\n\n");
    }else{
        LEC* aux = lista;

        do{
            
            printf("%d->", aux->valor);
            aux = aux->proximo;

        } while (aux != lista);
        printf("Inicio\n");
    }
}

LEC* liberar_lista(LEC* lista){

    if (lista != NULL){
        LEC* inicio = lista;
        LEC* aux = lista;

        do{

            lista = lista->proximo;
            free(aux);
            aux = lista;

        }while(aux != inicio);

        lista = NULL;
    }
    return lista;
}
int main(){

    LEC* lista = NULL;

    int num;

    while(scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }

    while(getchar() != '\n');

    int remover;

    printar_lista(lista);
    printf("Digite o numero a ser removido da lista: ");
    scanf("%d", &remover);

    lista = remover_todos_buscados(lista, remover);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);

    return 0;
}