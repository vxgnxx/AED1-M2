/*
Faca um programa que simule a memoria de um computador: o usuario ira especificar o
tamanho da memoria, ou seja, quantos bytes serao alocados do tipo inteiro. Para tanto,
a memoria solicitada deve ser um valor multiplo do tamanho do tipo inteiro. Em seguida,
o usuario ter a 2 opcoes: inserir um valor em uma determinada posicao ou consultar o
valor contido em uma determinada posicao. A memoria deve iniciar com todos os dados
zerados.
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

    int tamMem;
    int opcao;

    printf("Informe o tamanho da memoria (Em Bytes): ");
    scanf("%d", &tamMem);

    if(tamMem % sizeof(int) != 0){
        printf("O tamanho da memoria deve ser multiplo de %d bytes!\n", sizeof(int));
        return 1;
    }

    int numPos = tamMem / sizeof(int);
    int *memoria = (int *) calloc(numPos, sizeof(int));

    while(1){
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir valor em uma posicao\n");
        printf("2. Consultar valor em uma posicao\n");
        printf("3. Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            int posicao, valor;
            printf("Informe a posicao (0 a %d): ", numPos - 1);
            scanf("%d", &posicao);

            if (posicao >= 0 && posicao < numPos) {
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &valor);
                memoria[posicao] = valor;
                printf("Valor %d inserido na posicao %d.\n", valor, posicao);
            } else {
                printf("Posicao invalida!\n");
            }
            break;
        case 2:
            printf("Informe a posicao (0 a %d): ", numPos - 1);
            scanf("%d", &posicao);
            if (posicao >= 0 && posicao < numPos) {
                printf("Valor na posicao %d: %d\n", posicao, memoria[posicao]);
            } else {
                printf("Posicao invalida!\n");
            }
            break;
        case 3:
            printf("Saindo.");
            free(memoria);
            exit(1);
            break;
        
        default:
            break;
        }
    }

    free(memoria);
}