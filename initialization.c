#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

/**
This Funktion starts the initialisation
**/
struct Puzzle initializeGame(struct Puzzle Sudoku)
{
        if(Sudoku.Difficulty == 1) //Easy
        {
             int Raetsel[81] =      {0,0,0,7,5,0,4,8,9,
                                    0,4,5,6,9,0,0,1,8,
                                    0,0,6,0,0,0,7,0,0,
                                    9,8,0,2,0,0,0,0,0,
                                    2,0,7,1,0,8,0,0,0,
                                    0,0,3,0,0,5,8,0,7,
                                    4,2,0,0,6,7,1,8,0,
                                    5,0,0,0,2,0,0,7,4,
                                    3,0,0,5,1,0,9,0,2};
            Sudoku = fillSudoku(Sudoku, Raetsel);
        }
        else if(Sudoku.Difficulty == 2) //Medium
        {
             int Raetsel[81] =     {0,0,0,5,0,0,0,0,2,
                                    0,7,0,6,0,0,0,4,0,
                                    4,2,0,0,0,1,0,9,0,
                                    0,4,0,1,0,0,0,0,6,
                                    0,0,0,0,0,0,0,0,0,
                                    0,3,0,0,9,0,0,7,0,
                                    5,0,2,0,0,0,0,0,0,
                                    0,0,3,0,0,5,0,0,7,
                                    0,1,0,3,0,0,0,0,8};
            Sudoku = fillSudoku(Sudoku, Raetsel);
        }
        else if(Sudoku.Difficulty == 3) //Hard
        {
             int Raetsel[81] =     {0,4,0,8,0,0,0,0,6,
                                    0,0,1,0,0,6,0,0,4,
                                    0,0,6,3,0,9,8,0,0,
                                    2,5,0,6,0,3,0,0,0,
                                    0,0,0,0,0,0,0,0,0,
                                    0,8,7,0,0,0,0,4,0,
                                    0,0,0,0,9,0,7,0,0,
                                    0,0,0,0,0,4,0,1,0,
                                    0,0,0,0,0,1,0,0,5};
            Sudoku = fillSudoku(Sudoku, Raetsel);
        }

    Sudoku.CursorX = 0;
    Sudoku.CursorY = 0;
    Sudoku.Initialized = 1;
    return Sudoku;
};

/**
This funktion fills the Sudoku with Values
**/
struct Puzzle fillSudoku(struct Puzzle Sudoku, int Ziffern[81])
{
    int currentZiffer = 0;
    for(int i=0; i<9 ; i++)
    {
        for(int j=0; j<9; j++)
        {
            // Filling of the Grid
            Sudoku.Grid[i][j] = Ziffern[currentZiffer];

            // Filling of the DefaulGrid
            if(Ziffern[currentZiffer] == 0)
                Sudoku.DefaultGrid[i][j] = 0;
            else
                Sudoku.DefaultGrid[i][j] = 1;

            currentZiffer++;
        }
    }
    return Sudoku;
};
