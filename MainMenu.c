#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

// Logic for the Main Menu
// Sets the Gamestate in menus.c depending on the selected option
struct Puzzle showMainMenu(struct Puzzle sudoku)
{
    // declaring of help variables
    int lastInput = 0;
    int currentSelection = 1;

    // menu loop: wait for button press and resolve accordingly
    do
    {
        system("cls");
        drawMainMenu(currentSelection);
        lastInput = getInput();
        currentSelection = menuNavigation(lastInput, currentSelection, 3);

    }
    while(lastInput != 5);

    // resolve: When ENTER is pressed, set gamestate to advance to the next menu
    switch(currentSelection)
    {
        case 1:
            sudoku.Gamestate = 2;
            return sudoku;
        case 2:
            sudoku.Gamestate = 4;
            return sudoku;
        case 3:
            sudoku.Gamestate = 0;
            return sudoku;
    };
}

// Draws the MainMenu and shows an arrow next to the currently selected option
void drawMainMenu(int selection)
{
    printf("   Main menu   \n");
    printf("-------------------\n");
    printf("\n");

    if(selection == 1)
        printf(" -> New game\n");
    else
        printf("    New game\n");

    if(selection == 2)
        printf(" -> Load game\n");
    else
        printf("    Load game\n");

    printf("\n");

    if(selection == 3)
        printf(" -> Exit\n");
    else
        printf("    Exit\n");

    printf("-------------------\n");
    return;
}
