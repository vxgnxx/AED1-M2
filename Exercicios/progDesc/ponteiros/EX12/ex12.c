/*
Faca um programa que leia tres valores inteiros e chame uma funcao que receba estes 3
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel,
o segundo menor valor na variavel do meio, e o maior valor na ultima variavel. A funcao
deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes.
Exibir os valores ordenados na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b, int *c){
    int temp;
    if (*a > *b && *a > *c) {
        temp = *a;
        if(*b > *c){
            *a = *c;
            *c = temp;
            return 0;
        } else {
            *a = *b;
            *b = *c;
            *c = temp;
            return 0;
        }
    } else if (*b > *a && *b > *c){
        temp = *b;
        if(*c > *a){
            *b = *c;
            *c = temp;
            return 0;
        } else {
            *b = *a;
            *a = *c;
            *c = temp;
            return 0;
        }
    } else if (*c > *b && *c > *a){
        temp = *a;
        if (*a > *b){
            *a = *b;
            *b = temp;
            return 0;
        }
    } else {
        return 0;
    }
}

int main(void){
    int x, y, z;

    printf("Entre com a variavel 1: ");
    scanf("%d", &x);
    printf("Entre com a variavel 2: ");
    scanf("%d", &y);
    printf("Entre com a variavel 3: ");
    scanf("%d", &z);

    printf("Pre-modificacao: \nx = %d \ny = %d\nz = %d\n", x, y, z);

    swap(&x, &y, &z);

    printf("Pos-modificacao: \nx = %d \ny = %d\nz = %d\n", x, y, z);
}