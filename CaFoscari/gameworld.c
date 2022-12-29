#include "gameworld.h"
#define OS_Windows

int drill = 0;
int points = 1000;

char** initBoard(int rows, int cols){
    char** board = malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++)
        board[i] = malloc(sizeof(char) * cols);
    return board;
}

void fillBoard(int rows, int cols, char** board){
    for (int i = 0; i < rows; i++) {
        getchar(); // for '\n' char
        for (int j = 0; j < cols; j++) {
            char value;
            value = (char)getchar();
            board[i][j] = value;
        }
    }
}

void printBoard(int rows, int cols, char** board, vector_t* snake) {
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
    printf_s("############################################################\n\n");
    printf_s("Welcome to the game!\n");
    printf_s("Below you see the board!\n");
    printf_s("If you need any information about the game type 'i'.");
    printf_s("\n\n############################################################\n\n");
    vector_t* tmp = v_clone(snake);
    int count = 0;
    while (v_size(tmp) > 0) {
        int y = v_pop_front(tmp); // row
        int x = v_pop_front(tmp); // column
        if (count == 0)
            board[y][x] = 'O';
        else board[y][x] = 'o';
        count++;
    }
    printf_s("Points: ");
    printf_s("%d\n", points);
    printf_s("Drills available: ");
    printf_s("%d\n", drill);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
    v_free(tmp);
}

vector_t* initSnake(int rows, int cols, char** board){
    vector_t* snake = v_create();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++){
            if (board[i][j] == 'o'){
                v_push_back(snake, i);
                v_push_back(snake, j);
                board[i][j] = ' ';
                return snake;
            }
        }
    return NULL;
}

void info() {
    printf_s("##########################################################################\n\n");
    printf_s("Welcome to the info menu!\n");
    printf_s("Everytime you move, you lose a point\n");
    printf_s("1) Use 'N' to go North\n");
    printf_s("2) Use 'S' to go South\n");
    printf_s("3) Use 'E' to go West\n");
    printf_s("4) Use 'W' to go Ovest\n");
    printf_s("5) If you touch '#' you die\n");
    printf_s("6) If you touch '!' your score is halved and same for the body\n");
    printf_s("7) If you touch '$' you earn 10 points and also a body part\n");
    printf_s("8) If you touch 'T you earn a drill wich is used to break walls '#'\n");
    printf_s("9) If yout touch 'o' you lose part of the body");
    printf_s("\n\n##########################################################################\n\n");
    printf_s("Type 'e' to return to the game");
    char input;
    printf_s("\n");
    scanf_s("%c", &input);
    input = tolower(input);
    if (input != 'e') {
        #ifdef OS_Windows
            system("cls");
        #else
            system("clear");
        #endif
        info();
    }
}