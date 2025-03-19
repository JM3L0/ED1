#include<stdio.h>

void ordenaVetor(int n, int *vet){
    int i = 0, temp;

    while (i < n-1)
    {
        if (i >= 0 && vet[i] > vet[i+1])
        {
            temp = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = temp;
            i--;
        }else{
            i++;
        }   
    }
    
}

int buscaBi(int busca, int *vet, int i, int j, int cont){
    if (i > j){
        printf("NAO ENCONTRADO\n");
        return -1;
    }

    int meio = (i + j)/2;

    if (vet[meio] == busca){
        printf("Numero de chamadas: %d\n", cont);
        return meio;
    }else if (busca < vet[meio])
    {
        return (buscaBi(busca, vet, i, meio -1, cont + 1));
    }else{
        return (buscaBi(busca, vet, meio + 1, j, cont + 1));
    } 

}

int main(){
    int tam;
    scanf("%d", &tam);

    int vet[tam];

    for (int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
    
    int busca;
    printf("Digite o numeor a ser buscado: ");
    scanf("%d", &busca);

    ordenaVetor(tam, vet);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    int resultado = buscaBi(busca, vet, 0, tam, 1);

    if (resultado != -1){
        printf("Encontardo na posicao %d\n", resultado);
    }
    return 0;
}