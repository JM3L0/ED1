#include<stdio.h>

#define num_notas 3

int main(){
    
    typedef struct{

        char nome[50];
        float notas[num_notas];
        float media;
        
    }Alunos;
    
    int N;
    scanf("%d", &N);

    Alunos alunos[N];

    for (int i = 0; i < N; i++){
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome);

        for(int j = 0; j < num_notas; j++){
            printf("Digite a %d nota: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        alunos[i].media = 0;
        for (int k = 0; k < num_notas; k++){
            alunos[i].media = alunos[i].media + alunos[i].notas[k];
        }
        
    }

    printf("\nMedias dos alunos\n");
    for (int i = 0; i < N; i++){
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Media: %.2f", alunos[i].media/num_notas);
    }
    
    return 0;
}