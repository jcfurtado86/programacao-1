#include <stdio.h>

void desenhaQuadrado(int altura);


int fazASoma(int n1, int n2)
{
    int resultado = n1 + n2;

    return resultado;
}

int fazMultiplicacao(int n1, int n2)
{
    int resultado = n1 * n2;

    return resultado;
}

float fazDivisao(int n1, int n2)
{
    int resultado = n1 / n2;

    return resultado;
}

int fazASubtracao(int n1, int n2)
{
    int resultado = n1 - n2;

    return resultado;
}

int main()
{
    int n1, n2;
    char operacao;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    printf("Digite a operacao (+, -, *, /): ");
    scanf(" %c", &operacao);

    switch (operacao)
    {
    case '+':
        printf("Resultado: %d\n", fazASoma(n1, n2));
        break;
    case '-':
        fazASubtracao(n1, n2);
        break;
    case '*':
        fazMultiplicacao(n1, n2);
        break;
    case '/':
        if (n2 == 0)
            printf("Divisao por zero!\n");
        else
            fazDivisao(n1, n2);
        break;
    default:
        printf("Operacao invalida!\n");
        break;
    }

    desenhaQuadrado(8);
    return 0;
}

void desenhaQuadrado(int altura){
    for(int i = 0; i < altura; i++){
        for(int j = 0; j < altura; j++){
            printf("*");
        }
        printf("\n");
    }
}
