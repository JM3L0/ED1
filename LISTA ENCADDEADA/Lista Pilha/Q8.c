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

int main(){

    PILHA* pilha = criar_pilha();
    int N;

    printf("Digite um numero: ");
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        if (N % i == 0){
            pilha = empilhar(pilha, i);
        }
    }

    printf("Pilha de divisore:\n\n");

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
