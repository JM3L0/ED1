#include<stdio.h>

int main(){
    
    int N;
    scanf("%d", &N);

    int vet[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &vet[i]);
    }

    int j = N - 1, vdd = 0;

    for(int i = 0; i < j; i++){
        if(vet[i] != vet[j]){
            vdd = 1;
        }
        j--;
    }

    if (vdd == 1){
        printf("Nao eh palindramo");
    }else{
        printf("Eh palindramo");
    }
    
    return 0;
}