//STRUCTS:

// Struct für die Einstellungen
struct Settings
{
    int Difficulty;
};

// Struct für das gesamte Sudoku, inklusive Einstellungen
struct Puzzle
{
    int Grid[9][9];
    struct Settings;
    // Evtl. weitere Felder: z.B. für vorgegebene Felder
};


// ALLGEMEINE METHODEN:
void printErrorMessage();
int getInput();

// MENUS:
// Ausgabe der Menüs
struct Puzzle initializeMenu(struct Puzzle sudoku);





// INITIALIZATION:
// Methoden zum Befüllen des Raetsels
struct Puzzle initializeGame(struct Puzzle);
struct Puzzle fillSudoku(struct Puzzle, int[81]);

// GAMEPLAY:
// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);

