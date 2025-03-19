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

LEC* inserir_final(LEC* lista, int valor){
    LEC* novo = novo_no(valor);

    if (lista == NULL){
        lista = novo;
    }else{
        LEC* aux = lista;

        while (aux->proximo != lista){
            aux = aux->proximo;
        }

        aux->proximo = novo;
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
        printf("INICIO\n");
    }else{
        printf("Lista Vazia!!\n\n");
    }
}

LEC* liberar_lista(LEC* lista){
    
    if (lista != NULL){
        LEC* aux = NULL;
        LEC* inicio = lista;

        do{
            aux = lista;
            lista = lista->proximo;
            free(aux);
        } while (lista != inicio);// fique atento essa comparaçao deve ser feita com o ponteiro que esta sendo movido para frente primeiro 
        lista = NULL;
    }

    return lista;
}

int tamanho(LEC* lista) {// lista circular é do-while tem o que fazer não
    int cont = 0;
    if (lista != NULL) {
        LEC* aux = lista;
        do {
            cont++;
            aux = aux->proximo;
        } while (aux != lista);
    }
    printf("%d\n\n", cont);
    return cont;
}


void esta_contida(LEC* lista1, LEC* lista2){
    LEC* aux1 = lista1;
    LEC* aux2 = lista2;

    int tamanhoL1 = tamanho(lista1);
    int tamanhoL2 = tamanho(lista2);

    int verifica = 0, rodada = 0, resultado = 0;

    if (tamanhoL1 <= tamanhoL2){
        
        do{
            verifica = 0;
            aux1 = lista1;
            printf("\n\nrodada %d aux1 -> %d aux2-> %d\n\n", rodada, aux1->valor, aux2->valor);
            do{
                //parece que o promeiro laço não para se a lista um nao estiver contida na lsita 2
                //porem o do-while sempre roda uma vez o que faz com que o aux2 sempre ande para frente
                //o aux1 tmb anda, mais volta ao começo se não estiver iqual a aux2
                //como isso acontece no mesmo laço os dois andam juntos o que resolveu o problema de sempre ter qeu andar com aux 2
                //e ainda se mantem sincronizados
                
                verifica++;
                if (verifica == tamanhoL1 && aux1->valor == aux2->valor){ //a segunda condição sere para se a lista 1 tiver so um elemento
                    resultado = 1;
                }
                aux1 = aux1->proximo;
                aux2 = aux2->proximo;
                printf("\nVerifica %d\n", verifica);
                rodada++;

            }while (aux1->valor == aux2->valor && resultado == 0);
        }while (aux2 != lista2 && resultado == 0);
        
    }else{
        printf("\nLista 1 nao pode ser maior que lista 2\n\n");
    }
    
    if (resultado == 1){
        printf("\nSim (Lista1 esta contida em Lista2)\n\n");
    }else{
        printf("\nNao (Lista1 nao esta contida em Lista2)\n\n");
    }
}


int main(){

    LEC* lista1 = NULL;
    LEC* lista2 = NULL;

    int num;

    while (scanf("%d", &num) == 1){
        lista1 = inserir_final(lista1, num);
    }while(getchar() != '\n');


    while (scanf("%d", &num) == 1){
        lista2 = inserir_final(lista2, num);
    }while(getchar() != '\n');

///////////////////////////////////////////////////////

    esta_contida(lista1, lista2);

////////////////////////////////////////////////////////
    printar_lista(lista1);

    lista1 = liberar_lista(lista1);

    printar_lista(lista1);

///////////////////////////////////////////////////////

    printar_lista(lista2);

    lista2 = liberar_lista(lista2);

    printar_lista(lista2);

    return 0;
}
