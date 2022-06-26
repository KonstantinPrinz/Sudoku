#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

void drawSudoku(struct Puzzle Sudoku)
{
    system("cls");
    for(int row = 0; row < 9; row++)
    {
        if(row % 3 == 0 || row == 0)
        {
            printf("  +---------+---------+---------+\n");
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
    printf("  +---------+---------+---------+\n");
}

// Gibt eine Nummer aus, je nachdem ob die Nummer vorgegeben ist oder ob der Cursor dort steht.
// Liste für ColorCodes: https://www.codeproject.com/Tips/5255355/How-to-Put-Color-on-Windows-Console
void printNumber(int row, int column, struct Puzzle Sudoku)
{
    // Wenn die Zahl 0 ist
    if(Sudoku.Grid[row][column] == 0)
    {
        // Check, ob der Cursor hier steht
        if(cursorCheck(row, Sudoku.CursorY, column, Sudoku.CursorX))
        {
            printf("\033[47m\033[30m . \033[0m");
        }
        else
        {
            printf(" . ");
        }
    }
    // Wenn die Zahl nicht 0 ist
    else
    {
        // Wenn der Cursor darauf steht
        if(cursorCheck(row, Sudoku.CursorY, column, Sudoku.CursorX))
        {
            // Wenn das Feld ein vorgegebenes ist
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
            // Wenn das Feld vorgegeben ist
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
