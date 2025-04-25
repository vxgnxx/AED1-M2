/*
Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas
2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas
variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B
tera o valor de A.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void main(){
    int x, y;
    // int *pX = &x;
    // int *pY = &y;
    // int *pZ;
    // pZ = (int*) malloc(sizeof(int));

    printf("Entre com a variavel 1: ");
    scanf("%d", &x);
    printf("Entre com a variavel 2: ");
    scanf("%d", &y);

    printf("Pre-modificacao: %d, %d\n", x, y);

    // *pZ = *pY;
    // *pY = *pX;
    // *pX = *pZ;

    swap(&x, &y);

    printf("Pos-modificacao: %d, %d", x, y);

}