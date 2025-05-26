/*
Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,
(b) Peca para o usuario digitar os 5 numeros no espaco alocado,
(c) Mostre na tela os 5 numeros,
(d) Libere a memoria alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *p;
    p = (int *) malloc(5*sizeof(int));

    if(p == NULL){exit(1);};

    for(int i = 0; i < 5; i++){
        printf("Escreva o numero da posicao %d: ", i+1);
        scanf("%d", &p[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", p[i]);
    }

    free(p);
}