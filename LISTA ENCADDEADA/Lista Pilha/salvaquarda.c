#include<stdio.h>
#include<stdlib.h>

typedef struct LISTA{

    int valor;
    struct LISTA* proximo;

}LISTA;

typedef struct PILHA{

    LISTA* topo;
    //lempre que a estrutura pilha so tem um ponterio para lista
    //se fosse uma pilha de lista seria nescessario ter um ponteiro proximo na struct pilha
    //struct PILHA* proximo;
                       
}PILHA;

PILHA* criar_pilha();
PILHA* empilhar(PILHA* pilha, int valor);
int verifica_pilha_vazia(PILHA* pilha);
int desempilhar(PILHA* pilha);
void printar_pilha(PILHA* pilha);
PILHA* liberar_pilha(PILHA* pilha);

int main(){

    PILHA* pilha = criar_pilha();
    int desempilhado;

    pilha = empilhar(pilha, 1);
    pilha = empilhar(pilha, 2);
    pilha = empilhar(pilha, 3);
    pilha = empilhar(pilha, 4);
    pilha = empilhar(pilha, 5);

    printar_pilha(pilha);

    desempilhado = desempilhar(pilha);
    printf("Desempilhado: %d\n", desempilhado);
    // desempilhado = desempilhar(pilha);
    // printf("Desempilhado: %d\n", desempilhado);
    // desempilhado = desempilhar(pilha);
    // printf("Desempilhado: %d\n", desempilhado);
    // desempilhado = desempilhar(pilha);
    // printf("Desempilhado: %d\n", desempilhado);
    // desempilhado = desempilhar(pilha);
    // printf("Desempilhado: %d\n", desempilhado);
    
    printar_pilha(pilha);

    pilha = liberar_pilha(pilha);

    printar_pilha(pilha);

    return 0;
}

PILHA* criar_pilha(){
    PILHA* pilha = malloc(sizeof(PILHA));//apenas para criar a pilha e ela sempre começa em null
    pilha->topo = NULL;                 //não precisa receber nada, pois so retorna uma nova pilha 
    return pilha;                       //que eu vopu usar la no main
}

PILHA* empilhar(PILHA* pilha, int valor){
    LISTA* lista = malloc(sizeof(LISTA));

    lista->valor = valor;           //aqui basicamente eu crio um no da lista 
    lista->proximo = pilha->topo;   //aponto o proximo dele para o topo da pilha 
    pilha->topo = lista;            //e ajusto o topo para o novo topo

    return pilha;                   //com isso a struct pilha quarda so o topo e a struct lista quarda o proximo                              
}

int verifica_pilha_vazia(PILHA* pilha){//verifica se a pilha ou o no da pilha esta vazio e retorna "verdadeiro ou falso"
    return(pilha == NULL || pilha->topo == NULL);
}

int desempilhar(PILHA* pilha){

    int retorno;

    if (! verifica_pilha_vazia(pilha)){//eu verifico se a lista esta vazia, se não estiver
        LISTA* aux;

        aux = pilha->topo;              //eu atribuo o lista aux para o topo(primeiro elemento)
        retorno = aux->valor;           //pego o valor que vai ser retornado
        pilha->topo = aux->proximo;     //passo o topo para o proxomo elemento 
        free(aux);                      //e libero o aux, no caso, o no que foi desempilhado

    }else{
        retorno = -1;
        printf("\nErro: Pilha vazia ou inexistente.\n");
    }
    return retorno;
}

void printar_pilha(PILHA* pilha){

    if (! verifica_pilha_vazia(pilha)){//verifica se a lista esta vazia e se não estiver eu imprimo 
        LISTA* aux = pilha->topo;
        int elemento = 1;//para fazer a contagem dos elementos

        printf("DO TOPO PARA A BASE\n\n");

        while (aux != NULL){//faço normalmente como uma lista normal(se fosse pilha de lista mudaria um pouco)
            printf("Elemento %d: ", elemento);
            printf("%d\n", aux->valor);
            aux = aux->proximo;
            elemento++;
        }
        printf("\nBASE DA PILHA\n\n");
    }else{
        printf("\nPilha Vazia\n");
    }
}

PILHA* liberar_pilha(PILHA* pilha){

    if (! verifica_pilha_vazia(pilha)){//verifica se a lista ta vazia ou não
        LISTA* lista = pilha->topo;//atribuo o ponteiro lista ao topo o que basicamente vira uma lista normal
        LISTA* aux;

        while (lista != NULL){//o loop para printar é normal como lista
            aux = lista;      //se fosse pilha de lista seria diferente
            lista = lista->proximo;
            free(aux);
        }
        free(pilha);
        printf("Pilha Liberada\n\n");
        pilha = NULL;
    }else{
        printf("Pilha ja esta vazia\n\n");
    }
    return pilha;
}

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct LISTA{
    
//     int valor;
//     struct LISTA* proximo;

// }LISTA;

// typedef struct PILHA{
    
//     LISTA* topo;

// }PILHA;

// PILHA* criar_pilha();
// PILHA* empilhar (PILHA* pilha, int valor);
// int vazia_pilha(PILHA* pilha);
// int desempilhar(PILHA* pilha);
// void mostrar_pilha(PILHA* pilha);
// PILHA* liberar_pilha(PILHA* pilha);

// int main(){


//     return 0;
// }

// PILHA* criar_pilha(){
//     PILHA* pilha = malloc(sizeof(pilha));
//     pilha->topo = NULL;
//     return pilha;
// }

// PILHA* empilhar (PILHA* pilha, int valor){
//     LISTA* lista = malloc(sizeof(LISTA));

//     lista->valor = lista;
//     lista->proximo = pilha->topo;
//     pilha->topo = lista;

//     return pilha;
// }

// int vazia_pilha(PILHA* pilha){
//     return (pilha == NULL || pilha->topo == NULL);
// }

// int desempilhar(PILHA* pilha){

//     int desempilhado;

//     if (! vazia_pilha(pilha)){
//         LISTA* lista = pilha->topo;

//         desempilhado = lista->valor;
//         pilha->topo = lista->proximo;
//         free(lista);
//     }else{
//         desempilhado = -1;
//     }
//     return desempilhado;
// }

// void mostrar_pilha(PILHA* pilha){

//     if (! vazia_pilha(pilha)){
//         LISTA* lista = pilha->topo;
//         int camada = 1;

//         printf("TOPO DA PILHA\n\n");
//         while (lista != NULL){
            
//             printf("Camada %d: %d\n", camada, lista->valor);
//             lista = lista->proximo;
            
//         }
//         printf("\nTOPO DA PILHA\n");
//     }
// }

// PILHA* liberar_pilha(PILHA* pilha){

//     if (! vazia_pilha(pilha)){
//         LISTA* lista = pilha->topo;
//         LISTA* aux;

//         while (lista != NULL){
            
//             aux = lista;
//             lista = lista->proximo;
//             free(aux);

//         }
//         free(pilha);
//         pilha = NULL;
//     }
//     return pilha;
// }