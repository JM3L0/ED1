#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LEC{

    char nome[50];
    struct LEC* proximo;

}LEC;

LEC* novo_no(char* nome){// para passar um char no uso de lista como é uma string deve-se passar um ponteiro de char--> char* nome
    LEC* no = malloc(sizeof(LEC));
    strcpy(no->nome, nome); // tem que usar o strcpy(no->nome, nome) para atribuir o nome, diretamente não vai
    no->proximo = no;
    return no;
}

LEC* inserir_final(LEC* lista, char* nome){

    LEC* novo = novo_no(nome);

    if (lista == NULL){
        lista = novo;
    }else{
        LEC* ultimo = lista;

        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novo;
        novo->proximo = lista;
    }
    
    return lista;
}

LEC* liberar_lista(LEC* lista){

    if (lista != NULL){
        LEC* aux ;
        LEC* inicio = lista;

        do{
            aux = lista->proximo;
            free(lista);
            lista = aux;
        } while (aux != inicio);
        lista = NULL;
    }
    
    return lista;
}

LEC* inverte_lista(LEC* lista){    

    if (lista != NULL && lista->proximo != lista){
        
        LEC* anterior = NULL;
        LEC* atual = lista;
        LEC* proximo = NULL;

        do{
            
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual =  proximo;

        } while (atual != lista);
        
        lista->proximo = anterior;
        lista = anterior;
    }
    return lista;
}

void printar_lista(LEC* lista){

    if (lista == NULL){
        printf("Lista Vazia\n\n");
    }else{
        LEC* aux = lista;

        do{
            printf("%s->", aux->nome);
            aux = aux->proximo;
        } while (aux != lista);
        printf("Inicio\n\n");
    }
    
}

int main(){

    LEC* lista = NULL;

    int numNomes;
    printf("Digite a quantidade de nomes: ");
    scanf("%d", &numNomes);

    char nome[50];

    for(int i = 0; i < numNomes; i++){
        printf("Digite o %d nome: ", i+1);
        scanf(" %[^\n]", nome);

        lista = inserir_final(lista, nome);// na chamada da funcao posso passar o nome normalmente não precisa ser por ponteiro
    }

    printar_lista(lista);

    lista = inverte_lista(lista);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);

    return 0;
}