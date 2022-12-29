#include "player.h"
#include "gameworld.h"
#include "logic.h"

extern int drill;
extern int points;

void nextMove(int direction, const char *surrounding, vector_t* snake, char** board) {
    if (direction == 'n') {
        if (surrounding[0] == '#') {
            if (drill > 0) {
                int y = v_get(snake, 0);
                int x = v_get(snake, 1);
                board[y - 1][x] = ' ';
                drill--;
            }
            else hitWall();
        }
        else if (surrounding[0] == ' ')
            snakeMoves(snake, direction, board);
        else if (surrounding[0] == '_')
            snakeWins();
        else if (surrounding[0] == '$'){
            snakeEats(snake);
            snakeMoves(snake, direction, board); 
        }
        else if (surrounding[0] == 'o') {
            collapse(snake, board, direction);
        }
        else if (surrounding[0] == 'T') {
            snakeMoves(snake, direction, board);
            drill++;
        }
        else if (surrounding[0] == '!') {
            mistake(board, snake);
            snakeMoves(snake, direction, board);
        }
/////////////////////////////////////////////////////////
    } else if (direction == 's') {
        if (surrounding[1] == '#') {
            if (drill > 0) {
                int y = v_get(snake, 0);
                int x = v_get(snake, 1);
                board[y + 1][x] = ' ';
                drill--;
            }else hitWall();
        }
        else if (surrounding[1] == ' ')
            snakeMoves(snake, direction, board);
        else if (surrounding[1] == '_')
            snakeWins();
        else if (surrounding[1] == '$'){
            snakeEats(snake);
            snakeMoves(snake, direction, board);
        }
        else if (surrounding[1] == 'o') {
            collapse(snake, board, direction);
        }
        else if (surrounding[1] == 'T') {
            snakeMoves(snake, direction, board);
            drill++;
        }
        else if (surrounding[1] == '!') {
            mistake(board, snake);
            snakeMoves(snake, direction, board);
        }
/////////////////////////////////////////////////////////
    } else if (direction == 'e') {
        if (surrounding[2] == '#') {
            if (drill > 0) {
                int y = v_get(snake, 0);
                int x = v_get(snake, 1);
                board[y][x + 1] = ' ';
                drill--;
            }else hitWall();
        }
        else if (surrounding[2] == ' ')
            snakeMoves(snake, direction, board);
        else if (surrounding[2] == '_')
            snakeWins();
        else if (surrounding[2] == '$'){
            snakeEats(snake);
            snakeMoves(snake, direction, board);
        }
        else if (surrounding[2] == 'o') 
            collapse(snake, board, direction);
        else if (surrounding[2] == 'T') {
            snakeMoves(snake, direction, board);
            drill++;
        }
        else if (surrounding[2] == '!') {
            mistake(board, snake);
            snakeMoves(snake, direction, board);
        }
/////////////////////////////////////////////////////////
    } else if (direction == 'w') {
        if (surrounding[3] == '#') {
            if (drill > 0) {
                int y = v_get(snake, 0);
                int x = v_get(snake, 1);
                board[y][x - 1] = ' ';
                drill--;
            }else hitWall();
        }
        else if (surrounding[3] == ' ')
            snakeMoves(snake, direction, board);
        else if (surrounding[3] == '_')
            snakeWins();
        else if (surrounding[3] == '$'){
            snakeEats(snake);
            snakeMoves(snake, direction, board);
        }
        else if (surrounding[3] == 'o') {
            collapse(snake, board, direction);
        }
        else if (surrounding[3] == 'T') {
            snakeMoves(snake, direction, board);
            drill++;
        }
        else if (surrounding[3] == '!') {
            mistake(board, snake);
            snakeMoves(snake, direction, board);
        }
    }
}

char playerInput() {
    printf("Choose your direction\n");
    char direction;
    getchar(); // for '\n' char
    direction = (char)getchar();
    return direction;
}