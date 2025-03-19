#include<stdio.h>

int main(){
    
    typedef struct 
    {
        char nome [50];
        int idade;
        int matricula;
    }Aluno;

    Aluno alunos [5];
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Digite a idade do aluno: ");
        scanf("%d", &alunos[i].idade);
        printf("Digite a matricula do aluno: ");
        scanf("%d", &alunos[i].matricula);
        printf("\n");
    }

    for (int i = 0; i < N; i++){
        printf("\n");
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Matricula: %d\n", alunos[i].matricula);
    }
    
    return 0;
}