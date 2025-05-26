/*
Faca um programa que leia numeros do teclado e os armazene em um vetor alocado
dinamicamente. O usuario ira digitar uma sequencia de numeros, sem limite de quantidade. 
Os numeros serao digitados um a um e, sendo que caso ele deseje encerrar a
entrada de dados, ele ira digitar o numero ZERO. Os dados devem ser armazenados na
memoria deste modo
• Inicie com um vetor de tamanho 10 alocado dinamicamente;
• Apos, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor
anterior adicionado espaco para mais 10 valores (tamanho N+10, onde N inicia com
10);
• Copie os valores ja digitados da area inicial para esta area maior e libere a memoria
da area inicial;
• Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor
alocado cada vez que o mesmo estiver cheio. Assim o vetor ira ser 'expandido' de
10 em 10 valores.
Ao final, exiba o vetor lido. Nao use a funcao REALLOC.
*/

#include <stdio.h>
#include <stdlib.h>

void reAlloc(int **init, int tamanho){
    int *temp = (int *)malloc(tamanho * sizeof(int));
    
    for(int i = 0; i < tamanho; i++){
        temp[i] = (*init)[i];
    }

    free(*init);

    (*init) = (int *)malloc((tamanho + 10) * sizeof(int));

    for(int i = 0; i < tamanho; i++){
        (*init)[i] = temp[i];
    }

    free(temp);
}

int main(){
    int tamanho = 10;
    int qtd = 0;
    int val;

    int *init = (int *)malloc(tamanho * sizeof(int));
    
    while(val != 0){
        printf("[Entre com o valor 0 caso deseje sair]");
        printf("Entre com o valor desejado: ");
        scanf("%d", &val);

        if(val != 0){

        }
    }

    printf("[Entre com o valor 0 caso deseje sair]\n");
    while(1){
        printf("Entre com o valor desejado: ");
        scanf("%d", &val);

        if(val == 0){
            break;
        }

        if(qtd == tamanho){
            reAlloc(&init, tamanho);
            tamanho += 10;
        }

        init[qtd] = val;
        qtd++;

    }

    printf("Vetor armazenado: ");
    for (int j = 0; j < qtd; j++) {
        printf("%d ", init[j]);
    }
    printf("\n");

    free(init);
}