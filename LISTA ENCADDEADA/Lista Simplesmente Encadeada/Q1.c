#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int valor;
    struct LSE* proximo;
}LSE;

LSE* novo_no(){
    LSE *novo_no = malloc(sizeof(LSE));
    return novo_no;
}

void inserir_no_inicio(LSE **lista, int valor){
    LSE* novo = novo_no();

    if(novo){
        novo->valor = valor;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar!!");
    }
}

void printar_lista(LSE *lista){
    if (lista == NULL){
        printf("lista vazia!!\n");
        exit(1);
    }

    LSE* atual = lista;

    while (atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void conta_elementos(LSE *lista){
    if (lista == NULL){
        printf("Lista Vazia!!\n");
    }
   

    LSE *atual = lista;
    int cont = 0;

    while (atual != NULL){
        cont ++;
        atual = atual->proximo;
    }

    printar_lista(lista);

    printf("A lista possui %d\n", cont);
    
}

LSE* libera_lista(LSE *lista){
    if (lista == NULL){
        printf("Lista vazia!\n");
    }else{
        LSE *atual = lista;
        while (atual != NULL){
            LSE * proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        printf("Lista liberada!!\n");
        lista = NULL;
    }
    return lista;
}

int main(){
    LSE* lista = NULL;

    printf("Digite qualquer coisa que nao um numero para finalizar a lista\n");

    while (1){
        int num;
        if(scanf("%d", &num)){
            inserir_no_inicio(&lista, num);
        }else{
            break;
        }
    }

    printar_lista(lista);

    conta_elementos(lista);

    lista = libera_lista(lista);
    
    return 0;
}