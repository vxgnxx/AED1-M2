/*
Faca um programa que leia um numero N e:
• Crie dinamicamente e leia um vetor de inteiro de N posicoes;
• Leia um numero inteiro X e conte e mostre os multiplos desse numero que existem
no vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *mul;
    int t;

    printf("Qual o tamanho do vetor? ");
    scanf("%d", &t);

    mul = (int *) malloc(t * sizeof(int));

    printf("Qual o numero base? ");
    scanf("%d", &mul[0]);

    for(int i = 1; i < t; i++){
        mul[i] = mul[0] * (i + 1);
    }

    for(int i = 0; i < t; i++){
        printf("%d ", mul[i]);
    }

    free(mul);



}