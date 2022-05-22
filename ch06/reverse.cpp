#include <iostream>

void reverse(int intArray[], int low, int high);


int main()
{
    using namespace std;

    int length = 10, low = 2, high = 7;
    int intArray[] = {1, 4, 57, 18, 37, 2,
                      65, 48, 98, 17, 15};

    cout << "intArray[] = ";
    for (int i = 0; i < length; i++)
        cout << intArray[i] << " ";
    cout << endl << endl;

    reverse(intArray, low, high);

    cout << "After reverse(intArray[], " << low << ", " << high << "),"
         << "intArray[] = ";
    for (int i = 0; i < length; i++)
        cout << intArray[i] << " ";
    cout << endl << endl;

    return 0;
}

void reverse(int intArray[], int low, int high)
{
    if (low == high || high - low == 1)
        return;
    else {
        int temp = intArray[high];
        intArray[high] = intArray[low];
        intArray[low] = temp;
        reverse(intArray, low + 1, high - 1);
    }
}
