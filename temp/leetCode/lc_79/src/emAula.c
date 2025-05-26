/*
Código sem o main pois desenvolvi direto no leetcode
*/

/* 
16:24
Talvez fazer uma struct que armazene cada caractere individualmente junto com sua coordenada na matriz. 
A partir disso fazer uma função booleana onde se busca pelo caractere alvo e o compara com o seu antecessor 
fazendo um calculo onde se a diferença de suas coordenadas X ou Y forem igual a 1 ele retorna verdadeiro. 
*/

bool checkadjacent(char** board, int boardSize, int* boardColSize, char* word, int *I, int*J){
    int i = *I;
    int j = *J;

    while(i < (i + 2)){
        while(j < (j + 2)){
            if(i >= boardSize || j >= (*boardColSize)){
                break;
            }
            
            if(board[i][j] == word){
                if(checkadjacent(board, boardSize, boardColSize, word+1, I, J)){
                    return 1;
                }
            } else {
                break;
            }
            (*J)++;
            j++;
        }
        (*I)++;
        i++;
    }
    
    if(word[0] == '\0'){
        return 1;
    } else {
        return 0;
    }
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i = 0;
    int j = 0;
    int *I = &i;
    int *J = &j;

    while(i < boardSize){
        while(j < (* boardColSize)){
            if(board[i][j] == word[0]){
                if(checkadjacent(board, boardSize, boardColSize, word+1, I, J)){
                    return 1;
                }
            } 
            j++;
        }
        i++;
    }
    return 0;
}



// Recursão??