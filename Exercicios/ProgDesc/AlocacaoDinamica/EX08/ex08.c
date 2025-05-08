/*
Faca um programa para armazenar em memoria um vetor de dados contendo 1500 
valores do tipo int, usando a funcao de alocacao dinamica de memoria CALLOC:
(a) Faca um loop e verifique se o vetor contem realmente os 1500 valores inicializados
com zero (conte os 1500 zeros do vetor).
(b) Atribua para cada elemento do vetor o valor do seu indice junto a este vetor.
(c) Exibir na tela os 10 primeiros e os 10 ultimos elementos do vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v = (int *) calloc(1500, sizeof(int));
    int count = 0;

    for(int i = 0; i < 1500; i++){
        if(v[i] == 0){
            count++;
        }
    }

    if(count == 1500){
        printf("Inicializados corretamente.");
    }

    for(int i = 0; i < 1500; i++){
        v[i] = i;
    }

    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("... ");
    for(int i = 1489; i < 1500; i++){
        printf("%d ", v[i]);
    }

    free(v);
}