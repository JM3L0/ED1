#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{

    int valor;
    struct LEC* proximo;

}LEC;

LEC* novo_no(int valor);
LEC* ultimo_no(LEC* lista);
LEC* inserir_final(LEC* lista, int valor);
void printar_lista(LEC* lista);
LEC* liberar_lista(LEC* lista);
LEC* separar_par_impar(LEC* lista);

int main(){

    LEC* lista = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista = inserir_final(lista, num);
    }while(getchar() != '\n');
    
    printar_lista(lista);

    lista = separar_par_impar(lista);

    printar_lista(lista);

    lista = liberar_lista(lista);

    printar_lista(lista);

    return 0;
}

LEC* novo_no(int valor){
    LEC* no = malloc(sizeof(LEC));
    no->valor = valor;
    no->proximo = no;
    return no;
}

LEC* ultimo_no(LEC* lista){//pegar o ultimo elemento mais diretamente
    LEC* ultimo = lista;

    if (lista != NULL){
        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }
    }
    return ultimo;
}

LEC* inserir_final(LEC* lista, int valor){

    LEC* novo = novo_no(valor);

    if (lista == NULL){
        lista = novo;
    }else{
        LEC* ultimo = ultimo_no(lista);
        ultimo->proximo = novo;
        novo->proximo = lista;
    }
    return lista;
}

void printar_lista(LEC* lista){

    if (lista != NULL){
        LEC* aux = lista;

        do{

            printf("%d->", aux->valor);
            aux = aux->proximo;

        } while (aux != lista);
        printf("Inicio\n\n");
    }else{
        printf("Lista Vazia\n\n");
    }
}

LEC* liberar_lista(LEC* lista){

    if (lista != NULL){
        LEC* aux = lista;
        LEC* inicio = lista;

        do{

            lista = lista->proximo;
            printf("%d\n", aux->valor);
            free(aux);
            aux = lista;

        } while (aux != inicio);
        printf("\n");
        lista = NULL;
    }
    return lista;
}

LEC* separar_par_impar(LEC* lista){

    LEC* lista_par = NULL;
    LEC* lista_impar = NULL;

    if (lista != NULL){

        LEC* aux = lista;

        do{

            if (aux->valor %2 == 0){
                lista_par = inserir_final(lista_par, aux->valor);
            }else{
                lista_impar = inserir_final(lista_impar, aux->valor);
            }
            
            aux = aux->proximo;
            
        } while(aux != lista);
        
        LEC* ultimo_par = ultimo_no(lista_par);
        LEC* ultimo_impar = ultimo_no(lista_impar);

        ultimo_par->proximo = lista_impar;
        ultimo_impar->proximo = lista_par;

        lista = liberar_lista(lista);
        lista = lista_par;
    }

    return lista;
}