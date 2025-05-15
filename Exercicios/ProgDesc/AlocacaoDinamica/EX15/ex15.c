/*
Faca um programa que leia dois numeros N e M e:
• Crie e leia uma matriz de inteiros N x M;
• Localize os tres maiores numeros de uma matriz e mostre a linha e a coluna onde estao.
*/

#include <stdio.h>
#include <stdlib.h>

int findBig(int axisXS, int axisYS, int **matrix){
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int pos1[2] = {0, 0}, pos2[2] = {0, 0}, pos3[2] = {0, 0};
    
    for (int i = 0; i < axisXS; i++) {
        for (int j = 0; j < axisYS; j++) {
            int val = matrix[i][j];

            if (val > max1) {
                max3 = max2; 
                pos3[0] = pos2[0]; 
                pos3[1] = pos2[1];

                max2 = max1; 
                pos2[0] = pos1[0]; 
                pos2[1] = pos1[1];

                max1 = val;  
                pos1[0] = i;       
                pos1[1] = j;
            } else if (val > max2) {
                max3 = max2; 
                pos3[0] = pos2[0]; 
                pos3[1] = pos2[1];
                
                max2 = val;  
                pos2[0] = i;       
                pos2[1] = j;
            } else if (val > max3) {
                max3 = val;  
                pos3[0] = i;       
                pos3[1] = j;
            }
        }
    }

    printf("\nMaiores valores encontrados:\n");
    printf("1o maior: %d na posicao [%d][%d]\n", max1, pos1[0], pos1[1]);
    printf("2o maior: %d na posicao [%d][%d]\n", max2, pos2[0], pos2[1]);
    printf("3o maior: %d na posicao [%d][%d]\n", max3, pos3[0], pos3[1]);

}

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

    findBig(axisXS, axisYS, matrix);

    // Liberar a memória
    for (int i = 0; i < axisXS; i++) {
        free(matrix[i]);
    }
    free(matrix);


}