#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{

    int valor;
    struct LSE* proximo;

}LSE;

LSE* novo_no(){
    LSE* no = malloc(sizeof(LSE));
    return no;
}

LSE* inseri_inicio(LSE* lista, int valor){
    LSE* novo = novo_no();

    if (novo){
        novo->valor = valor;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro de alocacao");
    }
    return lista;
}

void printar_lista(LSE* lista){
    if (lista == NULL){
        printf("Lista vazia\n");
    }else{
        LSE* aux = lista;

        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

LSE* intercesao(LSE* lista1, LSE* lista2, LSE* lista3){
    LSE* aux1 = lista1;
    LSE* aux2;

    while (aux1 != NULL){
        aux2 = lista2;
        while (aux2 != NULL){
            if(aux1->valor == aux2->valor){
                lista3 = inseri_inicio(lista3, aux1->valor);
            }
            aux2 = aux2->proximo;
        }
        aux1 = aux1->proximo;        
    }
    return lista3;
}

void libera_lista(LSE* lista){
    LSE* aux = lista;

    while (aux != NULL){
        lista = lista->proximo;
        free(aux);
        aux = lista;
    }
    printf("Lista Liberada!!\n");
}

int main(){

    LSE* lista1 = NULL;
    LSE* lista2 = NULL;
    int num;

    printf("Digite a lista 1\n");
    while (scanf("%d", &num) == 1){
        lista1 = inseri_inicio(lista1, num);
    }
    while(getchar() != '\n');

    printf("Digite a lista 2\n");
    while(scanf("%d", &num) == 1){
        lista2 = inseri_inicio(lista2, num);
    }
    while (getchar() != '\n');
    
    printar_lista(lista1);
    printar_lista(lista2);

    LSE* lista3 = NULL;

    lista3 = intercesao(lista1, lista2, lista3);

    printar_lista(lista3);

    libera_lista(lista1);
    libera_lista(lista2);
    libera_lista(lista3);
    return 0;
}