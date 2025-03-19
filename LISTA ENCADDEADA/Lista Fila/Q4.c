#include<stdio.h>
#include<stdlib.h>

typedef struct NO{

   char caractere;
   struct NO* proximo;

}NO;

typedef struct FILA{
    
    NO* primeiro;
    NO* ultimo;

}FILA;

FILA* criar_fila();
void enfileirar(FILA* fila, int caractere);
int vazia(FILA* fila);
char desenfileirar(FILA* fila);
void mostrar_fila(FILA* fila);
FILA* liberar_fila(FILA* fila);
int tamanho_fila(FILA* fila);
int menor_num(int a, int b, int c);
void distribuir_nos_caixas(FILA* fila, FILA* caixa1, FILA* caixa2, FILA* caixa3);

int main(){

    FILA* fila = criar_fila();

    FILA* caixa1 = criar_fila();
    FILA* caixa2 = criar_fila();
    FILA* caixa3 = criar_fila();

    char caractere;

    while (scanf("%c", &caractere) == 1 && caractere != '\n'){
        enfileirar(fila, caractere);
    }
    
    mostrar_fila(fila);

    distribuir_nos_caixas(fila, caixa1, caixa2, caixa3);

    printf("Caixa1: ");
    mostrar_fila(caixa1);
    printf("Caixa2: ");
    mostrar_fila(caixa2);
    printf("Caixa3: ");
    mostrar_fila(caixa3);

    mostrar_fila(fila);
    
    fila = liberar_fila(fila);

    mostrar_fila(fila);


    return 0;
}

FILA* criar_fila(){
    FILA* fila = malloc(sizeof(FILA));

    fila->primeiro = NULL;
    fila->ultimo = NULL;

    return fila;
}

void enfileirar(FILA* fila, int caractere){
    NO* novo = malloc(sizeof(NO));

    novo->caractere = caractere;
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

char desenfileirar(FILA* fila){

    char caractere;

    if (! vazia(fila)){
        NO* aux = fila->primeiro;//preciso dessa cara unicamente para dar o free no elemento desenfileirado 
        
        caractere = aux->caractere;//pego o caractere rerirado
        fila->primeiro = aux->proximo;//passo o primeiro para o proximo
        free(aux);//libero o NO do caractere ja coletado

        if (fila->primeiro == NULL){//caso a fila fique vazia
            fila->ultimo = NULL;//eu igualo o ultimo a null
        }
        
    }else{
        caractere = -1;//caso esteja vazio finaliza erro
    }
    return caractere;
}

void mostrar_fila(FILA* fila){//mostrar normal de pilha e lista nao tem segredo

    if (! vazia(fila)){
        NO* aux = fila->primeiro;

        printf("\nInicio->");
        while (aux != NULL){
            printf("%c->", aux->caractere);
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

int tamanho_fila(FILA* fila){
    int tamanho = 0;

    if (! vazia(fila)){
        NO* aux = fila->primeiro;

        while (aux != NULL){
            tamanho++;
            aux = aux->proximo;
        }
    }
    return tamanho;
}

int menor_num(int a, int b, int c){
    int menor = a;

    if (b < menor) menor = b;
    if (c < menor) menor = c;

    return menor;
}

void distribuir_nos_caixas(FILA* fila, FILA* caixa1, FILA* caixa2, FILA* caixa3){
    int T_caixa1;
    int T_caixa2;
    int T_caixa3;
    int menor;
    int valor;

    while (! vazia(fila)){
        
        T_caixa1 = tamanho_fila(caixa1);
        T_caixa2 = tamanho_fila(caixa2);
        T_caixa3 = tamanho_fila(caixa3);

        menor =  menor_num(T_caixa1, T_caixa2, T_caixa3);

        if (menor == T_caixa1){
            valor = desenfileirar(fila);
            enfileirar(caixa1, valor);
        }else if (menor == T_caixa2){
            valor = desenfileirar(fila);
            enfileirar(caixa2, valor);
        }else{
            valor = desenfileirar(fila);
            enfileirar(caixa3, valor);
        }
    }
}