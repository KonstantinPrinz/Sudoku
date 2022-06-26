#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    /** Funktionsweise:
     - Ein struct Puzzle wird generiert. Der GameState wird auf "1" gesetzt (Hauptmen�).
     - "showMenu" liest den GameState aus und geht in die dazugeh�rigen Men�s.
     - Das Struct wird jeweils in die Men�s und Methoden mitgegeben.
     - Sobald der Gamestate sich �ndert gibt das dazugeh�rige Men� das Struct zur�ck an "showMenu", welches es zur�ck gibt in die while-Schleife in Main
     - Dadurch wird das n�chste Men� aufgerufen

     - Steuerung erfolgt mit den Pfeiltasten, Enter, ESC, Entf und den Zahlentasten
     - Wenn ein Sudoku einmal geladen ist kann man zwischendurch zur�ck ins Hauptmen� und auf "Continue" klicken, um weiter zu spielen
    **/


    struct Puzzle sudoku;
    sudoku.Gamestate = 1;
    sudoku.Initialized = 0;

    // Menu
    while(sudoku.Gamestate > 0)
    {
        sudoku = showMenu(sudoku);
    }
    return 0;
}
