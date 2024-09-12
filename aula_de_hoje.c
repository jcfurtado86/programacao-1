#include <stdio.h>

#define MAX_PESSOAS 3

typedef struct
{
    char nome[50];
    int idade;
} Pessoa;
int main()
{

    Pessoa p[MAX_PESSOAS];

    for (int i = 0; i < MAX_PESSOAS; i++)
    {
        printf("Informe o nome da pessoa: ");
        fgets(p[i].nome, 50, stdin);
        printf("Informe a idade da pessoa:");
        scanf("%d", &p[i].idade);

        getchar();
        printf("\n");
    }

    printf("\n Pessoas cadastradas: \n");

    for (int i = 0; i < MAX_PESSOAS; i++)
    {
        printf("Nome: %s, Idade: %d", p[i].nome, p[i].idade);
    }

    return 0;
}