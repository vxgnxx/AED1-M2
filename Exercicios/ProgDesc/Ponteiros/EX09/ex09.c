/*
Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereco de cada posicao dessa matriz.
*/

#include <stdio.h>

void main() {
    float x[3][3];

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("O endereco da posicao [%d][%d], do array e: %p\n", i, j, (void*)&x[i][j]);
        }
    }
}