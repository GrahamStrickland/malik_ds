// Driver program to test recursive star printing function.

#include <iostream>
#include <cassert>

using namespace std;

void printStars(int n);
// Function to print 2n rows of stars, in decreasing number
// until 1; then increasing until n.
// Precondition: n >= 1
// Postcondition: 2n rows printed to console.

int main()
{
    int n;

    cout << "Please enter the number of lines in the pattern: ";
    cin >> n;

    printStars(n);

    return 0;
}

void printStars(int n)
{
    assert(n >= 1);

    for (int stars = 0; stars < n; ++stars)
        cout << '*';
    cout << endl;

    if (n != 1) printStars(n - 1);

    for (int stars = 0; stars < n; ++stars)
        cout << '*';
    cout << endl;
}
