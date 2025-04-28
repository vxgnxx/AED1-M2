/*
Considere a seguinte declaracao: int A, *B, **C, ***D; Escreva um programa que leia a
variavel a e calcule e exiba o dobro, o triplo e o quadruplo desse valor utilizando apenas
os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
o quadruplo.
*/

#include <stdio.h>

int main(void){
    int a = 2;
    int *b = &a;
    int **c = &b;
    int ***d = &c;

    printf("\nO valor dobrado e %d", 2 * *b);
    printf("\nO valor triplicado e %d", 3 * **c);
    printf("\nO valor quadriplicado e %d", 4 * ***d);


}