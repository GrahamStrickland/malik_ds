// Driver program to test the ADT nQueensPuzzle with various values for n,
// representing the length of one side of a chessboard.

#include "nQueensPuzzle.h"
#include <iostream>

int main() {
  int n;

  std::cout << "Please enter the length (n) of the side of a chessboard "
            << "to test the n Queens Puzzle: ";
  std::cin >> n;

  nQueensPuzzle puzzle(n);

  puzzle.queensConfiguration(0);

  std::cout << "Number of solutions: " << puzzle.solutionsCount() << std::endl;

  return 0;
}
