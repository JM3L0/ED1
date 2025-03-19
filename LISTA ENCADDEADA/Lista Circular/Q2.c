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
        } while (aux != lista);
        printf("Inicio\n\n");
    }
}

LEC* liberar_lista(LEC* lista){

    if (lista != NULL){
        LEC* inicio = lista;
        LEC* aux;

        do{
            aux = lista->proximo;
            free(lista);
            lista = aux;
        } while (aux != inicio);
        lista = NULL;
    }
    return lista;
}

int primos(int num){

    int P = 1;
    if (num <= 1)
        P = 0;// Não é primo
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            P = 0;// Não é primo
        }
        
    } 
    return P; // É primo
}

int main(){

    LEC* lista = NULL;

    int quantP, cont = 0, atual = 2;

    printf("Digite a quantidade de numeros primos: ");
    scanf("%d", &quantP);

    while (cont < quantP){
        if (primos(atual)){
            lista = inserir_final(lista, atual);
            cont ++;
        }
        atual++;
    }

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);

    return 0;
}