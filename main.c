#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    struct Puzzle Sudoku;

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
    printsudoku(Sudoku);

    GetInput(Sudoku);
}
