#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

// Draws the Sudoku every time the method is called
void drawSudoku(struct Puzzle Sudoku)
{
    system("cls");
    for(int row = 0; row < 9; row++)
    {
        if(row % 3 == 0 || row == 0)
        {
            printf("+---------+---------+---------+\n");
        }
        for(int col = 0; col < 9; col++)
        {
            if(col % 3 == 0 || col == 0)
            {
                printf("|");
            }
            printNumber(row, col, Sudoku);
        }
        printf("|");
        printf("\n");
    }
    printf("+---------+---------+---------+\n");
}

// Gives out a number depending on the given number or if the cursor is there.
// List of ColorCodes: https://www.codeproject.com/Tips/5255355/How-to-Put-Color-on-Windows-Console
void printNumber(int row, int column, struct Puzzle Sudoku)
{
    // If number is 0
    if(Sudoku.Grid[row][column] == 0)
    {
        // Check, if the cursor is in the field
        if(cursorCheck(row, Sudoku.CursorY, column, Sudoku.CursorX))
        {
            printf("\033[47m\033[30m . \033[0m");
        }
        else
        {
            printf(" . ");
        }
    }
    // If number is not 0
    else
    {
        // If cursor is on the field
        if(cursorCheck(row, Sudoku.CursorY, column, Sudoku.CursorX))
        {
            // If the field is given
            if(Sudoku.DefaultGrid[row][column])
            {
                printf("\033[47m\033[91m %i \033[0m", Sudoku.Grid[row][column]);
            }
            else
            {
                printf("\033[47m\033[30m %i \033[0m", Sudoku.Grid[row][column]);
            }
        }
        else
        {
            // If the field is given
            if(Sudoku.DefaultGrid[row][column])
            {
                printf("\033[91m %i \033[0m", Sudoku.Grid[row][column]);
            }
            else
            {
                printf(" %i ", Sudoku.Grid[row][column]);
            }
        }
    }
    return;
}

int cursorCheck(int row, int cursorRow, int column, int cursorColumn)
{
    if(row == cursorRow && column == cursorColumn)
        return 1;
    else
        return 0;
}
