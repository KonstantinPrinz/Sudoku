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

// Methode zum Ausgeben des Raetsels
void printsudoku(struct Puzzle);
