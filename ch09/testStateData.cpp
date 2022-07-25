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

    //Close files.
    infile.close();
    outfile.close();

    return EXIT_SUCCESS;
}