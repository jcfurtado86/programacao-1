#include <stdio.h>
int main()
{
    int idade; //%d
    float altura; //%f
   
    printf("Informe sua idade \n");
    scanf("%d", &idade);

    printf("Informe a sua altura \n");
    scanf("%f", &altura);

    printf("%d é a sua idade \n", idade);
    printf("Sua altura é %.2f \n", altura);
    
    return 0;
}
