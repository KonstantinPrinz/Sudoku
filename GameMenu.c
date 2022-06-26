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
        sudoku = checkCompletion(sudoku);

    } while(sudoku.Gamestate == 3);

    // Check, ob das Sudoku vollständig gelöst wurde und Anzeige des Siegesbildschirms
    if(sudoku.Gamestate == 5)
    {
        printf("\n\nSudoku Solved!\n   YOU WON!!\nPress any button to return to the main menu!");
        getInput();
    }
    sudoku.Gamestate = 1;
    return sudoku;
}
