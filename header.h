//STRUCTS:
// Struct für das gesamte Sudoku, inklusive Einstellungen
struct Puzzle
{
    // Grid: Das Spielfeld
    int Grid[9][9];

    // Difficulty: 1 für Easy, 2 für Medium, 3 für Hard
    int Difficulty;

    // Gamestate: Das derzeitige Menü. 1 = Hauptmenü, 2 = Difficulty Selection, 3 = Gameplay
    int Gamestate;

};


// ALLGEMEINE METHODEN:
void printErrorMessage();
int getInput();
int menuNavigation(int input, int currentlySelected, int maxSelection);

// MENUS:
// Dictionary, welches je nach Gamestate ins nächste Menü weiterleitet
struct Puzzle showMenu(struct Puzzle sudoku);

// Methoden für MainMenu
int showMainMenu(struct Puzzle sudoku);
void drawMainMenu();

// Methoden für DifficultyMenu
int showDifficultyMenu(struct Puzzle sudoku);

// Methoden für GameMenu
int showGameMenu(struct Puzzle sudoku);




// INITIALIZATION:
// Methoden zum Befüllen des Raetsels
struct Puzzle initializeGame(struct Puzzle);
struct Puzzle fillSudoku(struct Puzzle, int[81]);

// GAMEPLAY:
// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);

