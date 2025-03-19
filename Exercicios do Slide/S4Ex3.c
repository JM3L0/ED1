#include<stdio.h>

int multiplica(int numero, int vezes){
    if(vezes == 0){
        return 0;
    }else{
        return numero + multiplica(numero, vezes-1);
    }
}

int main(){
    int numero, vezes;
    printf("Digite o numero: ");
    scanf("%d", &numero);
    printf("Digite o vezes: ");
    scanf("%d", &vezes);

    printf("%d", multiplica(numero, vezes));
}