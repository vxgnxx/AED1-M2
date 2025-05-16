/*
Escreva um programa para fazer a alocacao dinamica dos blocos de dados conforme
solicitado abaixo:
(a) Vetor de 1024 Bytes (1 Kbyte).
(b) Matriz de inteiros de dimensao 10 x 10.
(c) Vetor para armazenar 50 registros contendo: nome do produto (30 caracteres),
codigo do produto (inteiro) e preco em reais.
(d) Texto de ate 100 linhas com ate 80 caracteres em cada linha.
*/

#include <stdio.h>
#include <stdlib.h>

struct cadastro{
    char nome[30];
    int codigo;
    float preco;
};


int main(){
    void *vector = malloc(1024);


    int **matrix = (int **) malloc(10 * sizeof(int *));
    for(int i = 0; i < 10; i++){
        matrix[i] = (int *) malloc (10 * sizeof(int));
    }

    struct cadastro *list = (struct cadastro *) malloc(50 * sizeof(struct cadastro));


    char **text = (char **) malloc(100 * sizeof(char *));
    for(int i = 0; i < 100; i++){
        text[i] = (char *) malloc (80 * sizeof(char));
    }


    for (int i = 0; i < 10; i++) {
        free(matrix[i]);
    }
    for (int i = 0; i < 100; i++) {
        free(text[i]);
    }
    free(matrix);
    free(vector);
    free(list);
    free(text);
}