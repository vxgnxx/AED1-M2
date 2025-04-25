/*
Crie um programa que contenha uma funcao que permita passar por parametro dois
numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e
armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera
modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal.
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int *a, int *b){
    *a = *a + *b;
}

void main(){
    int x, y, z;

    printf("Entre com a variavel 1: ");
    scanf("%d", &x);
    printf("Entre com a variavel 2: ");
    scanf("%d", &y);

    printf("Pre-modificacao: \nx = %d \ny = %d\n", x, y);

    sum(&x, &y);

    printf("Pos-modificacao: \nx = %d \ny = %d", x, y);

}