#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool CheckAdjacent_r(char** board, int boardSize, int* boardColSize, char* word, int i, int j, int index);
bool exist(char** board, int boardSize, int* boardColSize, char* word);

int main() {
    char* raw_board[] = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    
    int boardSize = 3;
    int boardColSizeVal = 4;
    int* boardColSize = &boardColSizeVal;

    char** board = malloc(boardSize * sizeof(char*));
    for (int i = 0; i < boardSize; i++) {
        board[i] = strdup(raw_board[i]);
    }

    char word[] = "ASFDA";

    if (exist(board, boardSize, boardColSize, word)) {
        printf("The word \"%s\" exists in the board.\n", word);
    } else {
        printf("The word \"%s\" does not exist in the board.\n", word);
    }

    for (int i = 0; i < boardSize; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}




bool exist(char** board, int boardSize, int* boardColSize, char* word) {
   for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < (*boardColSize); j++){
            if(word[0] == board[i][j]){
                if(CheckAdjacent_r(board, boardSize, boardColSize, word, i, j, 0)){
                    return 1;
                }
            }
        }
   }    

   return 0; 
}

bool CheckAdjacent_r(char** board, int boardSize, int* boardColSize, char* word, int i, int j, int index){
    if(word[index] == '\0') return 1;
    if(i < 0 || i >= boardSize || j < 0 || j >= (*boardColSize)) return 0;
    if(board[i][j] != word[index]) return 0;

    char temp = board[i][j];
    board[i][j] = '*';

    bool adjacent = 
        CheckAdjacent_r(board, boardSize, boardColSize, word, i+1, j, index+1) ||
        CheckAdjacent_r(board, boardSize, boardColSize, word, i-1, j, index+1) ||
        CheckAdjacent_r(board, boardSize, boardColSize, word, i, j+1, index+1) ||
        CheckAdjacent_r(board, boardSize, boardColSize, word, i, j-1, index+1);

    board[i][j] = temp;

    return adjacent;
}