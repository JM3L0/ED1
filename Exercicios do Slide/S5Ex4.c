#include<stdio.h>

int main(){
    
    int arr [5] = {1,2,3,4,5};
    int *inicio, *final, aux;

    inicio = arr;
    final = arr + 4;

    printf("Array original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while(inicio < final){
        aux = *inicio;
        *inicio = *final;
        *final = aux;

        inicio ++;
        final --;
    }

    printf("Array invertido: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}