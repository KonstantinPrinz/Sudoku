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
    int Raetsel[81] =           {0,2,3,4,5,6,7,8,9,
                                4,5,6,7,8,9,1,2,3,
                                7,8,9,1,2,3,4,5,6,
                                2,3,4,5,6,7,8,9,1,
                                5,6,7,8,9,1,2,3,4,
                                8,9,1,2,3,4,5,6,7,
                                3,4,5,6,7,8,9,1,2,
                                6,7,8,9,1,2,3,4,5,
                                9,1,2,3,4,5,6,7,8};

    Sudoku = fillSudoku(Sudoku, Raetsel);
    Sudoku.CursorX = 0;
    Sudoku.CursorY = 0;
    Sudoku.Initialized = 1;
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
            // Füllen des Grids
            Sudoku.Grid[i][j] = Ziffern[currentZiffer];

            // Füllen des DefaultGrids
            if(Ziffern[currentZiffer] == 0)
                Sudoku.DefaultGrid[i][j] = 0;
            else
                Sudoku.DefaultGrid[i][j] = 1;

            currentZiffer++;
        }
    }
    return Sudoku;
};
