#include<stdio.h>

int main(){
    int tam;
    scanf("%d", &tam);

    int vet[tam];

    for(int i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < tam; i++){
        for(int j = i + 1; j < tam; j++){
            if(vet[i] == vet[j]){
                for(int k = j; k < tam - 1; k++){
                    vet[k] = vet[k+1];
                }
                tam--;
                j--;
            }
        }
    }

    for (int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    
    return 0;
}