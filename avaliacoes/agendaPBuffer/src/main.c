#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set of defined names and aliases for better coding and readability

#define INT_SIZE sizeof( int )
#define NAME_MAX 100
#define MAIL_MAX 100

#define MENU_OFFSET 0                                               
#define COUNT_OFFSET          ( MENU_OFFSET           + INT_SIZE )  
#define NAME_SIZE_OFFSET      ( COUNT_OFFSET          + INT_SIZE )  
#define AGE_TEMP__OFFSET      ( NAME_SIZE_OFFSET      + INT_SIZE )  
#define MAIL_SIZE_OFFSET      ( AGE_TEMP__OFFSET      + INT_SIZE )  
#define TEMP_NAME_OFFSET      ( MAIL_SIZE_OFFSET      + INT_SIZE )  
#define TEMP_MAIL_OFFSET      ( TEMP_NAME_OFFSET      + NAME_MAX )  
#define PERSON_SIZE_OFFSET    ( TEMP_MAIL_OFFSET      + MAIL_MAX )  
#define BUFFER_TRACKER_OFFSET ( PERSON_SIZE_OFFSET    + INT_SIZE )  
#define ITERATOR_OFFSET       ( BUFFER_TRACKER_OFFSET + INT_SIZE )  
#define DATA_TRACKER_OFFSET   ( ITERATOR_OFFSET       + INT_SIZE )  
#define CS_NAME_OFFSET        ( DATA_TRACKER_OFFSET   + INT_SIZE )  
#define CS_MAIL_OFFSET        ( CS_NAME_OFFSET        + INT_SIZE )  
#define BLOCK_SIZE_OFFSET     ( CS_MAIL_OFFSET        + INT_SIZE )  
#define TO_MOVE_OFFSET        ( BLOCK_SIZE_OFFSET     + INT_SIZE )  
#define BOOL_OFFSET           ( TO_MOVE_OFFSET        + INT_SIZE )  
#define DATA_OFFSET           ( BOOL_OFFSET           + INT_SIZE )  

// Global pointers

char *ptr;
int  *quantity;
int  *personSize;
int  *bufferSize;
int  *iterator;
int  *currentOffset;
int  *cNameSize;
int  *cMailSize;
int  *toMove;
int  *found;

int  *age;
int  *nameSize;
int  *mailSize;
int  *blockSize;
char *tempName;
char *tempMail;

// Function prototypes

void UpdatePointers( void *pBuffer );
void AddPerson( void **pBuffer );
void GetPerson ( void *pBuffer );
void ListAll( void *pBuffer );
void RemovePerson( void **pBuffer );
void SearchPerson( void *pBuffer );

// Main function

int main(){

    void *pBuffer = malloc( DATA_OFFSET );
    memset(pBuffer, 0, DATA_OFFSET);

    
    UpdatePointers( pBuffer );

    *bufferSize = DATA_OFFSET;
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
    UpdatePointers( *pBuffer );

    GetPerson( *pBuffer );
    
    *personSize = *nameSize + INT_SIZE + *mailSize + INT_SIZE;
    *iterator = 0;
    *currentOffset = 0;
    
    for(; *iterator < *quantity; ( *iterator )++){
        char *currentPerson = ptr + DATA_OFFSET + *currentOffset;
        
        *cNameSize = strlen( currentPerson ) + 1;
        *cMailSize = strlen( currentPerson + *cNameSize + INT_SIZE )+1;
        *blockSize = *( int * )( currentPerson + *cNameSize + INT_SIZE + *cMailSize );

        *currentOffset += *blockSize;
    }
    
    *bufferSize += *personSize;
    void *newBuffer = realloc( *pBuffer, *bufferSize );
    if ( newBuffer == NULL ) {
        printf( "Memory reallocation failed!\n" );
        exit( 1 );
    }

    *pBuffer = newBuffer;

    UpdatePointers( *pBuffer );

    char *newPerson = ptr + DATA_OFFSET + *currentOffset;

    memcpy( newPerson, tempName, *nameSize );
    memcpy( newPerson + *nameSize, age, INT_SIZE );
    memcpy( newPerson + *nameSize + INT_SIZE, tempMail, *mailSize );
    
    // Registra a quantidade de espaço alocado para o registro.
    *( int * )( newPerson + (*personSize - INT_SIZE) ) = *personSize; 

    *quantity += 1;
}

/*
============================
    ListAll
        cria uma lista com
        todos os registros
============================
*/

void ListAll( void *pBuffer) {

    UpdatePointers( pBuffer );

    *currentOffset = 0;
    *iterator = 0;

    if ( *quantity == 0 ) {
        printf( "Nenhuma pessoa cadastrada.\n" );
        return;
    }

    for ( ; *iterator < *quantity; ( *iterator )++ ) {
        char *personPtr = ptr + DATA_OFFSET + *currentOffset;

        char *cName = personPtr;
        *cNameSize = strlen( cName ) + 1;

        int *cAge = ( int * )( personPtr + *cNameSize );

        char *cMail = personPtr + *cNameSize + INT_SIZE;
        *cMailSize = strlen( cMail ) + 1;

        int *blockSize = ( int * )( personPtr + *cNameSize + INT_SIZE + *cMailSize );

        printf( "\nPessoa %d:\n", *iterator + 1 );
        printf( "   Nome : %s\n", cName );
        printf( "   Idade: %d\n", *cAge );
        printf( "   Email: %s\n", cMail );

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
    UpdatePointers(*pBuffer);

    memset( tempName, 0, NAME_MAX );
    *found = 0;
    *currentOffset = 0;
    *iterator = 0;

    printf( "Nome da pessoa a remover: " );
    fgets( tempName, NAME_MAX, stdin );
    tempName[strcspn( tempName, "\n" )] = '\0';

    for ( ; *iterator < *quantity; ( *iterator )++) {
        char *personPtr = ptr + DATA_OFFSET + *currentOffset;

        char *name = personPtr;
        *cNameSize = strlen( name ) + 1;

        char *email = personPtr + *cNameSize + INT_SIZE;
        *cMailSize    = strlen( email ) + 1;

        *blockSize = *( int *)( personPtr + *cNameSize + INT_SIZE + *cMailSize );

        if ( strcmp( name, tempName ) == 0 ) {
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
    char *end   = ptr + *bufferSize;
    *toMove = end - ( start + *blockSize );

    if (*toMove > 0) {
        memmove(start, start + *blockSize, *toMove);
    }

    *bufferSize -= *blockSize;
    *quantity -= 1;

    void *newBuffer = realloc( *pBuffer, *bufferSize );
    if ( newBuffer == NULL && *quantity > 0 ) {
        printf( "Erro ao realocar memória após remoção!\n" );
        exit( 1 );
    }

    *pBuffer = newBuffer;
    UpdatePointers( *pBuffer );

}

/*
============================
    SearchPerson
        Busca uma pessoa pelo nome
============================
*/

void SearchPerson( void *pBuffer ){
    
    UpdatePointers( pBuffer );

    memset( tempName, 0, NAME_MAX );
    *currentOffset = 0;
    *iterator = 0;
    *found = 0;

    printf( "\nNome da pessoa a buscar: " );
    fgets( tempName, NAME_MAX, stdin );
    tempName[strcspn( tempName, "\n" )] = '\0';

    for ( ; *iterator < *quantity; ( *iterator )++ ) {
        char *personPtr = ptr + DATA_OFFSET + *currentOffset;

        char *cName = personPtr;
        *cNameSize = strlen( cName ) + 1;

        int *age = ( int * )( personPtr + *cNameSize );
        char *cMail = personPtr + *cNameSize + INT_SIZE;
        *cMailSize    = strlen( cMail ) + 1;

        *blockSize = *( int * )( personPtr + *cNameSize + INT_SIZE + *cMailSize );

        if ( strcmp( cName, tempName ) == 0 ) {
            printf( "\nPessoa encontrada:\n" );
            printf( "  Nome : %s\n", cName );
            printf( "  Idade: %d\n", *age );
            printf( "  Email: %s\n", cMail );
            *found = 1;
            break;
        }

        *currentOffset += *blockSize;
    }

    if ( !*found ) {
        printf( "Pessoa não encontrada.\n" );
    }
}

void UpdatePointers( void *pBuffer ){

    ptr = ( char * )pBuffer;

    quantity         = ( int * )( ptr  + COUNT_OFFSET );
    personSize       = ( int * )( ptr  + PERSON_SIZE_OFFSET );
    bufferSize       = ( int * )( ptr + BUFFER_TRACKER_OFFSET );
    iterator         = ( int * )( ptr + ITERATOR_OFFSET );
    currentOffset    = ( int * )( ptr + DATA_TRACKER_OFFSET);
    cNameSize        = ( int * )( ptr + CS_NAME_OFFSET );
    cMailSize        = ( int * )( ptr + CS_MAIL_OFFSET );
    blockSize        = ( int * )( ptr + BLOCK_SIZE_OFFSET );
    toMove           = ( int * )( ptr + TO_MOVE_OFFSET );
    found            = ( int * )( ptr + BOOL_OFFSET ); 

    // Input Data
    age              =  ( int * ) ( ptr + AGE_TEMP__OFFSET );
    nameSize         =  ( int * ) ( ptr + NAME_SIZE_OFFSET );
    mailSize         =  ( int * ) ( ptr + MAIL_SIZE_OFFSET );
    tempName         =  ( char * )( ptr + TEMP_NAME_OFFSET );
    tempMail         =  ( char * )( ptr + TEMP_MAIL_OFFSET );
}

/*
==========================================
    GetPerson

        Armazena o input do usuario
==========================================
*/


void GetPerson( void *pBuffer ){
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
    *mailSize = strlen( tempMail ) + 1;
}