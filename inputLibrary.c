#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

// constants
#define MAX_ROW 9
#define MAX_COLUMN 9
#define MAX_NUMBER 9


/**
  * Diese Funktion führt Eingabeaufforderungen für alle 3 notwendigen
  * Eingaben eines Sudoku feldes durch (Reihe, Spalte, Zahl).
  * Der Übergabeparameter dient legidlich dazu, das Sudoku auf dem
  * Bildschirm auszugeben.
  *
**/
struct ValidatedInput GetInput(struct Puzzle sudoku)
{
    struct Input input;
    input.row = 0;
    input.column = 0;
    input.number = 0;

    int inputPassed = 1;
    do
    {
        system("cls");
        printsudoku(sudoku);
        if(inputPassed == 0)
        {
            PrintErrorMessage();
        }

        // Eingabeaufforderung für die Reihe
        printf("Enter row: ");
        scanf("%c", &input.row);
        // Mehrmals "scanf()" hintereinander funktioniert nicht, ohne
        // ein "fflush(stdin)" nach jedem "scanf()".
        fflush(stdin);

        // Eingabeaufforderung für die Spalte
        printf("Enter column: ");
        scanf("%c", &input.column);
        fflush(stdin);

        // Eingabeaufforderung für die Zahl
        printf("Enter number: ");
        scanf("%c", &input.number);
        fflush(stdin);

        int digitsOnlyPassed = ValidateDigitsOnly(input);
        //int numberPassed = ValidateNumber(input);
        inputPassed = digitsOnlyPassed; //&& numberPassed;
    }
    while(inputPassed == 0);

    struct ValidatedInput validatedInput;
    validatedInput.column = input.column;
    validatedInput.row = input.row;
    validatedInput.number = input.number;

    return validatedInput;
}

/**
  * Prüft, ob nur Zahlen eingegeben worden sind.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zurück.
  *
**/
int ValidateDigitsOnly(struct Input input)
{
    if(!isdigit(input.number))
    {
        return 0;
    }

    if(!isdigit(input.column))
    {
        return 0;
    }

    if(!isdigit(input.row))
    {
        return 0;
    }

    return 1;
}

/**
  * Zeigt eine Fehlermeldung an, dass eine
  * falsche Tastatureingabe gemacht worden ist.
  *
**/
void PrintErrorMessage()
{
    printf("\n");
    printf("+-------------------------------+\n");
    printf("|        Incorrect input        |\n");
    printf("+-------------------------------+\n");
    printf("\n");
}
