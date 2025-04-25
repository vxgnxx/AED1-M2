/*
Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na
segunda variavel. Escreva o conteudo das 2 variaveis na tela.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    if (*b > *a) {
        *a = *b;
        *b = temp;
    }
}

void main(){
    int x, y;


    printf("Entre com a variavel 1: ");
    scanf("%d", &x);
    printf("Entre com a variavel 2: ");
    scanf("%d", &y);

    printf("Pre-modificacao: \nx = %d \ny = %d\n", x, y);

    swap(&x, &y);

    printf("Pos-modificacao: \nx = %d \ny = %d", x, y);

}