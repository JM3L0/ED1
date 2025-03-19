#include<stdio.h>
#include<stdlib.h>

typedef struct LISTA{

    int valor;
    struct LISTA* proximo;

}LISTA;

typedef struct POILHA{
    
    LISTA* topo;

}PILHA;

PILHA* criar_pilha();
PILHA* empilhar(PILHA* pilha, int valor);
int verifica_pilha_vazia(PILHA* pilha);
int desempilhar(PILHA* pilha);
PILHA* libera_pilha(PILHA* pilha);
void printar_pilha(PILHA* pilha);
PILHA* decimal_para_binario(PILHA* pilha, int num);

int main(){

    PILHA* pilha = criar_pilha();
    //int desempilhado;

    //pilha = empilhar(pilha, 5);

    //printar_pilha(pilha);

    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    pilha = decimal_para_binario(pilha, num);
    
    printar_pilha(pilha);

    while (!verifica_pilha_vazia(pilha)) {
        printf("%d", desempilhar(pilha));  // Retirar os elementos da pilha e imprimir
    }

    //desempilhado = desempilhar(pilha);

    pilha = libera_pilha(pilha);
    //printf("passoi aqui\n");

    printar_pilha(pilha);
    //printf("passoi aqui\n");

    return 0;
}

PILHA* criar_pilha(){
    PILHA* pilha = malloc(sizeof(PILHA));

    pilha->topo = NULL;

    return pilha;
}

PILHA* empilhar(PILHA* pilha, int valor){ //semelhante ao inserir no inicio da lista normal
    LISTA* novo = malloc(sizeof(LISTA)); // tem que manter o ponteiro do topo atualizado

    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
  
    return pilha;
}

int verifica_pilha_vazia(PILHA* pilha){
    return(pilha == NULL || pilha->topo == NULL);
}

int desempilhar(PILHA* pilha){

    int retorno;

    if (pilha == NULL || pilha->topo == NULL){
        printf("\nErro: Pilha vazia ou inexistente.\n");
        retorno = -1;  // Define o valor especial para indicar erro
    }else{
        LISTA* temp; //ponteiro temporario para armazenar o elemento a ser removido 

        temp = pilha->topo;
        retorno = temp->valor;
        pilha->topo = temp->proximo;
        free(temp);
    }
    return retorno;
}

PILHA* libera_pilha(PILHA* pilha){

    if (pilha != NULL){
        LISTA* liberar = pilha->topo;

        while (liberar != NULL){
            LISTA* temp = liberar->proximo;
            free(liberar);
            liberar = temp;
        }
        free(pilha);//liberar a pilha no final
        pilha = NULL;
        printf("\nPilha Liberada\n\n");
    }
    //printf("passoi aqui\n");
    return pilha;
}

void printar_pilha(PILHA* pilha){
    
    if (! verifica_pilha_vazia(pilha)){
        LISTA* lista = pilha->topo;
        int elemento = 1;

        printf("Do topo para a base:\n\n");

        while (lista != NULL){
            printf("Elemento %d:\n", elemento);
            printf("%d\n\n", lista->valor);
            lista = lista->proximo;
            elemento ++;
        }
    }else{
        printf("\nPilha Vazia\n\n");
    }
}

PILHA* decimal_para_binario(PILHA* pilha, int num){

    while (num > 0){
        pilha = empilhar(pilha, num % 2);
        num = num/2;
    }

    return pilha;    
}