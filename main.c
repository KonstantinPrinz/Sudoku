#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    struct Puzzle sudoku;
    sudoku.Gamestate = 1;
    sudoku.Initialized = 0;

    // Menu
    while(sudoku.Gamestate > 0)
    {
        sudoku = showMenu(sudoku);
    }
    return 0;
}
