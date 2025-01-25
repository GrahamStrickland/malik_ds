#include <iostream>

int multiply(int m, int n);

int main() {
  using namespace std;

  int m = 3, n = 4;

  cout << m << " * " << n << " = " << multiply(m, n) << endl << endl;

  return 0;
}

int multiply(int m, int n) {
  if (n == 1)
    return m;
  else
    return multiply(m, n - 1) + m;
}
