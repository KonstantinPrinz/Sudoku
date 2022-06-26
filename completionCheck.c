#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

struct Puzzle checkCompletion(struct Puzzle sudoku)
{
    // Checks for Rows, Columns and Blocks.
    if(checkRows(sudoku) && checkColumns(sudoku) && checkBlocks(sudoku))
       {
           sudoku.Gamestate = 5;
       }
    return sudoku;
};

int checkRows(struct Puzzle sudoku)
{
    int success = 1;

    // Gets Rows
    for(int i = 0; i<9 ; i++)
    {
        // Flushing comparison array
        int row[9] = {0,0,0,0,0,0,0,0,0};

        for(int j = 0; j<9 ; j++)
        {
            // Check: Is there a Zero?
            if(sudoku.Grid[i][j] == 0)
            {
                success = 0;
                break;
            }
            else
            {
                // Check: Did this number already appear once? Array indexes are used to keep track of this information
                if(row[(sudoku.Grid[i][j])-1] == 0)
                {
                   row[(sudoku.Grid[i][j])-1] = 1;
                }
                else
                {
                    success = 0;
                    break;
                }
            }
        }
        if(success == 0)
            break;
    }
    return success;
}

int checkColumns(struct Puzzle sudoku)
{
    int success = 1;

    // Gets Columns
    for(int i = 0; i<9 ; i++)
    {
        // Flushing comparison array
        int column[9] = {0,0,0,0,0,0,0,0,0};

        for(int j = 0; j<9 ; j++)
        {
                // No Zero check: This is done in the Rows
                // Check: Did this number already appear once? Array indexes are used to keep track of this information
                if(column[(sudoku.Grid[j][i])-1] == 0)
                {
                   column[(sudoku.Grid[j][i])-1] = 1;
                }
                else
                {
                    success = 0;
                    break;
                }
        }
        if(success == 0)
            break;
    }
    return success;
}

int checkBlocks(struct Puzzle sudoku)
{
    int success = 1;

    for(int i = 0; i<9 ; i++)
    {
        // Flushing comparison array
        int block[9] = {0,0,0,0,0,0,0,0,0};

        // Berechnung für die Ziffer ganz rechts oben im Block, wenn die Blöcke von links oben nach rechts unten durchnummerier werden
        // BSP: Block Nr. 7 (mitte unten)
        //      x = floor(7/3) * 3 = 6
        //      y = (7 % 3) * 3 = 3
        double rowHelper = (double)i;
        int xStart = (int)floor(rowHelper/3)*3;
        int yStart = (i % 3) * 3;
        int xTarget = xStart+3;
        int yTarget = yStart+3;

        for(int x = xStart; x<xTarget; x++)
        {
            for(int y = yStart; y<yTarget; y++)
            {
                if(block[(sudoku.Grid[x][y])-1] == 0)
                {
                    block[(sudoku.Grid[x][y])-1] = 1;
                }
                else
                {
                    success = 0;
                }
            }
            if(success == 0)
            {
                break;
            }
        }
        if(success == 0)
            break;
    }
    return success;
}
