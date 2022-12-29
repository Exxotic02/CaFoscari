#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

#ifndef TESTV2_PLAYER_H
#define TESTV2_PLAYER_H
/*
 * Returns a char containing the player input (direction).
 */
char playerInput();
/*
 * Moves the snake to the given direction and updates the board accordingly.
 */
void nextMove(int direction, const char *surrounding, vector_t* snake, char** board);

#endif //TESTV2_PLAYER_H
