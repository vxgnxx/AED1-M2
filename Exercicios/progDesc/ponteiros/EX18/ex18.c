/*
Implemente uma funcao que calcule a area da superficie e o volume de uma esfera de
raio R. Essa funcao deve obedecer ao prototipo:

void calc_esfera(float R, float *area, float *volume)

A area da superficie e o volume sao dados, respectivamente, por:
A = 4 ∗ p ∗ R2
V = 4/3 ∗ p ∗ R3
*/

#include <stdio.h>

void calc_esfera(float R, float *area, float *volume){
    *area = 4 * 3.14 * (R*R);
    *volume = (4 / 3) * 3.14 * (R*R*R);

}

int main(void){
    float R = 3;
    float A;
    float V;

    calc_esfera(R, &A, &V);

    printf("Volume = %f\nArea = %f\n", V, A);
}