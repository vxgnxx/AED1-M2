/*
Elabore uma funcao que receba duas strings como parametros e verifique se a segunda
string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres
das strings.
*/

#include <stdio.h>

int verificaSubstring(char *str1, char *str2) {
    char *p1, *p2, *inicio;

    if (*str2 == '\0') {
        return 1;
    }

    while (*str1 != '\0') {
        p1 = str1;
        p2 = str2;
        inicio = str1;

        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return 1;
        }

        str1++;
    }

    return 0; 
}


int main() {
    char str1[] = "linguagem de programacao";
    char str2[] = "guage";

    if (verificaSubstring(str1, str2)) {
        printf("A segunda string ocorre dentro da primeira.\n");
    } else {
        printf("A segunda string NAO ocorre dentro da primeira.\n");
    }

    return 0;
}
