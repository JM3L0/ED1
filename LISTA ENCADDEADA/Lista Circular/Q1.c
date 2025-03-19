#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{

    int valor;
    int posicao;
    struct LEC* proximo;

}LEC;

void printar_lista(LEC* lista);

LEC* novo_no(int valor, int posicao){
    LEC* no = malloc(sizeof(LEC));
    no->valor = valor;
    no->posicao = posicao;
    no->proximo = no;
    return no;
}

LEC* inserir_final(LEC* lista, int valor, int posicao){
    LEC* novo = novo_no(valor, posicao);

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

LEC* remover_elemento_pulando(LEC* lista, int pulos){

    LEC* atual = lista;
    LEC* anterior = NULL;
    printar_lista(lista);

    while (lista != NULL && atual->proximo != atual){
        
        for(int i = 0; i < pulos; i++){
            anterior = atual;
            atual = atual->proximo;
        }

        anterior->proximo = atual->proximo;

        if(lista == atual){
            lista = lista->proximo;
        }
        free(atual);
        atual = anterior->proximo;

        printar_lista(lista);
    }
    return lista;
}

void printar_lista(LEC* lista){

    if(lista == NULL){
        printf("Lista Vazia\n\n");
    }else{

        LEC* aux = lista;

        do{
            printf("[%d:%d]->", aux->valor, aux->posicao);
            aux = aux->proximo;
        } while (aux != lista);
        
        printf("inicio\n\n");
    }
}

LEC* liberar_lista(LEC* lista){
    if(lista != NULL){
        LEC* inicio = lista;
        LEC* aux;

        do{
            aux = lista->proximo;
            free(lista);
            lista = aux;
        } while (inicio != lista);
        lista = NULL;
    }
    return lista;
}

int main(){

    LEC* lista = NULL;

    int tam, num;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tam);

    for(int i = 0; i < tam; i++){
        printf("Digite o %d nuemro da lista: ", i+1);
        scanf("%d", &num);
        lista = inserir_final(lista, num, i+1);
    }

    printar_lista(lista);
    
    int pulos;

    printf("Digite quantos deve pular: ");
    scanf("%d", &pulos);

    lista = remover_elemento_pulando(lista, pulos);

    printf("Posicao inicial do ultimo elemento restante: %d", lista->posicao);

    lista = liberar_lista(lista);

    return 0;
}