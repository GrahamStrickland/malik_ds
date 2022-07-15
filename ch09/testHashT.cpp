//This is a driver program to test the ADT hashT that implements
//a hash table using quadratic probing.

#include "hashT.h"

int hashFunction(int k, int hashSize);
    //Hashing function for hashTables.
    //Postcondition: returned k % hashSize.

int main()
{   //Test constructors.
    int ID, 
        studentHashSize(13), 
        teacherHashSize(19), 
        workerHashSize(7);
    hashT<int> studentID(studentHashSize),
               teacherID(teacherHashSize), 
               workerID(workerHashSize);

    //Test insertion function.
    std::cout << "Please enter ID of student: ";
    std::cin >> ID;
    studentID.insert(hashFunction(ID, studentHashSize), ID);

    return 0;
}

int hashFunction(int k, int hashSize)
{
    return k % hashSize;
}