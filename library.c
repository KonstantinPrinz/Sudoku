#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

/**
Gibt eine Reihe zur�ck. Von oben nach unten, Reihe 1 - 9
**/
int* getRow(struct Puzzle sudoku, int rowNr)
{
    int row[9];
    for(int i = 0; i<9 ; i++)
    {
       row[i] = sudoku.Grid[rowNr-1][i];
    }
    return row;
}

/**
Gibt eine Spalte zur�ck. Von links nach rechts, 1 - 9
**/
int* getColumn(struct Puzzle sudoku, int columnNr)
{
    int column[9];
    for(int i = 0; i<9 ; i++)
    {
        column[i] = sudoku.Grid[i][columnNr-1];
    }
    return column;
}

/**
Gibt einen Block zur�ck. Von links oben nach rechts unten 1 - 9.
**/
int* getBlock(struct Puzzle sudoku, int blockNr)
{
    int block[9];
    int zaehler = 0;
    double blockNrDouble = blockNr;

    int row = (int)floor((blockNrDouble-1) / 3);

    int column = (blockNr-1) % 3;

    for(int i = 0; i<3 ; i++)
    {
        for(int j = 0; j<3; j++)
        {
            block[zaehler] = sudoku.Grid[(row*3)+i][(column*3)+j];
            zaehler++;

        }
    }

    return block;
}



/**
Diese Funktion bef�llt das Sudoku-Grid mit Werten
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
