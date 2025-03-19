#include<stdio.h>
#include<stdlib.h>

typedef struct LISTA{
    
    char caractere;
    struct LISTA* proximo;

}LISTA;

typedef struct PILHA{

    LISTA* topo;

}PILHA;

PILHA* criar_pilha();
void empilhar(PILHA* pilha, char caractere);
int verificar_pilha_vazia(PILHA* pilha);
char desempilhar(PILHA* pilha);
void mostrar_pilha(PILHA* pilha);
PILHA* liberar_pilha(PILHA* pilha);
//PILHA* invert_pilha(PILHA* pilha);

int main(){

    PILHA* pilha = criar_pilha();
    
    char caractere;

    while (scanf("%c", &caractere) == 1 && caractere != '\n'){
        empilhar(pilha, caractere);
    }

    mostrar_pilha(pilha);

    //pilha = invert_pilha(pilha);

    //mostrar_pilha(pilha);

    //pilha = liberar_pilha(pilha);

    mostrar_pilha(pilha);

    return 0;
}

PILHA* criar_pilha(){
    PILHA* pilha = malloc(sizeof(PILHA));

    pilha->topo = NULL;

    return pilha;
}

void empilhar(PILHA* pilha, char caractere){
    LISTA* lista = malloc(sizeof(LISTA));

    lista->caractere = caractere;
    lista->proximo = pilha->topo;
    pilha->topo = lista;
}

int verificar_pilha_vazia(PILHA* pilha){
    return (pilha == NULL || pilha->topo == NULL);
}

char desempilhar(PILHA* pilha){

    char retorno_carctere;

    if (! verificar_pilha_vazia(pilha)){
        
        LISTA* lista = pilha->topo;
        retorno_carctere = lista->caractere;
        pilha->topo = lista->proximo;
        free(lista);

    }else{
        printf("Pilha esta vazia\n\n");
        retorno_carctere = -1;
    }
    return retorno_carctere;
}

void mostrar_pilha(PILHA* pilha){

    if (! verificar_pilha_vazia(pilha)){
        
        LISTA* lista = pilha->topo;
        //int elemento = 1;

        printf("TOPO DA PILHA\n\n");

        while (lista != NULL){

            //printf("Elemento %d: %c\n", elemento, lista->caractere);
            printf("%c", lista->caractere);
            lista = lista->proximo;
            //elemento++;

        }

        printf("\nBASE DA PILHA\n\n");
    }else{
        printf("Pilha Vazia\n\n");
    }
}

PILHA* liberar_pilha(PILHA* pilha){

    if (! verificar_pilha_vazia(pilha)){
        
        LISTA* lista = pilha->topo;
        LISTA* aux;

        while (lista != NULL){
            aux = lista;
            lista = lista->proximo;
            free(aux);
        }
        free(pilha);
        pilha = NULL;
    }else{
        printf("Pilha ja vazia\n\n");
    }
    return pilha;
}

// PILHA* invert_pilha(PILHA* pilha){
//     PILHA* pilha_invert = criar_pilha(pilha);
//     char caractere;

//     while (!verificar_pilha_vazia(pilha)){
//         caractere = desempilhar(pilha);
//         empilhar(pilha_invert, caractere);
//     }
//     return pilha_invert;
// }