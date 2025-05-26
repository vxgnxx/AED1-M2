/*
Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faca uma funcao
que retorne a soma do dobro dos dois numeros lidos. A funcao devera armazenar o dobro
de A na propria variavel A e o dobro de B na propria variavel B
*/

#include <stdio.h>
#include <stdlib.h>

int sumOfDoubles(int *a, int *b){
    *b = *b * 2;
    *a = *a * 2;
    return *a + *b;

}

void main(){
    int x, y, z;

    printf("Entre com a variavel 1: ");
    scanf("%d", &x);
    printf("Entre com a variavel 2: ");
    scanf("%d", &y);

    printf("Pre-modificacao: \nx = %d \ny = %d\n", x, y);

    z = sumOfDoubles(&x, &y);

    printf("Pos-modificacao: \nx = %d \ny = %d \nz = %d", x, y, z);

}