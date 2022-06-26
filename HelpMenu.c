#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

struct Puzzle showHelpMenu(struct Puzzle sudoku)
{
        system("cls");
        printf("       HELP   \n");
        printf("-------------------\n");
        printf("  - Control the game with the arrow keys\n");
        printf("  - Enter a number on an empty field to fill it\n");
        printf("  - Press DEL to delete a number from a field\n");
        printf("  - ESC exits the current game\n");
        printf("-------------------\n");
        printf("    press ANY KEY to go back!");
        getInput();

        sudoku.Gamestate = 1;
        return sudoku;
};
