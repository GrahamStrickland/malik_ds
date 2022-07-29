//This is a driver program to test the ADT's hashT and stateData.

#include "hashT.h"
#include "stateData.h"

const int HTSize = 13;

int hashFunc(std::string name);
    //Hash function for strings.
    //Precondition: name.length() <= 15.
    //Postcondition: Returned hashFunc(name) using modulo HTSize.

int main()
{
    hashT<stateData> stateHashT;
    stateData state;
    std::ifstream infile("outfile.txt");
    std::string name, capital, area;
    int yearOfAdmission, orderOfAdmission, hashIndex;
    bool found;

    //Add states in "outfile.txt" to hash table.
    while (infile >> state)
    {
        std::cout << "Adding state:\n" << state << '\n';
        state.getStateInfo(name, capital, area,
            yearOfAdmission, orderOfAdmission);
        hashIndex = hashFunc(name);
        stateHashT.insert(hashIndex, state);
    }

    //Search for state by last found name.
    stateHashT.search(hashIndex, state, found);
    std::cout << (found ? name + " found in hash table.\n"
                : name + " not found in hash table.\n");

    //Search for non-existent state.
    name = "Nebraska";
    capital = "Lincoln";
    area = "Midwest";
    yearOfAdmission = 1867;
    orderOfAdmission = 37;
    state.setStateInfo(name, capital, area, yearOfAdmission, 
        orderOfAdmission);
    hashIndex = hashFunc(name);
    stateHashT.search(hashIndex, state, found);
    std::cout << (found ? name + " found in hash table.\n"
                : name + " not found in hash table.\n");

    return EXIT_SUCCESS;
}

int hashFunc(std::string name)
{
    int i, sum;
    int len;

    i = 0;
    sum = 0;

    len = name.length();

    for (int k = 0; k < 15 - len; k++)
        name = name + ' ';  //increase the length of the name
                            //to 15 characters

    for (int k = 0; k < 5; k++)
    {
        sum = sum + static_cast<int>(name[i]) * 128 * 128
                + static_cast<int>(name[i + 1]) * 128
                + static_cast<int>(name[i + 2]);
        i = i + 3;
    }

    return sum % HTSize;
}