/*
Crie um programa que contenha um array de float contendo 10 elementos. 
Imprima o endereco de cada posicao desse array.
*/

#include <stdio.h>

void main() {
    float x[10];

    
    for(int i = 0; i < 10; i++){
        printf("O endereco da posicao %d, do array e: %p\n", i+1, (void*)&x[i]);
    }
}