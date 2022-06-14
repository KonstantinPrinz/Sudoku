

struct ValidatedInput
{
    int row;
    int column;
    int number;
};

struct Input
{
    char row;
    char column;
    char number;
};

// Struct für Sudoku-Raetsel
struct Puzzle
{
    int Grid[9][9];
    // Evtl. weitere Felder: z.B. für vorgegebene Felder
};

// Methoden zur Ausgabe von Reihen, Spalten, Kaestchen
getRow(struct Puzzle, int);
getColumn(struct Puzzle, int);
getBlock(struct Puzzle, int);

// Methode zum Befüllen des Raetsels
struct Puzzle fillSudoku(struct Puzzle, int[81]);
struct ValidatedInput GetInput(struct Puzzle);

// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);



// Methoden zum Input
struct ValidatedInput GetInput(struct Puzzle sudoku);
int ValidateNumber(struct Input input);
int ValidateDigitsOnly(struct Input input);
void PrintErrorMessage();
