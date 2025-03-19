#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int valor;
    struct LSE* proximo;
}LSE;

LSE* novo_no(){
    LSE* novo = malloc(sizeof(LSE));
    return novo;
}

LSE* inserir_inicio(LSE* lista, int valor){
    LSE* novo = novo_no();

    if (novo){
        novo->valor = valor;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro de alocacao de valor!!\n");
    }

    return lista;
}

LSE* libera_lista(LSE* lista){
    LSE* aux = lista;

    if (lista == NULL){
        printf("Lista vazia!!\n");
    }else{

        while (aux != NULL){
            LSE* proximo = aux->proximo;
            free(aux);
            aux = proximo;
        }
        printf("Lista liberada!!\n");
        lista = NULL;
    }
    return lista;
}

void busca_na_lista(LSE* lista, int buscado){
    LSE* atual = lista;

    int cont = 0, achou = 0;
    while (atual != NULL){
        if (atual->valor == buscado){
            printf("Valor buscado encontrado na posicao %d da lista\n", cont);
            achou ++;
        }
        atual = atual->proximo;
        cont ++;
    }
    if(achou == 0){
        printf("Elemento nao encontrado na lista\n\n");
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

int main(){
    LSE* lista = NULL;

    int num;
    printf("Digite qualquer coisa que nao um numero para finalizar a lista\n");

    while (scanf("%d", &num) == 1){
        lista = inserir_inicio(lista, num);
    }
    
    while (getchar() != '\n');//Limpar o buffer

    printar_lista(lista);

    int buscado;
    printf("\nDigite o elemento a ser buscado na lista: ");
    scanf("%d", &buscado);

    busca_na_lista(lista, buscado);

    libera_lista(lista);
    
    return 0;
}