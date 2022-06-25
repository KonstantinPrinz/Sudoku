#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    struct Puzzle sudoku;
    // Menu
    sudoku = initializeMenu(sudoku);


    // Initialization
    initializeGame(sudoku);

    // Gameplay
    return 0;
}
