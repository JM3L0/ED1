#include <stdio.h>

int soma_recursivo(int n){
    if(n == 0){
        return 0;
    }else{
        return n + soma_recursivo(n-1);
    }
}

int main(){
    int n;
    printf("Digite a quantidade de digitos: ");
    scanf("%d", &n);
    printf("%d", soma_recursivo(n));
}