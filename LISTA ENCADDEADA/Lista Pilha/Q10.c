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
int eh_primo(int num);
void separa_primos(PILHA* pilha, PILHA* pilha_primos);

int main(){

    PILHA* pilha = criar_pilha();
    PILHA* pilha_P = criar_pilha();
    int num;

    while (scanf("%d", &num) == 1){
        pilha = empilhar(pilha, num);
    }while(getchar() != '\n');

    mostrar_pilha(pilha);

    separa_primos(pilha, pilha_P);

    printf("Pilha nao primos\n");
    mostrar_pilha(pilha);

    printf("Pilha Primos\n");
    mostrar_pilha(pilha_P);

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

int eh_primo(int num){
    int primo = 1;

    if (num > 1){
        
        for (int i = 2; i * i <= num; i++){
            if (num % i == 0){
                primo = 0;
            }   
        }
    }else{
        primo = 0;
    }
    return primo;
}

void separa_primos(PILHA* pilha, PILHA* pilha_primos){

    PILHA* aux_pilha = criar_pilha();
    PILHA* aux_pilha_primos = criar_pilha();

    while (! vazia_pilha(pilha)){

        int valor = desempilhar(pilha);
        
        if (eh_primo(valor)){
            aux_pilha_primos = empilhar(aux_pilha_primos, valor);
        }else{
            aux_pilha = empilhar(aux_pilha, valor);
        }
    }

    while (! vazia_pilha(aux_pilha)){
        pilha = empilhar(pilha, desempilhar(aux_pilha));
    }
    while (! vazia_pilha(aux_pilha_primos)){
        pilha_primos = empilhar(pilha_primos, desempilhar(aux_pilha_primos));
    }
    
    free(aux_pilha);
    free(aux_pilha_primos);
}
