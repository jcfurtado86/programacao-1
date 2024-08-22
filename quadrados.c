// LER 4 NOTAS E MOSTRAR A MEDIA SIMPLES
// LEIA AS 4 NOTAS USANDO UM LAÇO FOR

#include <stdio.h>

int main()
{
    int altura;

    printf("Digite a altura do quadrado: ");
    scanf("%d", &altura);

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            if (i == 0 ||
                j == 0 ||
                i == altura - 1 ||
                j == altura - 1 ||
                i == j ||
                i + j == altura - 1)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }

    return 0;
}