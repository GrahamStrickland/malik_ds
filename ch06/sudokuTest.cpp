// This is a driver program to test the sudoku ADT.

#include <iostream>
#include "sudoku.h"

int main()
{
    sudoku puzzle;

    puzzle.initializeSudokuGrid();
    
    if (puzzle.solveSudoku())
    {
        std::cout << "The sudoku problem has the following solution:";
        puzzle.printSudokuGrid();
    }
    else
        std::cout << "The sudoku problem has no solution.";
    std::cout << std::endl;

    return 0;
}
