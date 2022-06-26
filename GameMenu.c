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
        lastInput = getInput();
    } while(lastInput != 6);

    sudoku.Gamestate = 1;
    return sudoku;
}
