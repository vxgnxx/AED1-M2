/*
Crie uma funcao para somar dois arrays. Esta funcao deve receber dois arrays e retornar
a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente
entao a funcao retornara ZERO (0). Caso a funcao seja concluida com sucesso a mesma
deve retornar o valor UM (1). Utilize aritmetica de ponteiros para manipulacao do array.
*/

#include <stdio.h>

int somar_arrays(int *a, int *b, int *res, int t1, int t2) {
    if (t1 != t2) {
        return 0; // Tamanhos diferentes
    }

    for (int i = 0; i < t1; i++) {
        *(res + i) = *(a + i) + *(b + i);
    }

    return 1;
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    int res[4];

    int tam1 = sizeof(arr1) / sizeof(arr1[0]);
    int tam2 = sizeof(arr2) / sizeof(arr2[0]);

    int foi = somar_arrays(arr1, arr2, res, tam1, tam2);

    if (foi) {
        printf("Resultado da soma: ");
        for (int i = 0; i < tam1; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    } else {
        printf("Erro: os arrays têm tamanhos diferentes.\n");
    }

    return 0;
}
