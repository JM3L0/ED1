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
PILHA* empilhar(PILHA* pilha, int valor);
int verificar_pilha_vazia(PILHA* pilha);
int desempilhar(PILHA* pilha);
void mostrar_pilha(PILHA* pilha);
PILHA* liberar_pilha(PILHA* pilha);
PILHA* remover_menoresQ(PILHA* pilha, int remover);

int main(){

    PILHA* pilha = criar_pilha();
    int num;

    while (scanf("%d", &num) == 1){
        pilha = empilhar(pilha, num);
    }while(getchar() != '\n');

    mostrar_pilha(pilha);

    printf("Digite um numero (valores menores que ele seram removidos): ");
    scanf("%d", &num);

    pilha = remover_menoresQ(pilha, num);

    mostrar_pilha(pilha);

    pilha = liberar_pilha(pilha);

    mostrar_pilha(pilha);

    return 0;
}

PILHA* criar_pilha(){
    PILHA* pilha = malloc(sizeof(PILHA));

    pilha->topo = NULL;
    return pilha;
}

PILHA* empilhar(PILHA* pilha, int valor){
    LISTA* lista = malloc(sizeof(lista));

    lista->valor = valor;
    lista->proximo = pilha->topo;
    pilha->topo = lista;

    return pilha;
}

int verificar_pilha_vazia(PILHA* pilha){
    return (pilha == NULL || pilha->topo == NULL);
}

int desempilhar(PILHA* pilha){

    int desempilhado;

    if (! verificar_pilha_vazia(pilha)){
        desempilhado = pilha->topo->valor;
        LISTA* aux = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(aux);
    }else{
        desempilhado = -1;
    }
    return desempilhado;
}

void mostrar_pilha(PILHA* pilha){

    if (! verificar_pilha_vazia(pilha)){
        LISTA* lista = pilha->topo;
        int camada = 1;

        printf("TOPO DA PILHA\n\n");

        while (lista != NULL){
            printf("Camada %d: %d\n", camada, lista->valor);
            lista = lista->proximo;
            camada++;
        }
        printf("\nBASE DA PILHA\n\n");
    }else{
        printf("Pilha vazia\n\n");
    }
}

PILHA* liberar_pilha(PILHA* pilha){

    if (!verificar_pilha_vazia(pilha)){
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

PILHA* remover_menoresQ(PILHA* pilha, int remover){

    PILHA* aux_pilha = criar_pilha();
    int desempilhado;

    if (! verificar_pilha_vazia(pilha)){
        
        while (! verificar_pilha_vazia(pilha)){
            desempilhado = desempilhar(pilha);

            if (desempilhado >= remover){
                aux_pilha = empilhar(aux_pilha, desempilhado);
            }
        }

        while (! verificar_pilha_vazia(aux_pilha)){
            desempilhado = desempilhar(aux_pilha);
            pilha = empilhar(pilha, desempilhado);
        }
        free(aux_pilha);
    }
    return pilha;
}