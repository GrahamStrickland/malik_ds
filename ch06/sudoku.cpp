//***************************************************************
// D.S. Malik
//
// This class specifies the functions to solve a sudoku problem.
//***************************************************************

#include "sudoku.h"
#include <iostream>

sudoku::sudoku() {
  for (int row = 0; row < 9; ++row)
    for (int col = 0; col < 9; ++col)
      grid[row][col] = 0;
}

sudoku::sudoku(int g[][9]) { initializeSudokuGrid(g); }

void sudoku::initializeSudokuGrid() {
  std::cout << "Please enter the numbers in the sudoku grid, "
            << "row by row, separated by spaces (0 for empty):";
  for (int row = 0; row < 9; ++row)
    for (int col = 0; col < 9; ++col)
      std::cin >> grid[row][col];
}

void sudoku::initializeSudokuGrid(int g[][9]) {
  for (int row = 0; row < 9; ++row)
    for (int col = 0; col < 9; ++col)
      grid[row][col] = g[row][col];
}

void sudoku::printSudokuGrid() {
  for (int row = 0; row < 9; ++row) {
    for (int col = 0; col < 9; ++col)
      std::cout << grid[row][col] << ' ';
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool sudoku::solveSudoku() {
  int row, col;

  if (findEmptyGridSlot(row, col)) {
    for (int num = 1; num <= 9; num++) {
      if (canPlaceNum(row, col, num)) {
        grid[row][col] = num;
        if (solveSudoku()) // recursive call
          return true;
        grid[row][col] = 0;
      }
    }
    return false; // backtrack
  } else
    return true; // there are no empty slots
}

bool sudoku::findEmptyGridSlot(int &row, int &col) {
  for (row = 0; row < 9; ++row)
    for (col = 0; col < 9; ++col)
      if (grid[row][col] == 0)
        return true;
  return false;
}

bool sudoku::canPlaceNum(int row, int col, int num) {
  return !numAlreadyInRow(row, num) && !numAlreadyInCol(col, num) &&
         !numAlreadyInBox(row / 3, col / 3, num);
}

bool sudoku::numAlreadyInRow(int row, int num) {
  for (int col = 0; col < 9; ++col)
    if (grid[row][col] == num)
      return false;
  return true;
}

bool sudoku::numAlreadyInCol(int col, int num) {
  for (int row = 0; row < 9; ++row)
    if (grid[row][col] == num)
      return false;
  return true;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num) {
  for (int row = smallGridRow * 3; row < smallGridRow * 3 + 2; ++row)
    for (int col = smallGridCol * 3; col < smallGridCol * 3 + 2; ++col)
      if (grid[row][col] == num)
        return false;
  return true;
}
