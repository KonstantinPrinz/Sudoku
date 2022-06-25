#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "header.h"

void printMainMenu(struct Puzzle sptr)
{
    int again = 0;
    int error = 0;
    do
    {
        system("cls");

        again = 0;
        int selection = 0;
        printf("   Main menu   \n");
        printf("-------------------\n");
        printf("\n");
        printf("(1) New game\n");
        printf("(2) Continue game\n");
        printf("(3) Load game\n");
        printf("\n");
        printf("(4) Exit\n");
        printf("-------------------\n");

        if(error)
        {
            printErrorMessage();
        }
        error = 0;

        printf("Input: ");
        scanf("%i", &selection);
        fflush(stdin);

        switch(selection)
        {
        case 1:
            printDifficultyMenu(sptr);
            break;
        case 2:
            ;
            break;
        case 3:
            break;
        case 4:
            exit(0);
            break;
        default:
            again = 1;
            error = 1;
        }
    }
    while(again);
}

void printDifficultyMenu(struct Puzzle sptr)
{
    int again = 0;
    int error = 0;
    do
    {
        system("cls");
        if(error)
        {
            printErrorMessage();
        }
        error = 0;

        again = 0;
        int selection = 0;
        printf("   Difficulty  \n");
        printf("-------------------\n");
        printf("\n");
        printf("(1) Easy \n");
        printf("(2) Normal \n");
        printf("(3) Hard \n");
        printf("\n");
        printf("(4) Back \n");
        printf("-------------------\n");
        printf("Input: ");

        if(error)
        {
            printErrorMessage();
        }
        error = 0;

        scanf("%i", &selection);
        fflush(stdin);

        switch(selection)
        {
        case 1:
            printGame(sptr);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printMainMenu(sptr);
            break;
        default:
            again = 1;
            error = 1;
        }
    }
    while(again);
}

void printGame(struct Puzzle sptr)
{
    int again = 0;
    int error = 0;
    do
    {
        system("cls");

        again = 0;
        int selection = 0;
        printf("   Game   \n");
        printf("-------------------\n");
        printf("\n");
        printsudoku(sptr);
        printf("\n");
        printf("(1) Set number\n");
        printf("(2) Save game\n");
        printf("(3) Abort \n");
        printf("-------------------\n");

        if(error)
        {
            printErrorMessage();
        }
        error = 0;

        printf("Input: ");
        scanf("%i", &selection);
        fflush(stdin);

        switch(selection)
        {
        case 1:
            printEnterNumber(sptr);
            break;
        case 2:
            ;
            break;
        case 3:
            printConfirmAbort(sptr);
            break;
        default:
            again = 1;
            error = 1;
        }
    }
    while(again);
}

void printConfirmAbort(struct Puzzle sptr)
{
    int again = 0;
    int error = 0;
    do
    {
        system("cls");

        again = 0;
        int selection = 0;
        printf("   Confirmation   \n");
        printf("-------------------\n");
        printf("Are you sure you want \n");
        printf("to abort the current game?\n");
        printf("\n");
        printf("(1) yes \n");
        printf("(2) no \n");
        printf("-------------------\n");

        if(error)
        {
            printErrorMessage();
        }
        error = 0;

        printf("Input: ");
        scanf("%i", &selection);
        fflush(stdin);

        switch(selection)
        {
        case 1:
            printMainMenu(sptr);
            break;
        case 2:
            printGame(sptr);
            break;
        default:
            again = 1;
            error = 1;
        }
    }
    while(again);
}

void printEnterNumber(struct Puzzle sptr)
{
    //struct Puzzle *refSpiel = sptr;
    int again = 0;
    int error = 0;

    system("cls");

    struct Input input;
    input.column = 0;
    input.row = 0;
    input.number = 0;

    printf("   Game   \n");
    printf("-------------------\n");
    printf("\n");
    printsudoku(sptr);
    printf("\n");
    //struct ValidatedInput* validInput = GetInput(sptr);

    int row = 0;
    int column = 0;
    int number = 0;

    // Eingabeaufforderung für die Reihe
    printf("Enter row: ");
    scanf("%i", &row);
    // Mehrmals "scanf()" hintereinander funktioniert nicht, ohne
    // ein "fflush(stdin)" nach jedem "scanf()".
    fflush(stdin);

    // Eingabeaufforderung für die Spalte
    printf("Enter column: ");
    scanf("%i", &column);
    fflush(stdin);

    // Eingabeaufforderung für die Zahl
    printf("Enter number: ");
    scanf("%i", &number);
    fflush(stdin);


    printf("-------------------\n");

    sptr.Grid[row - 1][column- 1] = number;
    printGame(sptr);
}


void printErrorMessage()
{
    printf("\n");
    printf("+-----------------+\n");
    printf("| Incorrect input |\n");
    printf("+-----------------+\n");
    printf("\n");
}
