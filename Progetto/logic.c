#include "logic.h"
#include <stdbool.h>
#include "around.h"

extern int points;
extern int drill;

bool isTail = false;

void snakeEats(vector_t* snake){
    points += 10;
    int tailY = v_get(snake, v_size(snake) - 2);
    int tailX = v_get(snake, v_size(snake) - 1);
    v_push_back(snake, tailY);
    v_push_back(snake, tailX);
}

void hitWall(){
    printf("You lose!");
    exit(0);
}

void snakeWins(){
    printf("You Win!");
    exit(0);
}

void mistake(char** board, vector_t* snake) {
    points /= 2;
    if (v_size(snake) > 2)
        cut(snake, board);
}

void cut(vector_t* snake, char** board) {
    int i = 0;
    if ((v_size(snake) / 2) % 2 == 1)
        i = 1;
    for (i; i < v_size(snake) / 2; i++) {
        int tailY = v_get(snake, v_size(snake) - 2);
        int tailX = v_get(snake, v_size(snake) - 1);
        board[tailY][tailX] = ' ';
        v_delete_at(snake, v_size(snake) - 2);
        v_delete_at(snake, v_size(snake) - 1);
    }
}
void collapse(vector_t* snake, char** board, char direction) {
    int tailY;
    int tailX;
    while (!isTail) {
        tailY = v_get(snake, v_size(snake) - 2);
        tailX = v_get(snake, v_size(snake) - 1);
        if (direction == 'n') {
            if (v_get(snake, 0) - 1 == tailY && v_get(snake, 1) == tailX) {
                snakeMoves(snake, direction, board);
                isTail = true;
            }
        }
        if (direction == 's') {
            if (v_get(snake, 0) + 1 == tailY && v_get(snake, 1) == tailX) {
                snakeMoves(snake, direction, board);
                isTail = true;
            }
        }
        if (direction == 'e') {
            if (v_get(snake, 0) == tailY && v_get(snake, 1) + 1 == tailX) {
                snakeMoves(snake, direction, board);
                isTail = true;
            }
        }
        if (direction == 'w') {
            if (v_get(snake, 0) == tailY && v_get(snake, 1) - 1 == tailX) {
                snakeMoves(snake, direction, board);
                isTail = true;
            }
        }
        if (!isTail) {
            board[tailY][tailX] = ' ';
            v_delete_at(snake, v_size(snake) - 2);
            v_delete_at(snake, v_size(snake) - 1);
        }
    }
    isTail = false;
}

void snakeMoves(vector_t* snake, int direction, char** board) {
    int tailY = v_get(snake, v_size(snake) - 2);
    int tailX = v_get(snake, v_size(snake) - 1);
    board[tailY][tailX] = ' ';
    vector_t *tmp = v_clone(snake);
    for (int i = 2; i < v_size(snake); i++)
        v_set(snake, i, v_get(tmp, i - 2));
    v_free(tmp);
    if (direction == 'n')
        v_set(snake, 0, v_get(snake, 0) - 1);
    if (direction == 's')
        v_set(snake, 0, v_get(snake, 0) + 1);
    if (direction == 'e')
        v_set(snake, 1, v_get(snake, 1) + 1);
    if (direction == 'w')
        v_set(snake, 1, v_get(snake, 1) - 1);
}


