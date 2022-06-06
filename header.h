void printsudoku(int array[9][9]);
struct ValidatedInput GetInput(int sudoku[9][9]);

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
