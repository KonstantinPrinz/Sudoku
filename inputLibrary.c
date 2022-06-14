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
    struct ValidatedInput input;
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
        scanf("%i", &input.row);
        // Mehrmals "scanf()" hintereinander funktioniert nicht, ohne
        // ein "fflush(stdin)" nach jedem "scanf()".
        fflush(stdin);

        // Eingabeaufforderung für die Spalte
        printf("Enter column: ");
        scanf("%i", &input.column);
        fflush(stdin);

        // Eingabeaufforderung für die Zahl
        printf("Enter number: ");
        scanf("%i", &input.number);
        fflush(stdin);

        int digitsOnlyPassed = ValidateDigitsOnly(input);
        int numberPassed = ValidateNumber(input);
        int rowPassed = ValidateRow(input, sudoku);
        int columnPassed = ValidateColumn(input, sudoku);
        int squarePassed = ValidateSquare(input, sudoku);
        inputPassed = digitsOnlyPassed && columnPassed &&  rowPassed && numberPassed && squarePassed;
    }
    while(inputPassed == 0);

    return input;
}

/**
  * Prüft die Eingabe einer Reihe.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zurück.
  *
**/
int ValidateRow(struct ValidatedInput input, struct Puzzle sudoku)
{
    if (input.row > MAX_ROW || input.row <= 0)
    {
        printf("Row: %c", input.row);
        return 0;
    }
    int rowNumbers[9];
    for(int i = 0; i < 9; i++)
    {
        rowNumbers[i] = getRow(sudoku, input.row)[i]; // Noch hinzuzufügende Funktion
    }
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
  * Prüft die Eingabe einer Spalte.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zurück.
  *
**/
int ValidateColumn(struct ValidatedInput input, struct Puzzle sudoku)
{
    if (input.column > MAX_COLUMN || input.column <= 0)
    {
        return 0;
    }
    int columnNumbers[9];
    for(int i = 0; i < 9; i++)
    {
         columnNumbers[i] = getColumn(sudoku, input.column)[i]; // Noch hinzuzufügende Funktion
    }
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
  * Prüft die Eingabe einer Zahl für das Sudoku-Feld.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zurück.
  *
**/
int ValidateNumber(struct ValidatedInput input)
{
    if (input.number > MAX_NUMBER || input.number <= 0)
    {
        return 0;
    }

    return 1;
}

/**
  * Prüft, ob die Eingaben für das aktuelle Viereck (square) valide sind.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zurück.
  *
**/
int ValidateSquare(struct ValidatedInput input, struct Puzzle sudoku)
{
    int squareNumbers[9];
    for(int i = 0; i < 9; i++)
    {
        squareNumbers[i] = getBlock(sudoku, getSquareNumber(input.row, input.column))[i]; // Noch hinzuzufügende Funktion
    }

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
  * Prüft, ob nur Zahlen eingegeben worden sind.
  * Gibt bei fehlerhafter Eingabe 0, bei richtiger eine 1 zurück.
  *
**/
int ValidateDigitsOnly(struct ValidatedInput input)
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

int getSquareNumber(int row, int column)
{
    if(column <= 3)
    {
        if(row <= 3)
        {
            return 1;
        }
        else if(row <= 6)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }else if(column <= 6)
    {
        if(row <= 3)
        {
            return 4;
        }
        else if(row <= 6)
        {
            return 5;
        }
        else
        {
            return 6;
        }
    }else
    {
        if(row <= 7)
        {
            return 1;
        }
        else if(row <= 6)
        {
            return 8;
        }
        else
        {
            return 9;
        }
    }
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
