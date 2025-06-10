#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    void *pBuffer = malloc(sizeof(int));

    *(int *)pBuffer = 0;

    int *opcao = (int *)((char *)pBuffer + sizeof(int));

    do {
        printf("\nAGENDA\n");
        printf("1- Adicionar Pessoa\n");
        printf("2- Remover Pessoa\n");
        printf("3- Buscar Pessoa\n");
        printf("4- Listar todos\n");
        printf("5- Sair\n");
        printf("Opcao: ");

        scanf("%d", opcao);
        getchar();
        
        switch (*opcao) {
            case 1:
                //adicionarPessoa(pBuffer);
                printf("\nadd\n");
                break;
            case 2:
                //removerPessoa(pBuffer);
                printf("\nremove\n");
                break;
            case 3:
                //buscarPessoa(pBuffer);
                printf("\nsearch\n");
                break;
            case 4:
                //listarPessoas(pBuffer);
                printf("\nlist\n");
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (*opcao != 5);

    free(pBuffer);
    return 0;
}