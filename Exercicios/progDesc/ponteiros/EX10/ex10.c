/*
Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada
valor lido.
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    int x[5];
    int *pt = x;

    for (int i = 0; i < 5; i++){
        printf("\nDigite o valor %d: ", i+1);
        scanf("%d", pt + i);
    }

    for (int i = 0; i < 5; i++){
        printf("\nNa posicao %d, o valor dobrado e %d", i+1, 2 * (*(pt + i)));
    }

}