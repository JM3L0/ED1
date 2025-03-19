#include<stdio.h>

int main(){

    int arr [5], maior = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    int *ptr, *end = arr+5;
    ptr = arr;

    while(ptr < end){
        if(*ptr > maior){
            maior = *ptr;
        }
        ptr++;
    }

    printf("%d", maior);

    return 0;
}