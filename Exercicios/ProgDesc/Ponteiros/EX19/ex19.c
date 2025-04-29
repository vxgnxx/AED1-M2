/*
Escreva uma funcao que aceita como parametro um array de inteiros com N valores, e
determina o maior elemento do array e o numero de vezes que este elemento ocorreu
no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
8, 6, 15, a funcao deve retorna para o programa que a chamou o valor 15 e o numero 3
(indicando que o numero 15 ocorreu 3 vezes). A funcao deve ser do tipo void.
*/

#include <stdio.h>

void find(int *a, int *b, int*c){
    for(int i = 0; i < 8; i++){
        if(*a == *b){
            (*c)++;
        }
        a++;
    }
}

int main(void){
    int array[] = {3, 4, 5, 6, 12, 6, 6, 2}; //8
    int num = 3;
    int res = 0;

    find(array, &num, &res);
    printf("%d", res);

}