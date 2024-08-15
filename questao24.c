#include <stdio.h>

        int
        main()
{
    int clima;
    float temperatura;

    printf("Informe o clima: \n 1 para ensolarado \n 2 para nublado \n 3 para chuvoso");
    scanf("%d", &clima);
    printf("Informe a temperatura em Celcius: \n ");
    scanf("%f", &temperatura);
    switch (clima)
    {
    case 1:
        if(temperatura > 25){
            printf("Atividade sugerida: atividades ao ar como ir a praia ou piquenique" );
        }
        else if(temperatura <= 25 && temperatura >= 15){
            printf("Atividade sugerida: Caminhadas ou passeios de bicicleta" );

        }
        else {
            printf("Atividade sugerida: Atividade como fotografia ou obsercao de passaros" );
        }
        break;
    case 2:
        if(temperatura > 20){
            printf("Atividade sugerida: Visitar museus ou fazer compras em centros comerciais" );
        }
        else if(temperatura <= 20 && temperatura >= 10){
            printf("Atividade sugerida: Passeios culturais a galeria de artes ou teatros" );

        }
        else {
            printf("Atividade sugerida: Atividades como leitura em bibliotecas" );
        }
        break;
    case 3:
        if(temperatura > 15){
            printf("Atividade sugerida: Visitar Spas ou aulas de culinaria" );
        }
        else if(temperatura <= 15 && temperatura >= 5){
            printf("Atividade sugerida: Museus de ciencia ou sessoes de boliche" );

        }
        else {
            printf("Atividade sugerida: Tarde de jogos de tabuleiro ou maratona de filmes" );
        }
        break;
    default:
        break;
    }
    return 0;
    
    // Autor: Denny Lindo
}
