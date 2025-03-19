#include<stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    int vet1[N], vet2[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &vet1[i]);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &vet2[i]);
    }

    int cont = 0;

    for(int i = 0; i < N; i++){
        if(vet1[i] == vet2[i]){
            cont++;
        }
    }
    
    printf("%d", cont);
    return 0;
}