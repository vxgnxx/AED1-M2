/*
Faca um programa para associar nomes as linhas de uma matriz de caracteres. 
O usuario ira informar o numero maximo de nomes que poderao ser armazenados. 
Cada nome podera ter ate 30 caracteres com o '\0'. 
O usuario podera usar 5 opcoes diferentes para manipular a matriz:
(a) Gravar um nome em uma linha da matriz;
(b) Apagar o nome contido em uma linha da matriz;
(c) Informar um nome, procurar a linha onde ele se encontra e substituir por outro nome;
(d) Informar um nome, procurar a linha onde ele se encontra e apagar;
(e) Pedir para recuperar o nome contido em uma linha da matriz;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gravar_nome(char **matrix, int index) {
    char nome[31];
    printf("Digite o nome para gravar: ");
    scanf("%30s", nome);  // Lê o nome com até 30 caracteres
    strcpy(matrix[index], nome);  // Grava o nome na matriz
}

void apagar_nome(char **matrix, int index) {
    strcpy(matrix[index], "");  // Apaga o nome, colocando uma string vazia
}

void substituir_nome(char **matrix, int qtd) {
    char nome_antigo[31], nome_novo[31];
    printf("Digite o nome a ser substituido: ");
    scanf("%30s", nome_antigo);
    
    // Busca pelo nome
    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(matrix[i], nome_antigo) == 0) {
            printf("Digite o novo nome: ");
            scanf("%30s", nome_novo);
            strcpy(matrix[i], nome_novo);  // Substitui o nome na matriz
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome nao encontrado.\n");
    }
}

void apagar_nome_pesquisa(char **matrix, int qtd) {
    char nome[31];
    printf("Digite o nome a ser apagado: ");
    scanf("%30s", nome);

    // Busca pelo nome
    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(matrix[i], nome) == 0) {
            strcpy(matrix[i], "");  // Apaga o nome da matriz
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome nao encontrado.\n");
    }
}

void recuperar_nome(char **matrix, int index) {
    if (strlen(matrix[index]) == 0) {
        printf("Nenhum nome gravado nessa linha.\n");
    } else {
        printf("Nome na linha %d: %s\n", index, matrix[index]);
    }
}

int main(){
    int qtd, opcao, linha;

    printf("Entre com a dimensao da matriz no eixo X: ");
    scanf("%d", &qtd);

    char **matrix = (char **)malloc(qtd * sizeof(char *));
    for(int i = 0; i < qtd; i++){
        matrix[i] = (char *)malloc(31 * sizeof(char));
    }

        printf("\nEscolha uma opcao:\n");
        printf("1. Gravar um nome em uma linha\n");
        printf("2. Apagar o nome em uma linha\n");
        printf("3. Substituir um nome por outro\n");
        printf("4. Apagar um nome pesquisado\n");
        printf("5. Recuperar nome de uma linha\n");
        printf("6. Sair\n");

    do {
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o numero da linha (0 a %d): ", qtd - 1);
                scanf("%d", &linha);
                if (linha >= 0 && linha < qtd) {
                    gravar_nome(matrix, linha);
                } else {
                    printf("Numero de linha invalido.\n");
                }
                break;

            case 2:
                printf("Digite o numero da linha (0 a %d): ", qtd - 1);
                scanf("%d", &linha);
                if (linha >= 0 && linha < qtd) {
                    apagar_nome(matrix, linha);
                } else {
                    printf("Numero de linha invalido.\n");
                }
                break;

            case 3:
                substituir_nome(matrix, qtd);
                break;

            case 4:
                apagar_nome_pesquisa(matrix, qtd);
                break;

            case 5:
                printf("Digite o numero da linha (0 a %d): ", qtd - 1);
                scanf("%d", &linha);
                if (linha >= 0 && linha < qtd) {
                    recuperar_nome(matrix, linha);
                } else {
                    printf("Numero de linha invalido.\n");
                }
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                printf("\nEscolha uma opcao:\n");
                printf("1. Gravar um nome em uma linha\n");
                printf("2. Apagar o nome em uma linha\n");
                printf("3. Substituir um nome por outro\n");
                printf("4. Apagar um nome pesquisado\n");
                printf("5. Recuperar nome de uma linha\n");
                printf("6. Sair\n");
        }
    } while(opcao != 6);

    for (int i = 0; i < qtd; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
