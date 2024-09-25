#include <stdio.h>

#define MAX_ALUNOS 2

typedef struct
{
    char matricula[50];
    float nota1;
    float nota2;
    int faltas;
} Aluno;

// LEIAM 10 ALUNOS. NO FINAL INFORME SE O ALUNO ESTÁ
// REPROVADO OU APROVADO. ESTAO REPROVADOS QUEM TIVER
// MÉDIA MENOR QUE 5 OU MAIS QUE 15 FALTAS
int main()
{

    Aluno alunos[MAX_ALUNOS];

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("Informe a matricula do aluno %d: ", i + 1);
        fgets(alunos[i].matricula, 50, stdin);
        printf("Informe a primeira nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Informe a segunda nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);
        printf("Informe o numero de faltas do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].faltas);
        getchar();
        printf("\n");
    }
    for(int i=0; i< MAX_ALUNOS; i++){
        float media = (alunos[i].nota1 + alunos[i].nota2) / 2;
    
        if(media < 5 || alunos[i].faltas > 15){
            printf("\nAluno %s reprovado.", alunos[i].matricula);
        }else{
            printf("\nAluno %s aprovado.", alunos[i].matricula);
        }

    }
    return 0;
}