// Função para concatenar 3 listas
no* concatenar(no* menor, no* pivo, no* maior) {
    no *resultado = menor;

    // Se houver elementos em 'menor', avance até o final
    if (resultado != NULL) {
        no* atual = resultado;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = pivo; // Conecta o pivô ao final de 'menor'
    } else {
        resultado = pivo; // Se 'menor' for nulo, 'resultado' é o pivô
    }

    pivo->prox = maior; // Conecta 'maior' após o pivô
    return resultado;
}

// Função para particionar a lista em relação ao pivô
no* particionar(no* lista, no** menor, no** maior) {
    no* pivo = lista;        // O primeiro elemento é o pivô
    *menor = NULL;
    *maior = NULL;

    no* atual = lista->prox;
    while (atual != NULL) {
        no* proximo = atual->prox;
        if (atual->valor < pivo->valor) {
            atual->prox = *menor;
            *menor = atual;
        } else {
            atual->prox = *maior;
            *maior = atual;
        }
        atual = proximo;
    }
    pivo->prox = NULL; // Garante que o pivô seja isolado
    return pivo;
}

// Função principal do QuickSort recursivo
no* quick_sort_lista(no* lista) {
    if (lista == NULL || lista->prox == NULL) {
        return lista; // Base da recursão: lista vazia ou com 1 elemento
    }

    no *menor, *maior, *pivo = particionar(lista, &menor, &maior);

    // Ordena recursivamente as partes 'menor' e 'maior'
    menor = quick_sort(menor);
    maior = quick_sort(maior);

    // Concatena 'menor', 'pivo' e 'maior' em uma lista final
    return concatenar(menor, pivo, maior);
}