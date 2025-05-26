/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. 
Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros. 
Imprima os valores das variaveis antes e apos a modificacao.
*/

#include <stdio.h>

void main(){
    int   var01 = 20;
    char  var02 = 'c';
    float var03 = 4.77;

    int   *pInt;
    char  *pChar;
    float *pReal;

    pInt  = &var01;
    pChar = &var02;
    pReal = &var03;

    printf("Pre-modificacao:\n");
    printf("Inteiro: %d\n", var01);
    printf("Char: %c\n", var02);
    printf("Real: %.2f\n", var03);

    *pInt  = 30;
    *pChar = 'd';
    *pReal = 4.88;

    printf("\nPos-modificacao:\n");
    printf("Inteiro: %d\n", var01);
    printf("Char: %c\n", var02);
    printf("Real: %.2f\n", var03);
}