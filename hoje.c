#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[4][4], somaDiagonal = 0, somaTriangularSuperior = 0, somaTriangularInferior = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    // 1. a soma da diagonal principal i == j
    // 2, a soma da triangular superior i < j
    // 3, a soma da triangular inferior i > j

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
            if (i == j){
                somaDiagonal = somaDiagonal + matriz[i][j];
            }
            if (i < j){
                somaTriangularSuperior = somaTriangularSuperior + matriz[i][j];
            }
            if (i > j){
                somaTriangularInferior = somaTriangularInferior + matriz[i][j];
            }
        }
        printf("\n");
    }

    printf("Soma da diagonal principal: %d\n", somaDiagonal);
    printf("Soma da triangular superior: %d\n", somaTriangularSuperior);
    printf("Soma da triangular inferior: %d\n", somaTriangularInferior);
    
    return 0;
}