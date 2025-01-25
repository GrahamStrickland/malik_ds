#ifndef ORDERED_ARRAY_LIST_TYPE
#define ORDERED_ARRAY_LIST_TYPE

#include "arrayListType.h"

template <class elemType>
class orderedArrayListType : public arrayListType<elemType> {
public:
  int binarySearch(const elemType &item) const;
  void insertOrd(const elemType &item);
  orderedArrayListType(int size = 100);
};

template <class elemType>
int orderedArrayListType<elemType>::binarySearch(const elemType &item) const {
  int first = 0;
  int last = length - 1;
  int mid;

  bool found = false;

  while (first <= last && !found) {
    mid = (first + last) / 2;

    if (list[mid] == item)
      found = true;
    else if (list[mid] > item)
      last = mid - 1;
    else
      first = mid + 1;
  }

  if (found)
    return mid;
  else
    return -1;
} // end binarySearch

template <class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType &item) {
  int first = 0;
  int last = length - 1;
  int mid;

  bool found = false;

  if (length == 0) // the list is empty
  {
    list[0] = item;
    length++;
  } else if (length == maxSize)
    std::cerr << "Cannot insert into a full list.\n";
  else {
    while (first <= last && !found) {
      mid = (first + last) / 2;

      if (list[mid] == item)
        found = true;
      else if (list[mid] > item)
        last = mid - 1;
      else
        first = mid + 1;
    } // end while

    if (found)
      std::cerr << "The insert item is already in the list. "
                << "Duplicates are not allowed.\n";
    else {
      if (list[mid] < item)
        mid++;

      insertAt(mid, item);
    }
  }
} // end insertOrd

template <class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size)
    : arrayListType(size) {
  // Function body deliberately blank.
} // end constructor
#endif // ORDERED_ARRAY_LIST_TYPE