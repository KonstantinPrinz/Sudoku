//STRUCTS:

// Struct f�r die Einstellungen
struct Settings
{
    int Difficulty;
};

// Struct f�r das gesamte Sudoku, inklusive Einstellungen
struct Puzzle
{
    int Grid[9][9];
    struct Settings;
    // Evtl. weitere Felder: z.B. f�r vorgegebene Felder
};


// ALLGEMEINE METHODEN:
void printErrorMessage();
int getInput();

// MENUS:
// Ausgabe der Men�s
struct Puzzle initializeMenu(struct Puzzle sudoku);





// INITIALIZATION:
// Methoden zum Bef�llen des Raetsels
struct Puzzle initializeGame(struct Puzzle);
struct Puzzle fillSudoku(struct Puzzle, int[81]);

// GAMEPLAY:
// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);

