#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "header.h"

// Logic for the Main Menu
// Sets the Gamestate in menus.c depending on the selected option
int showMainMenu(struct Puzzle sudoku)
{
    int lastInput = 0;
    int currentSelection = 1;
    do
    {
        system("cls");
        drawMainMenu(currentSelection);
        lastInput = getInput();
        currentSelection = menuNavigation(lastInput, currentSelection, 3);

    }
    while(lastInput != 5);

    switch(currentSelection)
    {
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 0;
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
