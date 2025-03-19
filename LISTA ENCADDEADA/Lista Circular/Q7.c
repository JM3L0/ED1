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

LEC* ultimo_no(LEC* lista){
    LEC* ultimo = lista;
    while (ultimo->proximo != lista){
        ultimo = ultimo->proximo;
    }
    return ultimo;
}

LEC* inserir_final(LEC* lista, int valor){

    LEC* novo = novo_no(valor);

    if (lista == NULL){
        lista = novo;
    }else{
        LEC* ultimo = ultimo_no(lista);
        novo->proximo = ultimo->proximo;
        ultimo->proximo = novo;
    }
    return lista;
}

LEC* alterna_listas(LEC* lista1, LEC* lista2){

    LEC* lista_mesclada = NULL;

    if (lista1 == NULL){
        lista_mesclada = lista2;
    }else if(lista2 == NULL){
        lista_mesclada = lista1;
    }else{

        LEC* atualL1 = lista1;
        LEC* atualL2 = lista2;

        LEC* proxL1 = lista1->proximo;
        LEC* proxL2 = lista2->proximo;
        

        while (proxL1 != lista1 && proxL2 != lista2){
           atualL1->proximo = atualL2;
           atualL2->proximo = proxL1;

           atualL1 = proxL1;
           atualL2 = proxL2;

           proxL1 = proxL1->proximo;
           proxL2 = proxL2->proximo;
        }

        if (proxL1 == lista1 && proxL2 != lista2){// para a lista 2 maior que a lista 1

            atualL1->proximo = atualL2;
            LEC* ultimoL2 = ultimo_no(lista2);// se tentar pegar o ultimo antes de fazer a ligação acima ele quebra pos o fluxo do ponteiro não esta estavel
            ultimoL2->proximo = proxL1;

        }else if (proxL1 != lista1 && proxL2 == lista2){// para a lista 1 maior que a lista 2
            
            atualL1->proximo = atualL2;
            atualL2->proximo = proxL1;

        }else{
            
            atualL1->proximo = atualL2;
            atualL2->proximo = proxL1;

        }

        lista_mesclada = lista1;
    }
    
    return lista_mesclada;
}

void printar_lista(LEC* lista){

    if (lista != NULL){

        LEC* aux = lista;
        do{

            printf("%d->", aux->valor);
            aux = aux->proximo;

        } while (aux != lista);
        printf("Inicio\n\n");

    }else{
        printf("Lista Vazia!\n\n");
    }
}

LEC* liberar_lista(LEC* lista){

    if (lista != NULL){
        
        LEC* aux = NULL;
        LEC* inicio = lista;

        do{
            aux = lista->proximo;
            free(lista);
            lista = aux;

        } while (aux != inicio);
        lista = NULL;
    }
    return lista;
}

int main(){

    LEC* lista1 = NULL;
    LEC* lista2 = NULL;
    int num;

    while (scanf("%d", &num) == 1){
        lista1 = inserir_final(lista1, num);
    }while(getchar() != '\n');

    while (scanf("%d", &num) == 1){
        lista2 = inserir_final(lista2, num);
    }while(getchar() != '\n');

    lista1 = alterna_listas(lista1, lista2);

    printar_lista(lista1);

    lista1 = liberar_lista(lista1);

    printar_lista(lista1);
    
    return 0;
}