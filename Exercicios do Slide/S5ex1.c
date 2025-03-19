#include<stdio.h>

int main(){
    int array [5] = {1, 2, 5, 3, 4};
    int *ponteiro = array;

    printf("Array original:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; i++){
        *(ponteiro + i) = *(ponteiro + i) * 2;
    }

    printf("Array modificado:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}