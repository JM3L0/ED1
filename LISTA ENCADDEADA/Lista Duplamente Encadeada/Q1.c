#include<stdio.h>
#include<stdlib.h>

typedef struct LDP{
    
    int valor;
    struct LDP* proximo;
    struct LDP* anterior;

}LDP;

LDP* novo_no(int valor);
LDP* inserir_final(LDP* lista, int valor);
void printar_lista(LDP* lista);
LDP* liberar_lista(LDP* lista);
void remover_elemento(LDP** lista, int remover);
void remover_segundo_maior_elemento(LDP** lista);

int main(){

    LDP* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while (getchar() != '\n');
    
    printar_lista(lista);

    remover_segundo_maior_elemento(&lista);


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

LDP* inserir_final(LDP* lista, int valor){

    LDP* novo = novo_no(valor);

    if (lista == NULL){

        lista = novo;

    }else{

        LDP* aux = lista;

        while (aux->proximo != NULL){
            aux = aux->proximo;
        }
        
        aux->proximo = novo;
        novo->anterior = aux;
    }
    return lista;
}

void printar_lista(LDP* lista){
    if (lista != NULL){
        LDP* aux;

        printf("\nNULL<-> ");
        while(aux != NULL){
            
            printf("%d <-> ", aux->valor);
            aux = aux->proximo;

        }
        printf("NULL\n\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LDP* liberar_lista(LDP* lista){

    if (lista != NULL){
        LDP* aux = lista;

        while (aux != NULL){
            aux = lista;
            lista = lista->proximo;
            free(aux);
        }
        lista = NULL;
    }
    return lista;
}

void remover_elemento(LDP** lista, int remover){

    if (*lista != NULL){
        LDP* aux = *lista;
        int achou = 0;

        while(aux != NULL && achou == 0){
            
            if (aux->valor == remover){
                
                if (aux->anterior != NULL){ // caso nao seja o primeiro

                    aux->anterior->proximo = aux->proximo;

                }else{// se nao for o caso de nao ser o primeiro é claro que sera o primeiro entao atualiza o lista para frente

                    (*lista) = aux->proximo;
                }
                
                if (aux->proximo != NULL){// independente do que aconteça eu verifico se o proximo nao é NULL
                                          // assim eu sempre mantenho o anterior do proximo atualizado
                    aux->proximo->anterior = aux->anterior;
                }
                
                free(aux);
                achou = 1;
            }else{

                aux = aux->proximo;
            }
        }
        
        if (achou == 0){
            printf("Elemento nao encontrado\n\n");
        }else{
            printf("Elemento encontrado e removido com sucesso\n\n");
        }
    }
}

void remover_segundo_maior_elemento(LDP** lista){

    int maior = (*lista)->valor;
    int segundo_maior = (*lista)->valor;

    if (*lista != NULL && (*lista)->proximo != NULL){
        LDP* aux = *lista;

        while(aux != NULL){
            
            if (aux->valor > maior){
                maior = aux->valor;
            }

            aux = aux->proximo;
        }
        aux = *lista;
        while (aux != NULL){
            
            if (aux->valor < maior && aux->valor > segundo_maior){
                
                segundo_maior = aux->valor;
            }
            aux = aux->proximo;
        }

        if (segundo_maior != maior){
            remover_elemento(lista, segundo_maior);
        }
        else{
            printf("Todos os elementos sao iguais\n\n");
        }
        
    }else{
        printf("Lista vazia ou com somente um elemento\n\n");
    }

    printf("segundo maior %d\n", segundo_maior);
}

// void remover_elemento(LDP** lista, int remover){

//     if (lista != NULL){
//         LDP* aux = *lista;
//         int achou = 0;

//         while(aux != NULL && achou == 0){
            
//             if (aux->valor == remover){
//                 printf("passou aqui\n");
//                 aux->anterior->proximo = aux->proximo;
//                 aux->proximo->anterior = aux->anterior;
//                 free(aux);
//                 achou = 1;
//             }
//             aux = aux->proximo;
//         }
        
//         if (achou == 0){
//             printf("Elemento nao encontrado\n\n");
//         }else{
//             printf("Elemento encontrado e removido com sucesso\n\n");
//         }
//     }
// }