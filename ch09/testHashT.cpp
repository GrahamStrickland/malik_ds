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

    //Test insertion function.
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

    //Test search function.
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

    //End of test.
    std::cout << "End of test.\n";

    return 0;
}

int hashFunction(int k, int hashSize)
{
    return k % hashSize;
}