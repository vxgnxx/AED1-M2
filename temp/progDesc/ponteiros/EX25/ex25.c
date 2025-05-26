/*
Faca um programa que possua uma funcao para
• ler 2 notas e retorna-las por parametro (chamar uma funcao dedicada a ler 2 notas
validas e que devolver os 2 numeros lidos);
• calcular a media simples e a media ponderada e retorna-las por parametro, onde a
segunda nota tem peso 2 media ponderada = (n1 + n2 ∗ 2)/3;
*/

#include <stdio.h>
#include <stdlib.h>

void read(float *nota1, float *nota2){
    printf("Entre nota 1: ");
    scanf("%f", nota1);
    printf("\nEntre nota 2: ");
    scanf("%f", nota2);
}

void media(float *final){
    float nota1, nota2;
    read(&nota1, &nota2);
    *final = (nota1 + nota2 * 2) / 3;
}

int main(void){
    float final;
    media(&final);

    printf("Media final = %.2f", final);

}