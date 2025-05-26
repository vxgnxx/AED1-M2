/*
Escreva uma funcao que receba um array de inteiros V e os enderecos de duas variaveis
inteiras, min e max, e armazene nessas variaveis o valor minimo e maximo do array.
Escreva tambem uma funcao main que use essa funcao.
*/

#include <stdio.h>

void minmax(int *a, int *min, int *max){
    *max = *a;
    *min = *a;
    for(int i = 0; i < 10; i++){
        if(*min > *(a + i)){
            *min = *(a + i);
        }
        if(*max < *(a + i)){
            *max = *(a + i);
        }
    }
}

int main(void){
    int arr[] = {6, 5, 4, 8, 2, 9, 23, 1, 7, -33};
    int min;
    int max;

    minmax(arr, &min, &max);
    printf("%d %d", max, min);
}