#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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



/**
Diese Funktion gibt bekommt ein 2 dimensionales Array und gibt das gesamte Sudoku aus.
**/
void printsudoku(struct Puzzle Sudoku)
{
    printf("    1  2  3   4  5  6   7  8  9 \n");
    for(int col = 0; col < 9; col++)
    {
        if(col % 3 == 0 || col == 0)
        {
            printf("  +---------+---------+---------+\n");
        }
        printf("%i ", col + 1);;
        for(int row = 0; row < 9; row++)
        {
            if(row % 3 == 0 || row == 0)
            {
                printf("|");
            }
            if(Sudoku.Grid[col][row] == 0)
            {
                printf(" . ");
            }
            else
            {
                printf(" %i ", Sudoku.Grid[col][row]);
            }
        }
        printf("|");
        printf("\n");
    }
    printf("  +---------+---------+---------+\n");
}
