// Driver program to test recursive star printing function.

#include <cassert>
#include <iostream>

using namespace std;

void printStars(int n, int m);
// Function to print 2n rows of stars, increasing in number
// until n; then decreasing until 1.
// Precondition: n >= 1; m = 1;
// Postcondition: 2n rows printed to console.

int main() {
  int n;

  cout << "Please enter the number of lines in the pattern: ";
  cin >> n;

  printStars(n, 1);

  return 0;
}

void printStars(int n, int m) {
  assert(n >= 0);

  if (m < n) {
    for (int spaces = 0; spaces < n - m; ++spaces)
      cout << ' ';
    for (int stars = 0; stars < m; ++stars)
      cout << "* ";
    cout << endl;
    printStars(n, m + 1);
  } else if (n >= 1) {
    for (int spaces = 0; spaces < m - n; ++spaces)
      cout << ' ';
    for (int stars = 0; stars < n; ++stars)
      cout << "* ";
    cout << endl;
    printStars(n - 1, m);
  }
}
