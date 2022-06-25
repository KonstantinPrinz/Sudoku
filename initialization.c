#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

/**
Diese Funktion startet den Initialisierungsvorgang
**/
struct Puzzle initializeGame(struct Puzzle Sudoku)
{
    // Testwerte
    int Raetsel[81] =           {0,4,0,1,0,0,0,8,0,
                                0,0,0,0,0,0,0,9,0,
                                7,0,0,0,2,0,0,0,0,
                                0,0,0,4,0,6,0,0,0,
                                0,0,0,0,0,0,0,0,7,
                                0,5,0,0,0,8,4,0,0,
                                6,0,0,3,0,0,8,0,0,
                                0,0,0,0,1,0,2,0,0,
                               4,0,2,0,0,0,0,0,3};

    Sudoku = fillSudoku(Sudoku, Raetsel);
    return Sudoku;
};

/**
Diese Funktion befüllt das Sudoku-Grid mit Werten
**/
struct Puzzle fillSudoku(struct Puzzle Sudoku, int Ziffern[81])
{
    int currentZiffer = 0;
    for(int i=0; i<9 ; i++)
    {
        for(int j=0; j<9; j++)
        {
            Sudoku.Grid[i][j] = Ziffern[currentZiffer];
            currentZiffer++;
        }
    }
    return Sudoku;
};
