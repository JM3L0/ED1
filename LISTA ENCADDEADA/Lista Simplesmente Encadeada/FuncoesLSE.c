#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{
    int valor;
    struct LSE* proximo;
}LSE;

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

LSE* inserir_depois_de(LSE* lista, int valor, int buscado){
    LSE* aux = lista;

    if (lista == NULL){
        printf("Lista vazia\n");
    }else{
        while (aux != NULL){
            if (aux->valor == buscado){
                LSE* novo = novo_no();

                novo->valor = valor;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            aux = aux->proximo;
        }
        
    }
    return lista;
}

void buscar_elemento(LSE* lista, int buscado){
    LSE* aux = lista;

    if (lista == NULL){
        printf("Lista Vazia\n\n");
    }else{
        int cont = 0, achou = 0;
        while (aux != NULL){
            if (aux->valor == buscado){
                printf("Elemento %d encontrado na posicao %d\n\n", buscado, cont);
                achou++;
            }
            cont ++;
            aux = aux->proximo;
        }
        if(achou == 0){
            printf("Elemento nao encontrado\n\n");
        }
    }
}

LSE* remover_um_elemento(LSE* lista, int elemento){
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

LSE* remover_todos_buscados(LSE* lista, int elemento){
    LSE* aux = lista;
    LSE* anterior = NULL;

    while (aux != NULL){

        if(aux->valor == elemento){
            if(anterior == NULL){
                lista = lista->proximo;
                free(aux);
                aux = lista;
            }else{
                anterior->proximo = aux->proximo;
                free(aux);
                aux = anterior->proximo;
            }
        }else{
            anterior = aux;
            aux = aux->proximo;
        }
    }
    
    return lista;
}

LSE* concatenar_lista(LSE* lista1, LSE* lista2){
    LSE* aux = lista1;

    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = lista2;

    return lista1;
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

void menu(){
    printf("----- MENU -----\n\n");
    printf("1-> Inserir no inicio\n");
    printf("2-> Inserir no final\n");
    printf("3-> Inserir depois DE\n");
    printf("4-> Printar lista\n");
    printf("5-> Buscar elemento\n");
    printf("6-> Remover elemento\n");
    printf("7-> Remover todos elemento buscados na lista \n");
    printf("8-> Mesclar Lista\n");
    printf("9-> Liberar lista\n");
    printf("10-> Encerrar programa\n\n");
}

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
            break;
        }
        case 2:{
            int numero;
            printf("Digite um valor: ");
            scanf("%d", &numero);
            lista = inserir_final(lista, numero);
            break;
        }
        case 3:{
            int numero, buscado;
            printf("Digite um valor a ser inserido: ");
            scanf("%d", &numero);
            printar_lista(lista);
            printf("Digite depois de qual valor deve ser inserido: ");
            scanf("%d", &buscado);
            lista = inserir_depois_de(lista, numero, buscado);
            break;
        }
        case 4:
            printar_lista(lista);
            break;
        case 5:{
            int buscado;
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &buscado);
            buscar_elemento(lista, buscado);
            break;
        }
        case 6:{
            int buscado;
            printf("Digite o valor a ser apagado: ");
            scanf("%d", &buscado);
            lista = remover_um_elemento(lista, buscado);
            break;
        }
        case 7:{
            int buscado;
            printf("Digite o valor a ser apagado: ");
            scanf("%d", &buscado);
            lista = remover_todos_buscados(lista, buscado);
            break;
        }
        case 8:{
            LSE* lista1 = NULL;
            LSE* lista2 = NULL;

            int num;

            printf("Digite a primeira lista de 5 numeros: ");
            for(int i = 0; i < 5; i++){
                scanf("%d", &num);
                lista1 = inserir_no_inicio(lista1, num);
            }

            printf("Digite a segunda lista de 5 numeros: ");
            for(int i = 0; i < 5; i++){
                scanf("%d", &num);
                lista2 = inserir_final(lista2, num);
            }

            LSE* lista3 = concatenar_lista(lista1, lista2);

            lista = lista3;

            printar_lista(lista);
            break;
        }
        case 9:
            lista = libera_lista(lista);
            break;
        default:
            return 0;        
        }
    }

    return 0;
}