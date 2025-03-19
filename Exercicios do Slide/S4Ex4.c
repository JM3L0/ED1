#include<stdio.h>

void hanoi(int disco, char origem, char destino, char auxiliar){
    if(disco == 1){
        printf("Mover disco de %c para %c\n", origem, destino);
    }else{
        hanoi(disco-1, origem, auxiliar, destino);
        printf("Mover disco de %c para %c\n", origem, destino);
        hanoi(disco-1, auxiliar, destino, origem);
    }
}

int main(){
    int discos;
    printf("Digite o numero de discos: ");
    scanf("%d", &discos);
    hanoi(discos, 'A', 'B', 'C');
}