#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int valor;
    struct LSE* proximo;
}LSE;

///////// FUNÇÕES - LISTA ENCADEADA ////////////
LSE* novo_no();
LSE* inserir_no_inicio(LSE* lista, LSE* novo);
LSE* inserir_final(LSE* lista, LSE* novo);
LSE* inserir_posicao(LSE* lista, LSE* novo, int posicao);
LSE* inserir_recursivo(LSE* lista, LSE* novo, int posicao);
void inserir_ordenado_recursivo(LSE** lista, LSE* novo);
void consultar_posicao(LSE* lista, int posicao);
LSE* remover_elemento(LSE* lista, int elemento);
void printar_lista(LSE* lista);
void printar_lista_recursiva(LSE* lista);
LSE* libera_lista(LSE* lista);

///////// FUNÇÕES - RECURSIVIDADE ////////////
int soma_lista_recursiva(LSE* lista);

void menu();

int main(){
    LSE* lista = NULL;
    while(1){

        printar_lista(lista);
        
        menu();

        int opcao;
        printf("Digite a Opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            int numero;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            LSE* novo = novo_no();
            if(novo){
                novo->valor = numero;
                lista = inserir_no_inicio(lista, novo);
                printf("Inserido no inicio!\n\n");
            }
            break;
        }
        case 2:{
            int numero;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            LSE* novo = novo_no();
            if(novo){
                novo->valor = numero;
                lista = inserir_final(lista, novo);
                printf("Inserido no final!\n\n");
            }
            break;
        }
        case 3:{
            int numero, posicao;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            printf("Digite a posicao (0 para inicio): ");
            scanf("%d", &posicao);
            LSE* novo = novo_no();
            if(novo){
                novo->valor = numero;
                lista = inserir_posicao(lista, novo, posicao);
                printf("Inserido na posicao!\n\n");
            }
            break;
        }
        case 4:{
            int numero, posicao;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            printf("Digite a posicao (0 para inicio): ");
            scanf("%d", &posicao);
            LSE* novo = novo_no();
            if(novo){
                novo->valor = numero;
                lista = inserir_recursivo(lista, novo, posicao);
                printf("Inserido na posicao (recursivo)!\n\n");
            }
            break;
        }
        case 5:{
            int numero;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            LSE* novo = novo_no();
            if(novo){
                novo->valor = numero;
                inserir_ordenado_recursivo(&lista, novo);
                printf("Inserido em ordem (recursivo)!\n\n");
            }
            break;
        }
        case 6:{
            int posicao;
            printf("Digite a posicao a consultar: ");
            scanf("%d", &posicao);
            consultar_posicao(lista, posicao);
            break;
        }
        case 7:{
            int elemento;
            printf("Digite o valor a remover: ");
            scanf("%d", &elemento);
            lista = remover_elemento(lista, elemento);
            printf("Elemento removido!\n\n");
            break;
        }
        case 8:
            printf("Lista (iterativa):\n");
            printar_lista(lista);
            break;
        case 9:
            printf("Lista (recursiva):\n");
            printar_lista_recursiva(lista);
            printf("NULL\n\n");
            break;
        case 10:{
            if(lista != NULL){
                int soma = soma_lista_recursiva(lista);
                printf("Soma dos elementos (recursiva): %d\n\n", soma);
            }else{
                printf("Lista vazia!\n\n");
            }
            break;
        }
        case 11:
            lista = libera_lista(lista);
            break;
        default:
            return 0;
        }
    }

    return 0;
}

void menu(){
    printf("----- REVISAO ED1 - MENU -----\n\n");
    printf("--- LISTA ENCADEADA ---\n");
    printf("1-> Inserir no inicio\n");
    printf("2-> Inserir no final\n");
    printf("3-> Inserir em posicao especifica (iterativo)\n");
    printf("4-> Inserir em posicao especifica (recursivo)\n");
    printf("5-> Inserir em ordem (recursivo)\n");
    printf("6-> Consultar posicao especifica\n");
    printf("7-> Remover elemento\n");
    printf("8-> Listar (iterativa)\n");
    printf("9-> Listar (recursiva)\n");
    printf("--- RECURSIVIDADE ---\n");
    printf("10-> Soma lista recursiva\n");
    printf("--- GERAL ---\n");
    printf("11-> Liberar lista\n");
    printf("0-> Sair\n\n");
}

/////////////////////////////FUNÇÕES LISTA ENCADEADA/////////////////////////////

LSE* novo_no(){
    LSE* no = malloc(sizeof(LSE));

    if(no){
        no->proximo = NULL;
    }else{
        printf("Erro de alocacao\n");
        no = NULL;
    }

    return no;
}

LSE* inserir_no_inicio(LSE* lista, LSE* novo){

    if (novo != NULL){
        novo->proximo = lista;
        lista = novo;
    } 
    return lista;
}

LSE* inserir_final(LSE* lista, LSE* novo){
    if (lista ==  NULL){
        lista = novo;
    }else{
        LSE* aux = lista;

        while (aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }

    return lista;
}

LSE* inserir_posicao(LSE* lista, LSE* novo, int posicao){
    
    if(posicao == 0){
        novo->proximo = lista;
        lista = novo;
    }else{
        LSE* aux = lista;
        int cont = 0;

        while(aux != NULL && cont < posicao - 1){
            aux = aux->proximo;
            cont++;
        }

        if(aux != NULL){
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }else{
            printf("Posicao invalida!\n");
            free(novo);
        }
    }

    return lista;
}

LSE* inserir_recursivo(LSE* lista, LSE* novo, int posicao){
    LSE* result;

    if(posicao == 0){
        novo->proximo = lista;
        result = novo;
    }else if(lista == NULL){
        printf("Posicao invalida!\n");
        free(novo);
        result = lista;
    }else{
        lista->proximo = inserir_recursivo(lista->proximo, novo, posicao - 1);
        result = lista;
    }

    return result;
}

void inserir_ordenado_recursivo(LSE** lista, LSE* novo){

    if (*lista == NULL){
        *lista = novo;
    }else{
        if (novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }else{
            inserir_ordenado_recursivo(&(*lista)->proximo, novo);
        }
    }
}

void consultar_posicao(LSE* lista, int posicao){
    LSE* aux = lista;
    int cont = 0;

    if (lista == NULL){
        printf("Lista Vazia\n\n");
    }else{
        while (aux != NULL){
            if(cont == posicao){
                printf("Elemento na posicao %d: %d\n\n", posicao, aux->valor);
                aux = NULL;
            }else{
                cont++;
                aux = aux->proximo;
            }
        }

        if(aux == NULL && cont != posicao){
            printf("Posicao %d nao encontrada\n\n", posicao);
        }
    }
}

LSE* remover_elemento(LSE* lista, int elemento){
    LSE* aux = lista;

    if (aux != NULL && aux->valor == elemento){
        lista = lista->proximo;
        free(aux);
    }else{
        while (aux != NULL && aux->proximo != NULL){
            LSE* proximo = aux->proximo;
            if(proximo->valor == elemento){
                aux->proximo = proximo->proximo;
                free(proximo);
                aux = NULL;
            }else{
                aux = aux->proximo;
            }
        }
    }

    return lista;
}

void printar_lista(LSE* lista){
    LSE* aux = lista;

    while (aux != NULL){
        printf("%d->", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n\n");
}

LSE* libera_lista(LSE* lista){
    LSE* aux = lista;

    if (lista != NULL){
        while(aux != NULL){
            lista = lista->proximo;
            free(aux);
            aux = lista;
        }
    }
    lista = NULL;
    printf("Lista Liberada\n");
    return lista;
}

/////////////////////////////FUNÇÕES RECURSIVIDADE/////////////////////////////

int soma_lista_recursiva(LSE* lista){
    int resultado;

    if(lista == NULL){
        resultado = 0;
    }else{
        resultado = lista->valor + soma_lista_recursiva(lista->proximo);
    }

    return resultado;
}

void printar_lista_recursiva(LSE* lista){
    if(lista != NULL){
        printf("%d->", lista->valor);
        printar_lista_recursiva(lista->proximo);
    }
}
