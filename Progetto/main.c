#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include "vector.h"
#include "gameworld.h"
#include "player.h"
#include "around.h"

extern int points;

int main() {
    int cols, rows;
    scanf("%d", &cols);
    scanf("%d", &rows);
    char** board = initBoard(rows, cols);
    fillBoard(rows, cols, board);
    vector_t* snake = initSnake(rows, cols, board);
    printf("\nYour board is loading\n");
    Sleep(1000);
    printBoard(rows, cols, board, snake);
    char input = playerInput();
    input = tolower(input);
    while (input != 'k') {
        if (input == 'i') {
            info();
            printBoard(rows, cols, board, snake);
            input = playerInput();
        }
        char* surround = checkSurround(board, snake);
        nextMove(input, surround, snake, board);
        points--;
        printBoard(rows, cols, board, snake);
        //v_print(snake);
        input = playerInput();
        free(surround);
    }
    free(board);
    v_free(snake);
    return 0;
}