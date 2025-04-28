/*
Crie uma funcao que receba como parametro um array e o imprima. Nao utilize indices
para percorrer o array, apenas aritmetica de ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int *arr, int siz){
    int *p = arr;
    for(int i = 0; i < siz; i++){
        printf("Elementos na posicao %d, e: %d\n", i, *p);
        p++;
    }

}

int main(void){
    int arrSiz = 6;
    int arr[arrSiz];
    srand(time(0));


    for(int i = 0; i < arrSiz; i++){
        *(arr + i) = rand() % 10;
    }

    imprimir(arr, arrSiz);

}