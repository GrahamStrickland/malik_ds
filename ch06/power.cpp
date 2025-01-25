// Driver program to test the function power() that recursively
// calculates a base x to the power of an exponent y.

#include <cassert>
#include <iostream>

double power(int x, int y);
// Postcondition: Returned x to the power y.

int main() {
  int x, y;

  std::cout << "Calculate x to the power y" << std::endl
            << "Please enter a base integer: ";
  std::cin >> x;
  std::cout << "Please enter an exponent integer: ";
  std::cin >> y;
  std::cout << x << '^' << y << " = " << power(x, y) << std::endl;

  return 0;
}

double power(int x, int y) {
  assert(x != 0);

  if (y >= 0) {
    if (y == 0)
      return 1;
    else if (y == 1)
      return x;
    else
      return x * power(x, y - 1);
  } else
    return 1.0 / power(x, -y);
}
