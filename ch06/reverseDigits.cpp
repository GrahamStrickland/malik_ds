// Driver program to test a recursive function that takes a single 
// int parameter and outputs an int with the digits reversed.

#include <iostream>

using namespace std;

int reverseDigits(int forward);

int main()
{
    int forward;

    cout << "Please enter an integer value: ";
    cin >> forward;

    cout << reverseDigits(forward) << endl;

    return 0;
}

int reverseDigits(int forward)
{
    int digits = forward;
    int exp = 10;

    while ((digits /= 10) > 10)
        exp *= 10;

    if (forward < 10)
        return forward;
    else
        return (forward / exp) + (10 * reverseDigits(forward % exp));
}
