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
int* getRow(struct Puzzle, int);
int* getColumn(struct Puzzle, int);
int* getBlock(struct Puzzle, int);
int getSquareNumber(int, int);

// Methode zum Befüllen des Raetsels
struct Puzzle fillSudoku(struct Puzzle, int[81]);
struct ValidatedInput GetInput(struct Puzzle);

// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);

//Validierungsmethoden
int ValidateRow(struct ValidatedInput input, struct Puzzle);
int ValidateColumn(struct ValidatedInput input, struct Puzzle);
int ValidateSquare(struct ValidatedInput input, struct Puzzle);
int ValidateNumber(struct ValidatedInput input);
int ValidateDigitsOnly(struct ValidatedInput input);
void PrintErrorMessage();

