#include <stdio.h>

int main()
{
    int categoria, quantidade;
    float valor;

    printf("Informe a categoria do produto desejado\n 1: Produtos de tecnologia - R$150,00 cada\n 2: Produtos de alimentação - R$50,00 cada\n 3: Produtos de vestuário - R$80,00 cada\n 4: Produtos de saúde - R$120,00 cada\n 5: Produtos de lazer - R$90,00 cada\n");
    scanf("%d", &categoria);
    printf("Informe a quantidade do produto: ");
    scanf("%d", &quantidade);
    if (quantidade > 0)
    {

        switch (categoria)
        {
        case 1:
            printf("Produto de tecnologia");
            valor = quantidade * 150;
            break;
        case 2:
            printf("Produtos de alimentação");
            valor = quantidade * 50;
            break;
        case 3:
            printf("Produtos de vestuário");
            valor = quantidade * 80;
            break;
        case 4:
            printf("Produto de saúde");
            valor = quantidade * 120;
            break;
        case 5:
            printf("Produto de lazer");
            valor = quantidade * 90;
            break;

        default:
            break;
        }

        if (quantidade >= 1 && quantidade <= 5)
        {
            valor = valor - (valor * 0.05);
        }
        else
        {
            if (quantidade >= 6 && quantidade <= 10)
            {
                valor = valor - (valor * 0.10);
            }
            else
            {
                valor = valor - (valor * 0.15);
            }
        }

        printf("O valor total dos seus pedidos é de: R$ %.2f", valor);
    }
    return 0;
}
