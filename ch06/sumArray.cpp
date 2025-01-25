// Driver program to test a recursive function to sum
// all elements in an int array.

#include <iostream>

using namespace std;

int sumArr(int arr[], int size);
// Precondition: size = arr.size();
// Postcondition: Returned sum of all elements in arr.

int main() {
  int size;

  cout << "Please enter the size of the array to sum: ";
  cin >> size;

  int arr[size];

  cout << "Please enter all elements in array separated by spaces: ";
  for (int i = 0; i < size; ++i)
    cin >> arr[i];

  cout << "Sum of all elements in array = " << sumArr(arr, size) << endl;

  return 0;
}

int sumArr(int arr[], int size) {
  if (size == 1)
    return arr[size - 1];
  else
    return sumArr(arr, size - 1) + arr[size - 1];
}
