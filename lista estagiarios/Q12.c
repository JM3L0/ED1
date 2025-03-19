#include<stdio.h>

int main(){
    
    int N;
    scanf("%d", &N);

    int vet_A[N], vet_B[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &vet_A[i]);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &vet_B[i]);
    }

    int vet_C[N*2];

    int posicao = 0;
    
    for(int i = 0; i < N*2; i++){
        vet_C[posicao] = vet_A[i];
        posicao++;
        vet_C[posicao] = vet_B[i];
        posicao++;
    }

    for (int i = 0; i < N*2; i++){
        printf("%d ", vet_C[i]);
    }
    
    return 0;
}