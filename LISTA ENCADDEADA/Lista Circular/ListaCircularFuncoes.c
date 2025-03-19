#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{
    int valor;
    struct LEC* proximo;
}LEC;

LEC* novo_no(){
    LEC* no = malloc(sizeof(LEC));
    return no;
}

LEC* inserir_inicio(LEC* lista, int valor){
    LEC* novo = novo_no();
    LEC* ultimo = lista;
    novo->valor = valor;

    if (lista == NULL){
        novo->proximo = novo;
        lista = novo;
    }else{

        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }
        
        novo->proximo = lista;
        ultimo->proximo = novo;
        lista = novo;
    }
    return lista;
}

LEC* inserir_no_final(LEC* lista, int valor){
    LEC* novo = novo_no();
    novo->valor = valor;

    if (lista == NULL){
        novo->proximo = novo;
        lista = novo;
    }else{
        LEC* aux = lista;

        while(aux->proximo != lista){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        novo->proximo = lista;
    }
    return lista;
}

void buscar_elemento(LEC* lista, int buscado){
    LEC* aux = lista->proximo;
    int posicao = 0, achou = 0;

    if (lista->valor == buscado){
        printf("Elemento %d encontrado na posicao %d\n", buscado, posicao);
        achou++;
    }
    posicao++;
    while (aux != lista){
        if (aux->valor == buscado){
            printf("Elemento %d encontrado na posicao %d\n", buscado, posicao);
            achou++;
        }
        posicao++;
        aux = aux->proximo;
    }
    
    if (achou == 0){
        printf("Elemento nao encontrado");
    }
}

void printar_lista(LEC* lista){
    LEC* aux = lista;

    if (lista == NULL){
        printf("Lista Vazia!!\n\n");
    }else{
        do {
            printf("%d->", aux->valor);
            aux = aux->proximo;
        }while (aux != lista);
        printf("INICIO\n\n");
    } 
}

LEC* Busca(LEC* lista, int buscado){
    LEC* aux = lista;
    LEC* achou = NULL;

    if (lista != NULL){
        
        do{
            if (aux->valor == buscado){
                achou = aux;
            }
            aux = aux->proximo;
        }while (aux != lista && achou != aux);
    }

    return achou;
}

LEC* remover_elemento(LEC* lista, int buscado){
    LEC* remover = Busca(lista, buscado);

    if(remover != NULL){

        if(remover->proximo == lista){
            free(lista);
            lista = NULL;
        }else{

            
            if (remover == lista){
                LEC* ultimo = lista;

                while (ultimo->proximo != lista){
                    ultimo = ultimo->proximo;
                }
                ultimo->proximo = lista->proximo;
                free(lista);
                lista = ultimo->proximo;

            }else{
                LEC* anterior = lista;

                while (anterior->proximo != remover){
                    anterior = anterior->proximo;
                }

                anterior->proximo = remover->proximo;
                free(remover);
            }        
        }
    }

    return lista;
}

LEC* remover_todos_buscados(LEC* lista, int buscado){

    if (lista == NULL){
        printf("Lista esta vazia ");
    }else{
        LEC* aux = lista;
        LEC* ultimo = lista;

        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }

        while (lista != NULL && lista->valor == buscado ){
            if(lista ==  ultimo){
                free(lista);
                lista =  NULL;
            }else{

                aux = lista;
                lista = lista->proximo;
                ultimo->proximo = lista;
                free(aux);

            }
        }

        if (lista != NULL){
            aux = lista;

            do{

                LEC* proximo = aux->proximo;

                if (proximo->valor == buscado){
                    aux->proximo = proximo->proximo;
                    free(proximo);

                    if (proximo == ultimo){
                        ultimo = aux;
                    }
                    
                }else{
                    aux = aux->proximo;
                } 
                
            } while (aux->proximo != lista);   
        }
    }

    return lista;
}

LEC* inverter_recursivo(LEC* anterior, LEC* atual, LEC* lista){

    if (atual->proximo == lista){
        lista->proximo = anterior;
        return anterior;
    }
    
    LEC* proximo = atual->proximo;
    atual->proximo = anterior;

    return inverter_recursivo(atual, proximo, lista);
}


LEC* liberar_lista(LEC* lista){
    if (lista != NULL){
        
        LEC* aux = lista;
        LEC* temp;

        while (aux->proximo != lista){
            temp = aux;
            aux = aux->proximo;
            free(temp);
        }
        free(aux);
    }
    return NULL;
}
void menu(){
    printf("\n1-> Inserir inicio\n");
    printf("2-> Inserir Final\n");
    printf("3-> Buscar Elemento\n");
    printf("4-> Printar Lista\n");
    printf("5-> Remover Elemento\n");
    printf("6-> Remover Buscados\n");
    printf("7-> Liberar Lista\n");
    printf("8-> Inverter Recursivo\n");
    printf("9-> Encerrar Programa\n");
    printf("Digite uma opcao: ");
}

int main(){
    LEC* lista = NULL;
    int num;
    int opcao;

    do{
        menu();

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digte o numero a ser inderido no inicio: ");
            scanf("%d", &num);
            lista = inserir_inicio(lista, num);
            break;
        case 2:
            printf("Digite o numero a ser inserido no final: ");
            scanf("%d", &num);
            lista = inserir_no_final(lista, num);
            break;
        case 3:
            printf("Digite o elemnto buscado: ");
            scanf("%d", &num);
            buscar_elemento(lista, num);
            break;
        case 4:
            printar_lista(lista);
            break;
        case 5:
            printar_lista(lista);
            printf("Digite o numero a ser removido: ");
            scanf("%d", &num);
            lista = remover_elemento(lista, num);
            
            break;
        case 6:
            printar_lista(lista);
            printf("Digite o numero a ser removido totalmente da lista: ");
            scanf("%d", &num);
            lista = remover_todos_buscados(lista, num);
            break;
        case 7:
            lista = liberar_lista(lista);
            printf("Lista Liberada\n\n");
            break;
        case 8:
            lista = inverter_recursivo(NULL, lista, lista);
            break;
        case 9:
            lista = liberar_lista(lista);
            printf("encerrando programa...");
            return 0;
        
        default:
            break;
        }
    }while(1);

    return 0;
}