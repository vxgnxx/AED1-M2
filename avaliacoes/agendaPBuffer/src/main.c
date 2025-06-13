#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set of defined names and aliases for better coding and readability

#define INT_SIZE sizeof(int)
#define NAME_MAX 100
#define MAIL_MAX 100

#define MENU_OFFSET 0
#define COUNT_OFFSET        (MENU_OFFSET          + INT_SIZE)
#define NAME_SIZE_OFFSET    (COUNT_OFFSET         + INT_SIZE)
#define AGE_TEMP_OFFSET     (NAME_SIZE_OFFSET     + INT_SIZE)
#define EMAIL_SIZE_OFFSET   (AGE_TEMP_OFFSET      + INT_SIZE)
#define TEMP_NAME_OFFSET    (EMAIL_SIZE_OFFSET    + INT_SIZE)
#define TEMP_MAIL_OFFSET    (TEMP_NAME_OFFSET     + NAME_MAX)
#define PERSON_SIZE_OFFSET  (TEMP_MAIL_OFFSET     + MAIL_MAX)
#define TEMP_TRACKER_OFFSET (PERSON_SIZE_OFFSET   + INT_SIZE)
#define TEMP_INT_OFFSET     (TEMP_TRACKER_OFFSET  + INT_SIZE)
#define DATA_OFFSET         (TEMP_INT_OFFSET      + INT_SIZE)

// Function prototypes

void AddPerson(void **pBuffer);

// Main function

int main(){

    void *pBuffer = malloc(DATA_OFFSET);
    *(int *)pBuffer = 0;

    
    int  *totalBufferSize  = (int *)((char *)pBuffer + TEMP_TRACKER_OFFSET);
    *totalBufferSize = DATA_OFFSET;

    int *option = (int *) pBuffer;
    *option = 0;

    do {
        printf("\nA G E N D A\n");
        printf("1- Adicionar Pessoa\n");
        printf("2- Remover Pessoa\n");
        printf("3- Buscar Pessoa\n");
        printf("4- Listar todos\n");
        printf("5- Sair\n");
        printf("Opcao: ");

        scanf("%d", option);
        getchar();
        
        switch (*option) {
            case 1:
                //addPerson(&pBuffer);
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
    } while (*option != 5);

    free(pBuffer);
    return 0;
}
/*
void AddPerson(void **pBuffer){
    char *ptr = (char *)*pBuffer;

    int  *quantity         = (int *)(ptr + COUNT_OFFSET);
    int  *newPersonSize    = (int *)(ptr + PERSON_SIZE_OFFSET);
    int  *totalBufferSize  = (int *)(ptr + TEMP_TRACKER_OFFSET);
    int  *nameSize         = (int *)(ptr + NAME_SIZE_OFFSET);
    int  *age              = (int *)(ptr + AGE_TEMP_OFFSET);
    int  *emailSize        = (int *)(ptr + EMAIL_SIZE_OFFSET);
    char *tempName         = (char *)(ptr + TEMP_NAME_OFFSET);
    char *tempEmail        = (char *)(ptr + TEMP_MAIL_OFFSET);
    

    GetPerson(*pBuffer);

    *newPersonSize = *(int *)(ptr + NAME_SIZE_OFFSET) + sizeof(age_t) + *(int *)(ptr + EMAIL_SIZE_OFFSET);
    char *data = (int *)(ptr + TEMP_INT_OFFSET);
    
    for(int i = 0; i < *quantity; i++){
        int currNameSize = 
    }

}



void GetPerson(void *pBuffer){
    char *ptr = (char *)pBuffer;

    int *newPersonSize = (int *) (ptr + PERSON_SIZE_OFFSET );
    int *nameSize      = (int *) (ptr + NAME_SIZE_OFFSET   );
    int *age           = (int *) (ptr + AGE_TEMP_OFFSET    );
    int *emailSize     = (int *) (ptr + EMAIL_SIZE_OFFSET  );
    char *tempName     = (char *)(ptr + TEMP_NAME_OFFSET   );
    char *tempEmail    = (char *)(ptr + TEMP_MAIL_OFFSET   );

    memset(tempName, 0, NAME_MAX);
    memset(tempEmail, 0, MAIL_MAX);

    printf("Nome: ");
    fgets(tempName, NAME_MAX, stdin);
    tempName[strcspn(tempName, "\n")] = '\0';
    *nameSize = strlen(tempName) + 1;

    printf("Idade: ");
    scanf("%d", age);
    getchar();  

    printf("Email: ");
    fgets(tempEmail, MAIL_MAX, stdin);
    tempEmail[strcspn(tempEmail, "\n")] = '\0'; 
    *emailSize = strlen(tempEmail) + 1;

    *newPersonSize = *nameSize + INT_SIZE + *emailSize + INT_SIZE;
}

*/