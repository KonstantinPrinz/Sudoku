struct Puzzle
{
    int Grid[9][9];
    // Evtl. weitere Felder: z.B. f�r vorgegebene Felder
};

struct Puzzle fillSudoku(struct Puzzle, int[81]);
void printsudoku(struct Puzzle);
