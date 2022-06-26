//STRUCTS:
// Struct für das gesamte Sudoku, inklusive Einstellungen
struct Puzzle
{
    // Grid: Das derzeitige Spielfeld
    int Grid[9][9];

    // Die vorgegebenen und nicht veränderbaren Ziffern
    int DefaultGrid[9][9];


    // Methoden für X- und Y-Koordinate des derzeit ausgewählten Felds und die derzeit ausgewählte Zahl
    int CursorX;
    int CursorY;

    // Difficulty: 1 für Easy, 2 für Medium, 3 für Hard
    int Difficulty;

    // Gamestate: Das derzeitige Menü. 1 = Hauptmenü, 2 = Difficulty Selection, 3 = Gameplay, 4 = Hilfeseite
    int Gamestate;

    // Wurde ein Sudoku geladen? Wichtig für das Fortsetzen eines Puzzles.
    int Initialized;
};


// ALLGEMEINE METHODEN:
void printErrorMessage();
int getInput();
int menuNavigation(int input, int currentlySelected, int maxSelection);

// MENUS:
// Dictionary, welches je nach Gamestate ins nächste Menü weiterleitet
struct Puzzle showMenu(struct Puzzle sudoku);

// Methoden für MainMenu
struct Puzzle showMainMenu(struct Puzzle sudoku);
void drawMainMenu(int selection);

// Methoden für DifficultyMenu
struct Puzzle showDifficultyMenu(struct Puzzle sudoku);
void drawDifficultyMenu(int selection);

// Methoden für das Hilfemenü
struct Puzzle showHelpMenu(struct Puzzle sudoku);

// Methoden für GameMenu
struct Puzzle showGameMenu(struct Puzzle sudoku);
struct Puzzle resolveButtonPress(struct Puzzle sudoku);
int changeCursor(int value, int cursor);


// INITIALIZATION:
// Methoden zum Befüllen des Raetsels
struct Puzzle initializeGame(struct Puzzle);
struct Puzzle fillSudoku(struct Puzzle, int[81]);

// GAMEPLAY:
// Methode zum Ausgeben des Raetsels
void drawSudoku(struct Puzzle);
void printNumber(int row, int column, struct Puzzle Sudoku);
int cursorCheck(int row, int cursorRow, int column, int cursorColumn);

// Methoden zum completionCheck
struct Puzzle checkCompletion(struct Puzzle sudoku);
int checkRows(struct Puzzle sudoku);
int checkColumns(struct Puzzle sudoku);
int checkBlocks(struct Puzzle sudoku);
