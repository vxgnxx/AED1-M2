/*
Crie uma funcao que receba dois parametros: um array e um valor do mesmo tipo do
array. A funcao devera preencher os elementos de array com esse valor. Nao utilize
indices para percorrer o array, apenas aritmetica de ponteiros.
*/

#include <stdio.h>

void fill(int *a, int *x, int siz){
    for(int i = 0; i < siz; i++){
        *(a + i) = *x;
    }
}

int main(void){
    int arrSiz = 5;
    int arr[arrSiz];
    int x = 4;

    fill(arr, &x, arrSiz); // Arrays não precisam do prefixo '&' para serem passados para ponteiros

    for(int i = 0; i < arrSiz; i++){
        printf("%d", arr[i]);
    }
}