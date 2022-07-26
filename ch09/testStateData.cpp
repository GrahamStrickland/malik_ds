//This is a driver program to test the ADT stateData.

#include <cstdlib>
#include "stateData.h"

int main()
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string infName, outfName;

    //Get input filename, open and test for errors.
    std::cout << "Please enter an input file name: ";
    std::cin >> infName;
    infile.open(infName);
    if (infile.fail())
    {
        std::cerr << "Error: unable to open file.\n";
        exit(EXIT_FAILURE);
    }
    //Get output filename, open and test for errors.
    std::cout << "Please enter an output file name: ";
    std::cin >> outfName;
    if (outfile.fail())
    {
        std::cerr << "Error: unable to open output file.\n";
        exit(EXIT_FAILURE);
    }

    //Test stateData constructor.
    stateData state1("Louisiana", "Baton Rouge",
        "Deep South", 1812, 18),
        state2("Arkansas", "Little Rock", 
        "South Central", 1836, 25),
        state3, state4;

    //Test stateData setter.
    std::string name = "Texas", capital = "Austin", area = "South Central";
    int yearOfAdmission = 1845, orderOfAdmission = 28;
    state3.setStateInfo(name, capital, area,    
        yearOfAdmission, orderOfAdmission);
    std::cout << "Please enter the name of a state: ";
    std::cin >> name;
    std::cout << "Please enter " << name << "\'s capital city: ";
    std::cin >> capital;
    std::cout << "Please enter the area of " << name
              << ": ";
    std::cin >> area;
    std::cout << "Please enter the year of " << name
              << "\'s admission to the union: ";
    std::cin >> yearOfAdmission;
    std::cout << "Please enter the order of "  << name
              << "\'s admission to the union: ";
    std::cin >> orderOfAdmission;
    state4.setStateInfo(name, capital, area,    
        yearOfAdmission, orderOfAdmission);

    //Test stateData getter.

    //Test stateData stream operators.

    //Test stateData comparison operators.

    //Close files.
    infile.close();
    outfile.close();

    return EXIT_SUCCESS;
}