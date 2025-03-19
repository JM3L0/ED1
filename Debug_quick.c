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




Lista_encadeada  *contatenar_listas(Lista_encadeada *menor, Lista_encadeada *pivo, Lista_encadeada *maior)
{
    Lista_encadeada *inicio = pivo;

    if (menor != NULL)
    {
        inicio = menor;

        while (menor->proximo != NULL)
        {
            menor = menor->proximo;
        }
       
        menor->proximo = pivo;
        
    }
    
    pivo->proximo = maior;


    return inicio;

}


void adicionar_no(Lista_encadeada **inicio, Lista_encadeada *novo)
{
    if (novo == NULL)
    {
        return;
    }
    
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

void organizar_pivo(Lista_encadeada *inicio, Lista_encadeada *pivo, Lista_encadeada **menor, Lista_encadeada **maior)
{
    Lista_encadeada *aux = NULL;
   

    while (inicio != NULL)
    {
        aux = inicio;
        inicio = inicio->proximo;

        if (aux->valor < pivo->valor && inicio != pivo)
        {
            adicionar_no(menor, aux);
        }
        else if (aux->valor >= pivo->valor && inicio != pivo)
        {
            adicionar_no(maior, aux);
        }
        
    }
}

Lista_encadeada  *quick_sort_recursivo(Lista_encadeada *inicio)
{
    if (inicio == NULL || inicio->proximo == NULL)
    {
        return inicio;
    }

    Lista_encadeada *pivo = inicio;
    Lista_encadeada *menor = NULL;
    Lista_encadeada *maior = NULL;
    organizar_pivo(inicio->proximo, pivo, &menor, &maior);
    pivo->proximo = NULL;

    printf("Menor: ");
    printar_lista(menor);
    printf("Pivo: ");
    printar_lista(pivo);
    printf("Maior: ");
    printar_lista(maior);
    system("pause");

    menor = quick_sort_recursivo(menor);
    maior = quick_sort_recursivo(maior);


    return contatenar_listas(menor, pivo, maior);
}


void quick_sort(Lista_encadeada **inicio)
{
    if (*inicio == NULL || (*inicio)->proximo == NULL)
    {
        return;
    }
    
   *inicio = quick_sort_recursivo(*inicio);

}





int main()
{
    Lista_encadeada *lista = NULL;

    criar_lista_aleatoria(&lista, 10);

    printf("Lista: ");
    printar_lista(lista);
    printf("\n");
    quick_sort(&lista);

    printf("Lista: ");
    printar_lista(lista);

    liberar_lista(&lista);

    return 0;
}