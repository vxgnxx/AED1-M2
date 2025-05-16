/*
Faca um programa que leia dois numeros N e M:
• Crie e leia uma matriz N x M de inteiros;
• Crie e construa uma matriz transposta M x N de inteiros.
• Mostre as duas matrizes.
*/

#include <stdio.h>
#include <stdlib.h>

void matrixTrans(int axisYS, int axisXS, int **matrix, int ***matrixT){
    *matrixT = (int **)malloc(axisXS * sizeof(int *));
    for(int i = 0; i < axisXS; i++){
        (*matrixT)[i] = (int *)malloc(axisYS * sizeof(int));
    }

    for(int i = 0; i < axisXS; i++){
        for(int j = 0; j < axisYS; j++){
            (*matrixT)[i][j] = matrix[j][i];
        }
    }
};

int main(){
    int axisXS, axisYS, **matrixT;

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

    matrixTrans(axisXS, axisYS, matrix, &matrixT);

    printf("\nMatriz:\n");

    for (int i = 0; i < axisXS; i++) {
        for (int j = 0; j < axisYS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz Transposta:\n");

    for (int i = 0; i < axisYS; i++) {
        for (int j = 0; j < axisXS; j++) {
            printf("%d ", matrixT[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < axisXS; i++) {
        free(matrixT[i]);
    }
    free(matrixT);

        for (int i = 0; i < axisXS; i++) {
        free(matrix[i]);
    }
    free(matrix);

}