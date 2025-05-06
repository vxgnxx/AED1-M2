/*
Faca um programa que receba do usuario o tamanho de uma string e chame uma
funcao para alocar dinamicamente essa string. Em seguida, o usuario devera informar o
conteudo dessa string. O programa imprime a string sem suas vogais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void alocaString(char **s, int x){
    
    *s = (char *) malloc(x * sizeof(char));

    if(s == NULL){exit(1);};

    printf("Digite a string (até %d caracteres): ", x);
    getchar();
    fgets(*s, x + 1, stdin);
}

void imprimeString(char *str){
    while (*str) {
        char c = tolower(*str);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            putchar(*str);
        }
        str++;
    }
    putchar('\n');
}

int main (void){

    char *s;
    int t;

    printf("Qual o tamanho da string? ");
    scanf("%d", &t);

    alocaString(&s, t);
    imprimeString(s);
    free(s);
}