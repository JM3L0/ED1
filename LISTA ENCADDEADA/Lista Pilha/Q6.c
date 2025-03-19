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
PILHA* tirar_P2_P1(PILHA* pilha1, PILHA* pilha2);

int main(){

    PILHA* pilha1 = criar_pilha();
    PILHA* pilha2 = criar_pilha();
    int num;

    printf("Digite a pilha 1: ");
    while (scanf("%d", &num) == 1){
        pilha1 = empilhar(pilha1, num);
    }while(getchar() != '\n');

    printf("Digite a pilha 2: ");
    while (scanf("%d", &num) == 1){
        pilha2 = empilhar(pilha2, num);
    }while(getchar() != '\n');

    mostrar_pilha(pilha1);
    mostrar_pilha(pilha2);

    pilha1 = tirar_P2_P1(pilha1, pilha2);

    mostrar_pilha(pilha1);
    mostrar_pilha(pilha2);

    pilha1 = liberar_pilha(pilha1);
    pilha2 = liberar_pilha(pilha2);

    mostrar_pilha(pilha1);
    mostrar_pilha(pilha2);

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

PILHA* tirar_P2_P1(PILHA* pilha1, PILHA* pilha2){
    PILHA* aux_pilha = criar_pilha();

    if (vazia_pilha(pilha1)){
        printf("Pilha 1 vazia\n\n");
    }else if (vazia_pilha(pilha2)){
        printf("Pilha 2 vazia");
    }else{

        while (! vazia_pilha(pilha1)){
            
            int valor = desempilhar(pilha1);
            if (! existe_na_pilha(pilha2, valor)){
                aux_pilha = empilhar(aux_pilha, valor);
            }
        }
        
        while (! vazia_pilha(aux_pilha)){
            int valor = desempilhar(aux_pilha);

            pilha1 = empilhar(pilha1, valor);
        }
        free(aux_pilha);
    }
    return pilha1;
}