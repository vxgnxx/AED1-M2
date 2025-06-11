#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int nameSize_t;
typedef int age_t;
typedef int emailSize_t;

void addPerson(void **pBuffer);

int main(){

    void *pBuffer = malloc(216);
    *(int *)pBuffer = 0;

    int *opcao = malloc(sizeof(int));
    *opcao = 0;

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
                addPerson(&pBuffer);
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

void addPerson(void **pBuffer){
    void *p = *pBuffer;

    int  *quantity  = (int *) (p);        // offset 0
    int  *nameSize  = (int *) (p + 4);    // offset 4
    int  *age       = (int *) (p + 8);    // offset 8
    int  *emailSize = (int *) (p + 12);   // offset 12
    char *tempName  = (char *)(p + 16);   // offset 16
    char *tempEmail = (char *)(p + 116);  // offset 116

    // Input
    printf("Nome: ");
    fgets(tempName, 100, stdin);
    tempName[strcspn(tempName, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", age);
    getchar();

    printf("Email: ");
    fgets(tempEmail, 100, stdin);
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    *nameSize = strlen(tempName) + 1;
    *emailSize = strlen(tempEmail) + 1;

    int newPersonSize = sizeof(int) + *nameSize + sizeof(int) + sizeof(int) + *emailSize;
    int offset = 216; // Start of person data
    char *data = (char *)(p + 216);

    for (int i = 0; i < *quantity; i++) {
        int currNameSize = *(int *)data;
        data += sizeof(int) + currNameSize;  // nameSize + name
        data += sizeof(int);                 // age
        int currEmailSize = *(int *)data;
        data += sizeof(int) + currEmailSize; // emailSize + email
        offset = data - (char *)p;
    }

    *pBuffer = realloc(*pBuffer, offset + newPersonSize);

    // Update pointers after realloc
    p = *pBuffer;
    quantity =  (int *) (p);
    nameSize =  (int *) (p + 4);
    age =       (int *) (p + 8);
    emailSize = (int *) (p + 12);
    tempName =  (char *)(p + 16);
    tempEmail = (char *)(p + 116);

    data = (char *)p + offset;

    *(int *)data = *nameSize;
    data += sizeof(int);
    memcpy(data, tempName, *nameSize);
    data += *nameSize;

    *(int *)data = *age;
    data += sizeof(int);

    *(int *)data = *emailSize;
    data += sizeof(int);
    memcpy(data, tempEmail, *emailSize);

    (*quantity)++;
}

void removePerson(void **pBuffer){



}
