/*
Escreva um programa que leia primeiro os 6 numeros gerados pela loteria e depois os 6
numeros do seu bilhete. O programa entao compara quantos numeros o jogador acertou.
Em seguida, ele aloca espaco para um vetor de tamanho igual a quantidade de numeros
corretos e guarda os numeros corretos nesse vetor. Finalmente, o programa exibe os
numeros sorteados e os seus numeros corretos.
*/

#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int num[] = {51, 32, 72, 93, 10, 56};
    int bill[6];
    int acertos = 0;;

    printf("Digite os 6 numeros do seu bilhete:\n");
    for (int i = 0; i < 6; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &bill[i]);
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (num[i] == bill[j]) {
                acertos++;
                break;
            }
        }
    }

    int *corretos = (int *) malloc(acertos * sizeof(int));
    int y = 0;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(num[i] == bill[j]){
                corretos[y++] = num[i];
                break;
            }
        }
    }

    printf("\nNumeros corretos: ");
    for (int i = 0; i < y; i++) {
        printf("%d ", corretos[i]);
    }
    printf("\n");

    free(corretos);
    return 0;
}
