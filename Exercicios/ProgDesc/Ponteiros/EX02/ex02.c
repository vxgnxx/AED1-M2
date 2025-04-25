/* 
Escreva um programa que contenha duas variaveis inteiras. 
Compare seus enderecos e exiba o maior endereco.
*/

#include <stdio.h>

void main() {
    int x, y;
    x = 0;
    y = 1;

    if (&x > &y){
        printf("O maior endereco e o de x: %p\n", (void*)&x);
    } else {
        printf("O maior endereco e o de y: %p\n", (void*)&y);
    }
}