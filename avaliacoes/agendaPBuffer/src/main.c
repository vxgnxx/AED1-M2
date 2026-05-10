#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set of defined names and aliases for better coding and readability

#define INT_SIZE sizeof( int )
#define NAME_MAX 100
#define MAIL_MAX 100

#define MENU_OFFSET 0                                               //
#define COUNT_OFFSET          ( MENU_OFFSET           + INT_SIZE )  //
#define NAME_SIZE_OFFSET      ( COUNT_OFFSET          + INT_SIZE )  //
#define AGE_TEMP__OFFSET      ( NAME_SIZE_OFFSET      + INT_SIZE )  //
#define MAIL_SIZE_OFFSET      ( AGE_TEMP__OFFSET      + INT_SIZE )  //
#define TEMP_NAME_OFFSET      ( MAIL_SIZE_OFFSET      + INT_SIZE )  //
#define TEMP_MAIL_OFFSET      ( TEMP_NAME_OFFSET      + NAME_MAX )  //
#define PERSON_SIZE_OFFSET    ( TEMP_MAIL_OFFSET      + MAIL_MAX )  //
#define BUFFER_TRACKER_OFFSET ( PERSON_SIZE_OFFSET    + INT_SIZE )  //
#define TEMP_INT1_OFFSET      ( BUFFER_TRACKER_OFFSET + INT_SIZE )  //
#define TEMP_INT2_OFFSET      ( TEMP_INT1_OFFSET      + INT_SIZE )  //
#define TEMP_INT3_OFFSET      ( TEMP_INT2_OFFSET      + INT_SIZE )  //
#define TEMP_INT4_OFFSET      ( TEMP_INT3_OFFSET      + INT_SIZE )  //
#define TEMP_INT5_OFFSET      ( TEMP_INT4_OFFSET      + INT_SIZE )  //
#define TEMP_INT6_OFFSET      ( TEMP_INT5_OFFSET      + INT_SIZE )  //
#define TEMP_INT7_OFFSET      ( TEMP_INT6_OFFSET      + INT_SIZE )  //
#define DATA_OFFSET           ( TEMP_INT7_OFFSET      + INT_SIZE )  //

// Function prototypes

void AddPerson( void **pBuffer );
void GetPerson ( void *pBuffer );
void ListAll( void *pBuffer );
void RemovePerson( void **pBuffer );
void SearchPerson( void *pBuffer );

// Main function

int main(){

    void *pBuffer = malloc( DATA_OFFSET );
    *( int * )pBuffer = 0;

    
    int  *totalBufferSize  = ( int * )( ( char * )pBuffer + BUFFER_TRACKER_OFFSET );
    *totalBufferSize = DATA_OFFSET;

    int *option = ( int * ) pBuffer;
    *option = 0;

    do {
        printf( "\nA G E N D A\n" );
        printf( "1- Adicionar Pessoa\n" );
        printf( "2- Remover Pessoa\n" );
        printf( "3- Buscar Pessoa\n" );
        printf( "4- Listar todos\n" );
        printf( "5- Sair\n" );
        printf( "Opcao: " );

        scanf( "%d", option );
        getchar();
        
        switch ( *option ) {
            case 1:
                AddPerson( &pBuffer );
                break;
            case 2:
                RemovePerson( &pBuffer );
                break;
            case 3:
                SearchPerson( pBuffer );
                break;
            case 4:
                ListAll( pBuffer );
                break;
            case 5:
                printf( "Saindo...\n" );
                break;
            default:
                printf( "Opcao invalida!\n" );
        }
    } while ( *option != 5 );

    free( pBuffer );
    return 0;
}

/*
===============================================
    AddPerson

    Adiciona o input do usuário no pBuffer 
    através da aritmética de ponteiros. Além
    de automaticamente expandir a quantidade
    de memória para o pBuffer.

===============================================
*/

void AddPerson(void **pBuffer){
    char *ptr = ( char * )*pBuffer;

    int  *quantity         = ( int * ) ( ptr + COUNT_OFFSET );
    int  *newPersonSize    = ( int * ) ( ptr + PERSON_SIZE_OFFSET );
    int  *totalBufferSize  = ( int * ) ( ptr + BUFFER_TRACKER_OFFSET );
    int  *nameSize         = ( int * ) ( ptr + NAME_SIZE_OFFSET );
    int  *age              = ( int * ) ( ptr + AGE_TEMP__OFFSET );
    int  *emailSize        = ( int * ) ( ptr + MAIL_SIZE_OFFSET );
    char *tempName         = ( char * )( ptr + TEMP_NAME_OFFSET );
    char *tempEmail        = ( char * )( ptr + TEMP_MAIL_OFFSET );

    GetPerson( *pBuffer );

    int *pos          = ( int * )( ptr + TEMP_INT1_OFFSET );
    int *totalSizePtr = ( int * )( ptr + TEMP_INT2_OFFSET );
    
    *newPersonSize = *nameSize + INT_SIZE + *emailSize + INT_SIZE;
    *pos = 0;
    *totalSizePtr = 0;

    int *nameLen   = ( int * )( ptr + TEMP_INT3_OFFSET );
    int *emailLen  = ( int * )( ptr + TEMP_INT4_OFFSET );
    int *blockSize = ( int * )( ptr + TEMP_INT5_OFFSET );

    while( *pos < *quantity ){
        char *personPtr = ptr + DATA_OFFSET + *totalSizePtr;
        
        *nameLen = strlen( personPtr ) + 1;
        *emailLen = strlen( personPtr + *nameLen + INT_SIZE )+1;
        *blockSize = *( int * )( personPtr + *nameLen + INT_SIZE + *emailLen );

        *totalSizePtr += *blockSize;
        ( *pos )++;
    }
    
    *totalBufferSize += *newPersonSize;
    void *newBuffer = realloc( *pBuffer, *totalBufferSize );
    if ( newBuffer == NULL ) {
        printf( "Memory reallocation failed!\n" );
        exit( 1 );
    }

    *pBuffer = newBuffer;

    ptr                  = ( char * )*pBuffer;
    totalBufferSize      = ( int * )( ptr  + BUFFER_TRACKER_OFFSET );
    quantity             = ( int * )( ptr  + COUNT_OFFSET );
    newPersonSize        = ( int * )( ptr  + PERSON_SIZE_OFFSET );
    totalSizePtr         = ( int * )( ptr  + TEMP_INT2_OFFSET );
    nameSize             = ( int * )( ptr  + NAME_SIZE_OFFSET );
    age                  = ( int * )( ptr  + AGE_TEMP__OFFSET );
    emailSize            = ( int * )( ptr  + MAIL_SIZE_OFFSET );
    tempName             = ( char * )( ptr + TEMP_NAME_OFFSET );
    tempEmail            = ( char * )( ptr + TEMP_MAIL_OFFSET );

    char *newPersonPtr   = ptr + DATA_OFFSET + *totalSizePtr;

    memcpy( newPersonPtr, tempName, *nameSize );
    memcpy( newPersonPtr + *nameSize, age, INT_SIZE );
    memcpy( newPersonPtr + *nameSize + INT_SIZE, tempEmail, *emailSize );

    *( int * )( newPersonPtr + *nameSize + INT_SIZE + *emailSize ) = *newPersonSize;

    *quantity += 1;
}

/*
==========================================
    GetPerson

        Armazena o input do usuario
==========================================
*/


void GetPerson( void *pBuffer ){
    char *ptr = ( char * )pBuffer;
    int *nameSize      = ( int * ) ( ptr + NAME_SIZE_OFFSET );
    int *age           = ( int * ) ( ptr + AGE_TEMP__OFFSET );
    int *emailSize     = ( int * ) ( ptr + MAIL_SIZE_OFFSET );
    char *tempName     = ( char * )( ptr + TEMP_NAME_OFFSET );
    char *tempMail     = ( char * )( ptr + TEMP_MAIL_OFFSET );

    memset( tempName, 0, NAME_MAX );
    memset( tempMail, 0, MAIL_MAX );

    printf( "\nNome: ");
    fgets( tempName, NAME_MAX, stdin);
    tempName[strcspn( tempName, "\n")] = '\0';
    *nameSize = strlen( tempName) + 1;

    printf( "Idade: ");
    scanf( "%d", age);
    getchar();  

    printf( "Email: ");
    fgets( tempMail, MAIL_MAX, stdin );
    tempMail[strcspn( tempMail, "\n" )] = '\0'; 
    *emailSize = strlen( tempMail ) + 1;
}

/*
============================
    ListAll
        cria uma lista com
        todos os registros
============================
*/

void ListAll( void *pBuffer) {
    char *ptr = ( char * )pBuffer;

    int *quantity      = ( int * )( ptr + COUNT_OFFSET );
    int *i             = ( int * )( ptr + TEMP_INT4_OFFSET );
    int *emailLen      = ( int * )( ptr + TEMP_INT3_OFFSET );
    int *nameLen       = ( int * )( ptr + TEMP_INT2_OFFSET );
    int *currentOffset = ( int * )( ptr + TEMP_INT1_OFFSET );

    *currentOffset = 0;
    *i = 0;

    if ( *quantity == 0 ) {
        printf( "Nenhuma pessoa cadastrada.\n" );
        return;
    }

    for ( ; *i < *quantity; ( *i )++ ) {
        char *personPtr = ptr + DATA_OFFSET + *currentOffset;

        char *name = personPtr;
        *nameLen = strlen( name ) + 1;

        int *age = ( int * )( personPtr + *nameLen );

        char *email = personPtr + *nameLen + INT_SIZE;
        *emailLen = strlen( email ) + 1;

        int *blockSize = ( int * )( personPtr + *nameLen + INT_SIZE + *emailLen );

        printf( "\nPessoa %d:\n", *i + 1 );
        printf( "   Nome : %s\n", name );
        printf( "   Idade: %d\n", *age );
        printf( "   Email: %s\n", email );

        *currentOffset += *blockSize;
    }
}

/*
========================
    RemovePerson
        Remove a pessoa através de seu nome
        também diminui o tamanho do pBuffer
        automaticamente
========================
*/

void RemovePerson( void **pBuffer){
    char *ptr = ( char * )*pBuffer;

    int *totalBufferSize  = ( int * )( ptr  + BUFFER_TRACKER_OFFSET );
    int *quantity         = ( int * )( ptr  + COUNT_OFFSET );
    int *currentOffset    = ( int * )( ptr  + TEMP_INT1_OFFSET );
    int *i                = ( int * )( ptr  + TEMP_INT2_OFFSET );
    int *blockSize        = ( int * )( ptr  + TEMP_INT3_OFFSET );
    int *found            = ( int * )( ptr  + TEMP_INT4_OFFSET );
    int *emailLen         = ( int * )( ptr  + TEMP_INT5_OFFSET );
    int *nameLen          = ( int * )( ptr  + TEMP_INT6_OFFSET );
    int *bytesToMove      = ( int * )( ptr  + TEMP_INT7_OFFSET );
    char *searchName      = ( char * )( ptr + TEMP_NAME_OFFSET );

    memset( searchName, 0, NAME_MAX );
    *found = 0;
    *currentOffset = 0;
    *i = 0;

    printf( "Nome da pessoa a remover: " );
    fgets( searchName, NAME_MAX, stdin );
    searchName[strcspn( searchName, "\n" )] = '\0';

    for ( ; *i < *quantity; ( *i )++) {
        char *personPtr = ptr + DATA_OFFSET + *currentOffset;

        char *name = personPtr;
        *nameLen = strlen( name ) + 1;

        char *email = personPtr + *nameLen + INT_SIZE;
        *emailLen = strlen( email ) + 1;

        *blockSize = *( int *)( personPtr + *nameLen + INT_SIZE + *emailLen );

        if ( strcmp( name, searchName ) == 0 ) {
            *found = 1;
            break;
        }

        *currentOffset += *blockSize;
    }

    if ( !*found) {
        printf( "Pessoa não encontrada.\n" );
        return;
    }

    char *start = ptr + DATA_OFFSET + *currentOffset;
    char *end   = ptr + *totalBufferSize;
    *bytesToMove = end - ( start + *blockSize );

    memmove( start, start + *blockSize, *bytesToMove );

    *totalBufferSize -= *blockSize;
    *quantity -= 1;

    void *newBuffer = realloc( *pBuffer, *totalBufferSize );
    if ( newBuffer == NULL && *quantity > 0 ) {
        printf( "Erro ao realocar memória após remoção!\n" );
        exit( 1 );
    }

    *pBuffer = newBuffer;
    ptr = ( char * )*pBuffer;
}

/*
============================
    SearchPerson
        Busca uma pessoa pelo nome
============================
*/

void SearchPerson( void *pBuffer ){
    char *ptr = ( char * )pBuffer;

    int *quantity       = ( int * )( ptr  + COUNT_OFFSET );
    int *currentOffset  = ( int * )( ptr  + TEMP_INT1_OFFSET );
    int *i              = ( int * )( ptr  + TEMP_INT2_OFFSET );
    int *found          = ( int * )( ptr  + TEMP_INT3_OFFSET );
    int *blockSize      = ( int * )( ptr  + TEMP_INT4_OFFSET ) ;
    char *searchName    = ( char * )( ptr + TEMP_NAME_OFFSET );

    memset( searchName, 0, NAME_MAX );
    *currentOffset = 0;
    *i = 0;
    *found = 0;

    printf( "\nNome da pessoa a buscar: " );
    fgets( searchName, NAME_MAX, stdin );
    searchName[strcspn( searchName, "\n" )] = '\0';

    for ( ; *i < *quantity; ( *i )++ ) {
        char *personPtr = ptr + DATA_OFFSET + *currentOffset;

        char *name = personPtr;
        int nameLen = strlen( name ) + 1;

        int *age = ( int * )( personPtr + nameLen );
        char *email = personPtr + nameLen + INT_SIZE;
        int emailLen = strlen( email ) + 1;

        *blockSize = *( int * )( personPtr + nameLen + INT_SIZE + emailLen );

        if ( strcmp( name, searchName ) == 0 ) {
            printf( "\nPessoa encontrada:\n" );
            printf( "  Nome : %s\n", name );
            printf( "  Idade: %d\n", *age );
            printf( "  Email: %s\n", email );
            *found = 1;
            break;
        }

        *currentOffset += *blockSize;
    }

    if ( !*found ) {
        printf( "Pessoa não encontrada.\n" );
    }
}