/*
Implemente uma funcao que receba como parametro um array de numeros reais de
tamanho N e retorne quantos numeros negativos ha nesse array. Essa funcao deve
obedecer ao prototipo:

int negativos(float *vet, int N);
*/

#include <stdio.h>

int negativos(float *vet, int N){
    int res = 0;
    for(int i = 0; i < N; i++){
        if(*vet < 0){
            res++;
        }
        vet++;
    }
    return res;
}

int main (void){
    int tam = 8;    
    float vet[] = {1, -2, -33, 4, -7, 8 -23, 0} ;
    int res;

    res = negativos(vet, tam);

    printf("%d", res);
    


}