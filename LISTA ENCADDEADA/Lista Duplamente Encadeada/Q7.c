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
LDP* achar_valor(LDP* lista, int valor);
LDP* inverter_intervalo(LDP* lista, int X, int Y);

int main(){

    LDP* lista = NULL;

    int num, X, Y;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    if (lista != NULL){
        
        printf("Digite o valor de X: ");
        scanf("%d", &X);

        printf("Digite o valor de Y: ");
        scanf("%d", &Y);

        lista = inverter_intervalo(lista, X, Y);

        printar_lista(lista);

        lista = liberar_lista(lista);

        printar_lista(lista);
    }
    
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

LDP* achar_valor(LDP* lista, int valor){
    LDP* ponteiro_valor = NULL;

    if (lista != NULL){
        ponteiro_valor = lista;
        int achou_valor = 0;

        while (achou_valor == 0 && ponteiro_valor != NULL){
            if (ponteiro_valor->valor == valor){
                achou_valor = 1;
            }else{

                ponteiro_valor = ponteiro_valor->proximo;
            }
        }
    }
    return ponteiro_valor;
}

LDP* inverter_intervalo(LDP* lista, int X, int Y){//dica: se preocupe em inverter so os valores não os nós
    LDP* ponteiro_X = achar_valor(lista, X);
    LDP* ponteiro_Y = achar_valor(lista, Y);
    int autoriza = 0;

    //verifica todos os casos de imposibilidade de inverçao
    if (ponteiro_X == NULL){
        printf("Valor de X nao encontrado\n\n");
        autoriza = 1;
    }else if (ponteiro_Y == NULL){
        printf("Valor de Y nao encontrado\n\n");
        autoriza = 1;
    }else if (ponteiro_X == ponteiro_Y){
        printf("Intervalo nao possui elementos\n\n");
        autoriza = 1;
    }else if (ponteiro_X->proximo == ponteiro_Y->anterior){
        printf("Intervalo so possui um elemneto\n\n");
        autoriza = 1;
    }
    
    if (autoriza != 1){
        LDP* aux_X = ponteiro_X->proximo;
        LDP* aux_Y = ponteiro_Y->anterior;

        int temp;

        while (aux_X != aux_Y && aux_X->anterior != aux_Y){
            
            //inverte VALORES
            temp = aux_X->valor;
            aux_X->valor = aux_Y->valor;
            aux_Y->valor = temp;
            
            //avaça os ponteiros
            aux_X = aux_X->proximo;
            aux_Y = aux_Y->anterior;

        }
    }
    return lista;
}