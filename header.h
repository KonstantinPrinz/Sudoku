//STRUCTS:
// Struct f�r das gesamte Sudoku, inklusive Einstellungen
struct Puzzle
{
    // Grid: Das Spielfeld
    int Grid[9][9];

    // Difficulty: 1 f�r Easy, 2 f�r Medium, 3 f�r Hard
    int Difficulty;

    // Gamestate: Das derzeitige Men�. 1 = Hauptmen�, 2 = Difficulty Selection, 3 = Gameplay
    int Gamestate;

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

// Methoden f�r GameMenu
struct Puzzle showGameMenu(struct Puzzle sudoku);




// INITIALIZATION:
// Methoden zum Bef�llen des Raetsels
struct Puzzle initializeGame(struct Puzzle);
struct Puzzle fillSudoku(struct Puzzle, int[81]);

// GAMEPLAY:
// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);

