//This is a driver program to test the ADT hashT that implements
//a hash table using quadratic probing.

#include "hashT.h"

int hashFunction(int k, int hashSize);
    //Hashing function for hashTables.
    //Postcondition: returned k % hashSize.

int main()
{   //Test constructors.
    int ID, hashIndex,
        studentHashSize(13), 
        numStudents(8);
    hashT<int> studentID(studentHashSize);
    bool found(false);

    //Test insert() method.
    std::cout << "Welcome to the student ID entry portal.\n"
              << "Enter ID's for the first eight students.\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Please enter ID of student " 
                  << std::to_string(i+1) << ": ";
        std::cin >> ID;
        hashIndex = hashFunction(ID, studentHashSize);
        studentID.insert(hashIndex, ID);
    }
    std::cout << "\n";

    //Test search() method.
    std::cout << "Please enter a student ID to search for: ";
    std::cin >> ID;
    while (ID != -1) {
        hashIndex = hashFunction(ID, studentHashSize);
        studentID.search(hashIndex, ID, found);
        std::cout << (found ? "ID " + std::to_string(ID) + 
                  " found at position " + std::to_string(hashIndex) 
                  : "ID " + std::to_string(ID) + " not found.") << '\n'
                  << "Please enter another ID (-1 to exit): ";
        std::cin >> ID;
    }

    //Test isItemAtEqual() and retrieve() methods.
    std::cout << "\nPlease enter an index and the item stored at "
              << "that index.\nIndex: ";
    std::cin >> hashIndex;
    std::cout << "ID stored at index " << hashIndex << ": ";
    std::cin >> ID;
    std::cout << ID << (studentID.isItemAtEqual(hashIndex, ID)
              ? " is equal to" : " is not equal to") << " item at "
              << "position " << hashIndex << ".\nItem stored at "
              << "position " << hashIndex << ": ";
    studentID.retrieve(hashIndex, ID);
    std::cout << ID << ".\n\n";

    //Test remove().
    std::cout << "Please enter a student ID to remove: ";
    std::cin >> ID;
    std::cout << "Please enter the position of student ID "
              << ID << ": ";
    std::cin >> hashIndex;
    studentID.remove(hashIndex, ID);

    //End of test.
    std::cout << "\nEnd of test.\n";

    return 0;
}

int hashFunction(int k, int hashSize)
{
    return k % hashSize;
}