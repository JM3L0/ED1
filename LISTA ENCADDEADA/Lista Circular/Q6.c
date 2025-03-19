#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{

    int valor;
    struct LEC* proximo;

}LEC;

LEC* novo_no(int valor){
    LEC* no = malloc(sizeof(LEC));
    no->valor = valor;
    no->proximo = no;
    return no;
}

LEC* ultimo_no(LEC* lista){

    LEC* ultimo = lista;
    while (ultimo->proximo != lista){
        ultimo = ultimo->proximo;
    }
    return ultimo;
}

LEC* inseri_na_ordem(LEC* lista, int valor){

    LEC* novo = novo_no(valor);
    if(lista == NULL){
        lista = novo;

    }else if(lista->proximo == lista){
        
        if (lista->valor >= novo->valor){
            
            novo->proximo = lista;
            lista->proximo = novo;
            lista = novo;
        }else{

            lista->proximo = novo;
            novo->proximo = lista;
        }
    }else{

        LEC* aux = lista;
        LEC* anterior =  NULL;
        
        do{
            anterior = aux;
            aux = aux->proximo;

        }while(novo->valor >= aux->valor && aux != lista);

        // verifica se tem que colocar no inicio da lista
        if (novo->valor < lista->valor){// mais confiavel que (anterior == lista)

            LEC* ultimo = ultimo_no(lista);

            novo->proximo = lista;
            ultimo->proximo = novo;
            lista = novo;
        
        }else{// para o meio e fim da lista

            anterior->proximo = novo;
            novo->proximo = aux;
        }
    }
    return lista;
}

void printar_lista(LEC* lista){
    LEC* aux = lista;

    if (lista != NULL){
        do{
            printf("%d->", aux->valor);
            aux = aux->proximo;
        } while (aux != lista);
        printf("Inicio\n\n");
    }else{
        printf("Lista Vazia!\n\n");
    }
}

LEC* liberar_lista(LEC* lista){
    LEC* aux = NULL;
    LEC* inicio = lista;

    if (lista != NULL)
    {
        do{
            aux = lista->proximo;
            free(lista);
            lista = aux;
        } while (aux != inicio);
        lista = NULL;
    }
    return lista;
}

int main(){

    LEC* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inseri_na_ordem(lista, num);
    }while(getchar() != '\n');

    printf("Digite o numero a ser inserido: ");
    scanf("%d", &num);

    lista = inseri_na_ordem(lista, num);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);

    return 0;
}