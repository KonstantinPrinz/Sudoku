#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Redirects to the correct menu depending on the GameState of the sudoku
struct Puzzle showMenu(struct Puzzle sudoku)
{
    switch(sudoku.Gamestate)
    {
        case 1:
            sudoku = showMainMenu(sudoku);
            return sudoku;
        case 2:
            sudoku = showDifficultyMenu(sudoku);
            return sudoku;
        case 3:
            sudoku = showGameMenu(sudoku);
            return sudoku;
        case 4:
            sudoku = showHelpMenu(sudoku);
            return sudoku;
        default:
            sudoku.Gamestate = 0;
            return sudoku;
    };

};

// Responsible for mapping Up / Down in Menus
// needs the input (from getInput() ), the current selection and the highest selection in the current menu
int menuNavigation(int input, int currentlySelected, int maxSelection)
 {
     if (input == 1)
         {
             if (currentlySelected == 1)
                return maxSelection;
             else
                return (currentlySelected-1);
         }
     if (input == 2)
        {
            if (currentlySelected == maxSelection)
                return 1;
            else
                return (currentlySelected+1);
        }
    return currentlySelected;
 }
