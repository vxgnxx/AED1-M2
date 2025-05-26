/*
Escreva uma funcao que dado um numero real passado como parametro, retorne a parte
inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao.
Prototipo:
void frac(float num, int* inteiro, float* frac);
*/


void frac(float num, int* inteiro, float* frac){
    *inteiro = (int)num;
    *frac = num - *inteiro;

}

#include <stdio.h>

int main(void) {
    float real = 3.44;
    int inteiro;
    float fraci;

    frac(real, &inteiro, &fraci);

    printf("%d + %.2f", inteiro, fraci);


}