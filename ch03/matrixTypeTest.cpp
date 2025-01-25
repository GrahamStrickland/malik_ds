// This is a driver program to test the ADT matrixType.

#include "matrixType.h"
#include <iostream>

int main() {
  using namespace std;

  // Initialize objects of type matrixType.
  matrixType A(3, 3), B(3, 3);

  // Assign values to A and B.
  for (int i = 0; i < A.getRows(); i++)
    for (int j = 0; j < A.getCols(); j++) {
      A(i, j) = i + 2 * j + 1;
      B(i, j) = (2 * i) + (-1 * j);
    }

  // Output values in A and B.
  cout << "A = " << A << "B = " << B << endl;

  // Initialize output matrix using B.
  matrixType C(B);

  // Check addition operator.
  C = A + B;
  cout << "A + B = " << C << endl;

  // Check subtraction operator.
  C = A - B;
  cout << "A - B = " << C << endl;

  // Check matrix multiplication operator.
  C = A * B;
  cout << "A * B = " << C << endl;

  // Check overloaded assignment operator.
  A = B = C;
  cout << "A = " << A << "\nB = " << B << "\nC = " << C << endl;

  return 0;
}
