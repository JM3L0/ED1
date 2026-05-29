#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int valor;
    struct LSE* proximo;
}LSE;

///////// FUNÇÕES - LISTA ENCADEADA ////////////
LSE* novo_no();
LSE* inserir_no_inicio(LSE* lista, int valor);
LSE* inserir_final(LSE* lista, int valor);
LSE* inserir_posicao(LSE* lista, int valor, int posicao);
LSE* consultar_posicao(LSE* lista, int posicao);
LSE* remover_elemento(LSE* lista, int elemento);
void printar_lista(LSE* lista);
void printar_lista_recursiva(LSE* lista);
LSE* libera_lista(LSE* lista);

///////// FUNÇÕES - RECURSIVIDADE ////////////
int fat_recursivo(int n);
int fibonacci_recursivo(int n);
int soma_lista_recursiva(LSE* lista);
void printar_lista_recursiva_pura(LSE* lista);

void menu();

int main(){
    LSE* lista = NULL;
    while(1){
        menu();

        int opcao;
        printf("Digite a Opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:{
            int numero;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            lista = inserir_no_inicio(lista, numero);
            printf("Inserido no inicio!\n\n");
            break;
        }
        case 2:{
            int numero;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            lista = inserir_final(lista, numero);
            printf("Inserido no final!\n\n");
            break;
        }
        case 3:{
            int numero, posicao;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            printf("Digite a posicao (0 para inicio): ");
            scanf("%d", &posicao);
            lista = inserir_posicao(lista, numero, posicao);
            printf("Inserido na posicao!\n\n");
            break;
        }
        case 4:{
            int posicao;
            printf("Digite a posicao a consultar: ");
            scanf("%d", &posicao);
            consultar_posicao(lista, posicao);
            break;
        }
        case 5:{
            int elemento;
            printf("Digite o valor a remover: ");
            scanf("%d", &elemento);
            lista = remover_elemento(lista, elemento);
            printf("Elemento removido!\n\n");
            break;
        }
        case 6:
            printf("Lista (iterativa):\n");
            printar_lista(lista);
            break;
        case 7:
            printf("Lista (recursiva):\n");
            printar_lista_recursiva_pura(lista);
            printf("NULL\n\n");
            break;
        case 8:{
            if(lista != NULL){
                int soma = soma_lista_recursiva(lista);
                printf("Soma dos elementos (recursiva): %d\n\n", soma);
            }else{
                printf("Lista vazia!\n\n");
            }
            break;
        }
        case 9:{
            int n;
            printf("Digite um numero para calcular o fatorial: ");
            scanf("%d", &n);
            printf("Fatorial de %d = %d\n\n", n, fat_recursivo(n));
            break;
        }
        case 10:{
            int n;
            printf("Digite um numero para calcular fibonacci: ");
            scanf("%d", &n);
            printf("Fibonacci de %d = %d\n\n", n, fibonacci_recursivo(n));
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
    printf("3-> Inserir em posicao especifica\n");
    printf("4-> Consultar posicao especifica\n");
    printf("5-> Remover elemento\n");
    printf("6-> Listar (iterativa)\n");
    printf("7-> Listar (recursiva)\n");
    printf("--- RECURSIVIDADE ---\n");
    printf("8-> Soma lista recursiva\n");
    printf("9-> Fatorial recursivo\n");
    printf("10-> Fibonacci recursivo\n");
    printf("--- GERAL ---\n");
    printf("11-> Liberar lista\n");
    printf("0-> Sair\n\n");
}

/////////////////////////////FUNÇÕES LISTA ENCADEADA/////////////////////////////

LSE* novo_no(){
    LSE* no = malloc(sizeof(LSE));
    return no;
}

LSE* inserir_no_inicio(LSE* lista, int valor){
    LSE* novo = novo_no();

    if (novo){
        novo->valor = valor;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro de alocacao\n");
    }

    return lista;
}

LSE* inserir_final(LSE* lista, int valor){
    LSE* novo = novo_no();
    novo->proximo = NULL;

    if(novo){
        novo->valor = valor;

        if (lista ==  NULL){
            return novo;
        }

        LSE* aux = lista;

        while (aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }else{
        printf("Erro de alocacao\n");
    }
    return lista;
}

LSE* inserir_posicao(LSE* lista, int valor, int posicao){
    LSE* novo = novo_no();
    novo->valor = valor;

    if(posicao == 0){
        novo->proximo = lista;
        return novo;
    }

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

    return lista;
}

LSE* consultar_posicao(LSE* lista, int posicao){
    LSE* aux = lista;
    int cont = 0;

    if (lista == NULL){
        printf("Lista Vazia\n\n");
    }else{
        while (aux != NULL){
            if(cont == posicao){
                printf("Elemento na posicao %d: %d\n\n", posicao, aux->valor);
                return aux;
            }
            cont++;
            aux = aux->proximo;
        }
        printf("Posicao %d nao encontrada\n\n", posicao);
    }
    return NULL;
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
                return lista;
            }
            aux = aux->proximo;
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

int fat_recursivo(int n){
    if(n <= 1){
        return 1;
    }
    return n * fat_recursivo(n - 1);
}

int fibonacci_recursivo(int n){
    if(n <= 1){
        return n;
    }
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int soma_lista_recursiva(LSE* lista){
    if(lista == NULL){
        return 0;
    }
    return lista->valor + soma_lista_recursiva(lista->proximo);
}

void printar_lista_recursiva_pura(LSE* lista){
    if(lista == NULL){
        return;
    }
    printf("%d->", lista->valor);
    printar_lista_recursiva_pura(lista->proximo);
}
