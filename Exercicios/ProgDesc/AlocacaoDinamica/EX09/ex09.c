/*
Faca um programa que leia uma quantidade qualquer de numeros armazenando-os na
memoria e pare a leitura quando o usuario entrar um numero negativo. Em seguida,
imprima o vetor lido. Use a funcao REALLOC.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr = NULL;
    int i = 0;
    do{ 
        int temp;
        printf("Escreva o numero %d: ", i+1);
        scanf("%d", &temp);
        
        if(temp < 0){
            break;
        }
        
        int *arr1 = (int *) realloc(arr, (i) * sizeof(int));
        if(arr1 != NULL){
            arr = arr1;
        }
        
        arr[i] = temp;
        i++;
    }while(1);

    printf("array: ");
    for(int j = 0; j < i; j++){
        printf("%d ", arr[j]);
    }

    free(arr);
}