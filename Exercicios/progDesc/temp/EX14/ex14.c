/*
Construa um programa que leia o numero de linhas e de colunas de uma matriz de
numeros reais, aloque espaco dinamicamente para esta e a inicialize com valores 
fornecidos pelo usuario. Ao final, o programa devera retornar a matriz na saida padrao com
layout apropriado.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int axisXS, axisYS;

    printf("Entre com a dimensao da matriz no eixo X: ");
    scanf("%d", &axisXS);
    printf("Entre com a dimensao da matriz no eixo Y: ");
    scanf("%d", &axisYS);

    int **matrix = (int **)malloc(axisXS * sizeof(int *));
    for(int i = 0; i < axisXS; i++){
        matrix[i] = (int *)malloc(axisYS * sizeof(int));
    }

    for(int i = 0; i < axisXS; i++){
        for(int j = 0; j < axisYS; j++){
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matriz inserida:\n");
    for (int i = 0; i < axisXS; i++) {
        for (int j = 0; j < axisYS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória
    for (int i = 0; i < axisXS; i++) {
        free(matrix[i]);
    }
    free(matrix);


}