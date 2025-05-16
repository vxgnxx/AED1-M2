/*
Faca um programa que leia quatro numeros a, b, c e d, que serao as dimensoes de duas
matrizes, e:
• Crie e leia uma matriz, dadas as dimensoes dela;
• Crie e construa uma matriz que seja o produto de duas matrizes. Na sua funcao
main(), imprima as duas matrizes e o produto entre elas, se existir.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, d;
    int **prodMatrix = NULL;

    printf("Entre com a dimensao da matriz 1 no eixo X: ");
    scanf("%d", &a);
    printf("Entre com a dimensao da matriz 1 no eixo Y: ");
    scanf("%d", &b);
    printf("Entre com a dimensao da matriz 2 no eixo X: ");
    scanf("%d", &c);
    printf("Entre com a dimensao da matriz 2 no eixo Y: ");
    scanf("%d", &d);


    int **matrix1 = (int **) malloc(a * sizeof(int *));
    for(int i = 0; i < a; i++){
        matrix1[i] = (int *) malloc (b * sizeof(int));
    }

    int **matrix2 = (int **) malloc(c * sizeof(int *));
    for(int i = 0; i < c; i++){
        matrix2[i] = (int *) malloc (d * sizeof(int));
    }

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            printf("matrix1[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    for(int i = 0; i < c; i++){
        for(int j = 0; j < d; j++){
            printf("matrix2[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    if(b == c){
        prodMatrix = (int **)malloc(a * sizeof(int *));
        for(int i = 0; i < a; i++){
            prodMatrix[i] = (int *) malloc (d * sizeof(int));
        }

        for(int i = 0; i < a; i++){
            for(int j = 0; j < d; j++){
                prodMatrix[i][j] = 0;
                for(int k = 0; k < b; k++){
                prodMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    } else {
        printf("NaN");
    }

    printf("\nMatrix 1:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    if (prodMatrix != NULL){
        printf("\nProduct Matrix:\n");
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < d; j++) {
                printf("%d ", prodMatrix[i][j]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < a; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < c; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < a; i++) {
        free(prodMatrix[i]);
    }
    free(prodMatrix);
}