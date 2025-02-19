// This is a driver program to test the ADT stateData.

#include "stateData.h"
#include <cstdlib>

int main() {
  std::ifstream infile;
  std::ofstream outfile;
  std::string infName, outfName;

  // Get input filename, open and test for errors.
  std::cout << "Please enter an input file name: ";
  std::cin >> infName;
  infile.open(infName.c_str());
  if (infile.fail()) {
    std::cerr << "Error: unable to open file.\n";
    exit(EXIT_FAILURE);
  }
  // Get output filename, open and test for errors.
  std::cout << "Please enter an output file name: ";
  std::cin >> outfName;
  outfile.open(outfName.c_str());
  if (outfile.fail()) {
    std::cerr << "Error: unable to open output file.\n";
    exit(EXIT_FAILURE);
  }

  // Test stateData constructor.
  stateData state1("Louisiana", "Baton Rouge", "Deep South", 1812, 18),
      state2("Arkansas", "Little Rock", "South Central", 1836, 25), state3,
      state4;

  // Test stateData setter.
  std::string name = "Texas", capital = "Austin", area = "South Central";
  int yearOfAdmission = 1845, orderOfAdmission = 28;
  state3.setStateInfo(name, capital, area, yearOfAdmission, orderOfAdmission);
  std::cout << "\nPlease enter the name of a state: ";
  std::cin.ignore(100, '\n');
  getline(std::cin, name);
  std::cout << "Please enter " << name << "\'s capital city: ";
  getline(std::cin, capital);
  std::cout << "Please enter the area of " << name << ": ";
  getline(std::cin, area);
  std::cout << "Please enter the year of " << name
            << "\'s admission to the union: ";
  std::cin >> yearOfAdmission;
  std::cout << "Please enter the order of " << name
            << "\'s admission to the union: ";
  std::cin >> orderOfAdmission;
  state4.setStateInfo(name, capital, area, yearOfAdmission, orderOfAdmission);

  // Test stateData getter.
  std::cout << "\nTesting stateData.get():\n";
  state1.getStateInfo(name, capital, area, yearOfAdmission, orderOfAdmission);
  std::cout << "\nName: " << name << "\nCapital: " << capital
            << "\nArea: " << area
            << "\nYear of Admission to Union: " << yearOfAdmission
            << "\nOrder of Admission "
            << "to Union: " << orderOfAdmission << "\n";

  // Test stateData stream extraction operator.
  stateData state5, state6;
  infile >> state5 >> state6;

  // Test stateData stream insertion operator.
  std::cout << "\nWriting to file:\n"
            << state1 << '\n'
            << state2 << '\n'
            << state3 << '\n'
            << state4 << '\n'
            << state5 << '\n'
            << state6;
  outfile << state1 << state2 << state3 << state4 << state5 << state6;

  // Test stateData comparison operators.
  std::cout << "\nTesting comparison operators:\n"
            << (state1 == state1 ? "state1 == state1" : "state1 != state1")
            << '\n'
            << (state1 != state3 ? "state1 != state3" : "state1 == state3")
            << '\n'
            << (state2 < state3 ? "state2 < state3" : "state2 >= state3")
            << '\n'
            << (state2 <= state3 ? "state2 <= state3" : "state2 > state3")
            << '\n'
            << (state4 > state5 ? "state4 > state5" : "state4 <= state5")
            << '\n'
            << (state4 >= state6 ? "state4 >= state6" : "state4 < state6")
            << '\n';

  // Close files.
  infile.close();
  outfile.close();

  return EXIT_SUCCESS;
}