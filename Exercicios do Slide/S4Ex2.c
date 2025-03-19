#include<stdio.h>

int potencia(int base, int espoente){
    if(espoente == 0){
        return 1;
    }else{
        return base * potencia(base, espoente-1);
    }
}

int main(){
    int base, espoente;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o espoente: ");
    scanf("%d", &espoente);

    printf("%d", potencia(base, espoente));
}