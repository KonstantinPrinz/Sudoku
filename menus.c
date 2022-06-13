#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

void printMainMenu()
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
            printDifficultyMenu();
            break;
        case 2:;
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
    }while(again);
}

void printDifficultyMenu()
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printMainMenu();
            break;
        default:
            again = 1;
            error = 1;
        }
    }while(again);
}

void printErrorMessage()
{
    printf("\n");
    printf("+-----------------+\n");
    printf("| Incorrect input |\n");
    printf("+-----------------+\n");
    printf("\n");
}
