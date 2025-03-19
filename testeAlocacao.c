#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    char *vet = NULL;
    int size = 0;
    char num[10000];

    while (1){
        printf("Digite um texto (parar para parar): ");
        fgets(num, sizeof(num), stdin);

        num[strcspn(num, "\n")] = '\0';

        if (strcmp(num, "parar") == 0){
            break;
        }

        int buffer_len = strlen(num);

        char *temp = (char *)realloc(vet, size + buffer_len + 2);
        if(temp == NULL){
            printf("ERRO AO REALOAR!!!\n\n");
            free(vet);
            return 1;
        }

        vet = temp;

        if (size > 0){
            vet[size] = ' ';
            size++;
        }
        

       strcpy(vet + size, num);
        size += buffer_len;
    }
    
    printf("Testo digitado: ");
   
    printf("%s", vet);
    free(vet);
    return 0;
}