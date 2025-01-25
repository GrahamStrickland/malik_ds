#ifndef N_QUEENS_PUZZLE_H
#define N_QUEENS_PUZZLE_H

//***************************************************************
// D.S. Malik
//
// This class specifies the functions to solve the n-queens puzzle.
//***************************************************************

class nQueensPuzzle {
public:
  nQueensPuzzle(int queens = 8);
  // constructor
  // Postcondition: noOfSolutions = 0; noOfQueens = queens;
  //   queensInRow is a pointer to the array to store the
  //   n-tuple

  bool canPlaceQueen(int k, int i);
  // Function to determine whether a queen can be placed
  // in row k and column i.
  // Postcondition: returns true if a queen can be placed in
  //   row k and column i; otherwise it returns false

  void queensConfiguration(int k);
  // Function to determine all solutions to the n-queens
  // puzzle using backtracking.
  // The function is called with the value 0.
  // Postcondition: All n-tuples representing solutions of
  //   n-queens puzzle are generated and printed.

  void printConfiguration();
  // Function to output an n-tuple containing a solution
  // to the n-queens puzzle.

  int solutionsCount();
  // Function to return the total number of solutions.
  // Postcondition: The value of noOfSolutions is returned.

private:
  int noOfSolutions;
  int noOfQueens;
  int *queensInRow;
};
#endif // N_QUEENS_PUZZLE_H
