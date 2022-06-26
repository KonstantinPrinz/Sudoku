#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    /** Funktionsweise:
     - Ein struct Puzzle wird generiert. Der GameState wird auf "1" gesetzt (Hauptmenü).
     - "showMenu" liest den GameState aus und geht in die dazugehörigen Menüs.
     - Das Struct wird jeweils in die Menüs und Methoden mitgegeben.
     - Sobald der Gamestate sich ändert gibt das dazugehörige Menü das Struct zurück an "showMenu", welches es zurück gibt in die while-Schleife in Main
     - Dadurch wird das nächste Menü aufgerufen

     - Steuerung erfolgt mit den Pfeiltasten, Enter, ESC, Entf und den Zahlentasten
     - Wenn ein Sudoku einmal geladen ist kann man zwischendurch zurück ins Hauptmenü und auf "Continue" klicken, um weiter zu spielen
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
