/*
Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereco das posicoes contendo valores pares.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int x[5];
    int *pt = x;

    for (int i = 0; i < 5; i++){
        printf("\nDigite o valor %d: ", i+1);
        scanf("%d", pt + i);
    }

    for(int i = 0; i < 5; i++){
        if(*(pt + i) % 2 == 0){
            printf("O endereco da posicao %d, do array e: %p\n", i+1, (void*)&x[i]);
        } else {
            printf("O elemento da posicao %d, do array nao e par\n", i+1);
        }
    }
}