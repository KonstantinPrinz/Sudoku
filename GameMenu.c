#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

struct Puzzle showGameMenu(struct Puzzle sudoku)
{
    // Initialization
    sudoku = initializeGame(sudoku);

    // Deklaration of a temporary-variable
    int lastInput = 0;

    do
    {
        drawSudoku(sudoku);
        sudoku = resolveButtonPress(sudoku);
        sudoku = checkCompletion(sudoku);

    } while(sudoku.Gamestate == 3);

    // Checks, if the Sudoku if correct and displays the victory screen
    if(sudoku.Gamestate == 5)
    {
        printf("\n\nSudoku Solved!\n   YOU WON!!\nPress any button to return to the main menu!");
        getInput();
    }
    sudoku.Gamestate = 1;
    return sudoku;
}
