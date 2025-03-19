#include<stdio.h>
#include<stdlib.h>

typedef struct NO{

   int valor;
   struct NO* proximo;

}NO;

typedef struct FILA{
    
    NO* primeiro;
    NO* ultimo;

}FILA;

typedef struct PILHA{
    
    NO* topo;

}PILHA;

///////////FUNÇOES FILA/////////////
FILA* criar_fila();
void enfileirar(FILA* fila, int valor);
int vazia(FILA* fila);
int desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);
void inverter_fila(FILA* fila);
///////////FUNÇOES PILHA/////////////
PILHA* criar_pilha();
PILHA* empilhar(PILHA* pilha, int valor);
int verifica_pilha_vazia(PILHA* pilha);
int desempilhar(PILHA* pilha);
void printar_pilha(PILHA* pilha);
PILHA* liberar_pilha(PILHA* pilha);

int main(){

    FILA* fila = criar_fila();

    int num;

    while (scanf("%d", &num) == 1){
        enfileirar(fila, num);
    }while(getchar() != '\n');

    mostrar_fila(fila);

    inverter_fila(fila);

    mostrar_fila(fila);
    
    fila = liberar_fila(fila);

    mostrar_fila(fila);


    return 0;
}

//////////////////////////////////////////////////FILA//////////////////////////////////////////////////////////////
FILA* criar_fila(){
    FILA* fila = malloc(sizeof(FILA));

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

void enfileirar(FILA* fila, int valor){
    NO* novo = malloc(sizeof(NO));

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila->primeiro != NULL){//caso a fila não esteja vazia

        fila->ultimo->proximo = novo;//aponto o ultimo para o novo

    }else{//caso a fila esteja vazia

        fila->primeiro = novo;//aponto o primeiro para o novo

    }
    
    fila->ultimo = novo;//como essa é uma condição que sempre vai aconter já que é a estrutura da fila 
                        //pode-se colocar ela fora de qualquer condição
}

int vazia(FILA* fila){
    return (fila == NULL || fila->primeiro == NULL);
}

int desenfileirar(FILA* fila){

    int valor;

    if (! vazia(fila)){
        NO* aux = fila->primeiro;//preciso dessa cara unicamente para dar o free no elemento desenfileirado 
        
        valor = aux->valor;//pego o valor rerirado
        fila->primeiro = aux->proximo;//passo o primeiro para o proximo
        free(aux);//libero o NO do valor ja coletado

        if (fila->primeiro == NULL){//caso a fila fique vazia
            fila->ultimo = NULL;//eu igualo o ultimo a null
        }
        
    }else{
        valor = -1;//caso esteja vazio finaliza erro
    }
    return valor;
}

void mostrar_fila(FILA* fila){//mostrar normal de pilha e lista nao tem segredo

    if (! vazia(fila)){
        NO* aux = fila->primeiro;

        printf("\nInicio->");
        while (aux != NULL){
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }
        printf("Fim\n"); 

    }else{
        printf("\nFila Vazia\n");
    }
}

FILA* liberar_fila(FILA* fila){//a função retorna para poder printar sem problemas a fila depois
    NO* aux;                   //e para evitar o uso de ponteiro para ponteiro

    while (! vazia(fila)){
        aux = fila->primeiro;
        fila->primeiro = aux->proximo;
        free(aux);
    }

    free(fila);
    fila = NULL;

    return fila;
}

void inverter_fila(FILA* fila){//a questão é essa função aqui o resto é complementar
    PILHA* aux_pilha = criar_pilha();
    int valor;

    while (! vazia(fila)){
        valor = desenfileirar(fila);
        aux_pilha = empilhar(aux_pilha, valor);
    }

    while (! verifica_pilha_vazia(aux_pilha)){
        valor = desempilhar(aux_pilha);
        enfileirar(fila, valor);
    }
    free(aux_pilha);
}

//////////////////////////////////////////////////PILHA//////////////////////////////////////////////////////////////

PILHA* criar_pilha(){
    PILHA* pilha = malloc(sizeof(PILHA));//apenas para criar a pilha e ela sempre começa em null
    pilha->topo = NULL;                 //não precisa receber nada, pois so retorna uma nova pilha 
    return pilha;                       //que eu vopu usar la no main
}

PILHA* empilhar(PILHA* pilha, int valor){
    NO* lista = malloc(sizeof(NO));

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
        NO* aux;

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
        NO* aux = pilha->topo;
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
        NO* lista = pilha->topo;//atribuo o ponteiro lista ao topo o que basicamente vira uma lista normal
        NO* aux;

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