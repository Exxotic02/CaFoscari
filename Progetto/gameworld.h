#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vector.h"

#ifndef TESTV2_GAMEWORLD_H
#define TESTV2_GAMEWORLD_H
/*
 *  Initializes the board with a set number of rows and columns.
 */
char** initBoard(int rows, int cols);
/*
 * Fills the board with the given input.
 */
void fillBoard(int rows, int cols, char** board);
/*
 * Prints the board and the snake inside it.
 */
void printBoard(int rows, int cols, char** board, vector_t* snake);
/*
 * initializes the snake head.
 */
vector_t* initSnake(int rows, int cols, char** board);
/*
 * Returns an array with the board elements around the snake head.
 */

void info();

void menu();

#endif //TESTV2_GAMEWORLD_H
