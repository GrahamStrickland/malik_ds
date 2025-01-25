#ifndef ARRAY_LIST_TYPE_H
#define ARRAY_LIST_TYPE_H

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************

#include <cassert>
#include <iostream>

template <class elemType> class arrayListType {
public:
  const arrayListType<elemType> &operator=(const arrayListType<elemType> &);
  // Overloads the assignment operator.

  bool isEmpty() const;
  // Function to determine whether the list is empty.
  // Postcondition: Returns true if the list is empty;
  //   otherwise, returns false.

  bool isFull() const;
  // Function to determine whether the list is full.
  // Postcondition: Returns true if the list is full;
  //   otherwise, returns false.

  int listSize() const;
  // Function to determine the number of elements in the list
  // Postcondition: Returns the value of length.

  int maxListSize() const;
  // Function to determine the size of the list.
  // Postcondition: Returns the value of maxSize.

  void print() const;
  // Function to output the elements of the list.
  // Postcondition: Elements of the list are output on the
  //   standard output device.

  bool isItemEqualAt(int location, const elemType &item) const;
  // Function to determine whether the item is the same
  // as the item in the list at the position specified by location.
  // Postcondition: Returns true if list[location]
  //   is the same as the item; otherwise,
  //   returns false.

  void insertAt(int location, const elemType &insertItem);
  // Function to insert an item in the list at the
  // position specified by location. The item to be inserted
  // is passed as a parameter to the function.
  // Postcondition: Starting at location, the elements of the
  //   list are shifted down, list[location] = insertItem;,
  //   and length++;. If the list is full or location is
  //   out of range, an appropriate message is displayed.

  void insertEnd(const elemType &insertItem);
  // Function to insert an item at the end of the list.
  // The parameter insertItem specifies the item to be inserted.
  // Postcondition: list[length] = insertItem; and length++;
  //   If the list is full, an appropriate message is
  //   displayed.

  void removeAt(int location);
  // Function to remove the item from the list at the
  // position specified by location.
  // Postcondition: The list element at lis[location] is removed
  //   and length is decremented by 1. If location is out of
  //   range, an appropriate message is displayed.

  void retrieveAt(int location, elemType &retItem) const;
  // Function to retrieve the element from the list at the
  // position specified by location.
  // Postcondition: retItem = list[location]
  //   If location is out of range, an appropriate message is
  //   displayed.

  void replaceAt(int location, const elemType &repItem);
  // Function to replace the lements in the list at the
  // position specified by location. The item to be replaced
  // is specified by the parameter repItem.
  // Postcondition: list[location] = repItem
  //   If location is out of range, an appropriate message is
  //   displayed.

  void clearList();
  // Function to remove all the elements from the list.
  // After this operation, the size of the list is zero.
  // Postcondition: length = 0;

  int seqSearch(const elemType &item) const;
  // Function to search the list for a given item.
  // Postcondition: If the item is found, returns the location
  //   in the array where the item is found; otherwise,
  //   returns -1.

  void insert(const elemType &insertItem);
  // Function to insert the item specified by the parameter
  // insertItem at the end of the list. However, first the
  // list is searched to see whether the item to be inserted
  // is already in the list.
  // Postcondition: list[length] = insertItem and length++
  //   If the item is already in the list or the list
  //   is full, an appropriate message is displayed.

  void remove(const elemType &removeItem);
  // Function to remove an item from the list. The parameter
  // removeItem specifies the item to be removed.
  // Postcondition: If removeItem is found in the list,
  //   it is removed from the list and length is
  //   decremented by one.

  void selectionSort();
  // Function to sort elements in the list, one at a time,
  // moving them to the correct position in ascending order.
  // Postcondition: list is sorted in ascending order.

  void insertionSort();
  // Function to sort elements in the list, increasing the
  // sorted subarray from the first index to the entire array.
  // Postcondition: list is sorted in ascending order.

  void shellSort();
  // Function to sort elements in the list, increasing the
  // sorted subarray using an increment sequence.
  // Postcondition: list is sorted in ascending order.

  void quickSort();
  // Function to sort elements in the list, using a recursive
  // divide and conquer approach with a pivot. Calls the function
  // recQuickSort of the original list.
  // Postcondition: list is sorted in ascending order.

  void heapSort();
  // Function to sort elements in the list by first building
  // a heap and then swapping the first and last elements of
  // sequentially smaller sublists and restoring the heap.
  // Postcondition: list is sorted in ascending order.

  arrayListType(int size = 100);
  // constructor
  // Creates an array of the size specified by the
  // parameter size. The default array size is 100.
  // Postcondition: The list points to the array, length = 0,
  //   and maxSize = size

  arrayListType(const arrayListType<elemType> &otherList);
  // copy constructor

  ~arrayListType();
  // destructor
  // Deallocates the memory occupied by the array.

protected:
  elemType *list; // array to hold the list elements
  int length;     // to store the length of the list
  int maxSize;    // to store the maximum size of the list

  int minLocation(int first, int last);
  // Function to return the index of the smallest element
  // in list[first]...list[last].
  // Postcondition: Returned index of smallest element.

  void intervalInsertionSort(int begin, int inc);
  // Function to sort a sublist beginning at begin using an
  // increment inc.
  // Postcondition: Elements in sublist starting at begin
  //   sorted at a distance of inc.

  int partition(int first, int last);
  // Function to partition the list into two with a pivot.
  // for the quicksort() function.
  // Postcondition: Returned smallIndex (initial position
  //   of pivot).

  void recQuickSort(int first, int last);
  // Function to implement the recursive version of quickSort()
  // given the starting and ending indices of the sublist.

  void swap(int first, int second);
  // Function to swap the elements at index first and second.

  void heapify(int low, int high);
  // Function to restore the heap in a subtree by making one
  // item assignment each time through the loop.

  void buildHeap();
  // Function to convert the list into a heap using heapify().
};

template <class elemType>
const arrayListType<elemType> &
arrayListType<elemType>::operator=(const arrayListType<elemType> &otherList) {
  if (this != &otherList) // avoid self-assignment
  {
    delete[] list;
    maxSize = otherList.maxSize;
    length = otherList.length;

    list = new elemType[maxSize]; // create the array
    assert(list != NULL);         // if unable to allocate memory
                          // space, terminate the program
    for (int i = 0; i < length; i++)
      list[i] = otherList.list[i];
  }

  return *this;
}

template <class elemType> bool arrayListType<elemType>::isEmpty() const {
  return (length == 0);
}

template <class elemType> bool arrayListType<elemType>::isFull() const {
  return (length == maxSize);
}

template <class elemType> int arrayListType<elemType>::listSize() const {
  return length;
}

template <class elemType> int arrayListType<elemType>::maxListSize() const {
  return maxSize;
}

template <class elemType> void arrayListType<elemType>::print() const {
  for (int i = 0; i < length; i++)
    std::cout << list[i] << " ";

  std::cout << '\n';
}

template <class elemType>
bool arrayListType<elemType>::isItemEqualAt(int location,
                                            const elemType &item) const {
  return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location,
                                       const elemType &insertItem) {
  if (location < 0 || location >= maxSize)
    std::cerr << "The position of the item to be inserted "
              << "is out of range.\n";
  else if (length >= maxSize) // list is full
    std::cerr << "Cannot insert in a full list.\n";
  else {
    for (int i = length; i > location; i--)
      list[i] = list[i - 1]; // move the elements down

    list[location] = insertItem; // insert the item at the
                                 // specified position

    length++; // increment the length
  }
} // end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType &insertItem) {
  if (length >= maxSize) // the list is full
    std::cerr << "Cannot insert in a full list.\n";
  else {
    list[length] = insertItem; // insert the item at the end
    length++;                  // increment the length
  }
} // end insertEnd

template <class elemType> void arrayListType<elemType>::removeAt(int location) {
  if (location < 0 || location >= length)
    std::cerr << "The location of the item to be removed "
              << "is out of range.\n";
  else {
    for (int i = location; i < length - 1; i++)
      list[i] = list[i + 1];

    length--;
  }
} // end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location,
                                         elemType &retItem) const {
  if (location < 0 || location >= length)
    std::cerr << "The location of the item to be retrieved is "
              << "out of range.\n";
  else
    retItem = list[location];
} // end retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt(int location, const elemType &repItem) {
  if (location < 0 || location >= length)
    std::cerr << "The location of the item to be replaced is "
              << "out of range.\n";
  else
    list[location] = repItem;
} // end replaceAt

template <class elemType> void arrayListType<elemType>::clearList() {
  length = 0;
} // end clearList

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType &item) const {
  int loc;
  bool found = false;

  for (loc = 0; loc < length; loc++)
    if (list[loc] == item) {
      found = true;
      break;
    }

  if (found)
    return loc;
  else
    return -1;
} // end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType &insertItem) {
  int loc;

  if (length == 0)               // list is empty
    list[length++] = insertItem; // insert the item and
                                 // increment the length
  else if (length == maxSize)
    std::cerr << "Cannot insert in a full list.\n";
  else {
    loc = seqSearch(insertItem);

    if (loc == -1) // the item to be inserted
                   // does not exist in the list
      list[length++] = insertItem;
    else
      std::cerr << "The item to be inserted is already in "
                << "the list. No duplicates are allowed.\n";
  }
} // end insert

template <class elemType>
void arrayListType<elemType>::remove(const elemType &removeItem) {
  int loc;

  if (length == 0)
    std::cerr << "Cannot delete from an empty list.\n";
  else {
    loc = seqSearch(removeItem);

    if (loc != -1)
      removeAt(loc);
    else
      std::cout << "The item to be deleted is not in the list.\n";
  }
} // end remove

template <class elemType> void arrayListType<elemType>::selectionSort() {
  int minIndex;

  for (int loc = 0; loc < length - 1; loc++) {
    minIndex = minLocation(loc, length - 1);
    swap(loc, minIndex);
  }
} // end selectionSort

template <class elemType> void arrayListType<elemType>::insertionSort() {
  int firstOutOfOrder, location;
  elemType temp;

  for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    if (list[firstOutOfOrder] < list[firstOutOfOrder - 1]) {
      temp = list[firstOutOfOrder];
      location = firstOutOfOrder;

      do {
        list[location] = list[location - 1];
        location--;
      } while (location > 0 && list[location - 1] > temp);

      list[location] = temp;
    }
} // end insertionSort

template <class elemType> void arrayListType<elemType>::shellSort() {
  int inc;

  for (inc = 1; inc < (length - 1) / 9; inc = 3 * inc + 1)
    ;

  do {
    for (int begin = 0; begin < inc; begin++)
      intervalInsertionSort(begin, inc);
    inc = inc / 3;
  } while (inc > 0);
} // end shellSort

template <class elemType> void arrayListType<elemType>::quickSort() {
  recQuickSort(0, length - 1);
} // end quickSort

template <class elemType> void arrayListType<elemType>::heapSort() {
  elemType temp;

  buildHeap();

  for (int lastOutOfOrder = length - 1; lastOutOfOrder >= 0; lastOutOfOrder--) {
    temp = list[lastOutOfOrder];
    list[lastOutOfOrder] = list[0];
    list[0] = temp;
    heapify(0, lastOutOfOrder - 1);
  } // end for
} // end heapSort

template <class elemType> arrayListType<elemType>::arrayListType(int size) {
  if (size < 0) {
    std::cerr << "The array size must be positive. Creating "
              << "an array of size 100.\n";

    maxSize = 100;
  } else
    maxSize = size;

  length = 0;

  list = new elemType[maxSize];
  assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::arrayListType(
    const arrayListType<elemType> &otherList) {
  maxSize = otherList.maxSize;
  length = otherList.length;
  list = new elemType[maxSize]; // create the array
  assert(list != NULL);         // terminate if unable to allocate
                        // memory space

  for (int j = 0; j < length; j++) // copy otherList
    list[j] = otherList.list[j];
} // end copy constructor

template <class elemType> arrayListType<elemType>::~arrayListType() {
  delete[] list;
}

template <class elemType>
int arrayListType<elemType>::minLocation(int first, int last) {
  int minIndex;

  minIndex = first;

  for (int loc = first + 1; loc <= last; loc++)
    if (list[loc] < list[minIndex])
      minIndex = loc;

  return minIndex;
} // end minLocation

template <class elemType>
void arrayListType<elemType>::intervalInsertionSort(int begin, int inc) {
  for (int firstOutOfOrder = begin + inc; firstOutOfOrder < length;
       firstOutOfOrder += inc)
    if (list[firstOutOfOrder] < list[firstOutOfOrder - inc]) {
      int temp = list[firstOutOfOrder], location = firstOutOfOrder;

      do {
        list[location] = list[location - inc];
        location -= inc;
      } while (location >= 0 && list[location - inc] > temp);

      list[location] = temp;
    }
} // end intervalInsertionSort

template <class elemType>
int arrayListType<elemType>::partition(int first, int last) {
  elemType pivot;

  int index, smallIndex;

  swap(first, (first + last) / 2);

  pivot = list[first];
  smallIndex = first;

  for (index = first + 1; index <= last; index++)
    if (list[index] < pivot) {
      smallIndex++;
      swap(smallIndex, index);
    }

  swap(first, smallIndex);

  return smallIndex;
} // end partition

template <class elemType>
void arrayListType<elemType>::recQuickSort(int first, int last) {
  int pivotLocation;

  if (first < last) {
    pivotLocation = partition(first, last);
    recQuickSort(first, pivotLocation - 1);
    recQuickSort(pivotLocation + 1, last);
  }
} // end recQuickSort

template <class elemType>
void arrayListType<elemType>::swap(int first, int second) {
  elemType temp;

  temp = list[first];
  list[first] = list[second];
  list[second] = temp;
} // end swap

template <class elemType>
void arrayListType<elemType>::heapify(int low, int high) {
  int largeIndex;

  elemType temp = list[low]; // copy the root node of the subtree

  largeIndex = 2 * low + 1; // index of the left child

  while (largeIndex <= high) {
    if (largeIndex < high)
      if (list[largeIndex] < list[largeIndex + 1])
        largeIndex = largeIndex + 1; // index of the largest
                                     // child

    if (temp > list[largeIndex]) // subtree is already in a heap
      break;
    else {
      list[low] = list[largeIndex]; // move the larger child
                                    // to the root
      low = largeIndex; // go to the subtree to restore the heap
      largeIndex = 2 * low + 1;
    }
  } // end while

  list[low] = temp; // insert temp into the tree, that is, list
} // end heapify

template <class elemType> void arrayListType<elemType>::buildHeap() {
  for (int index = length / 2 - 1; index >= 0; index--)
    heapify(index, length - 1);
} // end buildHeap
#endif // ARRAY_LIST_TYPE_H