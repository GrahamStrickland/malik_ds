// This is a driver program to test a function that
// converts decimal numbers to binary using a stack.

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

int decToBin(int dec);
// Precondition: dec > 0;
// Postcondition: Returned binary equivalent of dec;

int main()
{
    int dec;

    cout << "Please enter a positive decimal integer: ";
    cin >> dec;

    cout << '(' << dec << ")_10 = (" << decToBin(dec) << ")_2"
         << endl;

    return 0;
}

int decToBin(int dec)
{
    assert(dec > 0);

    stack<int> binDigits;
    int bin = 0;
    
    // Store binary digits in stack.
    while (dec > 0) {
        binDigits.push(dec % 2);
        dec /= 2;
    }

    // Add binary digits to bin and multiply for weights.
    while (!binDigits.empty()) {
        bin *= 10;
        bin += binDigits.top();
        binDigits.pop();
    }

    return bin;
}
