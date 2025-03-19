#include<stdio.h>
#include<stdlib.h>

typedef struct LSE{

    int valor;
    struct LSE* proximo;

}LSE;

void menu(){
    printf("Digite a opcao desejada\n\n");
    printf("1-> Incluir no inicio\n");
    printf("2-> Incluir no final\n");
    printf("3-> Printar lista\n");
    printf("4-> Liberar lista\n");
    printf("5-> Inserir depois de\n");
    printf("6-> Remover elemmento\n");
    printf("7-> Sair\n");
}

LSE* criar_novo_no(int valor){
    LSE* novo_no = malloc(sizeof(LSE));
    if (novo_no == NULL){
        printf("Eorro de alocação\n");
        exit(1);
    }

    novo_no->valor = valor;
    novo_no->proximo = NULL;

    return novo_no;
}

LSE* insere_inicio(LSE* lista, int valor){// lista é o ponteiro lista 
    LSE* novo_no = criar_novo_no(valor);
    novo_no->proximo = lista;
    return novo_no; 
}

LSE* inserir_final(LSE* lista, int valor){
    LSE* novo_no = criar_novo_no(valor);

    if (lista == NULL){
        return novo_no;
    }

    LSE* aux =  lista;

    while (aux->proximo != NULL){
        aux = aux->proximo;
    }

    aux->proximo = novo_no;
    
    return lista;
}

LSE* ensere_depois_de(LSE* lista, int valor, int buscado){

    if (lista == NULL) {
        printf("Lista vazia, insercao nao realizada\n");
        return lista;
    }

    LSE* novo_no = criar_novo_no(valor);
    LSE* aux = lista;

    while (aux != NULL){
        if(aux->valor == buscado){
            novo_no->proximo = aux->proximo;
            aux->proximo = novo_no;
            return lista;
        }else{
            aux = aux->proximo;
        }
    }
    printf("Valor %d não encontrado na lista\n", buscado);
    free(novo_no); // Libera o nó criado, já que não será utilizado
    return lista;
}

LSE* remove_elemento(LSE* lista, int elemento){

    LSE* aux = lista;
    LSE* anterior = NULL;

    if (lista == NULL) {
        printf("Lista vazia, nada a remover\n");
        return lista;
    }

    if (aux->valor == elemento && anterior == NULL){
        lista = aux->proximo;
    }
    

    while (aux != NULL){

        if(aux->valor == elemento){
            anterior->proximo= aux->proximo;
            free(aux);
            return lista;
        }else{
            anterior = aux;
            aux = aux->proximo;
        }
    }
    printf("Elemento nao encontado na lista!!\n");
    return lista;
}

void printar_lista(LSE* lista){

    LSE* aux = lista;
    if (aux ==  NULL)
    {
        printf("Lista vazia\n");
    }
    
    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");

}

void libera_lista(LSE* lista){
    LSE* aux = lista;
    while (aux != NULL){
        LSE* proximo = aux->proximo;
        free(aux);
        aux = proximo;    
    }
}

int main(){

    LSE* lista = NULL;

    while (1)
    {
        menu();
        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:{
            int valor;
            printf("Digite o valor a ser inserido no inicio: ");
            scanf("%d", &valor);
            lista = insere_inicio(lista, valor);
            break;
        }
        case 2:{
            int valor;
            printf("Digite o valor a ser inserido no final: ");
            scanf("%d", &valor);
            lista = inserir_final(lista, valor);
            break;
        }
        case 3:
            printar_lista(lista);
            break;
        case 4:
            libera_lista(lista);
            lista = NULL;
            break;

        case 5:{
            int valor;
            printf("Digite o valo a ser inserido: ");
            scanf("%d", &valor);
            int buscado;
            printar_lista(lista);
            printf("Digite depois de qual valor deve ser inserido: ");
            scanf("%d", &buscado);
            ensere_depois_de(lista, valor, buscado);
            break;
        } 
        case 6:{
            int elemento;
            printar_lista(lista);
            printf("Digite o elemento a ser removido: ");
            scanf("%d", &elemento);
            remove_elemento(lista, elemento);
            break;
        } 
        case 7:
            printf("Programa Finalizado\n");
            libera_lista(lista);
            return 0;
        }
    }


    return 0;
}
