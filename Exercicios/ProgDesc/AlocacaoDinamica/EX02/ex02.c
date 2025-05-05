/*
Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao
dinamica de memoria. Em seguida, leia do usuario seus valores e imprima o vetor lido.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *p;
    int t;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &t);

    p = (int *) malloc(t*sizeof(int));

    if(p == NULL){exit(1);};

    for(int i = 0; i < t; i++){
        printf("Escreva o numero da posicao %d: ", i+1);
        scanf("%d", &p[i]);
    }

    for(int i = 0; i < t; i++){
        printf("%d ", p[i]);
    }

    free(p);
}