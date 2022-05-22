// Driver program to test the function gcd(), which returns
// the greatest common divisor of two integers.

#include <iostream>

int gcd(int x, int y);
// Postcondition: Returned greatest common divisor of x and y

int main()
{
    int x, y;

    std::cout << "Find the common divisor of two positive integers" 
              << std::endl << "Please enter the first integer: ";
    std::cin >> x;
    std::cout << "Please enter the second integer: ";
    std::cin >> y;
    std::cout << "gcd(" << x << ", " << y << ") = " << gcd(x, y)
              << std::endl;

    return 0;
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
