/*
Implemente uma funcao que calcule as raizes de uma equacao do segundo grau do tipo
Ax^2 + Bx + C = 0. Lembrando que:
X = (−B ± √∆) / 2A
Onde
∆ = B^2 − 4AC

A variavel A tem que ser diferente de zero.

• Se ∆ < 0 nao existe real.
• Se ∆ = 0 existe uma raiz real.
• Se ∆ ≥ 0 existem duas raizes reais.

Essa funcao deve obedecer ao seguinte prototipo:

int raizes(float A,float B,float C,float * X1,float * X2);

Essa funcao deve ter como valor de retorno o numero de raizes reais e distintas da
equacao. Se existirem raizes reais, seus valores devem ser armazenados nas variaveis
apontadas por X1 e X2.
*/

#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2){
    float delta;
    if (A == 0){
        printf("A = 0, calculo invalido\n");
        return 0;
    } else {
        delta = (B * B) + ((-4) * A * C);

        if (delta < 0) {
            printf("Nao ha raiz real\n");
            return 0;
        } else {
            *X1 = (-B + sqrt(delta)) / 2 * A;
            *X2 = (-B - sqrt(delta)) / 2 * A;
            if (*X1 == *X2) {
                printf("Ambas raizes tem valor: %.2f", *X1);
                return 1;
            } else {
                printf("Raiz 1 com valor: %.2f\nRaiz 2 com valor: %.2f", *X1, *X2);
                return 2;
            }
        }
    }
}

int main(void){
    float A = 0;
    float B = 4;
    float C = 4;
    float x1;
    float x2;

    int res = raizes(A, B, C, &x1, &x2);

}
