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
