#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista_encadeada
{
    int valor;
    struct Lista_encadeada *proximo;
} Lista_encadeada;

void adicionar_elemento(Lista_encadeada **inicio, int valor)
{
    Lista_encadeada *novo = malloc(sizeof(Lista_encadeada));
    novo->valor = valor;
    novo->proximo = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        Lista_encadeada *aux = *inicio;

        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }

        aux->proximo = novo;
    }
    
}


void criar_lista_aleatoria(Lista_encadeada **inicio, int tamanho)
{
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++)
    {
        adicionar_elemento(inicio, rand() % 100);
    }
}

void printar_lista(Lista_encadeada *inicio)
{
    Lista_encadeada *aux = inicio;

    printf("Lista: ");

    while (aux != NULL)
    {
        printf("%d->", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

void liberar_lista(Lista_encadeada **inicio)
{
    Lista_encadeada *aux = *inicio;
    Lista_encadeada *proximo = NULL;

    while (aux != NULL)
    {
        proximo = aux->proximo;
        free(aux);
        aux = proximo;
    }

    *inicio = NULL;
}


Lista_encadeada *achar_meio (Lista_encadeada *inicio)
{
    Lista_encadeada *lento = inicio;
    Lista_encadeada *rapido = inicio->proximo;



    while (rapido != NULL && rapido->proximo != NULL)
    {
        rapido = rapido->proximo->proximo;
        lento = lento->proximo;
    }

    return lento;
}

Lista_encadeada *mesclar(Lista_encadeada *metade1, Lista_encadeada *metade2)
{
    if (metade1 == NULL)
    {
        return metade2;
    }
    if (metade2 == NULL)
    {
        return metade1;
    }

    Lista_encadeada *resultado = NULL;

    if (metade1->valor <= metade2->valor)
    {
        resultado = metade1;
        resultado->proximo = mesclar(metade1->proximo, metade2);
    }
    else
    {
        resultado = metade2;
        resultado->proximo = mesclar(metade1, metade2->proximo);
    }

    return resultado;
}


Lista_encadeada *merge_sort_recursivo(Lista_encadeada *inicio)
{
    if ( inicio == NULL || inicio->proximo == NULL)
    {
        return inicio;
    }

    Lista_encadeada *meio = achar_meio(inicio);

    Lista_encadeada *proximo = meio->proximo;
    meio->proximo = NULL;
    
    // printf("Dividido\n");
    // printar_lista(inicio);
    // printar_lista(proximo);
    // system("pause");


    Lista_encadeada *Metade1 = merge_sort_recursivo(inicio);
    Lista_encadeada *Metade2 = merge_sort_recursivo(proximo);

    // printf("Mesclado\n");
    // printar_lista(Metade1);
    // printar_lista(Metade2);
    // system("pause");

    return mesclar(Metade1, Metade2);
}



void merge_sort(Lista_encadeada **inicio)
{
    if (*inicio == NULL || (*inicio)->proximo == NULL)
    {
        return;
    }

    *inicio = merge_sort_recursivo(*inicio);
    
}


int main()
{
    Lista_encadeada *lista = NULL;

    criar_lista_aleatoria(&lista, 6);

    printar_lista(lista);
    printf("\n");
    merge_sort(&lista);

    printar_lista(lista);

    liberar_lista(&lista);

    return 0;
}