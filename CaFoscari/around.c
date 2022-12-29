#include "around.h"
#include "vector.h"

char* checkSurround(char** board, vector_t* snake) {
    int y = v_get(snake, 0); // row number
    int x = v_get(snake, 1); // col number
    char* surround = malloc(sizeof(char*) * 4);
    surround[3] = board[y][x - 1]; // W
    surround[2] = board[y][x + 1]; // E
    surround[1] = board[y + 1][x]; // S
    surround[0] = board[y - 1][x]; // N
    return surround;               // NSEW
}