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
LDP* ordenar_lista(LDP* lista);
LDP* achar_valor_pela_esquerda(LDP* lista, int valor);
LDP* remover_entre_os_valores(LDP* lista, int x, int y);
LDP* achar_valor_pela_direita(LDP* lista, int valor);

int main(){

    LDP* lista = NULL;

    int num, x, y;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');

    printar_lista(lista);

    lista = ordenar_lista(lista);

    printar_lista(lista);

    printf("Digite o valor inicial do intervalo: ");
    scanf("%d", &x);

    printf("Digite o valor final do intervalo: ");
    scanf("%d", &y);

    lista = remover_entre_os_valores(lista, x, y);

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

LDP* ordenar_lista(LDP* lista){//MEU ALGORITIMO DE ORDENAÇÃO

    if (lista != NULL){
        
        LDP* aux = lista;
        int temp;

        while(aux != NULL){
            
            if (aux->proximo != NULL && aux->valor > aux->proximo->valor){
                
                temp = aux->valor;
                aux->valor = aux->proximo->valor;
                aux->proximo->valor = temp;
                
                if (aux->anterior != NULL){
                    
                    aux = aux->anterior;
                }
                
            }else{
                aux = aux->proximo;
            }
        }
    }
    return lista;
}

LDP* achar_valor_pela_esquerda(LDP* lista, int valor){
    LDP* ponteiro_valor = NULL;

    if (lista != NULL){
        
        ponteiro_valor = lista;

        while (ponteiro_valor != NULL && ponteiro_valor->valor < valor){
            
            ponteiro_valor = ponteiro_valor->proximo;

        }
    }
    return ponteiro_valor;
}

LDP* achar_valor_pela_direita(LDP* lista, int valor){
    LDP* ponteiro_valor = NULL;

    if (lista != NULL){
        
        ponteiro_valor = ultimo_no(lista);

        while (ponteiro_valor != NULL && ponteiro_valor->valor > valor){
            
            ponteiro_valor = ponteiro_valor->anterior;

        }
    }
    return ponteiro_valor;
}

LDP* remover_entre_os_valores(LDP* lista, int x, int y){//corrigie essa função para os extremos do intervalo ser o primeiro ou o ultimo elemento

    if (lista != NULL){
        LDP* ponteiro_x = achar_valor_pela_esquerda(lista, x);
        LDP* ponteiro_y = achar_valor_pela_direita(lista, y);

        if (ponteiro_x == NULL){
            printf("Inicio do intervalo nao encontrado\n\n");
        }else if (ponteiro_y == NULL){
            printf("Final do intervalo nao encontrado\n\n");
        }else{

            ponteiro_x->anterior->proximo = ponteiro_y->proximo;
            ponteiro_y->proximo->anterior = ponteiro_x->anterior;

            ponteiro_x->anterior = NULL;
            ponteiro_y->proximo = NULL;

            printar_lista(ponteiro_x);
            
            ponteiro_x = liberar_lista(ponteiro_x);

            printar_lista(ponteiro_x);
        }
    }else{
        printf("Lista Vazia\n\n");
    }
    return lista;
}