/*
Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. 
Associe o ponteiro ao array. Agora, some mais um (+1) a cada posicao do array usando o
ponteiro (use *).
*/

#include <stdio.h>

void oneUp(int *pt){
    for(int i = 0; i < 8; i++){
        (*pt)++;
        pt++;
    }
}

int main (void){
    int vet[] = {1, -2, -33, 4, -7, 8, -23, 0} ;

    oneUp(vet);


    for(int i = 0; i < 8; i++){
        printf("%d\n", vet[i]);
    }


}