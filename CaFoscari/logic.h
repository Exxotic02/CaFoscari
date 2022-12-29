#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#ifndef TESTV2_LOGIC_H
#define TESTV2_LOGIC_H

void snakeMoves(vector_t* snake, int direction, char** board);
void snakeEats(vector_t* snake);
void hitWall();
void snakeWins();
void cut();
void mistake();
void collapse();

#endif //TESTV2_LOGIC_H
