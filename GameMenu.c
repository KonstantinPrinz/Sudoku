#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

struct Puzzle showGameMenu(struct Puzzle sudoku)
{
    // Initialization
    sudoku = initializeGame(sudoku);

    // Deklarierung der Hilfsvariablen
    int lastInput = 0;

    do
    {
        drawSudoku(sudoku);
        sudoku = resolveButtonPress(sudoku);

    } while(sudoku.Gamestate == 3);

    sudoku.Gamestate = 1;
    return sudoku;
}
