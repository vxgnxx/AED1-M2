/*
Escreva uma funcao que retorna o maior valor de um array de tamanho N. Escreva um
programa que leia N valores inteiros, imprima o array com k elementos por linha, e o
maior elemento. O valor de k tambem deve ser fornecido pelo usuario.
*/

#include <stdio.h>

int bring(int *a, int n){     // Bubble Sort
    int temp;
    for(int i = 0; i < n - 1; i ++){
        for (int j = 0; j < n - i - 1; j++) {
            if (*(a + j) > *(a + j + 1)) {
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
    }
}

int main(void){
    int N = 8;
    int arr[] = {1, 2, 3, 4, 8, 5, 6, 7};

    bring(arr, N);
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n%d\n", arr[7]);

}

