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
void separa_POS_NEG(PILHA* pilha, PILHA* pilha_POS, PILHA* pilha_NEG);

int main(){

    PILHA* pilha = criar_pilha();
    PILHA* pilha_positivos = criar_pilha();
    PILHA* pilha_negativos = criar_pilha();
    int num;

    while (scanf("%d", &num) == 1){
        pilha = empilhar(pilha, num);
    }while(getchar() != '\n');


    mostrar_pilha(pilha);

    separa_POS_NEG(pilha, pilha_positivos, pilha_negativos);

    mostrar_pilha(pilha);

    printf("\nPilha Positivos\n");
    mostrar_pilha(pilha_positivos);

    printf("\nPilha Negativos\n");
    mostrar_pilha(pilha_negativos);

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
    }else{
        printf("\nPilha Vazia\n");
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

void separa_POS_NEG(PILHA* pilha, PILHA* pilha_POS, PILHA* pilha_NEG){

    while (! vazia_pilha(pilha)){
        int valor = desempilhar(pilha);
        
        if (valor > 0){
            pilha_POS = empilhar(pilha_POS, valor);
        }else if(valor < 0){
            pilha_NEG = empilhar(pilha_NEG, valor);
        }
    }
}
