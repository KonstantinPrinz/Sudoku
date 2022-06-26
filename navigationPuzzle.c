#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"


struct Puzzle resolveButtonPress(struct Puzzle sudoku)
{
    int input = getInput();
    // ARROW KEYS: UP / DOWN
    if(input == 1 || input == 2)
    {
        sudoku.CursorY = changeCursor((input-1), sudoku.CursorY);
    }
    // ARROW KEYS: RIGHT / LEFT
    else if(input == 3 || input == 4)
    {
        sudoku.CursorX = changeCursor((input-3), sudoku.CursorX);
    }
    // ESC
    else if(input == 6)
    {
        sudoku.Gamestate = 1;
    }
    // ENTF or 0
    else if(input == 7 || input == 10)
    {
        // Check for editable field
        if(sudoku.DefaultGrid[sudoku.CursorY][sudoku.CursorX] == 0)
            sudoku.Grid[sudoku.CursorY][sudoku.CursorX] = 0;
    }
    // 1 - 9
    else if(input >= 11 && input <= 19)
    {
        // Check for editable field
        if(sudoku.DefaultGrid[sudoku.CursorY][sudoku.CursorX] == 0)
            sudoku.Grid[sudoku.CursorY][sudoku.CursorX] = (input-10);
    }
    return sudoku;
};


int changeCursor(int value, int cursor)
{
    if(value)
    {
        if(cursor == 8)
            return 0;
        else
            return (cursor+1);
    }
    else
    {
        if(cursor == 0)
            return 8;
        else
            return (cursor-1);
    }
}
