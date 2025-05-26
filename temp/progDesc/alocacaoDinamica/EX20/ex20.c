/*
Faca um programa que:
(a) Peca para o usuario entrar com o nome e a posicao (coordenadas X e Y) de N
cidades e as armazene em um vetor de estruturas (N e informado pelo usuario);
(b) Crie uma matriz de distancias entre cidades de tamanho N x N;
(c) Calcule as distancia entre cada duas cidades e armazene na matriz;
(d) Exiba na tela a matriz de distancias obtida;
(e) Quando o usuario digitar o numero de duas cidades o programa devera retornar a
distancia entre ela.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cidades {
    char nome[30];
    int coordX;
    int coordY;
} cidades;

int calcDis(int i, int j, cidades *vecCic){
    int disX = vecCic[i].coordX - vecCic[j].coordX;
    int disY = vecCic[i].coordY - vecCic[j].coordY;
    return disX + disY;
}

int main(){
    int nm;

    printf("Entre num cidades: ");
    scanf("%d", &nm);
    getchar();

    cidades *vecCic = (cidades *) malloc(nm * sizeof(cidades));
    
    for(int i = 0; i < nm; i++){
        printf("Entre com o nome da cidade: ");
        fgets(vecCic[i].nome, sizeof(vecCic[i].nome), stdin);
        size_t len = strlen(vecCic[i].nome);
        if (len > 0 && vecCic[i].nome[len - 1] == '\n') {
            vecCic[i].nome[len - 1] = '\0';
        }

        printf("Entre com a coordenada X: ");
        scanf("%d", &vecCic[i].coordX);
        printf("Entre com a coordenada Y: ");
        scanf("%d", &vecCic[i].coordY);
        getchar();
    }

    int **matrix = (int **) malloc(nm * sizeof(int *));
    for(int i = 0; i < nm; i++){
        matrix[i] = (int *) malloc(nm * sizeof(int));
    }

    for(int i = 0; i < nm; i++){
        for(int j = 0; j < nm; j++){
            matrix[i][j] = calcDis(i, j, vecCic);
        }
    }

    for (int i = 0; i < nm; i++) {
        for (int j = 0; j < nm; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int cidade1, cidade2;
    printf("\nDigite o numero de duas cidades para saber a distancia entre elas (1 a %d): ", nm);
    printf("\nDigite o numero da primeira cidade: ");
    scanf("%d", &cidade1);
    printf("Digite o numero da segunda cidade: ");
    scanf("%d", &cidade2);

    if (cidade1 >= 1 && cidade1 <= nm && cidade2 >= 1 && cidade2 <= nm) {
        printf("\nA distancia entre %s e %s e: %d\n", vecCic[cidade1 - 1].nome, vecCic[cidade2 - 1].nome, matrix[cidade1 - 1][cidade2 - 1]);
    } else {
        printf("Numeros de cidades invalidos!\n");
    }

    for (int i = 0; i < nm; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vecCic);


}