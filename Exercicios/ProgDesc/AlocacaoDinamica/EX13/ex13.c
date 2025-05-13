/*
Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes
definidas pelo usuario e a leia. Em seguida, implemente uma funcao que receba um
valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int axisXS, axisYS;

    printf("Entre com a dimensao da matriz no eixo X: ");
    scanf("%d", &axisXS);
    printf("Entre com a dimensao da matriz no eixo Y: ");
    scanf("%d", &axisYS);

    int **matrix = (int **)malloc(axisXS * sizeof(int));
    for(int i = 0; i < axisYS; i++){
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