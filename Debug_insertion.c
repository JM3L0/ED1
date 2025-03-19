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

    // printf("Lista: ");

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




void insertion_sort(Lista_encadeada **inicio)
{
    if (*inicio == NULL || (*inicio)->proximo == NULL)
    {
        return;
    }

    Lista_encadeada *ordenado = NULL;
    Lista_encadeada *desordenado = *inicio;

    while (desordenado != NULL)
    {
        Lista_encadeada *aux = desordenado;
        desordenado = desordenado->proximo;

        if (ordenado == NULL || aux->valor < ordenado->valor)
        {
            aux->proximo = ordenado;
            ordenado = aux;
        }
        else
        {
            Lista_encadeada *aux2 = ordenado;

            while (aux2->proximo != NULL && aux->valor > aux2->proximo->valor)
            {
                aux2 = aux2->proximo;
            }

            aux->proximo = aux2->proximo;
            aux2->proximo = aux;
        }
    }

    *inicio = ordenado;
}





int main()
{
    Lista_encadeada *lista = NULL;

    criar_lista_aleatoria(&lista, 10);

    printf("Lista: ");
    printar_lista(lista);
    printf("\n");
    insertion_sort(&lista);

    printf("Lista: ");
    printar_lista(lista);

    liberar_lista(&lista);

    return 0;
}