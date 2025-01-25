// Program to compare the number of comparisons and item movements
// in insertion sort versus Shellsort using array-based implementations.

#include "arrayListTypeComparisons.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream> // For cout()

int main() {
  arrayListType<int> listThousand(1000), listTenThousand(10000);
  int comparisons(0), assignments(0);

  // Seed random number generator.
  srand(time(0));

  // Generate random numbers for lists.
  for (int i = 0; i < 1000; i++)
    listThousand.insert(rand());

  for (int i = 0; i < 10000; i++)
    listTenThousand.insert(rand());

  // Test on list of 1000 items.
  listThousand.insertionSort(comparisons, assignments);
  std::cout << "listThousand.insertionSort(): comparisons = " << comparisons
            << ", assignments = " << assignments << '\n';
  comparisons = 0;
  assignments = 0;
  listThousand.shellSort(comparisons, assignments);
  std::cout << "listThousand.shellSort(): comparisons = " << comparisons
            << ", assignments = " << assignments << '\n';
  comparisons = 0;
  assignments = 0;

  // Test Shellsort.
  listTenThousand.shellSort(comparisons, assignments);
  std::cout << "listTenThousand.insertionSort(): comparisons = " << comparisons
            << ", assignments = " << assignments << '\n';
  comparisons = 0;
  assignments = 0;
  listTenThousand.insertionSort(comparisons, assignments);
  std::cout << "listTenThousand.shellSort(): comparisons = " << comparisons
            << ", assignments = " << assignments << '\n';

  return 0;
}