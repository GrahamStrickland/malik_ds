// Driver program to test Newton's method for finding a square
// root within a given tolerance epsilon.

#include <iostream>

double absVal(double val);
// Function to return the absolute value of a double value.
// Postcondition: If val >= 0, returned val; else returned
//  -val.

double newtonSqrt(double x, double a, double epsilon);
// Function to return the square root of x, within tolerance
//  epsilon.
// Postcondition: Returned square root of x.

int main()
{
    double x, epsilon;

    std::cout << "Calculating the square root of a value within "
              << "a given tolerance, using Newton\'s method.\n"
              << "Please enter value: ";
    std::cin >> x;
    std::cout << "Please enter tolerance: ";
    std::cin >> epsilon;
    std::cout << "Square root of " << x << " = " 
              << newtonSqrt(x, x, epsilon) << std::endl;

    return 0;
}

double absVal(double val)
{
    return val >= 0.0 ? val : -val;
}

double newtonSqrt(double x, double a, double epsilon)
{
    if (a == 0.0 || a == 1.0)
        return a;
    else if (absVal(a*a - x) <= epsilon)
        return a;
    else
        return newtonSqrt(x, (a*a + x) / (2.0 * a), epsilon);
}
