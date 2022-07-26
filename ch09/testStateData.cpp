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
        state3;

    //Test stateData setter.


    //Test stateData getter.

    //Test stateData stream operators.

    //Test stateData comparison operators.

    //Close files.
    infile.close();
    outfile.close();

    return EXIT_SUCCESS;
}