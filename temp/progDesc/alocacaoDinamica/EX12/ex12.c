/*
Considere um cadastro de produtos de um estoque, com as seguintes informacoes para
cada produto:
• Codigo de identificacao do produto: representado por um valor inteiro
• Nome do produto: com ate 50 caracteres
• Quantidade disponivel no estoque: representado por um numero inteiro
• Preco de venda: representado por um valor real
(a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para
guardar as informacoes de um produto
(b) Crie um conjunto de N produtos (N e um valor fornecido pelo usuario) e peca ao
usuario para entrar com as informacoes de cada produto
(c) Encontre o produto com o maior preco de venda
(d) Encontre o produto com a maior quantidade disponivel no estoque
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
    int id;
    int quantEstoque;
    float preco;
    char *nomeProd;
};

void iniProd(int *quant, struct produto **lista);
int getNome(char **nome, int i);
int cmpPreco(const void *a, const void *b);
int cmpQuant(const void *a, const void *b);

int main(){
    int quant;
    struct produto *lista; 


    iniProd(&quant, &lista);
    qsort(lista, quant, sizeof(struct produto), cmpPreco);
    printf("\n%s e o produto mais caro no valor de R$%.2f\n", lista[0].nomeProd, lista[0].preco);

    qsort(lista, quant, sizeof(struct produto), cmpQuant);
    printf("%s e o produto com mais itens em estoque: %d unidades\n", lista[0].nomeProd, lista[0].quantEstoque);

    free(lista->nomeProd);
    free(lista);
}

int cmpQuant(const void *a, const void *b) {
    int quantA = ((struct produto *)a)->quantEstoque;
    int quantB = ((struct produto *)b)->quantEstoque;
    return quantB - quantA;
}


int cmpPreco(const void *a, const void *b) {
    float precoA = ((struct produto *)a)->preco;
    float precoB = ((struct produto *)b)->preco;
    return (precoB > precoA) - (precoB < precoA); // Invertido para ordem decrescente
}

void iniProd(int *quant, struct produto **lista){
    printf("Quantos produtos serao cadastrados? ");
    scanf("%d", quant);

    *lista = (struct produto *) malloc((*quant) * sizeof(struct produto));

    for(int i = 0; i < *quant; i++){
        getNome(&(*lista)[i].nomeProd, i+1);

        printf("\nEntre com o ID de %s: ", (*lista)[i].nomeProd);
        scanf("%d", &(*lista)[i].id);

        printf("\nEntre com a quantidade de %s em estoque: ", (*lista)[i].nomeProd);
        scanf("%d", &(*lista)[i].quantEstoque);

        printf("\nEntre com o preco de %s: ", (*lista)[i].nomeProd);
        scanf("%f", &(*lista)[i].preco);

    }
};

int getNome(char **nome, int i){
    char temp[50];
    printf("Qual o nome do produto %i: ", i);
    scanf("%50s", temp);
    *nome = (char *) malloc((strlen(temp)+ 1) * sizeof(char));
    strcpy(*nome, temp);
}