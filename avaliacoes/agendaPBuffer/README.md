# Felipe Wagner da Silva [22101248] ~ AED1-M2

## Agenda pBuffer

Faça uma agenda com o seguinte menu:
```
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair
```
O desafio é não poder criar variáveis e sim um buffer de memória (void *pBuffer). Nisso vocês terão que fazer o trabalho que o Sistema Operacional faz para vocês ao organizar a memória.

Entregar link de um vídeo explicando o código e mostrando alguns testes e ao final o resultado do Valgrind. (link)
 
### Regras:
```
    1. NENHUMA VARIAVEL PODE SER DECLARADA EM TODO O PROGRAMA, SOMENTE PONTEIROS. Todos os dados do programa devem ser guardados dentro do pBuffer;
        1.1 Nem mesmo como parametro de funcao. So ponteiros que apontam para dentro do pBuffer. Exemplo: int *ptr=(int*)pBuffer;
        1.2 Exemplo do que nao pode: int c; char a; int v[10]; void Funcao(int parametro);
        1.3 Todas as strings que ficarem dentro do pBuffer deve ter somente o tamanho necessário, somente um buffer para receber o que o usuario difita no scanf pode ter um tamanho fixo.
    2. Não pode usar struct em todo o programa.
```

