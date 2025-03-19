#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CARACTERE{
    
    char caractere;
    struct CARACTERE* proximo;

}CARACTERE;

typedef struct PILHA_PALAVRAS{
    
    CARACTERE* topo;//não tenho o pronteiro para o proximo por que 

}PILHA_PALAVRAS;

PILHA_PALAVRAS* criar_pilha();
CARACTERE* empilhar_caractere(CARACTERE* topo, char caractere);
CARACTERE* desempilhar_caractere(CARACTERE* topo, char* caractere);
void empilhar_palavra(PILHA_PALAVRAS* pilha, char* palavra);
void desempilhar_palavra(PILHA_PALAVRAS* pilha);
void inverte_frase(char* frase);


int main() {
    char frase[100];

    while (1){

        printf("Digite a frase a ser invertida (Ctrl + c para finalizar): ");
        scanf(" %[^\n]", frase);

        inverte_frase(frase);
    }

    return 0;
}

PILHA_PALAVRAS* criar_pilha(){
    PILHA_PALAVRAS* pilha = malloc(sizeof(PILHA_PALAVRAS));

    pilha->topo = NULL;

    return pilha;
}

CARACTERE* empilhar_caractere(CARACTERE* topo, char caractere){
    CARACTERE* novo = malloc(sizeof(CARACTERE));

    novo->caractere = caractere;
    novo->proximo = topo;

    return novo;
}

CARACTERE* desempilhar_caractere(CARACTERE* topo, char* caractere){

    if (topo != NULL){
        *caractere = topo->caractere;
        CARACTERE* novo_topo = topo->proximo;
        free(topo);
        topo = novo_topo;
    }
    return topo;
}

void empilhar_palavra(PILHA_PALAVRAS* pilha, char* palavra){

    while (*palavra != '\0' && *palavra != ' '){
        pilha->topo = empilhar_caractere(pilha->topo, *palavra);//passo o caracter para a funçao de empilhar caractere
        palavra++;//avanço a posição do array de palavra para frente
    }
}

void desempilhar_palavra(PILHA_PALAVRAS* pilha){

    char caractere;

    while (pilha->topo != NULL){
        pilha->topo = desempilhar_caractere(pilha->topo, &caractere);//em teoria aqui ja esta avançando para frente, que seria para o proximo caractere
        printf("%c", caractere);                                     //pois como os catacteres são uma pilha, alguma hora a função ira retornar o topo = null
    }
}

void inverte_frase(char* frase){
    PILHA_PALAVRAS* pilha = criar_pilha();

    printf("\nFrase Invertida: ");

    char* palavra = frase;

    while (*frase != '\0'){
        
        if(*frase == ' '){
            empilhar_palavra(pilha, palavra); // Empilha os caracteres da palavra
            desempilhar_palavra(pilha);      // Desempilha e imprime a palavra invertida
            printf(" ");                     // Imprime o espaço entre palavras
            palavra = frase + 1;             // Avança para a próxima palavra
            printf(" ");
        }
        frase ++;
    }
    empilhar_palavra(pilha, palavra); // Empilha a última palavra
    desempilhar_palavra(pilha);      // Desempilha e imprime a última palavra

    printf("\n");
    free(pilha);
}

// void inverte_frase(char* frase){
//     PILHA_PALAVRAS* pilha = criar_pilha();

//     printf("\nFrase Invertida: ");

//     char* palavra = frase;

//     while (*frase != '\0'){
        
//         if(*frase == ' '){
//             empilhar_palavra(pilha, palavra); // Empilha os caracteres da palavra
//             desempilhar_palavra(pilha);      // Desempilha e imprime a palavra invertida
//             printf(" ");                     // Imprime o espaço entre palavras
//             palavra = frase + 1;             // Avança para a próxima palavra
//             printf(" ");
//         }
//         frase ++;
//     }
//     empilhar_palavra(pilha, palavra); // Empilha a última palavra
//     desempilhar_palavra(pilha);      // Desempilha e imprime a última palavra

//     printf("\n");
//     free(pilha);
// }


