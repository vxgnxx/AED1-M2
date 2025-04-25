/*
Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do
teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.
*/

#include <stdio.h>

void main() {
    int x, y;

    printf("Entre com a variavel 1: ");
    scanf("%d", &x);
    printf("Entre com a variavel 2: ");
    scanf("%d", &y);

    if (&x > &y){
        printf("%d", x);
    } else {
        printf("%d", y);
    }
}
