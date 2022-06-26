//STRUCTS:
// Struct for the whole Sudoku, inclusive settings
struct Puzzle
{
    // Grid: The current Field
    int Grid[9][9];

    // The given Sudoku
    int DefaultGrid[9][9];


    // Methods for X- und Y-Koordinates of the selected field an number
    int CursorX;
    int CursorY;

    // Difficulty: 1 for Easy, 2 for Medium, 3 for Hard
    int Difficulty;

    // Gamestate: The current Menü. 1 = Mainmenu, 2 = Difficulty Selection, 3 = Gameplay, 4 = Help, 5 = Game Over
    int Gamestate;

    // is the Sudoku loaded? important for continuing a Sudoku.
    int Initialized;
};


// GENERAL METHODS:
int getInput();


// MENUS:
int menuNavigation(int input, int currentlySelected, int maxSelection);
// Dictionary, forwards you depending on the current GameState to the next menu
struct Puzzle showMenu(struct Puzzle sudoku);

// Methods for MainMenu
struct Puzzle showMainMenu(struct Puzzle sudoku);
void drawMainMenu(int selection);

// Methods for DifficultyMenu
struct Puzzle showDifficultyMenu(struct Puzzle sudoku);
void drawDifficultyMenu(int selection);

// Methods for das Hilfemenü
struct Puzzle showHelpMenu(struct Puzzle sudoku);

// Methods for GameMenu
struct Puzzle showGameMenu(struct Puzzle sudoku);
struct Puzzle resolveButtonPress(struct Puzzle sudoku);
int changeCursor(int value, int cursor);


// INITIALIZATION:
// Methods to Fill the Sudoku
struct Puzzle initializeGame(struct Puzzle);
struct Puzzle fillSudoku(struct Puzzle, int[81]);

// GAMEPLAY:
// Methods to print the Sudoku
void drawSudoku(struct Puzzle);
void printNumber(int row, int column, struct Puzzle Sudoku);
int cursorCheck(int row, int cursorRow, int column, int cursorColumn);

// Methods for completionCheck
struct Puzzle checkCompletion(struct Puzzle sudoku);
int checkRows(struct Puzzle sudoku);
int checkColumns(struct Puzzle sudoku);
int checkBlocks(struct Puzzle sudoku);
