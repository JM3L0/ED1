#include<stdio.h>

int main(){

    int tam;
    scanf("%d", &tam);

    int vet[tam];

    for (int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
    
    int i = 0, temp;

    //ordenar vetor
    while (i < tam - 1){

        if (i >= 0 && vet[i] > vet[i+1]){

            temp = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = temp;
            i--;

        }else{
            i++;
        }   
    }

    for (int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    
    return 0;
}