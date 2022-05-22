// This is a driver program to test the function reverseArr(),
// which reverses the ordering of elements between two indices
// in an array, in place.

#include <iostream>
#include <cassert>

void reverseArr(int intArr[], int low, int high, int length);
// Precondition: 0 <= low < high < length
// Postcondition: Order of elements in intArr between low and high
//  has been reversed.

int main()
{
    int low, high, length;

    std::cout << "Please enter the number of elements in the array: ";
    std::cin >> length;

    int intArr[length];

    std::cout << "Please enter the elements to be stored in the array: ";
    for (int i = 0; i < length; ++i)
        std::cin >> intArr[i];

    low = 0;
    high = length - 1;
    reverseArr(intArr, low, high, length);
    std::cout << "intArr reversed: ";
    for (int i = 0; i < length; ++i)
        std::cout << intArr[i] << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "Enter low (0 <= low < length): ";
    std::cin >> low;
    std::cout << "Enter high (low < high < length): ";
    std::cin >> high;
    reverseArr(intArr, low, high, length);
    std::cout << "intArr with elements between low and high reversed: ";
    for (int i = 0; i < length; ++i)
        std::cout << intArr[i] << ' ';
    std::cout << std::endl;

    return 0;
}

void reverseArr(int intArr[], int low, int high, int length)
{
    assert(0 <= low && low <= high && high < length);

    if (low == high)
        return;
    else if (high - low == 1) {
        int temp = intArr[high];
        intArr[high] = intArr[low];
        intArr[low] = temp;
    } else {
        int temp = intArr[high];
        intArr[high] = intArr[low];
        intArr[low] = temp;
        reverseArr(intArr, low + 1, high - 1, length);
    }
}
