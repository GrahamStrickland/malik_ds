// Driver program to test a recursive version of sequential search.

#include <iostream>

int seqSearch(int arr[], int length, int searchItem);
// Postcondition: Returned index of searchItem if arr contains
//  searchItem; otherwise returned -1.

int main() {
  int item, index, length = 10;
  int arr[] = {9, 81, 27, 48, 19, 57, 1, 45, 91, 73};

  std::cout << "Please enter an integer to search for in arrray: ";
  std::cin >> item;
  index = seqSearch(arr, length, item);
  std::cout << item
            << (index == -1 ? " not in array, returned " : " occurs at index ")
            << index << '.' << std::endl;

  return 0;
}

int seqSearch(int arr[], int length, int searchItem) {
  if (arr[length - 1] == searchItem)
    return length - 1;
  else if (length == 1)
    return -1;
  else
    return seqSearch(arr, length - 1, searchItem);
}
