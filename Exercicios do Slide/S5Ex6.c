#include<stdio.h>

int main(){
    int arr[5], soma = 0;

    for (int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    int *ptr,*end;
    ptr = arr;
    end = arr+5;
    
    while(ptr < end){
        soma += *ptr;
        ptr++;
    }

    printf("%d", soma);
    return 0;
}