/*
Faca um programa que pergunte ao usuario quantos valores ele deseja armazenar em
um vetor de double, depois use a funcao MALLOC para reservar (alocar) o espaco de
memoria de acordo com o especificado pelo usuario. Esse vetor deve ter um tamanho
maior ou igual a 10 elementos. Use este vetor dinamico como um vetor comum, atribuindo 
aos 10 primeiros elementos do vetor valores aleatorios (usando a funcao rand)
entre 0 e 100. Exiba na tela os valores armazenados nos 10 primeiros elementos do
vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    double *p;
    int t;
    
    do{
        printf("Qual o tamanho do vetor? ");
        scanf("%d", &t);
        if(t < 10){
            printf("O vetor deve ter tamanho igual ou maior que 10 elementos\n");
        }

    } while(t < 10);

    p = (double *) malloc(t*sizeof(double));

    if(p == NULL){exit(1);};

    for(int i = 0; i < 10; i++){
       p[i] = (rand() % 101);
    }

    for(int i = 0; i < 10; i++){
        printf("%.0f ", p[i]);
    }

    free(p);
}