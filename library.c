#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
Diese Funktion gibt bekommt ein 2 dimensionales Array und gibt das gesamte Sudoku aus.
**/
void printsudoku(int Sudoku[9][9])
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
            if(Sudoku[col][row] == 0)
            {
                printf(" . ");
            }
            else
            {
                printf(" %i ", Sudoku[col][row]);
            }
        }
        printf("|");
        printf("\n");
    }
    printf("  +---------+---------+---------+\n");
}