#include<stdio.h>
#include<stdlib.h>

typedef struct LISTA{
    
    int valor;
    struct LISTA* proximo;

}LISTA;

typedef struct PILHA{
    
    LISTA* topo;

}PILHA;

PILHA* criar_pilha();
PILHA* empilhar (PILHA* pilha, int valor);
int vazia_pilha(PILHA* pilha);
int desempilhar(PILHA* pilha);
void mostrar_pilha(PILHA* pilha);
PILHA* liberar_pilha(PILHA* pilha);
int existe_na_pilha(PILHA* pilha, int num);
PILHA* remover_duplicatas(PILHA* pilha);

int main(){

    PILHA* pilha = criar_pilha();
    int num;

    while (scanf("%d", &num) == 1){
        pilha = empilhar(pilha, num);
    }while(getchar() != '\n');

    mostrar_pilha(pilha);

    printf("Pilha sem duplicatas\n\n");
    pilha = remover_duplicatas(pilha);
    
    mostrar_pilha(pilha);

    pilha = liberar_pilha(pilha);

    mostrar_pilha(pilha);

    return 0;
}

PILHA* criar_pilha(){
    PILHA* pilha = malloc(sizeof(pilha));
    pilha->topo = NULL;
    return pilha;
}

PILHA* empilhar (PILHA* pilha, int valor){
    LISTA* lista = malloc(sizeof(LISTA));

    lista->valor = valor;
    lista->proximo = pilha->topo;
    pilha->topo = lista;

    return pilha;
}

int vazia_pilha(PILHA* pilha){
    return (pilha == NULL || pilha->topo == NULL);
}

int desempilhar(PILHA* pilha){

    int desempilhado;

    if (! vazia_pilha(pilha)){
        LISTA* lista = pilha->topo;

        desempilhado = lista->valor;
        pilha->topo = lista->proximo;
        free(lista);
    }else{
        desempilhado = -1;
    }
    return desempilhado;
}

void mostrar_pilha(PILHA* pilha){

    if (! vazia_pilha(pilha)){
        LISTA* lista = pilha->topo;
        int camada = 1;

        printf("TOPO DA PILHA\n\n");
        while (lista != NULL){
            
            printf("Camada %d: %d\n", camada, lista->valor);
            lista = lista->proximo;
            camada++;
            
        }
        printf("\nTOPO DA PILHA\n");
    }
}

PILHA* liberar_pilha(PILHA* pilha){

    if (! vazia_pilha(pilha)){
        LISTA* lista = pilha->topo;
        LISTA* aux;

        while (lista != NULL){
            
            aux = lista;
            lista = lista->proximo;
            free(aux);

        }
        free(pilha);
        pilha = NULL;
    }
    return pilha;
}

int existe_na_pilha(PILHA* pilha, int num){

    int existe = 0;
    LISTA* lista = pilha->topo;

    while(lista != NULL && existe == 0){
        if (lista->valor == num){
            existe = 1;
        }
        lista = lista->proximo;
    }
    return existe;
}

PILHA* remover_duplicatas(PILHA* pilha){
    PILHA* temp = criar_pilha();

    while (! vazia_pilha(pilha)){
        int valor = desempilhar(pilha);

        if (! existe_na_pilha(temp, valor)){
            temp = empilhar(temp, valor);
        }
    }

    while (! vazia_pilha(temp)){
        pilha = empilhar(pilha, desempilhar(temp));
    }
    free(temp);

    return pilha;
}