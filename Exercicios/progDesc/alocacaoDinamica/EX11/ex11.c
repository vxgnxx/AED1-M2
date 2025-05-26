/*
Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Deverao ser armazenados, para cada aluno: matricula, sobrenome (apenas um) e
ano de nascimento.
(b) Ao inicio do programa, o usuario devera informar o numero de alunos que serao
armazenados
(c) O programa devera alocar dinamicamente a quantidade necessaria de memoria
para armazenar os registros dos alunos.
(d) O programa devera pedir ao usuario que entre com as informacoes dos alunos.
(e) Ao final, mostrar os dados armazenados e liberar a memoria alocada
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getMatricula(){
    int temp;
    printf("Numero de matricula do aluno: ");
    scanf("%d", &temp);
    return temp;
}

int getNascimento(){
    int temp;
    printf("Ano de nascimento do aluno: ");
    scanf("%d", &temp);
    return temp;
}

void getSobrenome(char **sobrenome){
    char temp[100];
    printf("Sobrenome do aluno (Somente 1): ");
    scanf("%s", temp);
    *sobrenome = (char *) malloc((strlen(temp)+ 1) * sizeof(char));
    strcpy(*sobrenome, temp);
}


struct cadastro {
    int matricula;
    int anoNascimento;
    char *sobrenome;
};




int main(){
    int quant;
    struct cadastro *lista; 

    printf("Quantos alunos serao cadastrados? ");
    scanf("%d", &quant);

    lista = (struct cadastro *) malloc(quant * sizeof(struct cadastro));

    for(int i = 0; i < quant; i++){
        lista[i].matricula = getMatricula();
        lista[i].anoNascimento = getNascimento();
        getSobrenome(&lista[i].sobrenome);
    }


    printf("\nDados dos alunos cadastrados:\n\n");
    for (int i = 0; i < quant; i++) {
        printf("Aluno %d: Matricula: %d, Sobrenome: %s, Ano de Nascimento: %d\n\n", i + 1, lista[i].matricula, lista[i].sobrenome, lista[i].anoNascimento);
    }

    for (int i = 0; i < quant; i++) {
        free(lista[i].sobrenome);
    }

    free(lista);
}