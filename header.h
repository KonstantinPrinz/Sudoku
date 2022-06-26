//STRUCTS:
// Struct f�r das gesamte Sudoku, inklusive Einstellungen
struct Puzzle
{
    // Grid: Das derzeitige Spielfeld
    int Grid[9][9];

    // Die vorgegebenen und nicht ver�nderbaren Ziffern
    int DefaultGrid[9][9];


    // Methoden f�r X- und Y-Koordinate des derzeit ausgew�hlten Felds und die derzeit ausgew�hlte Zahl
    int CursorX;
    int CursorY;

    // Difficulty: 1 f�r Easy, 2 f�r Medium, 3 f�r Hard
    int Difficulty;

    // Gamestate: Das derzeitige Men�. 1 = Hauptmen�, 2 = Difficulty Selection, 3 = Gameplay, 4 = Hilfeseite
    int Gamestate;

    // Wurde ein Sudoku geladen? Wichtig f�r das Fortsetzen eines Puzzles.
    int Initialized;
};


// ALLGEMEINE METHODEN:
void printErrorMessage();
int getInput();
int menuNavigation(int input, int currentlySelected, int maxSelection);

// MENUS:
// Dictionary, welches je nach Gamestate ins n�chste Men� weiterleitet
struct Puzzle showMenu(struct Puzzle sudoku);

// Methoden f�r MainMenu
struct Puzzle showMainMenu(struct Puzzle sudoku);
void drawMainMenu(int selection);

// Methoden f�r DifficultyMenu
struct Puzzle showDifficultyMenu(struct Puzzle sudoku);
void drawDifficultyMenu(int selection);

// Methoden f�r das Hilfemen�
struct Puzzle showHelpMenu(struct Puzzle sudoku);

// Methoden f�r GameMenu
struct Puzzle showGameMenu(struct Puzzle sudoku);
struct Puzzle resolveButtonPress(struct Puzzle sudoku);
int changeCursor(int value, int cursor);


// INITIALIZATION:
// Methoden zum Bef�llen des Raetsels
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
