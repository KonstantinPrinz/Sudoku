#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

struct Puzzle showDifficultyMenu(struct Puzzle sudoku)
{
    // declaraction of helper variables
    int lastInput = 0;
    int currentSelection = 1;
    // main loop: wait for key press and resolve accordingly
    do
    {
        system("cls");
        drawDifficultyMenu(currentSelection);
        lastInput = getInput();
        currentSelection = menuNavigation(lastInput, currentSelection, 4);

    }
    while(lastInput != 5 && lastInput != 6);

    // go back to main menu when ESC was pressed
    if(lastInput == 6)
    {
        sudoku.Gamestate = 1;
    }

    // set chosen difficulty and set new gamestate
    else
    {
        switch(currentSelection)
        {
            case 1:
            case 2:
            case 3:
                sudoku.Difficulty = currentSelection;
                sudoku.Gamestate = 3;
            case 4:
                sudoku.Gamestate = 1;
        };
    }
    return sudoku;
}

void drawDifficultyMenu(int selection)
{

    printf("   Difficulty  \n");
    printf("-------------------\n");
    printf("\n");

    if(selection == 1)
        printf(" -> Easy \n");
    else
        printf("    Easy \n");

    if(selection == 2)
        printf(" -> Normal \n");
    else
        printf("    Normal \n");

    if(selection == 3)
        printf(" -> Hard \n");
    else
        printf("    Hard \n");

    printf("\n");

    if(selection == 4)
        printf(" -> Back \n");
    else
        printf("    Back \n");
    printf("-------------------\n");
}
