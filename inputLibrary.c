#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"

// constants
#define MAX_ROW 9
#define MAX_COLUMN 9
#define MAX_NUMBER 9

// function prototypes
int ValidateRow(struct Input input);
int ValidateColumn(struct Input input);
int ValidateNumber(struct Input input);
int ValidateSquare(struct Input input);
int ValidateDigitsOnly(struct Input input);
void PrintErrorMessage();

/**
  * Diese Funktion f�hrt Eingabeaufforderungen f�r alle 3 notwendigen
  * Eingaben eines Sudoku feldes durch (Reihe, Spalte, Zahl).
  * Der �bergabeparameter dient legidlich dazu, das Sudoku auf dem
  * Bildschirm auszugeben.
  *
**/
struct ValidatedInput GetInput(int sudoku[9][9])
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

        // Eingabeaufforderung f�r die Reihe
        printf("Enter row: ");
        scanf("%c", &input.row);
        // Mehrmals "scanf()" hintereinander funktioniert nicht, ohne
        // ein "fflush(stdin)" nach jedem "scanf()".
        fflush(stdin);

        // Eingabeaufforderung f�r die Spalte
        printf("Enter column: ");
        scanf("%c", &input.column);
        fflush(stdin);

        // Eingabeaufforderung f�r die Zahl
        printf("Enter number: ");
        scanf("%c", &input.number);
        fflush(stdin);

        int digitsOnlyPassed = ValidateDigitsOnly(input);
        int numberPassed = ValidateNumber(input);
        int columnPassed = ValidateColumn(input);
        int rowPassed = ValidateRow(input);
        int squarePassed = ValidateSquare(input);
        inputPassed = digitsOnlyPassed && columnPassed &&  rowPassed && numberPassed && squarePassed;
    }
    while(inputPassed == 0);

    struct ValidatedInput validatedInput;
    validatedInput.column = input.column;
    validatedInput.row = input.row;
    validatedInput.number = input.number;

    return validatedInput;
}

/**
  * Pr�ft die Eingabe einer Reihe.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zur�ck.
  *
**/
int ValidateRow(struct Input input)
{
    // Zu integer umwandeln.
    // Siehe "external sources" - Datei f�r stackoverflow link.
    input.row = input.row - '0';
    input.column = input.column - '0';
    input.number = input.number - '0';

    if (input.row > MAX_ROW || input.row <= 0)
    {
        printf("Row: %c", input.row);
        return 0;
    }

    int rowNumbers[9] = GetNumbersOfRow(input.row); // Noch hinzuzuf�gende Funktion
    for(int i = 0; i < 9; i++)
    {
        if (rowNumbers[i] == input.number && input.number != 0)
       {
           return 0;
        }
     }

    return 1;
}

/**
  * Pr�ft die Eingabe einer Spalte.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zur�ck.
  *
**/
int ValidateColumn(struct Input input)
{
    // Zu integer umwandeln
    // Siehe "external sources" - Datei f�r stackoverflow link.
    input.row = input.row - '0';
    input.column = input.column - '0';
    input.number = input.number - '0';

    if (input.column > MAX_COLUMN || input.column <= 0)
    {
        return 0;
    }

    int columnNumbers[9] = GetNumbersOfColumn(input.column); // Noch hinzuzuf�gende Funktion
    for(int i = 0; i < 9; i++)
    {
        if (columnNumbers[i] == input.number && input.number != 0)
        {
           return 0;
        }
    }

    return 1;
}

/**
  * Pr�ft die Eingabe einer Zahl f�r das Sudoku-Feld.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zur�ck.
  *
**/
int ValidateNumber(struct Input input)
{
    // Zu integer umwandeln
    // Siehe "external sources" - Datei f�r stackoverflow link.
    input.row = input.row - '0';
    input.column = input.column - '0';
    input.number = input.number - '0';

    if (input.number > MAX_NUMBER || input.number <= 0)
    {
        return 0;
    }

    return 1;
}

/**
  * Pr�ft, ob die Eingaben f�r das aktuelle Viereck (square) valide sind.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zur�ck.
  *
**/
int ValidateSquare(struct Input input)
{
    // Zu integer umwandeln
    // Siehe "external sources" - Datei f�r stackoverflow link.
    input.row = input.row - '0';
    input.column = input.column - '0';
    input.number = input.number - '0';

    int squareNumbers[9] = GetNumbersOfSquare(input.row, input.column); // Noch hinzuzuf�gende Funktion
    for(int i = 0; i < 9; i++)
    {
        if (squareNumbers[i] == input.number && input.number != 0)
        {
            return 0;
        }
    }

    return 1;
}

/**
  * Pr�ft, ob nur Zahlen eingegeben worden sind.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zur�ck.
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
